//* Description *//
// Title: Domain Exception
// Author: Tyler Reed
// Thrown when a Variable is Assigned a Value
// outside of its Domain

//* Package *//
package ConstraintSatisfaction;

//* Class *//
@ SuppressWarnings("serial")
public class DomainException extends Exception
{
	//* Constructors *//
	// Default Constructor
	public DomainException()
	{
		super();
	}

	// Message Constructor
	public DomainException(String message)
	{
		super(message);
	}
}
