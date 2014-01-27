//* Description *//
// Title: Information Desk
// Author: Tyler Reed
// Defines the Information Desk Class

//* Header Definition *//
#ifndef INFORMATION_DESK_H
#define INFORMATION_DESK_H

//* Libraries *//
#include <stdarg.h>
#include <queue>
#include <semaphore.h>
#include "Debug.h"
#include "Customer.h"
#include "Semaphores.h"

//* Namespaces *//
using namespace std;
using namespace Semaphore;

//* Global Variables *//
extern queue<Customer*> *informationQueue;
extern queue<int> *waitingAreaQueue;

//* Information Desk Class *//
class InformationDesk
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
		InformationDesk(int debug_mode);
		~InformationDesk();

		// Exclusive Methods
		void callCustomer();

		// Debug Methods
		void debug(int access, string message, ...);
		int getDebugMode();
		int setDebugMode(int debug_mode);
};

//* Constructor *//
// Default Constructor
InformationDesk::InformationDesk(int debug_mode = 0)
{
	// Initialize the Information Desk
	this -> debugger = new Debug(debug_mode);
	this -> ticket_number = 0;

	debug(3, "Object Initialized\n");
}

//* Destructor *//
// Triggered when the Object is called for Deletion
InformationDesk::~InformationDesk()
{
	debug(3, "Object Destroyed\n");

	// Delete the Debugger
	delete debugger;
}

//* Exclusive Methods *//
// Calls a Customer from in Information Line
void InformationDesk::callCustomer()
{
	// Wait for a Customer to enter the Information Line
	debug(1, "$f1Waiting$f0 on Semaphore $t1sem_customer_arriveAtInformationLine $t0(%i)\n", sem_value(sem_customer_arriveAtInformationLine));
	sem_wait(&sem_customer_arriveAtInformationLine);
	debug(1, "$f3Passed$f0 through Semaphore $t1sem_customer_arriveAtInformationLine $t0(%i)\n", sem_value(sem_customer_arriveAtInformationLine));

	// Wait to Secure the Information Queue
	debug(2, "$f1Waiting$f0 on Semaphore $t1sem_mutex_informationQueue $t0(%i)\n", sem_value(sem_mutex_informationQueue));
	sem_wait(&sem_mutex_informationQueue);
	debug(2, "$f3Passed$f0 through Semaphore $t1sem_mutex_informationQueue $t0(%i)\n", sem_value(sem_mutex_informationQueue));

	// Remove the First Customer in the Queue
	debug(3, "$f2Dequeuing$f0 $t1Customer$t0 from $t1informationQueue$t0\n");
	Customer *customer = informationQueue -> front();
	informationQueue -> pop();

	// Signal the Release of the Information Queue
	debug(2, "$f2Posting$f0 to Semaphore $t1sem_mutex_informationQueue $t0(%i)\n", sem_value(sem_mutex_informationQueue));
	sem_post(&sem_mutex_informationQueue);

	// Give the Customer their Ticket
	debug(3, "Giving Ticket Number $t1%i$t0 to Customer $t1%i$t0\n", ticket_number, customer -> getID());
	customer -> setTicketNumber(ticket_number);

	// Wait to Secure the Waiting Area Queue
	debug(2, "$f1Waiting$f0 on Semaphore $t1sem_mutex_waitingAreaQueue $t0(%i)\n", sem_value(sem_mutex_waitingAreaQueue));
	sem_wait(&sem_mutex_waitingAreaQueue);
	debug(2, "$f3Passed$f0 through Semaphore $t1sem_mutex_waitingAreaQueue $t0(%i)\n", sem_value(sem_mutex_waitingAreaQueue));

	// Enqueue the Ticket Number into the Waiting Area Queue
	debug(3, "$f1Enqueuing$f0 Ticket Number $t1%i$t0 into $t1waitingAreaQueue$t0\n", ticket_number);
	waitingAreaQueue -> push(ticket_number++);

	// Signal the Release of the Waiting Area Queue
	debug(2, "$f2Posting$f0 to Semaphore $t1sem_mutex_waitingAreaQueue $t0(%i)\n", sem_value(sem_mutex_waitingAreaQueue));
	sem_post(&sem_mutex_waitingAreaQueue);

	// Print the Calling of the Customer
	debug(0, "Calling next Customer\n");

	// Signal the Customer that it has been called
	int id = customer -> getID();
	debug(1, "$f2Posting$f0 to Semaphore $t1sem_informationDesk_callCustomer[%i] $t0(%i)\n", id, sem_value(sem_informationDesk_callCustomer[id]));
	sem_post(&sem_informationDesk_callCustomer[id]);
}

//* Debug Methods *//
// Calls the Debugger
void InformationDesk::debug(int access, string message, ...)
{
	if(access > debugger -> getDebugMode())
		return;

	va_list args;
	va_start(args, message);
	va_end(args);

	debugger -> debug(access, "$t1 + $t0$f5[Information Desk]$f0: " + message, args);
	sleep(1);
}

// Returns the Debug Mode
int InformationDesk::getDebugMode()
{
	return debugger -> getDebugMode();
}

// Sets the Debug Mode
int InformationDesk::setDebugMode(int debug_mode)
{
	return debugger -> setDebugMode(debug_mode);
}

//* End of Header Definition *//
#endif
