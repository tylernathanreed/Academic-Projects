//* Description *//
// Title: Value Ordering
// Author: Tyler Reed
// Creates the Interface for Ordering Values

//* Package *//
package ConstraintSatisfaction.Ordering;

//* Libraries *//
import ConstraintSatisfaction.ConstrainedVariable;
import ConstraintSatisfaction.DomainValue;

//* Interface *//
public interface ValueOrdering
{
	// Returns the Next Value
	public abstract DomainValue next();

	// Returns the Ordering
	public abstract ConstrainedVariable getOrdering();
}
