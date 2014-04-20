//* Description *//
// Title: Bayes Net
// Author: Tyler Reed
// Represents a Directed Graph of Probabilities

//* Package *//
package Probability;

//* Libraries *//
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.SortedMap;
import java.util.SortedSet;
import java.util.TreeMap;
import java.util.TreeSet;

//* Bayes Net Class *//
public class BayesNet
{
	//* Class Variables *//
	// Probability Variables
	SortedSet<Probability> probabilities;

	//* Constructor *//
	// Default Constructor
	public BayesNet()
	{
		probabilities = new TreeSet<Probability>();
	}

	// Probability Constructor
	public BayesNet(SortedSet<Probability> probabilities)
	{
		this.probabilities = probabilities;
	}

	//* Probability Methods *//
	// Adds the specified Probability to the Bayes net
	public boolean add(Probability probability)
	{
		return probabilities.add(probability);
	}

	// Returns the specified Probability by Name
	public Probability get(String name)
	{
		for(Probability probability : probabilities)
			if(probability.getName().equals(name))
				return probability;

		return null;
	}

	// Returns whether or not the specified Probability is within the Bayes Net
	public boolean contains(Probability probability)
	{
		return probabilities.contains(probability);
	}

	//* Query Methods *//
	// Parses the specified Query
	public Map<Boolean, Double> parseQuery(Query queryArg)
	{
		// Initialize the Query Map
		Map<Boolean, Double> query = new HashMap<Boolean, Double>();

		// Check if Trivial Case
		if(queryArg.getEvidence().contains(queryArg.getQuery()))
		{
			query.put(true, queryArg.getQuery().getState() ? 1.0 : 0.0);
			query.put(false, queryArg.getQuery().getState() ? 0.0 : 1.0);

			return query;
		}

		// Initialize the Alpha Value
		double alpha = 0;

		// Do Positive and Negative Enumeration
		for(int i = 0; i < 2; i ++)
		{
			// Copy Query States
			SortedMap<Probability, Boolean> states = new TreeMap<Probability, Boolean>(queryArg.getStates());

			// Add the Query Variable State
			states.put(queryArg.getQuery(), new Boolean(i == 1));

			// Enumerate the Variables
			double result = enumerateAll(sortProbabilities(), states, 0);

			// Map the Result
			query.put(new Boolean(i == 1), result);

			// Update the Alpha Value
			alpha += result;
		}	

		// Divide all Query Values by a Factor of Alpha
		for(Boolean bool : query.keySet())
			query.put(bool, query.get(bool)/alpha);

		return query;		
	}

	// Enumerates all of the specified Evidence
	private double enumerateAll(List<Probability> probabilities, SortedMap<Probability, Boolean> states, int index)
	{
		// Make sure something was Queried
		if(probabilities.isEmpty())
			return 1;

		// Determine the First Probability
		Probability first = probabilities.get(0);

		// Determine the Parent States
		SortedMap<Probability, Boolean> parentStates = new TreeMap<Probability, Boolean>(states);
		parentStates.keySet().retainAll(first.getParents());

		// Determine the Conditional Value
		double value = first.getEntry(parentStates);

		// Create Equation to follow the Math
		String equation = "";

		// Initialize the Enumerated Value
		double enumeration = 0;

		// Check of the Probability is Evidence
		if(states.containsKey(first))
		{
			// Flip the Value if Needed
			enumeration = (states.get(first) ? value : 1 - value);

			equation = "" + enumeration;

			// Create a Subset List for Recursion
			List<Probability> subset = probabilities.subList(1, probabilities.size());

			// Multiply Recursive Calls
			double mult = enumerateAll(subset, states, index + 1);

			enumeration *= mult; //enumerateAll(subset, states);

			equation += " * " + mult;

			value = enumeration;
		}
		else
		{
			// Initialize Summation Value
			/* 
			 * I've been having some weird issues with Java lately.
			 * I know that this could easily be one variable that I just
			 * add to, but for whatever reason, Java seemed to be forgetting
			 * the value each time, thus it was always '0 + x'. After I just
			 * got fed up and split it into an array of two numbers, which I agree
			 * that it is stupid, it seemed to worked. Whatever Java.
			*/
			double[] sum = {0, 0};

			// Do Positive and Negation Enumeration
			for(int i = 0; i < 2; i++)
			{
				// Map a Temporary State
				states.put(first, new Boolean(i == 1));
				
				// Determine Sub-Enumeration Value
				double sub = i == 1 ? value : 1 - value;

				String subEq = "";

				if(i == 1)
					subEq += sub;
				else
					subEq = "" + sub;

				// Create a Subset List for Recursion
				List<Probability> subset = probabilities.subList(1, probabilities.size());

				// Multiply Recursive Calls
				double mult = enumerateAll(subset, states, index + 1);
				sub *= mult; //enumerateAll(subset, states);

				subEq += " * " + mult;

				// Add Summation Values
				sum[i] = sub;

				if(equation == "")
					equation += subEq;
				else
					equation += " + " + subEq;

				// Remove Temporary State
				states.remove(first);
			}

			// Update the Value
			value = sum[0] + sum[1];
		}

		// Print Enumeration Step
		printStep(probabilities, states, value);

		return value;
	}

	// Prints the Enumeration Step
	private void printStep(List<Probability> probabilities, SortedMap<Probability, Boolean> states, double value)
	{
		// Determine the Number of Probabilities
		int count = this.probabilities.size();

		// Determine the Probability Names
		String names = "";

		for(Probability probability : probabilities)
			names += probability + " ";

		for(int i = 0; i < (count - probabilities.size()); i++)
			names += "  ";

		// Determine Probability States
		String state = "";

		for(Probability probability : states.keySet())
			state += probability + "=" + (states.get(probability) ? "t" : "f") + " ";

		for(int i = 0; i < (count - states.keySet().size()); i++)
			state += "    ";

		// Print out the Step
		System.out.printf(names + " | " + state + " = %.8f\n", value);
	}

	// Returns a List of Probabilities sorted by Query Dependence
	private List<Probability> sortProbabilities()
	{
		// Create a Map to mark off Probabilities
		final Map<Probability, Integer> map = new HashMap<Probability, Integer>();

		// Copy the Probabilities
		List<Probability> probabilities = new ArrayList<Probability>(this.probabilities);
		Collections.sort(probabilities);

		// Determine the Initial Size of the List
		int count = probabilities.size();

		// Iterate through the Probabilities until no more Remain or All have been Checked
		for(int i = 0; i < count && probabilities.size() > 0; i++)
		{
			Iterator<Probability> iterator = probabilities.iterator();

			while(iterator.hasNext())
			{
				// Determine the Current Probability
				Probability probability = iterator.next();

				// Check for Independence
				boolean independent = true;

				for(Probability parent : probability.getParents())
				{
					boolean mapped = false;

					for(Probability tracked : map.keySet())
					{
						if(tracked.equals(parent))
						{
							mapped = true;
							break;
						}
					}

					if(!mapped)
					{
						independent = false;
						break;
					}
				}

				if(independent)
				{
					// Add the Probability to the Independent Map
					map.put(probability, i);
					iterator.remove();
				}
			}
		}

		// Refresh the List of Probabilities
		probabilities.clear();
		probabilities.addAll(this.probabilities);

		// Perform a special Comparison
		Collections.sort(probabilities, new Comparator<Probability>()
			{
				public int compare(Probability prob1, Probability prob2)
				{
					// Order by Map Value
					if(map.containsKey(prob1) && map.containsKey(prob2))
					{
						int diff = map.get(prob1) - map.get(prob2);

						// Check for Difference
						if(diff != 0)
							return diff;
					}

					// Otherwise, use Name Comparison
					return prob1.compareTo(prob2);
				}
			}
		);
		
		// Return the Custom Sorted List
		return probabilities;
	}

	//* Conversion Methods *//
	// Returns a String Representation of the Bayes Net
	public String toString()
	{
		String result = "";

		for(Probability probability : probabilities)
			result += probability + "\n\n";

		return result;
	}
}
