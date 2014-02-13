//* Description *//
// Title: File Format Exception
// Author: Tyler Reed
// Thrown when File Contents have Syntax Errors

//* Package *//
package Assignment.Input;

//* Class *//
@SuppressWarnings("serial")
public class FileFormatException extends Exception
{
	//* Constructors *//
	// Default Constructor
	public FileFormatException()
	{
		super();
	}

	// Message Constructor
	public FileFormatException(String message)
	{
		super(message);
	}

	// Throwable Constructor
	public FileFormatException(Throwable cause)
	{
		super(cause);
	}
}
