//* Description *//
// Title: Solver
// Author: Tyler Reed
// Defines the Constraint Satisfaction Solver

//* Package *//
package ConstraintSatisfaction.Solver;

//* Libraries *//
import java.util.List;
import ConstraintSatisfaction.ConstrainedVariable;
import ConstraintSatisfaction.Constraint;
import ConstraintSatisfaction.DomainValue;
import ConstraintSatisfaction.Ordering.ValueOrdering;
import ConstraintSatisfaction.Ordering.ValueOrderingFactory;
import ConstraintSatisfaction.Ordering.VariableOrdering;

//* Class *//
public class Solver extends AbstractSolver
{
	//* Constructor *//
	public Solver(VariableOrdering ordering, ValueOrderingFactory factory, List<Constraint> constraints)
	{
		super(ordering, factory, constraints);
	}

	//* CSP Methods *//
	// Solves the Problem
	public boolean solve()
	{
		// Reset the Search
		attempts = 0;

		// Determine the First Variable
		ConstrainedVariable first = variableOrder.next();

		// Recursively Solve the Problem
		boolean success;

		try {success = recursiveSolve(first);}
		catch(Exception ex) {ex.printStackTrace(); return false;}

		variableOrder.backtrack(first);

		// Return whether or not the Problem was Solvable
		return success;
	}

	// Recursively Solves the Problem
	protected boolean recursiveSolve(ConstrainedVariable variable) throws Exception
	{
		// Determine whether or not the Constraints are Satisfied
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
		ValueOrdering ordering = valueFactory.createOrdering(variable);
		DomainValue value = ordering.next();

		// Try all Iterations of this Branch
		while(value != null && !success && attempts < maxAttempts)
		{
			// Assign the Variable a Value
			variable.setAssignedValue(value);

			// Determine the Next Variable
			ConstrainedVariable next = variableOrder.next();

			// Try that Branch
			success = recursiveSolve(next);

			// Incase that didn't work, prepare for another Iteration
			variableOrder.backtrack(next);
			value = ordering.next();
		}

		// The specified Variable has been Exhausted
		variable.unassign();
		activeVariables.remove(variable);
		return success;
	}
}
