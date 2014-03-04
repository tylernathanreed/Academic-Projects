//* Description *//
// Title: Constraint Reader
// Author: Tyler Reed
// Reads Variable Constraints from File

//* Package *//
package Assignment.Input;

//* Libraries *//
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import Assignment.Letter;
import Assignment.Constraints.*;
import ConstraintSatisfaction.Constraint;

//* Class *//
public class ConstraintReader
{
	//* Class Variables *//
	private BufferedReader reader;
	private int currentLine = -1;
	private List<Letter> variables;

	//* Constuctor *//
	// Creates the Constraint Reader Class
	public ConstraintReader(BufferedReader reader, List<Letter> variables)
	{
		this.reader = reader;
		this.variables = variables;
	}

	//* Read Methods *//
	// Reads and Returns the Next Constraint
	public Constraint read() throws IOException, FileFormatException
	{
		String line = reader.readLine();
		currentLine++;

		// Ignore Blank Lines
		if(line == null || line.equals(""))
			return null;

		// Determine the Constraint Components
		String[] components = line.split("\\s");

		// Require "A ? B" Format
		if(components.length < 3)
			throw new FileFormatException("[Constraints] Invalid Syntax on Line " + currentLine + ": Missing Component");
		else if(components.length > 3)
			throw new FileFormatException("[Constraints] Invalid Syntax on Line " + currentLine + ": Extra Component");

		// Require Single-Character Components
		for(int i = 0; i < 3; i++)
			if(components[i].length() > 1)
				throw new FileFormatException("[Constraints] Invalid Syntax on Line " + currentLine + ": Component " + i + " has Multiple Characters");

		// Require Letter-Character Variable Names
		if(!Character.isLetter(components[0].charAt(0)))
			throw new FileFormatException("[Constraints] Invalid Syntax on Line " + currentLine + ": Left Variable is not a Character");
		else if(!Character.isLetter(components[2].charAt(0)))
			throw new FileFormatException("[Constraints] Invalid Syntax on Line " + currentLine + ": Right Variable is not a Character");

		// Initialize Variables
		Letter left = null;
		Letter right = null;

		// Make sure that the Provided Variables Exist
		for(Letter letter : variables)
		{
			if(letter.getCharacter() == components[0].charAt(0))
				left = letter;
			else if(letter.getCharacter() == components[2].charAt(0))
				right = letter;
		}

		if(left == null)
			throw new FileFormatException("[Constraints] Invalid Syntax on Line " + currentLine + ": Non-Existant Variable '" + components[0].charAt(0) + "'");
		else if(right == null)
			throw new FileFormatException("[Constraints] Invalid Syntax on Line " + currentLine + ": Non-Existant Variable '" + components[2].charAt(0) + "'");

		// Validate Operator
		if(components[1].equals("<"))
			return new LessThanConstraint(left, right);
		else if(components[1].equals(">"))
			return new GreaterThanConstraint(left, right);
		else if(components[1].equals("="))
			return new EqualsConstraint(left, right);
		else if(components[1].equals("!"))
			return new NotEqualsConstraint(left,right);
		else
			throw new FileFormatException("[Constraints] Invalid Syntax on Line " + currentLine + ": Unrecognized Constraint Operator");
	}

	// Reads and Returns all Constraints
	public List<Constraint> readAll() throws IOException, FileFormatException
	{
		// Create the List of Constraints
		List<Constraint> constraints = new ArrayList<Constraint>();

		// Read the First Constraint
		Constraint constraint = read();

		// Read the Remaining Constraints
		while(constraint != null)
		{
			if(constraints.contains(constraint))
				throw new FileFormatException("[Constraints] Invalid Syntax on Line " + currentLine + ": Duplicate Constraint");

			constraints.add(constraint);
			constraint = read();
		}

		return constraints;
	}
}
