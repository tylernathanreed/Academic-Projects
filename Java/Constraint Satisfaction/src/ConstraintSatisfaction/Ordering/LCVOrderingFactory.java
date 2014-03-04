//* Description *//
// Title: Least-Constraining Value Factory
// Author: Tyler Reed
// Creates an LCV Ordering for Constrained Variables

//* Package *//
package ConstraintSatisfaction.Ordering;

//* Libraries *//
import java.util.List;
import ConstraintSatisfaction.ConstrainedVariable;
import ConstraintSatisfaction.Constraint;

//* Class *//
public class LCVOrderingFactory implements ValueOrderingFactory
{
	//* Class Variables *//
	private List<ConstrainedVariable> variables;
	private List<Constraint> constraints;

	//* Constructor *//
	// Creates the LCV Ordering Factory Class
	public LCVOrderingFactory(List<ConstrainedVariable> variables, List<Constraint> constraints)
	{
		this.variables = variables;
		this.constraints = constraints;
	}

	// Creates an Ordering for the specified Variable
	public ValueOrdering createOrdering(ConstrainedVariable variable)
	{
		return new LCVOrdering(variables, constraints, variable);
	}

	//* Conversion Methods *//
	// Returns a String Representation of the Ordering
	public String toString()
	{
		return "Least Constraining Value";
	}
}
