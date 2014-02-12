//* Description *//
// Title: Equals Constraint
// Author: Tyler Reed
// Defines an Equals Constraint for "A == B"

//* Package *//
package Assignment;

//* Libraries *//
import ConstraintSatisfaction.Constraint;
import ConstraintSatisfaction.ConstrainedVariable;

//* Class *//
public class EqualsConstraint extends Constraint
{
	//* Constructor *//
	// Creates the Less Than Constraint Class
	public EqualsConstraint(ConstrainedVariable left, ConstrainedVariable right)
	{
		super(left, right);
	}

	// Returns whether or not the Constraint is Enforced
	public boolean isEnforced()
	{
		if(isAssigned())
			return left.getAssignedValue().compareTo(right.getAssignedValue()) == 0;
		else
			return false;
	}
}