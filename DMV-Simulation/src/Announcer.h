//* Description *//
// Title: Announcer
// Author: Tyler Reed
// Defines the Announcer Class

//* Header Definition *//
#ifndef ANNOUNCER_H
#define ANNOUNCER_H

//* Libraries *//
#include <stdarg.h>
#include <semaphore.h>
#include "Debug.h"
#include "Definitions.h"
#include "Semaphores.h"

//* Namespaces *//
using namespace Semaphore;

//* Global Variables *//
extern queue<int> *waitingAreaQueue;
extern queue<int> *agentQueue;

//* Announcer Class *//
class Announcer
{
	//* Class Variables *//
	// Private Variables
	private:
		Debug* debugger;
		int ticket_number;

	//* Class Methods *//
	// Public Methods
	public:
		// Constructor and Destructor
		Announcer(int debug_mode);
		~Announcer();

		// Exclusive Methods
		void callCustomer();

		// Accessors
		int getTicketNumber();

		// Debug Methods
		void debug(int access, string message, ...);
		int getDebugMode();
		int setDebugMode(int debug_mode);
};

//* Constructor *//
// Default Constructor
Announcer::Announcer(int debug_mode = 0)
{
	// Initialize the Announcer
	this -> debugger = new Debug(debug_mode);

	debug(3, "Object Initialized\n");
}

//* Destructor *//
// Triggered when the Object is called for Deletion
Announcer::~Announcer()
{
	debug(3, "Object Destroyed\n");

	// Delete the Debugger
	delete debugger;
}

//* Exclusive Methods *//
// Calls a Customer from in Information Line
void Announcer::callCustomer()
{
	// Wait for an Opening in the Agent Queue
	debug(1, "$f1Waiting$f0 on Semaphore $t1sem_agentLine $t0(%i)\n", sem_value(sem_agentLine));
	sem_wait(&sem_agentLine);
	debug(1, "$f3Passed$f0 through Semaphore $t1sem_agentLine $t0(%i)\n", sem_value(sem_agentLine));

	// Wait for a Customer to enter the Waiting Area
	debug(1, "$f1Waiting$f0 on Semaphore $t1sem_customer_arriveAtWaitingArea $t0(%i)\n", sem_value(sem_customer_arriveAtWaitingArea));
	sem_wait(&sem_customer_arriveAtWaitingArea);
	debug(1, "$f3Passed$f0 through Semaphore $t1sem_customer_arriveAtWaitingArea $t0(%i)\n", sem_value(sem_customer_arriveAtWaitingArea));

	// Wait to Secure the Waiting Area Queue
	debug(2, "$f1Waiting$f0 on Semaphore $t1sem_mutex_waitingAreaQueue $t0(%i)\n", sem_value(sem_mutex_waitingAreaQueue));
	sem_wait(&sem_mutex_waitingAreaQueue);
	debug(2, "$f3Passing$f0 through Semaphore $t1sem_mutex_waitingAreaQueue $t0(%i)\n", sem_value(sem_mutex_waitingAreaQueue));

	// Remove the First Ticket Number in the Queue
	debug(3, "$f2Dequeuing$f0 $t1Ticket Number$t0 from $t1waitingAreaQueue$t0\n");
	int ticket_number = waitingAreaQueue -> front();
	waitingAreaQueue -> pop();

	// Signal the Release of the Waiting Area Queue
	debug(2, "$f2Posting$f0 to Semaphore $t1sem_mutex_waitingAreaQueue $t0(%i)\n", sem_value(sem_mutex_waitingAreaQueue));
	sem_post(&sem_mutex_waitingAreaQueue);

	// Wait to Secure the Agent Queue
	debug(2, "$f1Waiting$f0 on Semaphore $t1sem_mutex_agentQueue $t0(%i)\n", sem_value(sem_mutex_agentQueue));
	sem_wait(&sem_mutex_agentQueue);
	debug(2, "$f3Passing$f0 through Semaphore $t1sem_mutex_agentQueue $t0(%i)\n", sem_value(sem_mutex_agentQueue));

	// Enqueue the Ticket Number into the Agent Queue
	debug(3, "$f1Enqueuing$f0 Ticket Number $t1%i$t0 into $t1agentQueue$t0\n", ticket_number);
	agentQueue -> push(ticket_number);

	// Signal the Release of the Agent Queue
	debug(2, "$f2Posting$f0 to Semaphore $t1sem_mutex_agentQueue $t0(%i)\n", sem_value(sem_mutex_agentQueue));
	sem_post(&sem_mutex_agentQueue);

	// Print the Calling of the Customer
	debug(0, "Calling Ticket Number: %i$t0\n", ticket_number);

	// Signal the Customer that it has been called
	debug(1, "$f2Posting$f0 to Semaphore $t1sem_announcer_callCustomer[%i] $t0(%i)\n", ticket_number, sem_value(sem_announcer_callCustomer[ticket_number]));
	sem_post(&sem_announcer_callCustomer[ticket_number]);
}

//* Accessor Methods *//
// Returns the Ticket Number of the Announcer
int Announcer::getTicketNumber()
{
	return this -> ticket_number;
}

//* Debug Methods *//
// Calls the Debugger
void Announcer::debug(int access, string message, ...)
{
	if(access > debugger -> getDebugMode())
		return;

	va_list args;
	va_start(args, message);
	va_end(args);

	debugger -> debug(access, "$t1 + $t0$f6[Announcer]$f0: " + message, args);
	sleep(1);
}

// Returns the Debug Mode
int Announcer::getDebugMode()
{
	return debugger -> getDebugMode();
}

// Sets the Debug Mode
int Announcer::setDebugMode(int debug_mode)
{
	return debugger -> setDebugMode(debug_mode);
}

//* End of Header Definition *//
#endif
