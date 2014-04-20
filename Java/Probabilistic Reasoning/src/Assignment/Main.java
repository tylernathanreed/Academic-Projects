//* Description *//
// Title: Main
// Author: Tyler Reed
// Runs the Program

//* Package *//
package Assignment;

//* Libraries *//
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Map;
import Probability.BayesNet;
import Probability.Query;

//* Main Class *//
public class Main
{
	//* Main Method *//
	// Runs the Program and Interprets the Command Line
	public static void main(String[] args)
	{
		// Determine Arguments
		String bayesNetPath = getBayesNetPath(args);
		String operation = getOperation(args);
		String queryArg = getQuery(args);

		// Interpret the Bayes Net File
		Input input = null;

		try { input = new Input(bayesNetPath); }
		catch(FileNotFoundException ex) { System.out.println("Unable to find File: " + bayesNetPath); return;}
		catch(IOException e) { System.out.println("Unable to read File: " + bayesNetPath); return;}

		// Determine the Bayes Net
		BayesNet bayesNet = input.getBayesNet();

		// Validate the Operation
		if(operation == null)
		{
			System.out.println("Operation was not specified! Please use 'enum' or 'elim' (NYI)");
			return;
		}

		// Create the Query
		if(queryArg == null)
		{
			System.out.println("Query was not specified! Please use the form P(<Query>|<Evidence=t|f>)");
			return;
		}

		// Query the Bayes Net
		Query query = null;

		try { query = new Query(queryArg, bayesNet); }
		catch(Exception ex) { System.out.println(ex.getMessage()); return; }

		Map<Boolean, Double> result = bayesNet.parseQuery(query);

		// Print the Result
		System.out.println("\nRESULT:");

		// Determine Result Strings
		String positive, negative;

		positive = "P(" + query.getQuery() + "=t";
		negative = "P(" + query.getQuery() + "=f";

		int index = query.toString().indexOf("|");

		String evidence = "";

		if(index >= 0)
			evidence = query.toString().substring(query.toString().indexOf("|"));

		positive += evidence + ")";
		negative += evidence + ")";

		// Add Spacing for Neatness
		positive = ((positive.replaceAll("=", " = ")).replaceAll("\\|", " | ")).replaceAll(",", ", ");
		negative = ((negative.replaceAll("=", " = ")).replaceAll("\\|", " | ")).replaceAll(",", ", ");

		// Print the Result Strings
		System.out.println(positive + " = " + result.get(true));
		System.out.println(negative + " = " + result.get(false));
	}

	//* Command Line Methods *//
	// Returns the Bayes Net from the Command Line
	public static String getBayesNetPath(String[] args)
	{
		// Search for '-b' Tag
		for(int i = 0; i < args.length - 1; i++)
			if(args[i].equals("-b"))
				return args[i + 1];

		// Search for '*.bn' File
		for(int i = 0; i < args.length; i++)
			if(args[i].endsWith(".bn"))
				return args[i];

		// Argument not explicitly Stated
		return "";
	}

	// Returns the Operation Type
	public static String getOperation(String[] args)
	{
		// Search for 'enum' Argument
		for(int i = 0; i < args.length; i++)
			if(args[i].equalsIgnoreCase("enum"))
				return args[i];

		// Search for 'elim' Argument
		for(int i = 0; i < args.length; i++)
			if(args[i].equalsIgnoreCase("elim"))
				return null; // Not Yet Implemented

		// Argument not Present
		return null;
	}

	// Returns the Query
	public static String getQuery(String[] args)
	{
		// Search for '-q' Argument
		for(int i = 0; i < args.length - 1; i++)
			if(args[i].equals("-q"))
				return args[i + 1];

		// Search for 'P(' Prefix
		for(int i = 0; i < args.length; i++)
			if(args[i].startsWith("P("))
				return args[i];

		// Argument not explicitly Stated
		return null;
	}
}
