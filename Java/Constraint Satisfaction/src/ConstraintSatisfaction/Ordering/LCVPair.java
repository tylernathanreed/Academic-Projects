//* Description *//
// Title: Least-Constraining Value Pair
// Author: Tyler Reed
// Support Class for LCVOrdering

//* Package *//
package ConstraintSatisfaction.Ordering;

//* Libraries *//
import ConstraintSatisfaction.DomainValue;

//* Class *//
public class LCVPair implements Comparable<LCVPair>
{
	//* Class Variables *//
	private DomainValue value;
	private int size;

	//* Constuctor *//
	// Creates the LCVPair Class
	public LCVPair(DomainValue value, int size)
	{
		this.value = value;
		this.size = size;
	}

	//* Value Methods *//
	// Returns the Domain Value
	public DomainValue getValue()
	{
		return value;
	}

	// Returns the Domain Size
	public int getDomainSize()
	{
		return size;
	}

	//* Comparable Methods *//
	// Returns an Integer (-1, 0, 1) representing a Comparison
	public int compareTo(LCVPair otherPair)
	{
		// Determine the Domain Size of the Other Pair
		int otherSize = otherPair.getDomainSize();

		// Compare the Domain Sizes (Larger Domain Size is Bad)
		if(size > otherSize)
			return -1;
		else if(size < otherSize)
			return 1;
		else // Equal Domains
		{
			// Compare the Variables
			return value.compareTo(otherPair.getValue());
		}
	}

	//* Conversion Methods *//
	// Returns a String Representation of the LCV Pair
	public String toString()
	{
		return "[Value: " + value + ", Domain Size: " + size + "]";
	}
}
