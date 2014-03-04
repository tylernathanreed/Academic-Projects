//* Description *//
// Title: Least Constraining Value Ordering
// Author: Tyler Reed
// Orders Domain Values

//* Package *//
package ConstraintSatisfaction.Ordering;

//* Libraries *//
import java.util.List;
import java.util.PriorityQueue;
import java.util.SortedSet;
import java.util.Vector;
import ConstraintSatisfaction.ConstrainedVariable;
import ConstraintSatisfaction.Constraint;
import ConstraintSatisfaction.DomainValue;
import ConstraintSatisfaction.ParticipantException;

//* Class *//
public class LCVOrdering implements ValueOrdering
{
	//* Class Variables *//
	private ConstrainedVariable variable;
	private PriorityQueue<LCVPair> queue;
	
	//* Constructor *//
	public LCVOrdering(List<ConstrainedVariable> variables, List<Constraint> constraints, ConstrainedVariable orderVariable)
	{
		this.variable = orderVariable;
		queue = new PriorityQueue<LCVPair>();

		// Reconstruct the Variable List, skipping the Order Variable
		List<ConstrainedVariable> unassigned = new Vector<ConstrainedVariable>();

		// Add all Variables that are not the specified Variable
		for(ConstrainedVariable variable : variables)
			if(!variable.equals(orderVariable))
				unassigned.add(variable);

		// Determine the Domain Size
		for(DomainValue value : orderVariable.getConstrainedDomain())
		{
			int domainSize = 0;

			// Check each Constraint for Variables that will become Limited
			for(Constraint constraint : constraints)
			{
				// Only Focus on Constraints with the Order Variable
				if(constraint.isParticipant(orderVariable))
				{
					// Determine the Other Participant
					ConstrainedVariable other;

					try {other = constraint.getOtherParticipant(orderVariable);}
					catch(ParticipantException ex) {continue;}

					// Make sure that the Other Participant is Unassigned
					if(!other.isAssigned())
					{
						// Determine the Constraint Domain
						SortedSet<DomainValue> domain;
						
						try {domain = constraint.getConstrainedDomain(orderVariable, value);}
						catch(ParticipantException ex) {continue;}

						domainSize += domain.size();
					}
				}
			}

			queue.add(new LCVPair(value, domainSize));
		}
	}

	//* Interface Methods *//
	// Returns the Next Value
	public DomainValue next()
	{
		LCVPair pair = queue.poll();

		return pair == null ? null : pair.getValue();
	}

	// Returns the Ordering
	public ConstrainedVariable getOrdering()
	{
		return variable;
	}

	//* Conversion Methods *//
	// Returns a String Representation of the LCV Ordering
	public String toString()
	{
		return queue.toString();
	}
}
