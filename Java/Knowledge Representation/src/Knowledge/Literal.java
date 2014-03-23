//* Description *//
// Title: Literal
// Author: Tyler Reed
// Contains a Variable with a Negatible Condition

//* Package *//
package Knowledge;

//* Class *//
public class Literal implements Comparable<Literal>
{
	//* Class Variables *//
	private Variable variable;
	private boolean negated;

	//* Constructor *//
	// Creates the Literal with a Boolean Condition
	public Literal(Variable variable, boolean negated)
	{
		this.variable = variable;
		this.negated = negated;
	}

	//* Variable Methods *//
	// Returns the Name of the Variable
	public String getVariableName()
	{
		return variable.getName();
	}

	// Returns whether or not the Variable is Assigned
	public boolean isVariableAssigned()
	{
		return variable.isAssigned();
	}

	// Returns the Value of the Variable
	public boolean getVariableValue()
	{
		return variable.getValue();
	}

	// Returns the Variable in the Literal
	public Variable getVariable()
	{
		return variable;
	}

	//* Negation Methods *//
	// Returns whether or not the Literal is Negated
	public boolean isNegated()
	{
		return negated;
	}

	// Returns whether or not this Literal is the Inverse of Another
	public boolean isInverse(Literal literal)
	{
		// Make sure the Literals share the same Name
		if(!getVariableName().equals(literal.getVariableName()))
			return false;

		// Check if the Literals have Opposing Values
		return isNegated() != literal.isNegated();
	}

	//* Literal Methods *//
	// Returns the Value of the Literal
	public boolean getValue()
	{
		if(!variable.isAssigned())
			throw new IllegalStateException("You must assign a Literal Variable a Value before Accessing it!");

		return negated ? !variable.getValue() : variable.getValue();
	}

	//* Comparable Methods *//
	// Returns an Integer (-1, 0, 1) representing a Comparison
	public int compareTo(Literal otherLiteral)
	{
		// Determine the Name of the Literal and Other Literal
		String name = getVariableName();
		String otherName = otherLiteral.getVariableName();

		// Sort by Name First
		if(!name.equals(otherName))
			return name.compareTo(otherName);

		// Determine the Negation Status of the Literal and Other Literal
		boolean negated = isNegated();
		boolean otherNegated = otherLiteral.isNegated();

		// Sort by Negation Second
		if(negated && !otherNegated) // Negation is Greater
			return 1;
		else if(!negated && otherNegated)
			return -1;
		else
			return 0;
	}

	//* Conversion Methods *//
	// Returns a String Representation of the Literal
	public String toString()
	{
		return negated ? ("~" + variable) : variable.toString();
	}
}
