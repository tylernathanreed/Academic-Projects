//* Description *//
// Title: Input
// Author: Tyler Reed
// Reads the Variable Constraints from File

//* Package *//
package Assignment.Input;

//* Libraries *//
import java.io.File;
import java.io.FileNotFoundException;

import ConstraintSatisfaction.Configuration.*;

//* Class *//
public class Input
{
	//* Class Variables *//
	// File Variables
	private File variableFile;
	private File constraintFile;

	// Configuration Variables
	private ConsistencyProcedure procedure;
	private VariableHeuristic variableHeuristic;
	private ValueHeuristic valueHeuristic;

	//* Constructor *//
	public Input(String variablePath, String constraintPath) throws FileNotFoundException
	{
		variableFile = new File(variablePath);
		constraintFile = new File(constraintPath);

		// Make sure the Files Exist
		if(!variableFile.exists())
			throw new FileNotFoundException("variable");
		else if(!constraintFile.exists())
			throw new FileNotFoundException("constraint");

		variableHeuristic = VariableHeuristic.MostConstraining;
		valueHeuristic = ValueHeuristic.LeastingConstraining;
	}

	//* File Methods *//
	// Returns the Variable File
	public File getVariableFile()
	{
		return variableFile;
	}

	// Returns the Constraint File
	public File getConstraintFile()
	{
		return constraintFile;
	}

	//* Configuration Methods *//
	// Returns the Consistency Enforcing Procedure
	public ConsistencyProcedure getConsistencyProcedure()
	{
		return procedure;
	}

	// Returns the Variable Ordering Heuristic
	public VariableHeuristic getVariableHeuristic()
	{
		return variableHeuristic;
	}

	// Returns the Value Ordering Heuristic
	public ValueHeuristic getValueHeuristic()
	{
		return valueHeuristic;
	}
}
