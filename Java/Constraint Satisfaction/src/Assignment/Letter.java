//* Description *//
// Title: Letter
// Author: Tyler Reed
// Defines the Letter Class for the CSP Implementation

//* Package *//
package Assignment;

//* Libraries *//
import ConstraintSatisfaction.ConstrainedVariable;

//* Class *//
public class Letter extends ConstrainedVariable
{
	private char ch;

	//* Character Methods *//
	// Returns the Character of the Letter
	public char getCharacter()
	{
		return ch;
	}

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

	protected void applyConstraints()
	{
		// TODO Auto-generated method stub
		
	}
}
