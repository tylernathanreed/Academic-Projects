//* Description *//
// Title: Move
// Author: Tyler Reed
// Moves Tiles in a String using the given Operators

//* Package *//
package Assignment;

//* Move Class *//
public class Move
{
	//* Class Variables *//
	private int cost = 0;
	private int target = 0;
	private String previousState = "";

	//* Constructor *//
	// Creates the Move Class
	public Move(String initialState)
	{
		previousState = initialState;
	}

	//* Cost Methods *//
	// Returns the Cost of the Move
	public int getCost()
	{
		return cost;
	}

	// Sets the Cost of the Move
	public int setCost(int cost)
	{
		int old = this.cost;
		this.cost = cost;
		return old;
	}

	//* Target Methods *//
	// Returns the Target of the Move
	public int getTarget()
	{
		return target;
	}

	// Sets the Target of the Move
	public int setTarget(int target)
	{
		int old = this.target;
		this.target = target;
		return old;
	}

	//* Previous State Methods *//
	// Returns the Previous State of the Move
	public String getPreviousState()
	{
		return previousState;
	}

	// Sets the Previous State of the Move
	public String setPreviousState(String previousState)
	{
		String old = this.previousState;
		this.previousState = previousState;
		return old;
	}

	//* Next State Methods *//
	public String getNextState(int target)
	{
		// Set the Next State
		String nextState = previousState;

		// Determine the Index of the Blank Tile
		int blank = nextState.indexOf('X');

		// Check for Trivial Movement
		if(blank == target)
				return "";
		else if(target < nextState.length()) // Non-Trivial Movement
		{
			// Determine the Target Tile
			char tile = nextState.charAt(target);

			// Swap the Target with the Blank Tile
			nextState = nextState.substring(0, target) + "X" + nextState.substring(target + 1); // Set Blank on Tile
			nextState = nextState.substring(0, blank) + tile + nextState.substring(blank + 1); // Set Tile on Blank

			// Update the Target
			this.target = target;

			// Determine the Cost of the Movement
			this.cost = Math.abs(blank - target);
		}
		else // Invalid Target
		{
			return null;
		}

		return nextState;
	}
}
