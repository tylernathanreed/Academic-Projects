//* Description *//
// Title: Knowledge Base
// Author: Tyler Reed
// Holds Clauses and Deduces new Information

//* Package *//
package Knowledge;

//* Libraries *//
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.List;
import java.util.SortedSet;
import java.util.TreeSet;

//* Class *//
public class KnowledgeBase
{
	//* Class Methods *//
	SortedSet<Variable> variables;
	SortedSet<Clause> originalClauses;
	SortedSet<Clause> currentClauses;
	Hashtable<Clause, List<Integer>> derivationIndeces;

	//* Constructor *//
	// Creates a Knowledge Base with a Set of Clauses
	public KnowledgeBase(SortedSet<Clause> clauses) throws ContradictionException
	{
		// Determine the Set of Original Clauses
		originalClauses = clauses;

		// Determine the Set of Current Clauses
		currentClauses = new TreeSet<Clause>();
		currentClauses.addAll(clauses);

		// Determine the Set of Variables
		variables = new TreeSet<Variable>();

		// Loop through each Clause
		for(Clause clause : clauses)
		{
			// Determine the Set of Literals
			SortedSet<Literal> literals = clause.getOriginalLiterals();

			// Loop through each Literal in each Clause
			for(Literal literal : literals)
			{
				// Determine the Literal Variable
				Variable variable = literal.getVariable();

				// Determine if the Variable is not in the Knowledge Base
				if(!variables.contains(variable))
					variables.add(variable); // Add it to the Knowledge Base
			}
		}

		System.out.println("[Knowledge Base] Known Variables: " + variables);
		System.out.println("[Knowledge Base] Known Clauses: " + clauses);

		// Create the Derivation Hash Table
		derivationIndeces = new Hashtable<Clause, List<Integer>>();

		// Make sure there is not a Contradiction
		completeKnowledgeBase();
	}

	//* Knowledge Base Methods *//
	// Derives new Clauses from the existing Knowledge Base
	public SortedSet<Clause> deriveNewClauses() throws ContradictionException
	{
		// Determine the Initial Set of new Clauses
		SortedSet<Clause> derivedClauses = new TreeSet<Clause>();

		System.out.println("[Knowledge Base] Deriving New Clauses:");

		// Cycle through all Variables
		for(Variable variable : variables)
		{
			System.out.println(" -> Checking Variable: " + variable);

			// Create the Positive and Negative Literals for the Variable
			Literal positiveLiteral = new Literal(variable, false);
			Literal negativeLiteral = new Literal(variable, true);

			// Determine the Initial Set of Positive and Negative Clauses
			SortedSet<Clause> positiveClauses = new TreeSet<Clause>();
			SortedSet<Clause> negativeClauses = new TreeSet<Clause>();

			// Search Clauses for the Positive Literal
			for(Clause clause : currentClauses)
				if(clause.contains(positiveLiteral))
					positiveClauses.add(clause);
				else if(clause.contains(negativeLiteral))
					negativeClauses.add(clause);

			// Track the Positive Clause Index
			int positiveIndex = 0;

			System.out.println("    -> Positive Clauses: " + positiveClauses);
			System.out.println("    -> Negative Clauses: " + negativeClauses);

			// Create new Clauses using the Restitution Rule
			for(Clause positiveClause : positiveClauses)
			{
				// Increase the Positive Index
				positiveIndex++;

				// Determine the Initial Literals in the Positive Clause
				SortedSet<Literal> positiveLiterals = positiveClause.getOriginalLiterals();

				// Track the Negative Clause Index
				int negativeIndex = 0;

				// Create a New Clause for each Negative Clause
				for(Clause negativeClause : negativeClauses)
				{
					// Increase the Negative Index
					negativeIndex++;

					// Determine the Initial Literals in the Negative Clause
					SortedSet<Literal> negativeLiterals = negativeClause.getOriginalLiterals();

					// Join the two Sets for a New Clause
					SortedSet<Literal> newLiterals = new TreeSet<Literal>();
					newLiterals.addAll(positiveLiterals);
					newLiterals.addAll(negativeLiterals);

					// Remove the Positive and Negative Literal Variable
					newLiterals.remove(positiveLiteral);
					newLiterals.remove(negativeLiteral);

					// Attempt to create a new Clause
					try
					{
						// Construct a Clause with the new Literals
						Clause newClause = new Clause(newLiterals);

						// Make sure the Clause is Unique
						if(hasClause(newClause) || derivedClauses.contains(newClause))
							continue;

						// Add the Clause to the Derived Set
						derivedClauses.add(newClause);

						// Track the Clause Indeces
						List<Integer> indeces = new ArrayList<Integer>(2);
						indeces.add(positiveIndex);
						indeces.add(negativeIndex);

						// Map the Indeces with the Clause
						derivationIndeces.put(newClause, indeces);

						System.out.println("       -> Derived Clause: " + newClause);
					}
					catch(ContradictionException ex)
					{
						String message = "Knowledge Base contains derivable Contradiction '" +
										 positiveClause + negativeClause + " -> " + newLiterals + "'";

						throw new ContradictionException(message);
					}
				}
			}
		}

		System.out.println("[Knowledge Base] Derived " + derivedClauses.size() + " New Clauses");
		return derivedClauses;
	}

	// Completes the Knowledge Base by Deriving all possible Clauses
	private void completeKnowledgeBase() throws ContradictionException
	{
		// Derive Clauses until no new Clauses can be Derived
		SortedSet<Clause> derivedClauses = deriveNewClauses();

		while(derivedClauses.size() > 0)
		{
			currentClauses.addAll(derivedClauses);
			derivedClauses = deriveNewClauses();
		}
	}

	//* Clause Methods *//
	// Returns whether or not the specified Clause exists in the Current Knowledge Base
	public boolean hasClause(Clause clause)
	{
		return currentClauses.contains(clause);
	}

	//* Conversion Methods *//
	// Returns a String Representation of the Knowledge Base
	public String toString()
	{
		// Determine the Initial Representation
		String result = "";

		// Track the Clause Index
		int index = 0;

		// Cycle through each Clause
		for(Clause clause : currentClauses)
		{
			// Increase the Clause Index
			index++;

			// Annex the Clause Index
			result += index + ") ";

			// Annex the Clause
			result += clause;

			// Annex the Derivation (if any)
			if(derivationIndeces.containsKey(clause))
				result += derivationIndeces.get(clause);
			else
				result += "{}";

			// Delimit the Clauses
			result += "\n";
		}

		return result;
	}
}
