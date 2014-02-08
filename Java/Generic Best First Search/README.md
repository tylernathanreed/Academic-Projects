Generic Best First Search
=========================

**Compile:**
No compiling is necessary. Download the contents in the *exe* folder.

**Execution:**
Run the `GenericBestFirstSearch.jar` File with the following command:<br>
`java -jar <Jar File> -f <Input File Path> -t <Search Type> [-cost] [-print]`

**Flags:**
The following Flags serve the specified Purpose:
 - `-jar <Jar File>` : Tells Java to run the specified Jar File *(GenericBestFirstSearch.jar)*
 - `-f <Input File Path>` : Tells the Program to use the specified Input File *(./input.txt)*
 - `-t <Search Type>` : Tells the Program which Search Type to Use *(DFS|BFS|UCS|GS|ASTAR)*
 - `-cost` : Tells the Program to Print the Cost of each Step *[Optional]*
 - `-print` : Tells the Program to Print each Step *[Optional]*

**Example:**<br>
`java -jar GenericBestFirstSearch.jar -f ./input.txt -t ASTAR` *(Runs the Program using A&#42; Search)*

**Output:**<br>
Each thread outputs information prefixed with its own declaration. The various declarations of each thread is as follows:

**File Descriptions:**
 - `Configuration.java:` Defines the *Configuation* Class, which stores *static* information about the Search Procedure
 - `InvalidSearchTypeException.java:` Defines the *InvalidSearchType* Exception, which is called is an Invalid Search Type is used to create the *Configuration* class
 - `Main.java` Defines the *Main* Class, which runs the Program and interprets the Command Line
 - `Move.java` Defines the *Move* Class, whichs acts as a Successor Function for the Problem State
 - `Search.java` Defines the *Search* Class, which performs the Generic Search Algorithm
 - `SearchNode.java` Defines the *SearchNode* Class, which is used to iterate through the State Space
 - `SearchQueue.java` Defines the *SearchQueue* Class, which contains the Un-Expanded Leaf Nodes in the State Tree
 - `SearchType.java` Defines the *SearchType* Enumeration, which details the different types of Search Types
