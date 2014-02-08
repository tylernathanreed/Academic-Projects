//* Description *//
// Title: Main
// Author: Tyler Reed
// Runs the Program

//* Package *//
package Assignment;

//* Libraries *//
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

//* Main Class *//
public class Main
{
	//* Main Method *//
	// Runs the Program
	public static void main(String[] args)
	{
		// Interpret Command Line Arguments
		boolean cost = hasCostFlag(args);
		SearchType searchType = Configuration.castToSearchType(getSearchType(args));
		String filePath = getFilePath(args);
		boolean print = hasPrintFlag(args);

		// Determine the Initial State from the File
		String initialState = getInitialState(filePath);

		// Create the Search Configuration
		Configuration configuration = null;

		try { configuration = new Configuration(initialState, searchType, cost, print); }
		catch(InvalidSearchTypeException ex)
		{
			System.err.println("Invalid Search Type: '" + getSearchType(args) + "'\n -> Use <-t type> Argument" +
					"\n    -> Valid Search Types are: BFS | DFS | GS | UCS | ASTAR");
			System.exit(0);
		}

		// Create the Search Class
		new Search(configuration);
	}

	//* File Methods *//
	public static String getInitialState(String filePath)
	{
		try
		{
			BufferedReader buffer = new BufferedReader(new FileReader(filePath));
			String initialState = buffer.readLine().trim().toUpperCase();
			buffer.close();

			return initialState;
		}
		catch(FileNotFoundException ex)
		{
			System.err.println("Invalid File Path: '" + filePath + "'\n -> Use: <-f filepath> Argument");
			System.exit(0);
		}
		catch(IOException ex)
		{
			System.err.println("Invalid Content: '" + filePath + "'");
			System.exit(0);
		}

		// Make the Compilier Happy
		return null;
	}

	//* Command Line Methods *//
	// Returns whether or not the '-cost' Flag was Found
	public static boolean hasCostFlag(String[] args)
	{
		for(int i = 0; i < args.length; i++)
			if(args[i].equals("-cost"))
				return true;

		return false;
	}

	// Returns the Search Type after the '-t' Flag
	public static String getSearchType(String[] args)
	{
		for(int i = 0; i < args.length - 1; i++)
			if(args[i].equals("-t"))
				return args[i + 1];

		return "";
	}

	// Returns the Filepath after the '-f' Flag
	public static String getFilePath(String[] args)
	{
		for(int i = 0; i < args.length - 1; i++)
			if(args[i].equals("-f"))
				return args[i + 1];

		return "";
	}

	// Returns whether or not the '-print' Flag was Found
	public static boolean hasPrintFlag(String[] args)
	{
		for(int i = 0; i < args.length; i++)
			if(args[i].equals("-print"))
				return true;

		return false;
	}
}
