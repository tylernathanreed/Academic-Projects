//* Description *//
// Title: Search Configuration
// Author: Tyler Reed
// Stores Search Configuration Information

//* Package *//
package Assignment;

//* Search Configuration Class *//
public class Configuration
{
	// * Class Variables *//
	private static String initialState;
	private static SearchType searchType;
	private static boolean costing = false;
	private static boolean printing = false;

	// * Constructor *//
	// Creates the Configuration Class
	public Configuration(String initialState, SearchType searchType, boolean costing, boolean printing)
	{
		if(searchType == SearchType.TYPE_NONE)
			throw new InvalidSearchTypeException(searchType.toString());

		Configuration.initialState = initialState;
		Configuration.searchType = searchType;
		Configuration.costing = costing;
		Configuration.printing = printing;
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
	public static SearchType getSearchType()
	{
		return searchType;
	}

	// Sets the Search Type of the Configuration
	public static SearchType setSearchType(SearchType searchType)
	{
		SearchType old = Configuration.searchType;
		Configuration.searchType = searchType;
		return old;
	}

	// Returns the Name of the Search Type
	public static String getSearchTypeName()
	{
		switch(searchType)
		{
			case TYPE_DFS:
				return "Depth-First Search";
			case TYPE_BFS:
				return "Breadth-First Search";
			case TYPE_GS:
				return "Greedy Search";
			case TYPE_UCS:
				return "Uniform-Cost Search";
			case TYPE_ASTAR:
				return "A* Search";
			default:
				return "None";
		}
	}

	// Returns whether or not the Search Type is Depth-First Search
	public static boolean isDFS()
	{
		return searchType == SearchType.TYPE_DFS;
	}

	// Returns whether or not the Search Type is Depth-First Search
	public static boolean isBFS()
	{
		return searchType == SearchType.TYPE_BFS;
	}

	// Returns whether or not the Search Type is Depth-First Search
	public static boolean isUCS()
	{
		return searchType == SearchType.TYPE_UCS;
	}

	// Returns whether or not the Search Type is Depth-First Search
	public static boolean isGS()
	{
		return searchType == SearchType.TYPE_GS;
	}

	// Returns whether or not the Search Type is Depth-First Search
	public static boolean isAStar()
	{
		return searchType == SearchType.TYPE_ASTAR;
	}

	// Returns whether or not the specified Search Type is Valid
	public static boolean isValidSearchType(SearchType searchType)
	{
		return searchType != SearchType.TYPE_NONE;
	}

	// Casts the given String to a Search Type
	public static SearchType castToSearchType(String searchType)
	{
		if(searchType.equalsIgnoreCase("BFS"))
			return SearchType.TYPE_BFS;
		else if(searchType.equalsIgnoreCase("DFS"))
			return SearchType.TYPE_DFS;
		else if(searchType.equalsIgnoreCase("GS"))
			return SearchType.TYPE_GS;
		else if(searchType.equalsIgnoreCase("UCS"))
			return SearchType.TYPE_UCS;
		else if(searchType.equalsIgnoreCase("ASTAR"))
			return SearchType.TYPE_ASTAR;
		else
			return SearchType.TYPE_NONE;
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

	// * Printing Methods *//
	// Returns whether or not the Configuration is Printing each Step
	public static boolean isPrinting()
	{
		return printing;
	}

	// Sets whether or not the Configuration is Printing each Step
	public static boolean setPrinting(boolean printing)
	{
		boolean old = Configuration.printing;
		Configuration.printing = printing;
		return old;
	}
}
