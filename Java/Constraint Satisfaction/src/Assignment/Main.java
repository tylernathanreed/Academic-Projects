//* Description *//
// Title: Main
// Author: Tyler Reed
// Runs the Program

//* Package *//
package Assignment;

//* Libraries *//
import Assignment.Input.ArgumentException;
import Assignment.Input.FileFormatException;
import Assignment.Input.Input;
import ConstraintSatisfaction.Constraint;
import ConstraintSatisfaction.Ordering.ValueOrderingFactory;
import ConstraintSatisfaction.Ordering.VariableOrdering;
import ConstraintSatisfaction.Solver.AbstractSolver;
import ConstraintSatisfaction.Solver.FCSolver;
import ConstraintSatisfaction.Solver.Solver;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

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
		Input input = getInput(variablePath, constraintPath);

		// Determine the Variables and Constraints
		List<Letter> variables = new ArrayList<Letter>();
		List<Constraint> constraints = new ArrayList<Constraint>();

		variables.addAll(input.getLetters());
		constraints.addAll(input.getConstraints());

		// Determine the Variable and Value Ordering Factory
		VariableOrdering variableOrdering = getVariableOrdering(input);
		ValueOrderingFactory valueOrderingFactory = getValueOrderingFactory(input);

		// Determine the Solver used to Satisfy the Constraints
		AbstractSolver solver = getSolver(procedure, variableOrdering, valueOrderingFactory, constraints);

		solver.solve();

		// Print the Solution Path
		System.out.println(solver.getSolutionPath());
	}

	//* Program Methods *//
	// Returns the Input Class for the Program and Catches Errors
	public static Input getInput(String variablePath, String constraintPath)
	{
		try
		{
			return new Input(variablePath, constraintPath);
		}
		catch(FileNotFoundException ex)
		{
			// Determine the Missing File
			if(ex.getMessage().equals("variable"))
				System.err.println("Invalid Variable File '" + variablePath + "'");
			else // constraint
				System.err.println("Invalid Constraint File '" + constraintPath + "'");

			System.exit(0);
			return null;
		}
		catch(IOException ex)
		{
			System.err.println(ex.getMessage());
			System.exit(0);
			return null;
		}
		catch(FileFormatException ex)
		{
			System.err.println(ex.getMessage());
			System.exit(0);
			return null;
		}
	}

	// Returns the Variable Ordering and Catches Errors
	public static VariableOrdering getVariableOrdering(Input input)
	{
		try
		{
			return input.getVariableOrdering();
		}
		catch(ArgumentException ex)
		{
			System.err.println(ex.getMessage());
			System.exit(0);
			return null;
		}
	}

	// Returns the Value Ordering Factory and Catches Errors
	public static ValueOrderingFactory getValueOrderingFactory(Input input)
	{
		try
		{
			return input.getValueOrderingFactory();
		}
		catch(ArgumentException ex)
		{
			System.err.println(ex.getMessage());
			System.exit(0);
			return null;
		}
	}

	// Returns the Solver and Catches Errors
	public static AbstractSolver getSolver(String procedure, VariableOrdering variableOrdering, ValueOrderingFactory valueOrderingFactory, List<Constraint> constraints)
	{
		if(procedure != null && procedure.equalsIgnoreCase("fc"))
			return new FCSolver(variableOrdering, valueOrderingFactory, constraints);
		else if(procedure != null && procedure.equalsIgnoreCase("cp"))
			return null; // Not Yet Implemented
		else
			return new Solver(variableOrdering, valueOrderingFactory, constraints);
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
