//* Description *//
// Title: Input
// Author: Tyler Reed
// Reads and Interprets a Bayes Net File

//* Package *//
package Assignment;

//* Libraries *//
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.SortedMap;
import java.util.TreeMap;
import Probability.BayesNet;
import Probability.Probability;
//import Probability.Variable;

//* Input Class *//
public class Input
{
	//* Class Variables *//
	// File Reading Variables
	private String filepath;
	private BufferedReader reader;
	private int currentLine = 0;

	// Bayes Net Variables
	private BayesNet bayesNet;

	// Map for Unique Variables
	private Map<String, Probability> names;

	//* Constructor *//
	// Creates the Input Class with a specified File Path
	public Input(String filepath) throws IOException
	{
		// Allocate Parameters
		this.filepath = filepath;

		// Define the Bayes Net Variables
		bayesNet = new BayesNet();

		// Create Unique Variable Map
		names = new HashMap<String, Probability>();

		// Create Reader
		reader = new BufferedReader(new FileReader(filepath));

		// Determine the Bayes Net
		bayesNet = readAll();
	}

	//* Bayes Net Methods *//
	// Returns the Bayes Net read from the Input File
	public BayesNet getBayesNet()
	{
		return bayesNet;
	}

	//* Reading Methods *//
	// Reads the Next Line and Increments the Line Number
	private String next() throws IOException
	{
		String line = reader.readLine();
		currentLine++;

		return line;
	}

	// Reads the Next Segment
	public Probability read() throws IOException
	{
		// Read the Next Line
		String line = next();

		// Stop Reading if at End of File
		if(line == null)
			return null;

		// Determine Line Contents
		if(!line.trim().equals(""))
			return readVariableProbability(line);
		else
			return read();
	}

	// Reads the Next Variable Probability
	private Probability readVariableProbability(String line) throws IOException
	{
		// Determine Probability Type
		if(line.startsWith("P("))
			return readPriorProbability(line);
		else
			return readProbabilityTable(line);
	}

	// Reads the Next Prior Probability
	private Probability readPriorProbability(String line)
	{
		// Split at the Operator
		String[] operands = line.split("=");

		// Determine the Variable Name
		int start = operands[0].indexOf("(") + 1;
		int end = operands[0].indexOf(")");

		String name = operands[0].substring(start, end);

		// Determine the Variable Value
		double value;

		try{ value = Double.parseDouble(operands[1].trim()); }
		catch(NumberFormatException ex) { throw new FileFormatException(message("Expected Probability (" + operands[1].trim() + ")")); }

		// Make sure the Variable is Unique
		if(names.containsKey(name))
			throw new FileFormatException(message("Variable " + name + " has already been Defined!"));

		// Create the Probability
		Probability probability = new Probability(name, value);

		// Create and Return the Probability
		return probability;
	}

	// Reads the Next Probability Table
	private Probability readProbabilityTable(String line) throws IOException
	{
		// Split between Query and Evidence
		String[] header = line.split("\\|");

		if(header.length != 2)
			throw new FileFormatException(message("Expected Variable Header (" + line + ") [" + header.length + "]"));

		String[] evdnce = header[0].split(" ");
		String qry = header[1].trim();

		// Ensure that Duplicate Evidence is not Given
		List<Probability> evidence = new ArrayList<Probability>(evdnce.length);

		for(String name : evdnce)
			evidence.add(names.containsKey(name) ? names.get(name) : new Probability(name.trim()));

		((ArrayList<Probability>) evidence).trimToSize();

		if(evidence.size() != evdnce.length)
			throw new FileFormatException(message("Duplicate Evidence Variable (" + line + ") [" + evidence.size() + " != " + evdnce.length + "]"));

		// Determine Query Probability
		Probability query = names.containsKey(qry) ? names.get(qry) : new Probability(qry.trim(), evidence);

		// Read the Separator Line
		line = next();

		if(line == null)
			throw new FileFormatException(message("Expected Header/Body Separater (" + line + ")"));

		// Read the Table Body
		for(line = next(); line != null; line = next())
		{
			if(line.trim().equals(""))
				break;

			// Split between Conditions and Values
			String[] entry = line.split("\\|");

			if(entry.length != 2)
				throw new FileFormatException(message("Expected Table Entry (" + line + ")"));

			String[] conditions = entry[0].split(" ");
			double value;

			try{ value = Double.parseDouble(entry[1].trim()); }
			catch(NumberFormatException ex){ throw new FileFormatException(message("Expected Entry Value (" + entry[1].trim() + ")")); }

			if(value < 0 || value > 1)
				throw new FileFormatException(message("Expected Probability Value (" + value + ")"));

			// Map the Conditions and Variables to form an Entry Key
			SortedMap<Probability, Boolean> key = new TreeMap<Probability, Boolean>();

			for(int i = 0; i < evidence.size(); i++)
			{
				// Determine the Current Evidence Variable
				Probability probability = evidence.get(i);

				// Determine the Current Evidence Condition
				boolean condition = conditions[i].trim().toLowerCase().charAt(0) == 't' ? true : false;

				// Add the Evidence Configuration to the Entry Key
				key.put(probability, new Boolean(condition));
			}

			// Map the Entry Key and the Entry Value to the Probability
			query.putEntry(key, value);
		}

		// Determine the Optimal Entry Count
		int count = (int) Math.pow(2, evidence.size());

		// Validate the Entry Count
		if(query.getEntryCount() < count)
			throw new FileFormatException(message("Not Enough Entries specified [" + query.getEntryCount() + " != " + count + "]"));

		return query;
	}

	// Reads the Entire Input File
	public BayesNet readAll() throws IOException
	{
		BayesNet net = new BayesNet();

		Probability probability = read();

		while(probability != null)
		{
			net.add(probability);
			probability = read();
		}

		return net;
	}

	// Constructs the Message for a File Format Exception
	private String message(String message)
	{
		return filepath + ": Line " + currentLine + " - " + message;
	}
	
}
