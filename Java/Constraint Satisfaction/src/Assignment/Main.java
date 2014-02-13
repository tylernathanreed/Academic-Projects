//* Description *//
// Title: Main
// Author: Tyler Reed
// Runs the Program

//* Package *//
package Assignment;

import java.io.FileNotFoundException;

//* Libraries *//
import Assignment.Input.Input;

//* Class *//
public class Main
{
	//* Main Method *//
	// Runs the Program
	public static void main(String[] args)
	{
		// Interpret Command Line
		String variablePath = getVariableFilePath(args);
		String constraintPath = getConstraintFilePath(args);
		String procedure = getConsistencyProcedure(args);

		// Check for Missing Required Flags
		if(variablePath == null)
		{
			System.err.println("Missing Variable File Path! Use '-var <filepath>' to specify");
			System.exit(0);
		}
		else if(constraintPath == null)
		{
			System.err.println("Missing Constraint File Path! Use '-con <filepath>' to specify");
			System.exit(0);
		}

		// Create the Input File
		Input input;

		try
		{
			input = new Input(variablePath, constraintPath);
		}
		catch(FileNotFoundException ex)
		{
			// Determine the Missing File
			if(ex.getMessage().equals("variable"))
				System.err.println("Invalid Variable File '" + variablePath + "'");
			else // constraint
				System.err.println("Invalid Constraint File '" + constraintPath + "'");

			System.exit(0);
			return;
		}

		
	}

	//* Command Line Methods *//
	// Returns the specified Variable File
	public static String getVariableFilePath(String[] args)
	{
		// Loop for '-var' Flag
		for(int i = 0; i < args.length - 1; i++)
			if(args[i].equals("-var"))
				return args[i + 1]; 

		return null;
	}

	// Returns the specified Constraint File
	public static String getConstraintFilePath(String[] args)
	{
		// Loop for '-con' Flag
		for(int i = 0; i < args.length - 1; i++)
			if(args[i].equals("-con"))
				return args[i + 1];

		return null;
	}

	// Returns the specified Consistency Enforcing Procedure
	public static String getConsistencyProcedure(String[] args)
	{
		// Loop for '-cp' Flag
		for(int i = 0; i < args.length - 1; i++)
			if(args[i].equals("-cp"))
				return args[i + 1];

		return null;
	}
}
