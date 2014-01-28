//* Description //
// Title: Search Queue
// Author: Tyler Reed
// Creates the Search Queue to be used in the Search Class

//* Package *//
package Assignment;

//* Libraries *//
import java.util.List;
import java.util.Vector;

//* Search Queue Class *//
public class SearchQueue
{
	//* Class Variables *//
	private List<SearchNode> states;

	//* Constructor *//
	// Creates the Search Queue Class
	public SearchQueue()
	{
		this.states = new Vector<SearchNode>();
	}

	//* Queue Methods *//
	// Pushes the specified Node to the Queue
	public void push(SearchNode node)
	{
		if(Configuration.isDFS())
			states.add(0, node); // Insert Node at Beginning
		else if(Configuration.isBFS())
			states.add(node); // Annex Node at End
		else if(states.size() == 0)
			states.add(node);
		else
		{
			// Find the Node with the Lowest Cost
			int lowerBound = -1;
			int upperBound = states.size();

			// Do Binary Search
			while(lowerBound + 1 < upperBound)
			{
				int middle = (lowerBound + upperBound)/2;
				int cost = states.get(middle).getCost();

				if(cost > node.getCost())
					upperBound = middle;
				else
					lowerBound = middle;
			}

			states.add(upperBound, node);
		}
	}

	// Pushes the specified Node to the specified Index in the Queue
	public void push(SearchNode node, int index)
	{
		states.add(index, node);
	}

	// Pops the First Node in the Queue
	public SearchNode pop()
	{
		return states.remove(0);
	}

	// Returns the First Node in the Queue without Removing it
	public SearchNode peek()
	{
		return states.get(0);
	}

	//* Container Methods *//
	// Returns the Size of the Queue
	public int size()
	{
		return states.size();
	}

	// Returns whether or not the Queue is Empty
	public boolean isEmpty()
	{
		return states.isEmpty();
	}
}
