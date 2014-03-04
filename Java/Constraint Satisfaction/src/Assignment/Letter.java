//* Description *//
// Title: Letter
// Author: Tyler Reed
// Defines the Letter Class for the CSP Implementation

//* Package *//
package Assignment;

//* Libraries *//
import ConstraintSatisfaction.ConstrainedVariable;
import ConstraintSatisfaction.DomainValue;
import java.util.List;

//* Class *//
public class Letter extends ConstrainedVariable
{
	//* Class Variables *//
	private char ch;

	//* Constructors *//
	public Letter(String variable, List<DomainValue> domain)
	{
		super(variable, domain);

		ch = variable.charAt(0);
	}

	//* Character Methods *//
	// Returns the Character of the Letter
	public char getCharacter()
	{
		return ch;
	}

	//* Interface Methods *//
	// Returns an Integer (-1, 0, 1) representing a Comparison
	public int compareTo(ConstrainedVariable variable)
	{
		Letter letter = (Letter) variable;

		if(ch > letter.getCharacter())
			return 1;
		else if(ch < letter.getCharacter())
			return -1;
		else
			return 0;
	}

	//* Conversion Methods *//
	// Returns the Letter represented as a String
	public String toString()
	{
			return "" + ch;
	}
}
