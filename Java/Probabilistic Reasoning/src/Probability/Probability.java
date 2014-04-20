//* Description *//
// Title: Probability
// Author: Tyler Reed
// Represents a Probability within a Bayes Net

//* Package *//
package Probability;

//* Libraries *//
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.SortedMap;
import java.util.SortedSet;
import java.util.TreeSet;

//* Probability Class *//
public class Probability implements Comparable<Probability>
{
	//* Class Variables *//
	// Probability Variables
	private String name;
	private double value;
	private boolean state;
	private SortedSet<Probability> parents;

	// Table Variables
	private Map<SortedMap<Probability, Boolean>, Double> entries;

	//* Constructor *//
	// Name Constructor
	public Probability(String name)
	{
		this.name = name;
		this.value = 0;
		this.parents = new TreeSet<Probability>();
		this.entries = new HashMap<SortedMap<Probability, Boolean>, Double>();
	}

	// Name and Value Constructor
	public Probability(String name, double value)
	{
		this.name = name;
		this.value = value;
		this.parents = new TreeSet<Probability>();
	}

	// Name Constructor and Parent Constructor
	public Probability(String name, List<Probability> parents)
	{
		this.name = name;
		this.parents = new TreeSet<Probability>(parents);
		this.entries = new HashMap<SortedMap<Probability, Boolean>, Double>();
	}

	//* Name Methods *//
	// Returns the Name of the Probability
	public String getName()
	{
		return name;
	}

	//* Value Methods *//
	// Returns the Value of the Probability
	public double getValue()
	{
		return value;
	}

	// Returns the Conditional Value of the Probability
	public double getConditionalValue()
	{
		if(parents.isEmpty())
			return value;

		// Determine the Entry Row
		Map<Probability, Boolean> row = new HashMap<Probability, Boolean>();

		for(Probability parent : parents)
			row.put(parent, new Boolean(parent.getState()));

		return entries.get(row);
	}

	// Returns the Inverse Value of the Probability
	public double getInverseValue()
	{
		return 1 - value;
	}

	// Returns the Inverse Conditional Value of the Probability
	public double getInverseConditionValue()
	{
		return 1 - getConditionalValue();
	}

	//* State Methods *//
	// Returns the State of the Probability
	public boolean getState()
	{
		return state;
	}

	// Sets the State of the Probability
	public boolean setState(boolean state)
	{
		boolean old = this.state;
		this.state = state;
		return old;
	}

	//* Parent Methods *//
	// Returns the Set of Parents
	public SortedSet<Probability> getParents()
	{
		return parents;
	}

	// Returns whether or not the specified Probability is a Parent
	public boolean isParent(Probability parent)
	{
		return parents.contains(parent);
	}

	// Returns whether or not the specified Probability is an Ancestor
	public boolean isAncestor(Probability ancestor)
	{
		// Check if the Ancestor is a Parent
		if(isParent(ancestor))
			return true;

		// Prompt all Parents to check if the Ancestor is their Ancestor
		for(Probability parent : parents)
		{
			// Track Previous Probabilities to break Loops
			SortedSet<Probability> previous = new TreeSet<Probability>();
			previous.add(this);

			if(parent.isAncestor(ancestor, previous))
				return true;
		}

		return false;
	}

	// Recursive version to break Loops
	private boolean isAncestor(Probability ancestor, SortedSet<Probability> previous)
	{
		// Check if the Ancestor is a Parent
		if(isParent(ancestor))
			return true;

		// Break Loops
		if(previous.contains(this))
			return false;

		// Prompt all Parents to check if the Ancestor is their Ancestor
		for(Probability parent : parents)
		{
			// Add Self to Loop Tracker
			previous.add(this);

			if(parent.isAncestor(ancestor, previous))
				return true;
		}

		return false;
	}

	// Returns whether or not this Probability has Parents
	public boolean isPrior()
	{
		return parents.size() == 0;
	}
 
	//* Entry Methods *//
	// Puts the specified Entry into the Entry Table
	public boolean putEntry(SortedMap<Probability, Boolean> row, double value)
	{
		return entries.put(row, Double.valueOf(value)) == null;
	}

	// Returns the Value from the Entry Table given the specified Entry Key
	public double getEntry(SortedMap<Probability, Boolean> row)
	{
		if(entries == null || entries.isEmpty())
			return value;

		// Check each Key manually. Standard Contains Check is failing for some reason...
		for(SortedMap<Probability, Boolean> key : entries.keySet())
			if(key.equals(row))
				return entries.get(key);

		if(!entries.containsKey(row))
			throw new IllegalArgumentException("[Probability '" + name + "']: Row '" + row + "' does not exist in Entry Table '" + entries + "'"); 

		return entries.get(row);
	}

	// Returns the Number of Entries
	public int getEntryCount()
	{
		return entries.size();
	}
	
	//* Comparable Methods *//
	// Returns an Integer Representation (-1, 0, 1) of a Comparison
	public int compareTo(Probability other)
	{
		return name.compareTo(other.getName());
	}

	// Returns whether or not this Probability is Equal To another
	public boolean equals(Object other)
	{
		if(other.getClass() == this.getClass())
			return this.compareTo((Probability) other) == 0;
		else
			return super.equals(other);
	}

	//* Conversion Methods *//
	// Returns a String Representation of the Probability
	public String toString()
	{
		/*
		// Prior Probability
		if(parents.isEmpty())
			return "P(" + name + ") = " + value;

		// Probability Table
		String table = "";

		// Add Header
		for(Probability parent : parents)
			table += parent.getName() + " ";

		table += "| " + name + "\n";

		// Add Delimiter
		int length = table.length();

		for(int i = 0; i < length + 3; i++)
			if(i != table.indexOf("|"))
				table += "-";
			else
				table += "|";

		// Add Entries
		for(Map<Probability, Boolean> row : entries.keySet())
		{
			table += "\n";

			for(Boolean value : row.values())
				table += value.booleanValue() ? "t " : "f ";

			table += "| " + String.format("%.3f", entries.get(row));
		}

		return table;
		*/

		return name;
	}

	// Returns a String Representation of the Conditional Probability
	public String toConditionalString()
	{
		// Determine the Initial String
		String result = "P(" + name + "=" + (state ? "t" : "f");

		// Add Parents
		if(!parents.isEmpty())
		{
			result += "|";

			Probability first = parents.first();
			result += first.getName() + "=" + (first.getState() ? "t" : "f");

			for(Probability parent : parents)
				if(parent == first)
					continue;
				else
					result += "," + parent.getName() + "=" + (parent.getState() ? "t" : "f");

			return result + ")";
		}
		else
			return result + ")";
	}
}
