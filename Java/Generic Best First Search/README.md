Generic Best First Search
=========================

**Compile:**
No compiling is necessary. Download the contents in the *exe* folder.

**Execution:**
Run the **GenericBestFirstSearch.jar** File with the following command:
    java -jar GenericBestFirstSearch.jar -f <File Path> -t <Ssearch Type> [-cost] [-print]

**Flags:**
The following Flags serve the specified Purpose:
 - -jar &lt;Jar File&gt; : Tells Java to run the specified Jar File *(GenericBestFirstSearch.jar)*
 - -jar &lt;Jar File&gt; : Tells Java to run the specified Jar File *(GenericBestFirstSearch.jar)*
  - -jar &lt;Jar File&gt; : Tells Java to run the specified Jar File *(GenericBestFirstSearch.jar)* - -jar &lt;Jar File&gt; : Tells Java to run the specified Jar File *(GenericBestFirstSearch.jar)*

*Note:* The Debugger for this Program was designed for the Bash Console, and may result in undesired effects in other Consoles.

**Debug Levels:**
 - **1** : Basic Semaphore Activity (Includes Name and Value)
 - **2** : Mutex Semaphore Activity (Includes Name and Value)
 - **3** : Object Activity (Includes Creation and Deletion)

**Example:**
	DMV -dC 3 -dG 1 *(Debugs Customer at Level 3 and Agent at Level 1)*

**Output:**
	Each thread outputs information prefixed with its own declaration. The various declarations of each thread is as follows:


**Declarations:**
 - **Main:** [Main | &lt;Subsection&gt;]:
 - **Customer:** [Customer &lt;ID&gt;, &lt;Ticket Number&gt;]:
 - **Information Desk:** [Information Desk]:
 - **Announcer:** [Announcer]:
 - **Agent:** [Agent &lt;ID&gt;]:


**File Descriptions:**
 - **Agent.h:** Defines the *Agent* Class, which calls the Customers from the Agent Line
 - **Announcer.h:** Defines the *Announcer* Class, which calls the Customers to the Agent Line from the Information Line
 - **Customer.h:** Defines the *Customer* Class, which is a Customer at the DMV
 - **Debug.h:** Defines the *Debug* Class, which is a Support Class for debugging Programs
 - **Definitions.h:** Defines all of the Constants in the Program
 - **InformationDesk.h:** Defines the *InformationDesk* Class, which calls the Customers from the Information Line
 - **itoa.h:** Defines the *itoa* function embedded in the *ITOA* Namespace
 - ***Main.cpp:*** Runs the Program
 - **Semaphores.h:** Defines all of the Semaphores in the Program
 - **Threads.h:** Defines all of the Threads and Threaded Functions in the Program
