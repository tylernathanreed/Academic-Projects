DMV Simulation
==============

**Compile:**
Download Source files from *src* Directory. Run **makefile** with the '*make*' command in the directory where the Program has been downloaded.

**Execution:**
Run the **DMV** executable with the *./DMV* command after Compiling.

**Debugging:**
Should you want to see the Semaphore or Object activity, you can use the Debug feature implemented in the Program. Use one of the following tags suffixed with a Debug Level:
 - **dM <X>** : Debugs the Main Process
 - **dC <X>** : Debugs the Customer Thread
 - **dA <X>** : Debugs the Announcer Thread
 - **dI <X>** : Debugs the Information Desk Thread
 - **dG <X>** : Debugs the Agent Thread

**Debug Levels:**
 - **1** : Basic Semaphore Activity (Includes Name and Value)
 - **2** : Mutex Semaphore Activity (Includes Name and Value)
 - **3** : Object Activity (Includes Creation and Deletion)

**Example:**
	Project2 –dC 3 –dG 1 *(Debugs Customer at Level 3 and Agent at Level 1)*

**Output:**
	Each thread outputs information prefixed with its own declaration. The various declarations of each thread is as follows:


**Declarations:**
 - **Main:**		[Main | <Subsection>]:
 - **Customer:**		[Customer <ID>, <Ticket Number>]:
 - **Information Desk:**	[Information Desk]:
 - **Announcer:**		[Announcer]:
 - **Agent:**		[Agent <ID>]:


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