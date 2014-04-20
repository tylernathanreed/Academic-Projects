//* Description *//
// Title: Query
// Author: Tyler Reed
// Represents a Probability Query

//* Package *//
package Probability;

//* Libraries *//
import java.util.Iterator;
import java.util.Map;
import java.util.SortedMap;
import java.util.SortedSet;
import java.util.TreeMap;
import java.util.TreeSet;

//* Query Class *//
public class Query
{
	//* Class Variables *//
	// Bayes Net Variables
	BayesNet bayesNet;

	// Query Variables
	Probability query;
	SortedSet<Probability> evidence;
	SortedMap<Probability, Boolean> states;

	//* Constructor *//
	// Creates a Query from the specified String and Bayes Net
	public Query(String query, BayesNet bayesNet)
	{
		this.bayesNet = bayesNet;
		this.evidence = new TreeSet<Probability>();
		this.states = new TreeMap<Probability, Boolean>();

		parseQuery(query);
	}

	//* Query Methods *//
	// Returns the Query Probability
	public Probability getQuery()
	{
		return query;
	}

	// Parses the specified Query
	private void parseQuery(String query)
	{
		// Make sure the Query is Closed
		if(!query.endsWith(")"))
			throw new IllegalArgumentException("Query not closed: '" + query + "'");

		// Strip away the 'P(X);
		query = query.trim().substring(2, query.trim().length() - 1);

		// Split between Query and Evidence
		String[] split = query.split("\\|");

		// Make sure a Query was Specified
		if(split[0].length() == 0)
			throw new IllegalArgumentException("Query Probability not specified: 'P(" + query + ")'");

		// Determine the Query Variable
		this.query = bayesNet.get(split[0]);

		if(this.query == null)
			throw new IllegalArgumentException("The specified Query Probability '" + split[0] + "' was not specified in the Bayes Net");

		// Split the Evidence Variables
		if(split.length > 1)
		{
			String[] evidence = split[1].split(",");

			// Parse each Evidence String
			for(String variable : evidence)
			{
				// Make sure an Equality is Specified
				if(!variable.contains("="))
					throw new IllegalArgumentException("Evidence Probability '" + variable + "' must be assigned a State");

				// Determine the Operands of the Evidence
				String[] operands = variable.split("=");

				// Make sure the Assignment is of the Right Form
				if(operands.length != 2)
					throw new IllegalArgumentException("Evidence Probability '" + variable + "' is a malformed Statement");

				// Make sure an Evidence Probability was Specified
				if(operands[0].length() == 0)
					throw new IllegalArgumentException("Evidence Probability not specified: 'P(" + query + ")'");

				// Determine the Name of the Probability
				Probability probability = bayesNet.get(operands[0]);
	
				if(probability == null)
					throw new IllegalArgumentException("The specified Evidence Probability '" + operands[0] + "' was not specified in the Bayes Net");

				// Make sure a Boolean was Specified
				if(operands[1].length() == 0)
					throw new IllegalArgumentException("Evidence Probability '" + operands[0] + "' was not given a State: 'P(" + query + ")'");

				// Determine the State of the Probability
				probability.setState(operands[1].equalsIgnoreCase("t"));
				states.put(probability, new Boolean(operands[1].equalsIgnoreCase("t")));
	
				// Add the Probability to the Probability List
				this.evidence.add(probability);
			}
		}
	}

	//* Evidence Methods *//
	// Returns the Evidence Probabilities
	public SortedSet<Probability> getEvidence()
	{
		return evidence;
	}

	// Returns the States of Evidence Probabilities
	public Map<Probability, Boolean> getStates()
	{
		return states;
	}

	//* Conversion Methods *//
	// Returns a String Representation of the Query
	public String toString()
	{
		// Determine the Initial String
		String result = "P(" + query.getName();

		// Annex the Evidence
		Iterator<Probability> iterator = this.evidence.iterator();

		// Make sure Evidence Exists
		Probability evidence = null;

		if(iterator.hasNext())
		{
			evidence = iterator.next();

			if(evidence != null)
				result += "|" + evidence.getName() + "=" + (evidence.getState() ? "t" : "f");
		}

		while(iterator.hasNext())
		{
			evidence = iterator.next();

			if(evidence == null)
				break;

			result += "," + evidence.getName() + "=" + (evidence.getState() ? "t" : "f");
		}

		// Close and Return the Query
		return result += ")";
	}
}
