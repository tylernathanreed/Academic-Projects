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
import java.util.Map;
import java.util.SortedMap;
import java.util.SortedSet;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;

//* Class *//
public class KnowledgeBase
{
	//* Class Methods *//
	SortedSet<Variable> variables;
	List<Clause> originalClauses;
	List<Clause> currentClauses;
	Map<Clause, SortedSet<Integer>> indeces;
	SortedSet<Integer> contradictionIndex;

	//* Constructor *//
	// Creates a Knowledge Base with a Set of Clauses
	public KnowledgeBase(List<Clause> clauses) throws ContradictionException
	{
		// Determine the Set of Original Clauses
		originalClauses = clauses;

		// Initialize the Set of Derived Clauses
		//derivedClauses = new ArrayList<Clause>();

		// Determine the Set of Current Clauses
		currentClauses = new ArrayList<Clause>();

		for(Clause clause : clauses)
			currentClauses.add(clause);

		// Determine the Set of Variables
		variables = new TreeSet<Variable>();

		// Loop through each Clause
		for(Clause clause : clauses)
		{
			// Determine the Set of Literals
			List<Literal> literals = clause.getOriginalLiterals();

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

		// Simplify All Clauses
		for(Clause clause : clauses)
			clause.simplify();

		// Create the Derivation Hash Table
		indeces = new Hashtable<Clause, SortedSet<Integer>>();

		// Make sure there is not a Contradiction
		completeKnowledgeBase();
	}

	//* Knowledge Base Methods *//
	// Derives new Clauses from the existing Knowledge Base
	public SortedSet<Clause> deriveNewClauses() throws ContradictionException
	{
		// Set the Resolution Variables
		Resolution.setClauses(currentClauses);
		Resolution.clearDeductions();

		// Cycle through all Variables
		for(Variable variable : variables)
			new Resolution(variable);

		// Wait for Threads to Finish
		Resolution.joinAllThreads();

		// Add Derived Clauses
		currentClauses.addAll(Resolution.getDeductions());
		indeces.putAll(Resolution.getIndeces());

		// Add Termination Index
		if(Resolution.getTerminationIndex() != null)
			contradictionIndex = Resolution.getTerminationIndex();

		return Resolution.getDeductions();
	}

	// Completes the Knowledge Base by Deriving all possible Clauses
	private void completeKnowledgeBase() throws ContradictionException
	{
		// Derive Clauses until no new Clauses can be Derived
		SortedSet<Clause> clauses = deriveNewClauses();

		while(clauses.size() > 0 && contradictionIndex == null)
			clauses = deriveNewClauses();
	}

	//* Clause Methods *//
	// Returns whether or not the specified Clause exists in the Current Knowledge Base
	public boolean hasClause(Clause clause)
	{
		return currentClauses.contains(clause);
	}

	// Returns the Number of Clauses in the Knowledge Base
	public int getClauseCount()
	{
		return currentClauses.size();
	}

	//* Conversion Methods *//
	// Returns a String Representation of the Knowledge Base
	public String toString()
	{
		// Convert each Clause to a String using the Form:
		// X) Clause {Left, Right}
		// Where X is the Clause Index, and Left/Right are Parents
		// from the Resolution Rule.

		// In the Event of a Contradiction, only Clauses that
		// participated in the Contradiction should be Listed.

		// Determine the Initial Representation
		List<String> clauses = new ArrayList<String>(currentClauses.size() + 1);

		// Track the Clause Index
		int index = 0;

		// Cycle through each Clause
		for(Clause clause : currentClauses)
		{
			// Stop at Upper Contradiction Index
			if(contradictionIndex != null)
				if(index >= contradictionIndex.last())
					break;

			// Increase the Clause Index
			index++;

			// Determine the Initial Clause String
			String result = index + ") ";

			// Annex the Clause
			result += clause + " ";

			// Annex the Derivation (if any)
			if(indeces.containsKey(clause))
			{
				String str = indeces.get(clause).toString();
				result += "{" + str.substring(1, str.length() - 1) + "}";
			}
			else
				result += "{}";

			// Add the Result to the List
			clauses.add(index - 1, result);
		}

		// Add Contradiction Indeces
		if(contradictionIndex != null)
		{
			String str = contradictionIndex.toString();

			clauses.add(index, (index + 1) + ") False {" + str.substring(1, str.length() - 1) + "}");
		}

		// Convert the Array List to a String Output
		String result = "";

		// Use all Elements if no Contradiction Occurred
		if(contradictionIndex == null)
			for(String str : clauses)
				result += str + "\n";
		else
		{
			// Create a Sorted Hash to purge insignificant Clauses
			// while keeping the Output Sorted
			SortedMap<Integer, String> output = new TreeMap<Integer, String>();

			// Use another List to Determine which Clauses need Derivation Expansion
			Stack<String> expand = new Stack<String>();

			// Push the Contradiction (Final) Clause
			expand.push(clauses.get(clauses.size() - 1));

			// Expand all Clauses
			while(!expand.isEmpty())
			{
				// Determine the Next Clause
				String clause = expand.pop();

				// Determine the Index of the Clause
				index = Integer.valueOf(clause.substring(0, clause.indexOf(")")));

				// Add it to the Output
				output.put(index, clause);

				// Determine the Indeces in the Clause
				String substr = clause.substring(clause.indexOf("{") + 1, clause.indexOf("}"));

				if(substr == null || substr.equals(""))
					continue;

				String[] indeces = substr.split(", ");

				// Determine the Lower and Upper Indeces
				int lower = Integer.valueOf(indeces[0]);
				int higher = Integer.valueOf(indeces[1]);

				// Push the Derivation Clauses
				expand.push(clauses.get(lower - 1));
				expand.push(clauses.get(higher - 1));
			}

			// Convert the Sorted Output to a String
			for(Map.Entry<Integer, String> entry : output.entrySet())
				result += entry.getValue() + "\n";
		}

		// Add Final Clause Count
		result += "Clause Count: " + currentClauses.size();

		return result;
	}
}
