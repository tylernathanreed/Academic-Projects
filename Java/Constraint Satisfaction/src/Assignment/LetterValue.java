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
	public int compareTo(LetterValue otherValue)
	{
		if(value > otherValue.value)
			return 1;
		else if(value < otherValue.value)
			return -1;
		else
			return 0;
	}

	@Override
	public int compareTo(DomainValue o) {
		// TODO Auto-generated method stub
		return 0;
	}
}
