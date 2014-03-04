//* Description *//
// Title: Forward-Checking Solver
// Author: Tyler Reed
// Defines the CSS using the Forward-Checking Method

//* Package *//
package ConstraintSatisfaction.Solver;

//* Libraries *//
import java.util.List;
import java.util.SortedSet;
import ConstraintSatisfaction.ConstrainedVariable;
import ConstraintSatisfaction.Constraint;
import ConstraintSatisfaction.DomainException;
import ConstraintSatisfaction.DomainValue;
import ConstraintSatisfaction.ParticipantException;
import ConstraintSatisfaction.Ordering.ValueOrdering;
import ConstraintSatisfaction.Ordering.ValueOrderingFactory;
import ConstraintSatisfaction.Ordering.VariableOrdering;

//* Class *//
public class FCSolver extends Solver
{
	//* Constructor *//
	public FCSolver(VariableOrdering variables, ValueOrderingFactory factory, List<Constraint> constraints)
	{
		super(variables, factory, constraints);
	}

	//* CSP Methods *//
	// Solves the CSP Recursively
	protected boolean recursiveSolve(ConstrainedVariable variable) throws ParticipantException
	{
		boolean satisfied = isSatisfied();

		// Determine whether or not to Give Up
		if(attempts >= maxAttempts)
			return false;

		// Determine whether or not this Path is a Dead End
		if(!satisfied)
		{
			attempts++;
			storeFailure();
			return false;
		}

		// Determine whether or not this Path is Valid
		if(variable == null && satisfied)
		{
			attempts++;
			storeSuccess();
			return true;
		}

		// Search for another Path
		boolean success = false;

		// Add the Variable to the Working Stack
		activeVariables.add(variable);

		// Create the Value Ordering for the Variable
		ValueOrdering ordering = valueFactory.createOrdering(variable);

		// Determine the Next Value
		DomainValue value = ordering.next();

		// Try all Iterations of this Branch
		while(value != null && !success && attempts < maxAttempts)
		{
			// Assign the Variable a Value
			try {variable.setAssignedValue(value);}
			catch(DomainException ex) {continue;}

			// Perform Forward Checking
			if(forwardCheck(variable))
			{
				attempts++;
				storeFailure();
			}
			else
			{
				// Determine the Next Variable
				ConstrainedVariable next = variableOrder.next();
	
				// Try that Branch
				success = recursiveSolve(next);
	
				// Incase that didn't work, prepare for another Iteration
				variableOrder.backtrack(next);
			}

			// Remove Domains that are now Illegal from other Variables
			popConstrainedDomains(variable);

			value = ordering.next();
		}

		// The specified Variable has been Exhausted
		variable.unassign();
		activeVariables.remove(variable);
		return success;
	}

	//* Forward Checking Methods *//
	// Performs Forward Checking on the specified Variable
	protected boolean forwardCheck(ConstrainedVariable variable) throws ParticipantException
	{
		// Initial the Domain Status
		boolean empty = false;

		// Check each Constraint for possible Domain Values
		for(Constraint constraint : constraints)
		{
			// Make sure the Variable is a Participant
			if(!constraint.isParticipant(variable))
				continue;

			// Determine the Other Pariticipant
			ConstrainedVariable other = constraint.getOtherParticipant(variable);

			// Make sure the other Participant is Unassigned
			if(other.isAssigned())
				continue;

			SortedSet<DomainValue> domain = constraint.getConstrainedDomain(variable, variable.getAssignedValue());
			other.pushConstrainedDomain(domain);

			if(!empty && domain.isEmpty())
				empty = true;
		}

		return empty;
	}

	// Removes the Constrained Domains of Effected by the specified Variable
	protected void popConstrainedDomains(ConstrainedVariable variable) throws ParticipantException
	{
		// Selectively Remove the Domains of Constraints
		for(Constraint constraint : constraints)
		{
			// Make sure the specified Variable is a Participant
			if(constraint.isParticipant(variable))
			{
				// Determine the Other Participant
				ConstrainedVariable other = constraint.getOtherParticipant(variable);

				// Make sure the Other Participant is Unassigned
				if(!other.isAssigned())
					other.popConstrainedDomain();
			}
		}
	}
}
