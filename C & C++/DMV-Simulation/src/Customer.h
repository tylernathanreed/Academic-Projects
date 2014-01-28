//* Description *//
// Title: Customer
// Author: Tyler Reed
// Defines the Customer Class

//* Header Definition *//
#ifndef CUSTOMER_H
#define CUSTOMER_H

//* Libraries *//
#include <string>
#include <semaphore.h>
#include <stdarg.h>
#include "Debug.h"
#include "itoa.h"
#include "Definitions.h"
#include "Semaphores.h"

//* Forward Declarations *//
// Classes
class Customer;

//* Global Variables *//
// Tracking Variables
extern int customer_count;
extern int customers_processed;

// Queue Variables
extern queue<Customer*> *informationQueue;

//* Namespaces *//
using namespace std;
using namespace ITOA;
using namespace Semaphore;

//* Customer Class *//
class Customer
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
		Customer(int debug_mode);
		~Customer();

		// Exclusive Methods
		void arriveAtDMV();
		void arriveAtInformationLine();
		void arriveAtWaitingArea();
		void arriveAtAgentLine();
		void arriveAtAgent();
		void takeExam();
		void takeLicense();
		void leaveDMV();

		// Accessor Methods
		int getID();
		int getTicketNumber();

		// Mutator Methods
		void setTicketNumber(int ticket_number);

		// Debug Methods
		void debug(int access, string message, ...);
		int getDebugMode();
		int setDebugMode(int debug_mode);
};

//* Constructor *//
// Default Constructor
Customer::Customer(int debug_mode = 0)
{
	this -> id = -1;
	this -> ticket_number = -1;
	this -> debugger = new Debug(debug_mode);

	debug(3, "Object Initialized\n");
}

//* Destructor *//
// Triggered when the Object is called for Deletion
Customer::~Customer()
{
	debug(3, "Object Destroyed\n");

	// Delete the Debugger
	delete debugger;
}

//* Exclusive Methods *//
// Simulates the Customer arriving at the DMV
void Customer::arriveAtDMV()
{
	// Wait to Secure the Customer Count
	debug(2, "$f1Waiting$f0 on Semaphore $t1sem_mutex_customerCount $t0(%i)\n", sem_value(sem_mutex_customerCount));
	sem_wait(&sem_mutex_customerCount);
	debug(2, "$f3Passing$f0 through Semaphore $t1sem_mutex_customerCount $t0(%i)\n", sem_value(sem_mutex_customerCount));

	// Increase the Customer Count
	debug(3, "Increasing $t1customer_count $t0(%i)\n", customer_count);
	id = customer_count++;

	// Signal the Release of the Customer Count
	debug(2, "$f2Posting$f0 to Semaphore $t1sem_mutex_customerCount $t0(%i)\n", sem_value(sem_mutex_customerCount));
	sem_post(&sem_mutex_customerCount);

	// Print Arrival to DMV
	debug(0, "Arrived at $t1DMV$t0\n");
}

// Simulates the Customer arriving at the Information Line
void Customer::arriveAtInformationLine()
{
	// Wait for an Opening in the Information Line
	debug(1, "$f1Waiting$f0 on Semaphore $t1sem_informationLine $t0(%i)\n", sem_value(sem_informationLine));
	sem_wait(&sem_informationLine);
	debug(1, "$f3Passed$f0 through Semaphore $t1sem_informationLine $t0(%i)\n", sem_value(sem_informationLine));

	// Wait to Secure the Information Queue
	debug(2, "$f1Waiting$f0 on Semaphore $t1sem_mutex_informationQueue $t0(%i)\n", sem_value(sem_mutex_informationQueue));
	sem_wait(&sem_mutex_informationQueue);
	debug(2, "$f3Passed$f0 through Semaphore $t1sem_mutex_informationQueue $t0(%i)\n", sem_value(sem_mutex_informationQueue));

	// Enqueue into the Information Line
	debug(3, "$f1Enqueuing$f0 $t1self$t0 into $t1informationQueue$t0\n");
	informationQueue -> push(this);

	// Signal the Release of the Information Queue
	debug(2, "$f2Posting$f0 to Semaphore $t1sem_mutex_informationQueue $t0(%i)\n", sem_value(sem_mutex_informationQueue));
	sem_post(&sem_mutex_informationQueue);

	// Print Arrival to Information Line
	debug(0, "Arrived at $t1Information Line$t0\n");

	// Signal the Arrival to the Information Line
	debug(1, "$f2Posting$f0 to Semaphore $t1sem_customer_arriveAtInformationLine $t0(%i)\n", sem_value(sem_customer_arriveAtInformationLine));
	sem_post(&sem_customer_arriveAtInformationLine);
}

// Simulates the Customer arriving at the Waiting Area
void Customer::arriveAtWaitingArea()
{
	// Wait to be called by the Information Desk
	debug(1, "$f1Waiting$f0 on Semaphore $t1sem_informationDesk_callCustomer[%i] $t0(%i)\n", id, sem_value(sem_informationDesk_callCustomer[id]));
	sem_wait(&sem_informationDesk_callCustomer[id]);
	debug(1, "$f3Passed$f0 through Semaphore $t1sem_informationDesk_callCustomer[%i] $t0(%i)\n", id, sem_value(sem_informationDesk_callCustomer[id]));

	// Print the Arrival to the Waiting Area
	debug(0, "Arrived at $t1Waiting Area$t0 with Ticket Number: $t1%i$t0\n", this -> ticket_number);

	// Signal the Arrival to the Waiting Area
	debug(1, "$f2Posting$f0 to Semaphore $t1sem_customer_arriveAtWaitingArea $t0(%i)\n", sem_value(sem_customer_arriveAtWaitingArea));
	sem_post(&sem_customer_arriveAtWaitingArea);

	// Signal the Departure from the Information Line
	debug(1, "$f2Posting$f0 to Semaphore $t1sem_informationLine $t0(%i)\n", sem_value(sem_informationLine));
	sem_post(&sem_informationLine);
}

// Simulates the Customer arriving at the Agent Line
void Customer::arriveAtAgentLine()
{
	// Wait to be called by the Announcer
	debug(1, "$f1Waiting$f0 on Semaphore $t1sem_announcer_callCustomer[%i] $t0(%i)\n", ticket_number, sem_value(sem_announcer_callCustomer[ticket_number]));
	sem_wait(&sem_announcer_callCustomer[ticket_number]);
	debug(1, "$f3Passing$f0 through Semaphore $t1sem_announcer_callCustomer[%i] $t0(%i)\n", ticket_number, sem_value(sem_announcer_callCustomer[ticket_number]));

	// Print the Arrival to the Agent Line
	debug(0, "Arrived at $t1Agent Line$t0\n");

	// Signal the Arrival to the Agent Line
	debug(1, "$f2Posting$f0 to Semaphore $t1sem_customer_arriveAtAgentLine $t0(%i)\n", sem_value(sem_customer_arriveAtAgentLine));
	sem_post(&sem_customer_arriveAtAgentLine);
}

// Simulates the Customer arrive at an Agent
void Customer::arriveAtAgent()
{
	// Wait to be called by an Agent
	debug(1, "$f1Waiting$f0 on Semaphore $t1sem_agent_callCustomer[%i] $t0(%i)\n", ticket_number, sem_value(sem_agent_callCustomer[ticket_number]));
	sem_wait(&sem_agent_callCustomer[ticket_number]);
	debug(1, "$f3Passing$f0 through Semaphore $t1sem_agent_callCustomer[%i] $t0(%i)\n", ticket_number, sem_value(sem_agent_callCustomer[ticket_number]));

	// Print the Arrival to the Agent
	debug(0, "Arrived at $t1Agent$t0\n");

	// Signal the Arrival to the Agent
	debug(1, "$f2Posting$f0 to Semaphore $t1sem_customer_arriveAtAgent[%i] $t0(%i)\n", ticket_number, sem_value(sem_customer_arriveAtAgent[ticket_number]));
	sem_post(&sem_customer_arriveAtAgent[ticket_number]);

	// Signal the Departure from the Agent Line
	debug(1, "$f2Posting$f0 to Semaphore $t1sem_agentLine $t0(%i)\n", sem_value(sem_agentLine));
	sem_post(&sem_agentLine);
}

// Simulates the Customer taking an Exam
void Customer::takeExam()
{
	// Wait to be given an Exam
	debug(1, "$f1Waiting$f0 on Semaphore $t1sem_agent_giveExam[%i] $t0(%i)\n", ticket_number, sem_value(sem_agent_giveExam[ticket_number]));
	sem_wait(&sem_agent_giveExam[ticket_number]);
	debug(1, "$f3Passing$f0 through Semaphore $t1sem_agent_giveExam[%i] $t0(%i)\n", ticket_number, sem_value(sem_agent_giveExam[ticket_number]));

	// Print the Taking of the Exam
	debug(0, "Taking $t1Exam$t0\n");

	// Signal the completion of the Exam
	debug(1, "$f2Posting$f0 to Semaphore $t1sem_customer_takeExam[%i] $t0(%i)\n", ticket_number, sem_value(sem_customer_takeExam[ticket_number]));
	sem_post(&sem_customer_takeExam[ticket_number]);
}

// Simulates the Customer taking a License
void Customer::takeLicense()
{
	// Wait to be given a License
	debug(1, "$f1Waiting$f0 on Semaphore $t1sem_agent_giveLicense[%i] $t0(%i)\n", ticket_number, sem_value(sem_agent_giveLicense[ticket_number]));
	sem_wait(&sem_agent_giveLicense[ticket_number]);
	debug(1, "$f3Passing$f0 through Semaphore $t1sem_agent_giveLicense[%i] $t0(%i)\n", ticket_number, sem_value(sem_agent_giveLicense[ticket_number]));

	// Print the Taking of the License
	debug(0, "Taking $t1License$t0\n");

	// Signal the Taking of the License
	debug(1, "$f2Posting$f0 to Semaphore $t1sem_customer_takeLicense[%i] $t0(%i)\n", ticket_number, sem_value(sem_customer_takeLicense[ticket_number]));
	sem_post(&sem_customer_takeLicense[ticket_number]);
}

// Simulates the Customer leaving the DMV
void Customer::leaveDMV()
{
	// Wait to Secure the Customers Processed
	debug(2, "$f1Waiting$f0 on Semaphore $t1sem_mutex_customersProcessed $t0(%i)\n", sem_value(sem_mutex_customersProcessed));
	sem_wait(&sem_mutex_customersProcessed);
	debug(2, "$f3Passed$f0 through Semaphore $t1sem_mutex_customersProcessed $t0(%i)\n", sem_value(sem_mutex_customersProcessed));

	// Increase the Customers Processed
	debug(3, "Increasing $t1customers_processed $t0(%i)\n", customers_processed);
	customers_processed++;

	// Signal the Release of the Customers Processed
	debug(2, "$f2Posting$f0 to Semaphore $t1sem_mutex_customersProcessed $t0(%i)\n", sem_value(sem_mutex_customersProcessed));
	sem_post(&sem_mutex_customersProcessed);

	// Print the Departure from the DMV
	debug(0, "Leaving $t1DMV$t0\n");

	// Signal the Departure from the DMV
	debug(1, "$f2Posting$f0 to Semaphore $t1sem_customer_leaveDMV[%i] $t0(%i)\n", ticket_number, sem_value(sem_customer_leaveDMV[ticket_number]));
	sem_post(&sem_customer_leaveDMV[ticket_number]);
}

//* Accessor Methods *//
// Returns the ID of the Customer
int Customer::getID()
{
	return id;
}

// Returns the Ticket Number of the Customer
int Customer::getTicketNumber()
{
	return ticket_number;
}

//* Mutator Methods *//
// Sets the Ticket Number of the Customer
void Customer::setTicketNumber(int ticket_number)
{
	this -> ticket_number = ticket_number;
}

//* Debug Methods *//
// Calls the Debugger
void Customer::debug(int access, string message, ...)
{
	if(access > debugger -> getDebugMode())
		return;

	va_list args;
	va_start(args, message);
	va_end(args);

	string prefix = "$t1 + $t0$f4[Customer ";
	prefix.append(itoa(id));
	prefix.append(", ");
	prefix.append(itoa(ticket_number));
	prefix.append("]$f0: ");

	debugger -> debug(access, prefix + message, args);
	sleep(1);
}

// Returns the Debug Mode
int Customer::getDebugMode()
{
	return debugger -> getDebugMode();
}

// Sets the Debug Mode
int Customer::setDebugMode(int debug_mode)
{
	return debugger -> setDebugMode(debug_mode);
}

//* End of Header Definition *//
#endif
