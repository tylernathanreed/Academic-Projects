//* Description *//
// Usage: Constraint Solver
// Author: Tyler Reed
// Creates the Constraint Solver Class

//* Package *//
package ConstraintSatisfaction;

//* Libraries *//
import java.util.List;
import java.util.Vector;
import ConstraintSatisfaction.ConstrainedVariable;

//* Class *//
public class ConstraintSolver
{
	//* Class Variables *//
	private List<ConstrainedVariable> csp;

	//* Heuristic Methods *//
	// Returns the Next Constrained Variable to Assign
	public ConstrainedVariable getNextVariable()
	{
		// Determine Most Constrained Variable
		List<ConstrainedVariable> variables = getMostConstrainedVariables(csp.subList(0, csp.size()));

		// Check for Ties
		if(variables.size() > 1)
		{
			// Break Ties with Most Constraining Variable
			variables = getMostConstrainingVariables(variables);

			// Check for Additional Ties
			if(variables.size() > 1)
			{
				// Break Ties with Comparable<T>
				return getGreatestVariable(variables);
			}
			else
				return variables.get(0);
		}
		else
			return variables.get(0);
			
	}

	// Returns a List of Most Constrained Variables from a List of Variables
	public List<ConstrainedVariable> getMostConstrainedVariables(List<ConstrainedVariable> list)
	{
		// Determine the Most Constrained Variable Count
		int[] count = new int[list.size()];
		int max = 0;

		for(int i = 0; i < list.size(); i++)
		{
			count[i] = getConstraintCount(list.get(i));

			if(max < count[i])
				max = count[i];
		}

		// Create Constraint List
		List<ConstrainedVariable> variables = new Vector<ConstrainedVariable>();

		// Add Most Constrained Variables
		for(int i = 0; i < list.size(); i++)
			if(count[i] == max)
					variables.add(list.get(i));

		return variables;
	}

	// Returns a List of Most Constraining Variables from a List of Variables
	public List<ConstrainedVariable> getMostConstrainingVariables(List<ConstrainedVariable> list)
	{
		// Break Ties with Most Constraining Variable
		int[] count = new int[list.size()];
		int max = 0;

		for(int i = 0; i < list.size(); i++)
		{
			count[i] = list.get(i).getConstraintCount();

			if(max < count[i])
				max = count[i];
		}

		List<ConstrainedVariable> variables = new Vector<ConstrainedVariable>();

		for(int i = 0; i < list.size(); i++)
			if(count[i] == max)
				variables.add(list.get(i));

		return variables;
	}

	// Returns the Greatest Variable from a List of Variables
	public ConstrainedVariable getGreatestVariable(List<ConstrainedVariable> list)
	{
		for(int i = 0; i < list.size(); i++)
			for(int j = i; j < list.size(); j++)
				if(list.get(i).compareTo(list.get(j)) > 0)
					list.remove(j--);

		// Break Ties with Index
		return list.get(0);
	}

	// Returns the Number of Contraints on the specified Variable
	public int getConstraintCount(ConstrainedVariable variable)
	{
		int count = 0;

		for(int i = 0; i < csp.size(); i++)
			if(csp.get(i).isConstraining(variable))
				count++;

		return count;
	}
}
