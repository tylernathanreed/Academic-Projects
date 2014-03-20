//* Description *//
// Title: Input
// Author: Tyler Reed
// Interprets Files for the Program

//* Package *//
package Assignment;

//* Libraries *//
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.SortedSet;
import java.util.TreeSet;
import Knowledge.Clause;
import Knowledge.ContradictionException;
import Knowledge.Literal;
import Knowledge.Variable;

//* Class *//
public class Input
{
	//* Class Variables *//
	// File Reading Variables
	private BufferedReader reader = null;
	private int currentLine = 0;

	// Knowledge Base Variables
	private SortedSet<Clause> clauses;
	private SortedSet<Variable> variables;

	//* Constructor *//
	// File Path Constructor
	public Input(String filepath)
	{
		// Create the List of Clauses and Variables
		clauses = new TreeSet<Clause>();
		variables = new TreeSet<Variable>();

		try
		{
			reader = new BufferedReader(new FileReader(new File(filepath)));
			readAll();
		}
		catch(FileNotFoundException ex)
		{
			System.err.println("Invalid Input File '" + filepath + "'");
			System.exit(0);
		}
		catch(IOException ex)
		{
			System.err.println("Unable to Read Input File '" + filepath + "'");
			System.exit(0);
		}
	}

	//* Knowledge Base Methods *//
	// Returns the Set of Clauses
	public SortedSet<Clause> getClauses()
	{
		return clauses;
	}

	// Returns the Set of Variables
	public SortedSet<Variable> getVariables()
	{
		return variables;
	}

	//* Read Methods *//
	// Reads and Returns the next Clause
	private Clause read() throws IOException
	{
		String line = reader.readLine();
		currentLine++;

		// Ignore Blank Lines
		if(line == null || line.equals(""))
			return null;

		// Determine Clause Components
		String[] components = line.split(" ");

		// Determine each Literal
		SortedSet<Literal> literals = new TreeSet<Literal>();

		for(int i = 0; i < components.length; i++)
		{
			// Determine the Current Component
			String component = components[i];

			// Determine the Negated Status
			boolean negated = component.charAt(0) == '~';

			// Determine the Name of the Variable
			String name = component.replace("~", "");

			// Create the Variable for the Literal
			Variable variable = new Variable(name);

			// Add the Variable to the Set of Variables
			if(!variables.contains(variable))
				variables.add(variable);

			// Create the Literal
			Literal literal = new Literal(variable, negated);

			// Add the Literal to the Set of Literals
			if(!literals.contains(literal))
				literals.add(literal);
			
		}

		// Create the Clause
		Clause clause = null;

		try
		{
			clause = new Clause(literals);
			System.out.println("[Input] Read Clause: " + clause);
		}
		catch(ContradictionException ex)
		{
			System.err.println("Invalid Clause on Line " + currentLine + ": Contains Contradiction");
			System.exit(0);
		}

		// Add the Clause to the Set of Clauses
		if(clause != null && !clauses.contains(clause))
			clauses.add(clause);

		return clause;
	}

	// Reads and Returns all Clauses
	private void readAll() throws IOException
	{
		// Read the First Clause
		Clause clause = read();

		// Read the Remaining Clauses
		while(clause != null)
			clause = read();
	}
}
