//* Description *//
// Title: Variable Ordering
// Author: Tyler Reed
// Creates the Interface for Ordering Variables

//* Package *//
package ConstraintSatisfaction.Ordering;

//* Libraries *//
import java.util.List;
import ConstraintSatisfaction.ConstrainedVariable;

//* Interface *//
public abstract interface VariableOrdering
{
	// Returns the List of Variables
	public abstract List<ConstrainedVariable> getVariables();

	// Returns the List of Unassigned Variables
	public abstract List<ConstrainedVariable> getUnassignedVariables();

	// Returns the Next Variable in the Ordering
	public abstract ConstrainedVariable next();

	// Adds the specified Variable back into the Available Pool
	public abstract void backtrack(ConstrainedVariable variable);
}
