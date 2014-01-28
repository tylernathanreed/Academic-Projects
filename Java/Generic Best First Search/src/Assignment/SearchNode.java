//* Description *//
// Title: Search Node
// Author: Tyler Reed
// Defines the Search Node to be used in the Search Queue

//* Package *//
package Assignment;

//* Libraries *//
import java.util.List;
import java.util.Vector;

//* Search Node Class *//
public class SearchNode
{
	//* Class Variables *//
	private List<Move> previousStates;
	private String state;
	private int size;
	private int cost = 0;

	//* Constructor *//
	// Creates the Search Node
	public SearchNode(String initialState)
	{
		state = initialState;
		size = Configuration.getInitialState().length();
		previousStates = new Vector<Move>();
	}

	//* State Methods *//
	// Returns the Current State
	public String getState()
	{
		return state;
	}

	// Returns whether or not the Current State is a Goal State
	public boolean isGoalState()
	{
		int blank = (size - 1)/2;

		// Check for Blank Tile
		if(state.charAt(blank) != 'X')
			return false;

		// Check all Tiles
		for(int i = 0; i < blank; i++)
		{
			// Check Black Tiles
			if(state.charAt(i) != 'B')
				return false;

			// Check White Tiles
			if(state.charAt(i + blank + 1) != 'W')
				return false;
		}

		return true;
	}

	//* Step Methods *//
	// Returns the List of Previous States
	public List<Move> getPreviousStates()
	{
		return previousStates;
	}

	// Removes the specified Move
	public void removeStep(Move move)
	{
		previousStates.add(move);
		cost += move.getCost();
	}

	// Remove the specified List of Moves
	public void removeStep(List<Move> moves)
	{
		// Make sure the List Exists
		if(moves == null)
			return;

		// Remove the Steps
		previousStates.addAll(moves);
		for(int i = 0; i < moves.size(); i++)
			cost += moves.get(i).getCost();
	}

	//* Cost Methods *//
	// Returns the Cost of the Next Move based on the current Search Type
	public int getCost()
	{
		// Determine whether or not Cost is being Considered
		if(!Configuration.isCosting())
		{
			if(Configuration.isUCS())
				return previousStates.size();
			else if(Configuration.isGS())
				return getRunningCost();
			else if(Configuration.isAStar())
				return previousStates.size() + getEstimatedCost();
		}
		else // Costing
		{
			if(Configuration.isUCS())
				return getRunningCost();
			else if(Configuration.isGS())
				return getEstimatedCost();
			else if(Configuration.isAStar())
				return getRunningCost() + getRunningCost();
		}

		return cost;
	}

	// Returns the Cost from the Initial State to this State
	private int getRunningCost()
	{
		return cost;
	}

	// Returns the Estimated Cost to get to the next State
	private int getEstimatedCost()
	{
		int cost = 0;
		int half = (state.length() - 1)/2;
		
		for(int i = 0; i < half; i++)
		{
			// Check for missing Black Tiles
			if(state.charAt(i) != 'B')
				cost++;

			// Check for missing White Tiles
			if(state.charAt(i + half + 1) != 'W')
				cost++;
		}

		return cost;
	}

	//* Path Cost Methods *//
	// Returns the Path Cost based on the Current Search Type
	public int getPathCost()
	{
		int pathCost = 0;
		int half = (state.length() - 1)/2;

		for(int i = 0; i < half; i++)
		{
			// Check for missing Black Tiles
			if(state.charAt(i) != 'B')
				pathCost++;

			// Check for missing White Tiles
			if(state.charAt(i + half + 1) != 'W')
				pathCost++;
		}

		// Check for A-Star Case
		if(Configuration.isAStar())
			return previousStates.size() + pathCost;
		else // Other Search Types
			return cost + pathCost + Math.abs(state.indexOf('X') - half);
	}

	//* Printing Methods *//
	// Prints the Path to the Final State
	public String printSolution()
	{
		String result = "\nInitial State: " + Configuration.getInitialState() + "\n";

		for(int i = 0; i < previousStates.size(); i++)
		{
			// Determine the Previous State
			Move move = previousStates.get(i);

			result += " -> Step " + i + ": Move " + move.getTarget();

			// Check for Last State
			if(i != previousStates.size() - 1)
				result += ", " + previousStates.get(i + 1).getPreviousState();
			else
				result += ", " + state;

			// Add Cost if Considered
			if(Configuration.isCosting())
				result += " (Cost: " + move.getCost() + ")";

			// Terminate Line
			result += "\n";
		}
	
		// Return Final State
		return result + "\n\nFinal State (" + Configuration.getSearchType() + "): " + state;
	}
}
