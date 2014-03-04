//* Description *//
// Title: Letter Value
// Author: Tyler Reed
// Defines the Value Class acceptable for the Letter Class

//* Package *//
package Assignment;

//* Libraries *//
import ConstraintSatisfaction.DomainValue;

//* Class *//
public class LetterValue implements DomainValue
{
	//* Class Variables *//
	final int value;

	//* Constructor *//
	// Creates the Letter Value Class from the Integer Class
	public LetterValue(Integer value)
	{
		this.value = value;
	}

	// Creates the Letter Value Class from the Primitive Integer Type
	public LetterValue(int value)
	{
		this.value = value;
	}

	//* Value Methods *//
	// Returns the Value of the Letter Value
	public Object getValue()
	{
		return value;
	}

	//* Comparable Methods *//
	// Returns an Integer (-1, 0, 1) representing a Comparison
	public int compareTo(DomainValue otherValue)
	{
		int val = ((LetterValue) otherValue).value;

		if(value > val)
			return 1;
		else if(value < val)
			return -1;
		else // value == val
			return 0;
	}

	// Returns whether or not the Value is Equal to the specified Value
	public boolean equals(Object otherValue)
	{
		return compareTo((DomainValue) otherValue) == 0;
	}

	//* Conversion Methds *//
	// Returns the Letter Value as a String
	public String toString()
	{
		return "" + value;
	}
}
