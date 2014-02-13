//* Description *//
// Title: Letter
// Author: Tyler Reed
// Defines the Letter Class for the CSP Implementation

//* Package *//
package Assignment;

import java.util.List;


//* Libraries *//
import ConstraintSatisfaction.ConstrainedVariable;
import ConstraintSatisfaction.DomainValue;

//* Class *//
public class Letter extends ConstrainedVariable
{
	//* Class Variables *//
	private char ch;

	public Letter(Object variable, List<DomainValue> domain)
	{
		super(variable, domain);
		ch = (char) variable;
	}

	public Letter(String variable, List<Integer> domain)
	{
		super((Object) variable, (List<DomainValue>) domain);
	}

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
