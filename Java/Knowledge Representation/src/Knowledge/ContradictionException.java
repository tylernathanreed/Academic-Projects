//* Description *//
// Title: Contradiction Exception
// Author: Tyler Reed
// Thrown when a Clause or Knowledge Base is constructed with a Contradiction

//* Package *//
package Knowledge;

//* Class *//
@ SuppressWarnings("serial")
public class ContradictionException extends Exception
{
	//* Constructors *//
	// Default Constructor
	public ContradictionException()
	{
		super();
	}

	// Message Constructor
	public ContradictionException(String message)
	{
		super(message);
	}

	// Object Constructor
	public ContradictionException(Object object)
	{
		super(object.toString());
	}
}
