DMV Simulation
==============

**Compile:**
Download Source files from *src* Directory. Run **makefile** with the '*make*' command in the directory where the Program has been downloaded.

**Execution:**
Run the **DMV** executable with the *./DMV* command after Compiling.

**Debugging:**
Should you want to see the Semaphore or Object activity, you can use the Debug feature implemented in the Program. Use one of the following tags suffixed with a Debug Level:
 - **dM &lt;X&gt;** : Debugs the Main Process
 - **dC &lt;X&gt;** : Debugs the Customer Thread
 - **dA &lt;X&gt;** : Debugs the Announcer Thread
 - **dI &lt;X&gt;** : Debugs the Information Desk Thread
 - **dG &lt;X&gt;** : Debugs the Agent Thread

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
