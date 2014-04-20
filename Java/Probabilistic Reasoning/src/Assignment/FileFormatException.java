//* Description *//
// Title: File Format Exception
// Author: Tyler Reed
// Thrown when a File is Formatted Incorrectly

//* Package *//
package Assignment;

//* File Format Exception Class *//
@ SuppressWarnings("serial")
public class FileFormatException extends RuntimeException
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
}
