//* Description *//
// Title: Participant Exception
// Author: Tyler Reed
// Thrown when a Constraint Method requires a Variable
// Parameter and a Non-Participant is Provided

//* Package *//
package ConstraintSatisfaction;

//* Class *//
@ SuppressWarnings("serial")
public class ParticipantException extends Exception
{
	//* Constuctor *//
	// Default Constructor
	public ParticipantException()
	{
		super();
	}

	// Message Constructor
	public ParticipantException(String message)
	{
		super(message);
	}
}
