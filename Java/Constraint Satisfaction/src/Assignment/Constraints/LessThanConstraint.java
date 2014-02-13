//* Description *//
// Title: Less Than Constraint
// Author: Tyler Reed
// Defines a Less Than Constraint for "A < B"

//* Package *//
package Assignment.Constraints;

//* Libraries *//
import ConstraintSatisfaction.Constraint;
import ConstraintSatisfaction.ConstrainedVariable;

//* Class *//
public class LessThanConstraint extends Constraint
{
	//* Constructor *//
	// Creates the Less Than Constraint Class
	public LessThanConstraint(ConstrainedVariable left, ConstrainedVariable right)
	{
		super(left, right);
	}

	// Returns whether or not the Constraint is Enforced
	public boolean isEnforced()
	{
		if(isAssigned())
			return left.getAssignedValue().compareTo(right.getAssignedValue()) < 0;
		else
			return false;
	}
}