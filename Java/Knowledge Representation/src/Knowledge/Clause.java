//* Description *//
// Title: Clause
// Author: Tyler Reed
// Contains a Set of Literals joined by an OR Condition

//* Package *//
package Knowledge;

//* Libraries *//
import java.util.Iterator;
import java.util.List;
import java.util.SortedSet;
import java.util.TreeSet;

//* Class *//
public class Clause implements Comparable<Clause>
{
	//* Class Variables *//
	SortedSet<Literal> originalLiterals;
	SortedSet<Literal> currentLiterals;

	//* Constructors *//
	// Creates a Clause with a List of Literals
	public Clause(List<Literal> literals) throws ContradictionException
	{
		originalLiterals = new TreeSet<Literal>(literals);

		// Make sure the Clause is free of Contradictions
		if(hasContradiction())
			throw new ContradictionException("Clauses cannot contain Contradictions!");

		// Use a Copy for the Current Literals
		currentLiterals = new TreeSet<Literal>(literals);

		for(Literal literal : originalLiterals)
			currentLiterals.add(literal.getCopy());
	}

	// Creates a Clause with a Sorted Set of Literals
	public Clause(SortedSet<Literal> literals) throws ContradictionException
	{
		originalLiterals = new TreeSet<Literal>(literals);

		// Make sure the Clause is free of Contradictions
		if(hasContradiction())
			throw new ContradictionException("Clauses cannot contain Contradictions!");

		// Use a Copy for the Current Literals
		currentLiterals = new TreeSet<Literal>(literals);

		for(Literal literal : originalLiterals)
			currentLiterals.add(literal.getCopy());
	}

	//* Clause Methods *//
	// Returns whether or not the Clause is True given the Current Information
	public boolean isTrue()
	{
		// At least One Literal must be True
		for(Literal literal : currentLiterals)
			if(literal.isVariableAssigned())
				if(literal.getValue())
					return true;

		return false;
	}

	// Returns whether or not the Clause is False given the Current Information
	public boolean isFalse()
	{
		// Make sure all Literals are Assigned
		if(!isAssigned())
			return false;

		// All Literals must be False
		for(Literal literal : currentLiterals)
			if(literal.getValue())
				return false;

		return true;
	}

	// Removes all False and Duplicate Literals from the Current Information
	public int simplify()
	{
		// Determine the Number of Removed Literals
		int count = 0;

		// Cycle through all Literals
		for(Literal literal : currentLiterals)
		{
			// Remove False Literals
			if(literal.isVariableAssigned())
				if(!literal.getValue())
				{
					currentLiterals.remove(literal);
					count++;
				}

			// Remove Duplicate Literals
			for(Literal otherLiteral : currentLiterals)
			{
				// Determine whether or not the Loop has Intersected
				boolean self = false;

				// Check for Duplicate Literal
				if(literal.equals(otherLiteral))
				{
					// Make sure the Literals aren't the same Literal from the Different Loops
					if(!self)
						self = true;
					else
					{
						// At this point, a second Duplicate Literal has been Found
						currentLiterals.remove(otherLiteral);
						count++;
					}
				}
			}
		}

		return count;
	}

	// Returns whether or not there is a Contradiction in the Original Information
	public boolean hasContradiction()
	{
		return getContradictions().size() > 0;
	}

	// Returns a Subset of the Clause that contains Contradictions
	public SortedSet<Literal> getContradictions()
	{
		// Determine the Initial Contradictions
		SortedSet<Literal> contradictions = new TreeSet<Literal>();

		// Cycle through each Literal
		for(Literal literal : originalLiterals)
		{
			// Check if the Literal is a known Contradiction
			if(contradictions.contains(literal))
				continue;

			// Compare each Literal to the Others
			for(Literal otherLiteral : originalLiterals)
			{
				// Ignore Self
				if(literal.equals(otherLiteral))
					continue;

				// Check if the Other Literal is a known Contradiction
				if(contradictions.contains(otherLiteral))
					continue;

				// Check if the Literals are Inverses
				if(literal.isInverse(otherLiteral))
				{
					// Add Both Literals to the Set of Contradictions
					contradictions.add(literal);
					contradictions.add(otherLiteral);
				}
			}
		}

		return contradictions;
	}

	//* Literal Methods *//
	// Returns whether or not All Literals are Assigned
	public boolean isAssigned()
	{
		for(Literal literal : currentLiterals)
			if(!literal.isVariableAssigned())
				return false;

		return true;
	}

	// Returns the Original Set of Literals
	public SortedSet<Literal> getOriginalLiterals()
	{
		return originalLiterals;
	}

	// Returns the Current Set of Literals
	public SortedSet<Literal> getCurrentLiterals()
	{
		return currentLiterals;
	}

	//* Container Methods *//
	// Returns whether or not the specified Literal is within the Clause
	public boolean contains(Literal literal)
	{
		return currentLiterals.contains(literal);
	}

	// Returns the Number of Literals in the Current Information
	public int getCurrentLiteralCount()
	{
		return currentLiterals.size();
	}

	// Returns the Number of Literals in the Original Information
	public int getOriginalLiteralCount()
	{
		return originalLiterals.size();
	}

	//* Conversion Methods *//
	// Returns a String Representation of the Clause
	public String toString()
	{
		return originalLiterals.toString();
	}

	//* Comparable Methods *//
	// Returns an Integer (-1, 0, 1) representing a Comparison
	public int compareTo(Clause clause)
	{
		// Compare by Literals
		Iterator<Literal> iterator = originalLiterals.iterator();
		Iterator<Literal> otherIterator = clause.getOriginalLiterals().iterator();

		while(iterator.hasNext())
		{
			// Check if the Other Clause still has a remaining Domain
			if(!otherIterator.hasNext())
				return 1;

			// Determine the Next Literals
			Literal literal = iterator.next();
			Literal otherLiteral = otherIterator.next();

			// Compare the two Literals
			if(!literal.equals(otherLiteral))
				return literal.compareTo(otherLiteral);
		}

		// Check if this Clause ran out of Literals
		if(otherIterator.hasNext())
			return -1;

		// Clauses are the same Size, and all Literals match
		return 0;
	}
}
