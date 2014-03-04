//* Description *//
// Title: Less Than Constraint
// Author: Tyler Reed
// Defines a Less Than Constraint for "A < B"

//* Package *//
package Assignment.Constraints;

//* Libraries *//
import java.util.SortedSet;
import java.util.TreeSet;
import ConstraintSatisfaction.Constraint;
import ConstraintSatisfaction.ConstrainedVariable;
import ConstraintSatisfaction.DomainValue;
import ConstraintSatisfaction.ParticipantException;

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
			return true;
	}

	// Returns the Remaining Domain should the specified Variable have the specified Value
	public SortedSet<DomainValue> getConstrainedDomain(ConstrainedVariable variable, DomainValue value) throws ParticipantException
	{
		SortedSet<DomainValue> domain = new TreeSet<DomainValue>();

		// Determine which Side the specified Variable is on
		if(variable.equals(left))
		{
			// Check if the Other Variable allows the Value
			for(DomainValue val : right.getConstrainedDomain())
			{
				// Check if the Current Value satisifies the Constraint
				if(val.compareTo(value) > 0)
					domain.add(val);
			}
		}
		else if(variable.equals(right))
		{
			// Check if the Other Variable allows the Value
			for(DomainValue val : left.getConstrainedDomain())
			{
				// Check if the Current Value satisifies the Constraint
				if(val.compareTo(value) < 0)
					domain.add(val);
			}
		}
		else
			throw new ParticipantException();

		return domain;
	}

	//* Conversion Methods *//
	// Returns the Constraint as a String
	public String toString()
	{
		String leftValue = left.isAssigned() ? left.getAssignedValue().toString() : "?";
		String rightValue = right.isAssigned() ? right.getAssignedValue().toString() : "?";

		return left + " (" + leftValue + ") < " + right + " (" + rightValue + ")";
	}
}