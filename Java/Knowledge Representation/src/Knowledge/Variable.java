//* Description *//
// Title: Variable
// Author: Tyler Reed
// Contains a Name and Value with a possible Assignment

//* Package *//
package Knowledge;

//* Class *//
public class Variable implements Comparable<Variable>
{
	//* Class Variables *//
	String name;
	boolean assigned;
	boolean value;

	//* Constuctors *//
	// Creates a Named Variable with an Unassigned Value
	public Variable(String name)
	{
		this.name = name;
		this.assigned = false;
	}

	// Creates a Named Variable with an Assigned Value
	public Variable(String name, boolean value)
	{
		this.name = name;
		this.assigned = true;
		this.value = value;
	}

	//* Name Methods *//
	// Returns the Name of the Variable
	public String getName()
	{
		return name;
	}

	// Sets the Name of the Variable and Returns the Old Name
	public String setName(String name)
	{
		String old = this.name;
		this.name = name;
		return old;
	}

	//* Assignment Methods *//
	// Returns whether or not the Variable is Assigned
	public boolean isAssigned()
	{
		return assigned;
	}

	// Assigns the Variable a Value
	public void assign(boolean value)
	{
		this.value = value;
		this.assigned = true;
	}

	// Unassigns the Variable
	public void unassign()
	{
		this.assigned = false;
	}

	//* Value Methods *//
	// Returns the Value of the Variable
	public boolean getValue()
	{
		if(!assigned)
			throw new IllegalStateException("You must assign a Variable a Value before Accessing it!");

		return value;
	}

	// Sets the Value of the Variable
	public void setValue(boolean value)
	{
		assign(value);
	}

	// Flips the Value of the Variable and Returns the Old Value
	public boolean negateValue()
	{
		if(!assigned)
			throw new IllegalStateException("You must assign a Variable a Value before Negating it!");

		value = !value;

		return !value;
	}

	//* Comparable Methods *//
	// Returns an Integer (-1, 0, 1) representing a Comparison
	public int compareTo(Variable otherVariable)
	{
		// Determine the Name of the Other Variable
		String otherName = otherVariable.getName();

		// Sort by Name First
		if(!name.equals(otherName))
			return name.compareTo(otherName);

		// Determine the Assignment Status of the Other Variable
		boolean otherAssigned = otherVariable.isAssigned();

		// Sort by Assignment Status Second
		if(assigned && !otherAssigned) // Assignment is Greater
			return 1;
		else if(!assigned && otherAssigned) // Unassignment is Lesser
			return -1;
		else if(!assigned && !otherAssigned) // Both Unassigned are Equal
			return 0;

		// Determine the Value of the Other Variable
		boolean otherValue = otherVariable.getValue();

		// Sort by Value Third
		if(value == otherValue) // Same Value
			return 0;
		else if(value) // True is Greater
			return 1;
		else // False is Lesser
			return -1;
	}

	// Returns whether or not this Variable is Equal to Another
	public boolean equals(Object object)
	{
		// Check if other Object is a Variable
		if(object.getClass() == this.getClass())
			return compareTo((Variable) object) == 0;
		else
			return super.equals(object);
	}

	//* Conversion Methods *//
	// Returns a String Representation of the Variable
	public String toString()
	{
		return name;
	}
}
