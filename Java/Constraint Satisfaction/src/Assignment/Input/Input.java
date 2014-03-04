//* Description *//
// Title: Input
// Author: Tyler Reed
// Reads the Variable Constraints from File

//* Package *//
package Assignment.Input;

//* Libraries *//
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;
import java.util.Vector;
import Assignment.Letter;
import ConstraintSatisfaction.ConstrainedVariable;
import ConstraintSatisfaction.Constraint;
import ConstraintSatisfaction.Configuration.*;
import ConstraintSatisfaction.Ordering.LCVOrderingFactory;
import ConstraintSatisfaction.Ordering.MCVOrdering;
import ConstraintSatisfaction.Ordering.ValueOrderingFactory;
import ConstraintSatisfaction.Ordering.VariableOrdering;

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

	// Constraint Satisfaction Variables
	private List<ConstrainedVariable> variables;
	private List<Letter> letters;
	private List<Constraint> constraints;

	//* Constructor *//
	public Input(String variablePath, String constraintPath) throws IOException, FileFormatException
	{
		variableFile = new File(variablePath);
		constraintFile = new File(constraintPath);

		// Make sure the Files Exist
		if(!variableFile.exists())
			throw new FileNotFoundException("variable");
		else if(!constraintFile.exists())
			throw new FileNotFoundException("constraint");

		// Create Readers for Variables and Constraints
		VariableReader variableReader = new VariableReader(new BufferedReader(new FileReader(variableFile)));
		letters = variableReader.readAll();

		ConstraintReader constraintReader = new ConstraintReader(new BufferedReader(new FileReader(constraintFile)), letters);
		constraints = constraintReader.readAll();

		// Create the Upper Bounded Constrained Variable List
		variables = new Vector<ConstrainedVariable>();
		for(Letter letter : letters)
			variables.add((ConstrainedVariable) letter);

		// Determine the Heuristics
		variableHeuristic = VariableHeuristic.MostConstraining;
		valueHeuristic = ValueHeuristic.LeastConstraining;
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

	//* Constraint Satisfaction Methods *//
	// Returns the List of Variables
	public List<ConstrainedVariable> getVariables()
	{
		return variables;
	}

	// Returns the List of Variables as Letters
	public List<Letter> getLetters()
	{
		return letters;
	}

	// Returns the List of Constraints
	public List<Constraint> getConstraints()
	{
		return constraints;
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

	//* Ordering Methods *//
	// Returns the Variable Ordering Type
	public VariableOrdering getVariableOrdering() throws ArgumentException
	{
		switch(variableHeuristic)
		{
			case Alphabetic:
				return null; // Not Yet Implemented
			case MostConstraining:
				return new MCVOrdering(variables, constraints);
			default: // Unknown Ordering
				throw new ArgumentException("Unknown Variable Heuristic");
		}
	}

	// Returns the Value Ordering Factory Type
	public ValueOrderingFactory getValueOrderingFactory() throws ArgumentException
	{
		switch(valueHeuristic)
		{
			case Increment:
				return null; // Not Yet Implemented
			case LeastConstraining:
				return new LCVOrderingFactory(variables, constraints);
			default: // Unknown Factory
				throw new ArgumentException("Unknown Value Ordering Heuristic");
		}
	}
}
