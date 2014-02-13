//* Description *//
// Title: Variable Reader
// Author: Tyler Reed
// Reads Variables and their Domains from File

//* Package *//
package Assignment.Input;

//* Libraries *//
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import Assignment.Letter;
import ConstraintSatisfaction.ConstrainedVariable;

//* Class *//
public class VariableReader
{
	//* Class Variables *//
	private BufferedReader reader;
	private int currentLine = -1;

	//* Constructor *//
	// Creates the Variable Reader Class
	public VariableReader(BufferedReader reader)
	{
		this.reader = reader;
	}

	//* Read Methods *//
	// Reads and Returns the next Variable
	public ConstrainedVariable read() throws IOException, FileFormatException
	{
		String line = reader.readLine();
		currentLine++;

		// Ignore Blank Lines
		if(line == null || line.equals(""))
			return read();

		// Require "Variable: Domain" Syntax
		if(!line.contains(":"))
			throw new FileFormatException("Invalid Syntax on Line " + currentLine + ": Missing ':' Delimiter");

		// Determine the Variable Components
		String[] components = line.split(":");

		// Require Only "Variable" and "Domain" Components
		if(components.length > 2)
			throw new FileFormatException("Invalid Syntax on Line " + currentLine + ": Multiple ':' Delimiters");

		// Determine Domain Components
		String[] values = components[1].split("\\s");

		// Convert Domain Components to Integers
		List<Integer> domain = new ArrayList<Integer>(values.length);

		for(int i = 0; i < values.length; i++)
		{
			if(values[i].length() > 0)
				try
				{
					domain.add(Integer.valueOf(Integer.parseInt(values[i])));
				}
				catch(NumberFormatException ex)
				{
					throw new FileFormatException("Invalid Syntax on Line " + currentLine + ": Invalid Number Format");
				}
		}

		ConstrainedVariable variable = new Letter(components[0], domain);
		return variable;
	}

	// Reads and Returns all Variables
	public List<ConstrainedVariable> readAll() throws IOException, FileFormatException
	{
		List<ConstrainedVariable> variables = new ArrayList<ConstrainedVariable>();

		ConstrainedVariable variable = read();

		while(variable != null)
		{
			if(variables.contains(variable))
				throw new FileFormatException("Invalid Syntax on Line " + currentLine + ": Duplicate Variable Name");

			variables.add(variable);
			variable = read();
		}

		return variables;
	}
}
