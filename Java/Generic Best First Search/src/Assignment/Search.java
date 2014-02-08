//* Description *//
// Title: Search
// Author: Tyler Reed
// Performs the Search on the Move Set

//* Package *//
package Assignment;

//* Libraries *//
import java.util.ArrayList;
import java.util.List;

//* Search Class *//
public class Search
{
	//* Class Variables *//
	public static Configuration configuration;
	private static SearchQueue searchQueue;
	private List<String> visitedStates = null;

	//* Constructor *//
	// Creates the Search Class with the specified Configuration
	public Search(Configuration configuration)
	{
		// Set Configuration
		Search.configuration = configuration;

		// Create Data Structures
		searchQueue = new SearchQueue();
		visitedStates = new ArrayList<String>();

		// Create Initial State
		SearchNode node = new SearchNode(Configuration.getInitialState());
		searchQueue.push(node);

		// Begin the Search
		doSearch();
	}

	// Performs the Search for the Goal State
	private void doSearch()
	{
		// Initialize Step Count
		int steps = 0;

		// Loop Indefinitely
		while(true)
		{
			// Check for Impossible Goal
			if(searchQueue.isEmpty())
			{
				System.out.println("No Solution Exists!");
				System.exit(0);
			}

			// Get the Next best State
			SearchNode node = searchQueue.pop();

			while(visitedStates.contains(node.getState())) // Ignore Visited States
				node = searchQueue.pop();

			// Add the Move to the Visisted States
			visitedStates.add(node.getState());

			// Print the Current Step
			if(Configuration.isPrinting())
				node.printCurrentStep();

			// Check for Goal
			if(node.isGoalState())
			{
				System.out.println(node.printSolution());
				System.out.println("Nodes Expanded: " + steps);
				return;
			}
			else
				steps++;

			// Get the Next Move
			int index = 0;
			for(int j = 0; j < Configuration.getInitialState().length(); j++)
			{
				Move move = new Move(node.getState());
				String state = move.getNextState(j);
	
				if(state == null)
					break;
				else if(!state.equals(""))
					if(!visitedStates.contains(state))
					{
						SearchNode nextState = new SearchNode(state);
						nextState.removeStep(node.getPreviousStates());
						nextState.removeStep(move);

						if(Configuration.isDFS())
							searchQueue.push(nextState, index++);
						else
							searchQueue.push(nextState);
					}
			}
		}
	}
}
