//* Description *//
// Title: Value Ordering Factory
// Author: Tyler Reed
// Creates Value Orderings for Constrained Variables

//* Package *//
package ConstraintSatisfaction.Ordering;

//* Libraries *//
import ConstraintSatisfaction.ConstrainedVariable;

//* Interface *//
public abstract interface ValueOrderingFactory
{
	// Creates an Ordering for the specified Variable
	public abstract ValueOrdering createOrdering(ConstrainedVariable variable);
}
