//* Description *//
// Title: Most-Constrained Variable Ordering
// Author: Tyler Reed
// Orders Variables by their Number of Constraints

//* Package *//
package ConstraintSatisfaction.Ordering;

//* Libraries *//
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Vector;
import ConstraintSatisfaction.ConstrainedVariable;
import ConstraintSatisfaction.Constraint;
import ConstraintSatisfaction.ParticipantException;

//* Class *//
public class MCVOrdering implements VariableOrdering
{
	//* Class Methods *//
	private List<ConstrainedVariable> variables;
	private List<ConstrainedVariable> available;
	private HashMap<ConstrainedVariable, Vector<Constraint>> constraints;

	//* Constructor *//
	// Creates the Most-Constrained Variable Ordering Class
	public MCVOrdering(List<ConstrainedVariable> variables, List<Constraint> constraints)
	{
		this.variables = variables;
		available = new Vector<ConstrainedVariable>();
		available.addAll(variables);

		this.constraints = new HashMap<ConstrainedVariable, Vector<Constraint>>();

		// Create a Hash Entry for each Variable
		for(int i = 0; i < variables.size(); i++)
		{
			// Determine the Current Variable
			ConstrainedVariable variable = variables.get(i);

			this.constraints.put(variable, new Vector<Constraint>());
		}

		// Populate the Hashed Constraints
		for(int i = 0; i < constraints.size(); i++)
		{
			// Determine the Current Constraint
			Constraint constraint = constraints.get(i);

			// Determine the Constraint Participants
			ConstrainedVariable left = constraint.getLeftVariable();
			ConstrainedVariable right = constraint.getRightVariable();

			// Hash the Constraints
			this.constraints.get(left).add(constraint);
			this.constraints.get(right).add(constraint);
		}
	}

	//* Interface Methods *//
	// Returns the List of Variables
	public List<ConstrainedVariable> getVariables()
	{
		return variables;
	}

	// Returns the List of Unassigned Variables
	public List<ConstrainedVariable> getUnassignedVariables()
	{
		// Return a Copy of the List
		List<ConstrainedVariable> list = new Vector<ConstrainedVariable>();
		list.addAll(available);
		return list;
	}

	// Returns the Next Variable in the Ordering
	public ConstrainedVariable next()
	{
		// Make sure there is an Available Variable
		if(available.isEmpty())
			return null;

		// Create a List of Candidates
		LinkedList<ConstrainedVariable> candidates = new LinkedList<ConstrainedVariable>();
		Iterator<ConstrainedVariable> iterator = available.iterator();
		candidates.add((ConstrainedVariable) iterator.next());

		// Determine all Candidates
		while(iterator.hasNext())
		{
			ConstrainedVariable next = (ConstrainedVariable) iterator.next();

			// Determine Domain Sizes
			int nextSize = next.getConstrainedDomain().size();
			int firstSize = candidates.getFirst().getConstrainedDomain().size();

			// Compare Domain Sizes (Looking for Most Constrained)
			if(nextSize == firstSize) // Possible Candidate
				candidates.add(next);
			else if(nextSize < firstSize) // Better Candidate
			{
				candidates.clear();
				candidates.add(next);
			}
		}

		// Determine the Best Variable
		ConstrainedVariable next = candidates.poll();
		int nextCount = getActiveConstraintCount(next);

		// Elimate all other Candidates before Deciding
		while(!candidates.isEmpty())
		{
			// Determine the Current Candidate
			ConstrainedVariable candidate = candidates.poll();
			int candidateCount = getActiveConstraintCount(candidate);

			// Determine if the Current Candidate is Better
			if(candidateCount > nextCount)
			{
				next = candidate;
				nextCount = candidateCount;
			}
		}

		// Remove the Next Variable from the Available List
		available.remove(next);

		//if(Configuration.inDebugMode())
		//	System.out.println("[MCV Ordering] Getting Next Variable '" + next + "'");

		return next;
	}

	// Adds the specified Variable back into the Available Pool
	public void backtrack(ConstrainedVariable variable)
	{
		//if(Configuration.inDebugMode())
		//	System.out.println("[MCV Ordering] Backtracking from Variable '" + variable + "'");

		if(variable != null)
			available.add(variable);
	}

	//* Conversion Methods *//
	// Returns a String Representation of the Ordering
	public String toString()
	{
		return "Most Constrained Variable";
	}

	//* Private Methods *//
	// Returns the Number of Active Constraints of the specified Variable
	private int getActiveConstraintCount(ConstrainedVariable variable)
	{
		int count = 0;

		for(int i = 0; i < constraints.get(variable).size(); i++)
		{
			// Determine the Current Constraint
			Constraint constraint = constraints.get(variable).get(i);

			// Determine if the Other Participant is Unassigned
			ConstrainedVariable other;

			try {other = constraint.getOtherParticipant(variable);}
			catch(ParticipantException ex) {continue;}

			if(!other.isAssigned())
				count++;
		}

		return count;
	}
}
