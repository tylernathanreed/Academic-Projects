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
import java.util.Hashtable;
import java.util.LinkedList;
import java.util.List;
import Knowledge.Clause;
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
	private List<Clause> clauses;
	private List<Variable> variables;

	// Hash for Unique Variables
	private Hashtable<String, Variable> names;

	//* Constructor *//
	// File Path Constructor
	public Input(String filepath)
	{
		// Create the List of Clauses and Variables
		clauses = new LinkedList<Clause>();
		variables = new LinkedList<Variable>();

		// Create the Unique Variable Hash
		names = new Hashtable<String, Variable>();

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
	public List<Clause> getClauses()
	{
		return clauses;
	}

	// Returns the Set of Variables
	public List<Variable> getVariables()
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
		List<Literal> literals = new LinkedList<Literal>();

		for(int i = 0; i < components.length; i++)
		{
			// Determine the Current Component
			String component = components[i];

			// Determine the Negated Status
			boolean negated = component.charAt(0) == '~';

			// Determine the Name of the Variable
			String name = component.replace("~", "");

			// Determine the Variable for the Literal
			Variable variable;

			// Check if the Name is Unique
			if(names.containsKey(name))
				variable = names.get(name);
			else
			{
				variable = new Variable(name);
				names.put(name, variable);
			}

			// Add the Variable to the List of Variables
			variables.add(variable);

			// Create the Literal
			Literal literal = new Literal(variable, negated);

			// Add the Literal to the List of Literals
			if(!literals.contains(literal))
				literals.add(literal);
		}

		// Create the Clause
		Clause clause = new Clause(literals);

		// Add the Clause to the Set of Clauses
		if(clause != null && !clauses.contains(clause))
			clauses.add(clause);
		else
			System.out.println("[Input] Ignoring Clause: " + clause);

		//System.out.println("[Input] Read Clause: " + clause);

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
