//* Description *//
// Title: Main
// Author: Tyler Reed
// Interprets the Command Line and Runs the Program

//* Package *//
package Assignment;

//* Libraries *//
import java.util.SortedSet;
import Knowledge.Clause;
import Knowledge.ContradictionException;
import Knowledge.KnowledgeBase;

//* Class *//
public class Main
{
	//* Main Method *//
	// Interprets the Command Line and Runs the Program
	public static void main(String[] args)
	{
		// Interpret the Command Line
		String inputPath = getInputFilePath(args);
		//String outputPath = getOutputFilePath(args);

		// Check for Missing Required Flags
		if(inputPath == null)
		{
			System.err.println("Missing Input File Path! Use '-i <filepath>' to specify");
			System.exit(0);
		}
		//else if(outputPath == null)
		//{
		//	System.err.println("Missing Output File Path! Use '-o <filepath>' to specify");
		//	System.exit(0);
		//}

		// Create the Input File
		Input input = new Input(inputPath);

		// Determine the Set of Clauses and Variables
		SortedSet<Clause> clauses = input.getClauses();

		// Attempt to Create the Knowledge Base
		try
		{
			KnowledgeBase knowledgeBase = new KnowledgeBase(clauses);
			System.out.println("[Main] Knowledge Base Successfully Created!");
			//System.out.println(knowledgeBase);
		}
		catch(ContradictionException ex)
		{
			System.err.println(ex);
		}
	}

	// Returns the Input File Path
	public static String getInputFilePath(String[] args)
	{
		// Loop for '-i' Flag
		for(int i = 0; i < args.length - 1; i++)
			if(args[i].equals("-i"))
				return args[i + 1];

		return null;
	}

	// Returns the Output File Path
	public static String getOutputFilePath(String[] args)
	{
		// Loop for '-o' Flag
		for(int i = 0; i < args.length - 1; i++)
			if(args[i].equals("-o"))
				return args[i + 1];

		return null;
	}
}
