//* Description *//
// Title: Invalid Search Type Exception
// Author: Tyler Reed
// Thrown if an Invalid Search Type is given to the Search Constructor

//* Package *//
package Assignment;

@ SuppressWarnings("serial")
public class InvalidSearchTypeException extends RuntimeException
{
	//* Constructors *//
	// Default Constructor
	public InvalidSearchTypeException()
	{
		super();
	}

	// Message Constructor
	public InvalidSearchTypeException(String message)
	{
		super(message);
	}

	// Message and Cause Constrcutor
	public InvalidSearchTypeException(String message, Throwable cause)
	{
		super(message, cause);
	}

	// Cause Constructor
	public InvalidSearchTypeException(Throwable cause)
	{
		super(cause);
	}
}
