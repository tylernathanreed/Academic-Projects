//* Description *//
// Title: Clause
// Author: Tyler Reed
// Contains a Set of Literals joined by an OR Condition

//* Package *//
package Knowledge;

//* Libraries *//
import java.util.ArrayList;
import java.util.List;
import java.util.SortedSet;
import java.util.TreeSet;

//* Class *//
public class Clause implements Comparable<Clause>
{
	//* Class Variables *//
	List<Literal> originalLiterals;
	SortedSet<Literal> currentLiterals;

	//* Constructors *//
	// Creates a Clause with a List of Literals
	public Clause(List<Literal> literals)
	{
		originalLiterals = new ArrayList<Literal>(literals);
		currentLiterals = new TreeSet<Literal>(literals);

		simplify();
	}

	// Creates a Clause with a Sorted Set of Literals
	public Clause(SortedSet<Literal> literals)
	{
		originalLiterals = new ArrayList<Literal>(literals);
		currentLiterals = new TreeSet<Literal>(literals);

		simplify();
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
	public void simplify()
	{
		// Create a Set to Track and Remove Literals
		SortedSet<Literal> knownLiterals = new TreeSet<Literal>();
		SortedSet<Literal> removeLiterals = new TreeSet<Literal>();

		// Cycle through all Literals
		for(Literal literal : currentLiterals)
		{
			// Check if the Literal is already Known
			if(knownLiterals.contains(literal))
				removeLiterals.add(literal);
			else
				knownLiterals.add(literal);

			// Create the Inverse of the Literal
			Literal inverse = new Literal(literal.getVariable(), !literal.isNegated());

			// Check if the Inverse Literal is Known
			if(knownLiterals.contains(inverse))
			{
				removeLiterals.add(literal);
				removeLiterals.add(inverse);
			}
		}

		// Remove the Marked Literals
		currentLiterals.removeAll(removeLiterals);

		// Check if only one Literal Remains
		if(currentLiterals.size() == 1 && !isAssigned())
		{
			// Determine the Remaining Literal
			Literal literal = currentLiterals.first();

			// Assign the Variable a Value
			literal.getVariable().setValue(!literal.isNegated());
		}
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
	public List<Literal> getOriginalLiterals()
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
		// Perform an Intersection on Current and Original
		List<Literal> stringLiterals = new ArrayList<Literal>();
		stringLiterals.addAll(originalLiterals);
		stringLiterals.retainAll(currentLiterals);

		// Determine the Literal String
		String str = stringLiterals.toString();

		return str.substring(1, str.length() - 1);
	}

	//* Comparable Methods *//
	// Returns an Integer (-1, 0, 1) representing a Comparison
	public int compareTo(Clause clause)
	{
		if(currentLiterals.containsAll(clause.getCurrentLiterals()))
		{
			if(clause.getCurrentLiterals().containsAll(currentLiterals))
				return 0;
			else
				return 1;
		}
		else
			return -1;
	}

	// Returns whether or another Clause is Equal To this Clause
	public boolean equals(Object object)
	{
		return compareTo((Clause) object) == 0;
	}
}
