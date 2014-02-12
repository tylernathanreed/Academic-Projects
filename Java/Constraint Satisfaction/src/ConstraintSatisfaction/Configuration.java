//* Description *//
// Title: Configuration
// Author: Tyler Reed
// Contains CSP Configuration Information

//* Package *//
package ConstraintSatisfaction;

//* Class *//
public class Configuration
{
	//* Enumerations *//
	// Defines the Consistency Enforcing Procedure Types
	public static enum ConsistencyProcedure
	{
		None, ForwardChecking, ConstraintProgation;
	}

	// Defines the Variable Heuristic Types
	public static enum VariableHeuristic
	{
		Alphabetic, MostConstraining;
	}

	// Defines the Value Heuristic Types
	public static enum ValueHeuristic
	{
		Increment, LeastingConstraining;
	}
}
