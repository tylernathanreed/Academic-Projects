//* Description *//
// Title: Argument Exception
// Author: Tyler Reed
// Thrown when an Invalid Argument is Provided

//* Package *//
package Assignment.Input;

//* Class *//
@ SuppressWarnings("serial")
public class ArgumentException extends Exception
{
	//* Constructor *//
	public ArgumentException(String message)
	{
		super(message);
	}
}
