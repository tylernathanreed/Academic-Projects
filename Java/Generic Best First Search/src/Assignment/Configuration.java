//* Description *//
// Title: Search Configuration
// Author: Tyler Reed
// Stores Search Configuration Information

//* Package *//

package Assignment;

//* Search Configuration Class *//
public class Configuration
{
	// * Constants *//
	public static final String TYPE_DFS = "DFS";
	public static final String TYPE_BFS = "BFS";
	public static final String TYPE_UCS = "UCS";
	public static final String TYPE_GS = "GS";
	public static final String TYPE_ASTAR = "ASTAR";

	// * Class Variables *//
	private static String initialState;
	private static String searchType;
	private static boolean costing = false;

	// * Constructor *//
	// Creates the Configuration Class
	public Configuration(String initialState, String searchType, boolean costing)
	{
		if(!isValidSearchType(searchType))
			throw new InvalidSearchTypeException("Invalid Search Type: " + searchType);

		Configuration.initialState = initialState;
		Configuration.searchType = searchType;
		Configuration.costing = costing;
	}

	// * Initial State Methods *//
	// Returns the Initial State of the Configuration
	public static String getInitialState()
	{
		return initialState;
	}

	// Sets the Initial State of the Conifguration
	public static String setInitialState(String initialState)
	{
		String old = Configuration.initialState;
		Configuration.initialState = initialState;
		return old;
	}

	// * Search Type Methods *//
	// Returns the Search Type of the Configuration
	public static String getSearchType()
	{
		return searchType;
	}

	// Sets the Search Type of the Configuration
	public static String setSearchType(String searchType)
	{
		String old = Configuration.searchType;
		Configuration.searchType = searchType;
		return old;
	}

	// Returns whether or not the Search Type is Depth-First Search
	public static boolean isDFS()
	{
		return searchType.equalsIgnoreCase(TYPE_DFS);
	}

	// Returns whether or not the Search Type is Depth-First Search
	public static boolean isBFS()
	{
		return searchType.equalsIgnoreCase(TYPE_BFS);
	}

	// Returns whether or not the Search Type is Depth-First Search
	public static boolean isUCS()
	{
		return searchType.equalsIgnoreCase(TYPE_UCS);
	}

	// Returns whether or not the Search Type is Depth-First Search
	public static boolean isGS()
	{
		return searchType.equalsIgnoreCase(TYPE_GS);
	}

	// Returns whether or not the Search Type is Depth-First Search
	public static boolean isAStar()
	{
		return searchType.equalsIgnoreCase(TYPE_ASTAR);
	}

	// Returns whether or not the specified Search Type is Valid
	public static boolean isValidSearchType(String searchType)
	{
		return searchType.equalsIgnoreCase(TYPE_DFS) ||
			   searchType.equalsIgnoreCase(TYPE_BFS) ||
			   searchType.equalsIgnoreCase(TYPE_UCS) ||
			   searchType.equalsIgnoreCase(TYPE_GS)  ||
			   searchType.equalsIgnoreCase(TYPE_ASTAR);
	}

	// * Costing Methods *//
	// Returns whether or not the Configuration is Considering Costs
	public static boolean isCosting()
	{
		return costing;
	}

	// Sets whether or not the Configuration is Considering Costs
	public static boolean setCosting(boolean costing)
	{
		boolean old = Configuration.costing;
		Configuration.costing = costing;
		return old;
	}
}
