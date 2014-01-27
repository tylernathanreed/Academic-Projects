//* Description *//
// Title: Agent
// Author: Tyler Reed
// Defines the Agent Class

//* Header Definition *//
#ifndef AGENT_H
#define AGENT_H

//* Libraries *//
#include <queue>
#include "itoa.h"
#include "Debug.h"
#include "Semaphores.h"

//* Namespaces *//
using namespace ITOA;
using namespace Semaphore;

//* Global Variables *//
extern int agent_count;
extern queue<int> *agentQueue;

//* Agent Class *//
class Agent
{
	//* Class Variables *//
	// Private Variables
	private:
		Debug* debugger;
		int id;
		int ticket_number;

	//* Class Methods *//
	// Public Methods
	public:
		// Constructor and Destructor
		Agent(int debug_mode);
		~Agent();

		// Exclusive Methods
		void callCustomer();
		void giveExam();
		void giveLicense();
		void waitToLeave();

		// Accessor Methods
		int getID();
		int getTicketNumber();

		// Mutator Methods
		void setID(int id);
		void setTicketNumber(int ticket_number);

		// Debug Methods
		void debug(int access, string message, ...);
		int getDebugMode();
		int setDebugMode(int debug_mode);
};

//* Constructor *//
// Default Constructor
Agent::Agent(int debug_mode = 0)
{
	// Initialize the Agent
	this -> debugger = new Debug(debug_mode);
	id = -1;

	// Wait to Secure the Agent Count
	debug(2, "$f1Waiting$f0 on Semaphore $t1sem_mutex_agentCount $t0(%i)\n", sem_value(sem_mutex_agentCount));
	sem_wait(&sem_mutex_agentCount);
	debug(2, "$f3Passed$f0 through Semaphore $t1sem_mutex_agentCount $t0(%i)\n", sem_value(sem_mutex_agentCount));

	// Increase the Agent Count
	id = agent_count++;

	// Signal the Release of the Agent Count
	debug(2, "$f2Posting$f0 to Semaphore $t1sem_mutex_agentCount $t0(%i)\n", sem_value(sem_mutex_agentCount));
	sem_post(&sem_mutex_agentCount);

	debug(3, "Object Initialized\n");
}

//* Destructor *//
// Triggered when the Object is called for Deletion
Agent::~Agent()
{
	debug(3, "Object Destroyed\n");

	// Delete the Debugger
	delete debugger;
}

//* Exlusive Methods *//
// Calls the Next Customer in the Agent Line
void Agent::callCustomer()
{
	// Wait for a Customer to enter the Agent Line
	debug(1, "$f1Waiting$f0 on Semaphore $t1sem_customer_arriveAtAgentLine $t0(%i)\n", sem_value(sem_customer_arriveAtAgentLine));
	sem_wait(&sem_customer_arriveAtAgentLine);
	debug(1, "$f3Passing$f0 through Semaphore $t1sem_customer_arriveAtAgentLine $t0(%i)\n", sem_value(sem_customer_arriveAtAgentLine));

	// Wait to Secure the Agent Queue
	debug(2, "$f1Waiting$f0 on Semaphore $t1sem_mutex_agentQueue $t0(%i)\n", sem_value(sem_mutex_agentQueue));
	sem_wait(&sem_mutex_agentQueue);
	debug(2, "$f3Passing$f0 through Semaphore $t1sem_mutex_agentQueue $t0(%i)\n", sem_value(sem_mutex_agentQueue));

	// Remove the First Ticket Number in the Queue
	debug(3, "$f2Dequeuing$f0 $t1Ticket Number$t0 from $t1agentQueue$t0\n");
	int ticket_number = agentQueue -> front();
	agentQueue -> pop();

	// Signal the Release of the Agent Queue
	debug(2, "$f2Posting$f0 to Semaphore $t1sem_mutex_agentQueue $t0(%i)\n", sem_value(sem_mutex_agentQueue));
	sem_post(&sem_mutex_agentQueue);

	// Store the Ticket Number
	this -> ticket_number = ticket_number;

	// Print the Calling of the Customer
	debug(0, "Calling Ticket Number: %i\n", ticket_number);

	// Signal the Customer that it has been called
	debug(1, "$f2Posting$f0 to Semaphore $t1sem_agent_callCustomer[%i] $t0(%i)\n", ticket_number, sem_value(sem_agent_callCustomer[ticket_number]));
	sem_post(&sem_agent_callCustomer[ticket_number]);
}

// Gives an Exam to the Customer
void Agent::giveExam()
{
	// Wait for the Arrival of the Customer
	debug(1, "$f1Waiting$f0 on Semaphore $t1sem_customer_arriveAtAgent[%i] $t0(%i)\n", ticket_number, sem_value(sem_customer_arriveAtAgent[ticket_number]));
	sem_wait(&sem_customer_arriveAtAgent[ticket_number]);
	debug(1, "$f3Passing$f0 through Semaphore $t1sem_customer_arriveAtAgent[%i] $t0(%i)\n", ticket_number, sem_value(sem_customer_arriveAtAgent[ticket_number]));

	// Give an Exam to the Customer
	debug(1, "$f2Posting$f0 to Semaphore $t1sem_agent_giveExam[%i] $t0(%i)\n", ticket_number, sem_value(sem_agent_giveExam[ticket_number]));
	sem_post(&sem_agent_giveExam[ticket_number]);

	// Print the Giving of the Exam
	debug(0, "Giving $t1Exam$t0\n");
}

// Gives a License to the Customer
void Agent::giveLicense()
{
	// Wait for the Customer to Take the Exam
	debug(1, "$f1Waiting$f0 on Semaphore $t1sem_customer_takeExam[%i] $t0(%i)\n", ticket_number, sem_value(sem_customer_takeExam[ticket_number]));
	sem_wait(&sem_customer_takeExam[ticket_number]);
	debug(1, "$f3Passing$f0 through Semaphore $t1sem_customer_takeExam[%i] $t0(%i)\n", ticket_number, sem_value(sem_customer_takeExam[ticket_number]));

	// Give the License to the Customer
	debug(1, "$f2Posting$f0 to Semaphore $t1sem_agent_giveLicense[%i] $t0(%i)\n", ticket_number, sem_value(sem_agent_giveLicense[ticket_number]));
	sem_post(&sem_agent_giveLicense[ticket_number]);

	// Print the Giving of the License
	debug(0, "Giving $t1License$t0\n");
}

// Waits for the Customer to Leave before calling another one
void Agent::waitToLeave()
{
	// Wait for the Customer to Take the License
	debug(1, "$f1Waiting$f0 on Semaphore $t1sem_customer_takeLicense[%i] $t0(%i)\n", ticket_number, sem_value(sem_customer_takeLicense[ticket_number]));
	sem_wait(&sem_customer_takeLicense[ticket_number]);
	debug(1, "$f3Passing$f0 through Semaphore $t1sem_customer_takeLicense[%i] $t0(%i)\n", ticket_number, sem_value(sem_customer_takeLicense[ticket_number]));

	// Wait for the Customer to Leave
	debug(1, "$f1Waiting$f0 on Semaphore $t1sem_customer_leaveDMV[%i] $t0(%i)\n", ticket_number, sem_value(sem_customer_leaveDMV[ticket_number]));
	sem_wait(&sem_customer_leaveDMV[ticket_number]);
	debug(1, "$f3Passed$f0 through Semaphore $t1sem_customer_leaveDMV[%i] $t0(%i)\n", ticket_number, sem_value(sem_customer_leaveDMV[ticket_number]));
}

//* Accessor Methods *//
// Returns the ID of the Agent
int Agent::getID()
{
	return id;
}

// Returns the Ticket Number of the Agent
int Agent::getTicketNumber()
{
	return ticket_number;
}

//* Mutator Methods *?/
// Sets the ID of the Agent
void Agent::setID(int id)
{
	this -> id = id;
}

// Sets the Ticket Number of the Agent
void Agent::setTicketNumber(int ticket_number)
{
	this -> ticket_number = ticket_number;
}

//* Debug Methods *//
// Calls the Debugger
void Agent::debug(int access, string message, ...)
{
	if(access > debugger -> getDebugMode())
		return;

	va_list args;
	va_start(args, message);
	va_end(args);

	string prefix = "$t1 + $t0$f2[Agent ";
	prefix.append(itoa(id));
	prefix.append("]$f0: ");

	debugger -> debug(access, prefix + message, args);
	sleep(1);
}

// Returns the Debug Mode
int Agent::getDebugMode()
{
	return debugger -> getDebugMode();
}

// Sets the Debug Mode
int Agent::setDebugMode(int debug_mode)
{
	return debugger -> setDebugMode(debug_mode);
}

//* End of Header Definition *//
#endif
