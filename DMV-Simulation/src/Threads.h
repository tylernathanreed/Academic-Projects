//* Description *//
// Title: Threads
// Author: Tyler Reed
// Creates all of the Threads

//* Header Definition *//
#ifndef THREADS_H
#define THREADS_H

//* Libraries *//
//#include <queue>
#include <pthread.h>
#include <stdarg.h>
#include "Definitions.h"
#include "Debug.h"
#include "Semaphores.h"
#include "Customer.h"
#include "InformationDesk.h"
#include "Announcer.h"
#include "Agent.h"

//* Global Variables *//
//extern int customer_count;
extern int customers_processed;

//extern queue<Customer*> *informationQueue;
//extern queue<int> *waitingAreaQueue;
//extern queue<int> *agentQueue;

//* Namespaces *//
using namespace Semaphore;

//* Namespace *//
namespace Thread
{
	//* Namespace Variables *//
	// Thread Variables
	static pthread_t thread_customer[COUNT_CUSTOMER];
	static pthread_t thread_agent[COUNT_AGENT];
	static pthread_t thread_informationDesk;
	static pthread_t thread_announcer;

	// Resources
	static Customer* customer[COUNT_CUSTOMER];
	static InformationDesk* informationDesk;
	static Announcer* announcer;
	static Agent* agent[COUNT_AGENT];

	// Debug Variables
	static int debug_customer;
	static int debug_informationDesk;
	static int debug_announcer;
	static int debug_agent;

	//* Simulation Methods *//
	// Simulates the Customer
	inline void* simulate_customer(void* arg)
	{
		Customer* temp = new Customer(debug_customer);

		// Arrive at the DMV
		temp -> arriveAtDMV();

		// Set the ID of the Customer
		int id = temp -> getID();
		customer[id] = temp;

		// Arrive at the Information Line
		customer[id] -> arriveAtInformationLine();

		// Arrive at the Waiting Area
		customer[id] -> arriveAtWaitingArea();

		// Arrive at the Agent Line
		customer[id] -> arriveAtAgentLine();

		// Arrive at the Agent
		customer[id] -> arriveAtAgent();

		// Take the Exam
		customer[id] -> takeExam();

		// Take the License
		customer[id] -> takeLicense();

		// Leave the DMV
		customer[id] -> leaveDMV();

		delete customer[id];
	}

	// Simulates the Information Desk
	inline void* simulate_informationDesk(void* arg)
	{
		informationDesk = new InformationDesk(debug_informationDesk);

		// Loop until all Customers have been called
		for(int i = 0; i < COUNT_CUSTOMER; i++)
		{
			// Call the Next Customer
			informationDesk -> callCustomer();
		}

		delete informationDesk;
	}

	// Simulates the Announcer
	inline void* simulate_announcer(void* arg)
	{
		announcer = new Announcer(debug_announcer);

		// Loop until all Customer have been called
		for(int i = 0; i < COUNT_CUSTOMER; i++)
		{
			// Call the Next Customer
			announcer -> callCustomer();
		}

		delete announcer;
	}

	// Simulates the Agent
	inline void* simulate_agent(void* arg)
	{
		Agent* temp = new Agent(debug_agent);

		// Determine the ID of the Agent
		int id = temp -> getID();
		agent[id] = temp;

		// Loop Indefinitely
		//while(customer_count != COUNT_CUSTOMER || informationQueue -> size() != 0
		//	|| waitingAreaQueue -> size() != 0 || agentQueue -> size() != 0)
		while(customers_processed < COUNT_CUSTOMER)
		{
			// Call the Next Customer
			agent[id] -> callCustomer();

			// Give the Customer an Exam
			agent[id] -> giveExam();

			// Give the Customer a License
			agent[id] -> giveLicense();

			// Wait for the Customer to Leave the DMV
			agent[id] -> waitToLeave();
		}

		// Terminate the Program
		agent[id] -> debug(1, "$f2Posting$f0 to Semaphore $t1sem_main_terminate $t0(%i)\n", sem_value(sem_main_terminate));
		sem_post(&sem_main_terminate);

		//delete agent[id];
	}

	//* Thread Methods
	// Creates all of the Threads used in the Simulation
	inline void createThreads(Debug* debugger)
	{
		// Create the Customer Threads
		for(int i = 0; i < COUNT_CUSTOMER; i++)
		{
			if(pthread_create(&thread_customer[i], NULL, simulate_customer, NULL))
			{
				debugger -> debug(0, "$f1Could not create Customer Thread %i$t0\n", i);
				exit(0);
			}
		}

		// Create the Agent Threads
		for(int i = 0; i < COUNT_AGENT; i++)
		{
			if(pthread_create(&thread_agent[i], NULL, simulate_agent, NULL))
			{
				debugger -> debug(0, "$f1Could not create Agent Thread %i$t0\n", i);
				exit(0);
			}
		}

		// Create the Information Desk Thread
		if(pthread_create(&thread_informationDesk, NULL, simulate_informationDesk, NULL))
		{
			debugger -> debug(0, "$f1Could not create Information Desk Thread$t0\n");
			exit(0);
		}

		// Create the Announcer Thread
		if(pthread_create(&thread_announcer, NULL, simulate_announcer, NULL))
		{
			debugger -> debug(0, "$f1Could not create Announcer Thread$t0\n");
			exit(0);
		}
	}

	// Removes all of the Threads used in the Simulation
	inline void joinThreads(Debug* debugger)
	{
		int* status;

		// Join the Information Desk Thread
		if(pthread_join(thread_informationDesk, (void**) &status))
		{
			debugger -> debug(0, "$f1Failed to Join $f0$t1Information Desk$t0$f1 Thread$t0\n");
			exit(0);
		}

		// Check the Status of the Information Desk Thread
		if(*status != 0)
		{
			debugger -> debug(0, "$f1Thread $f0$t1Information Desk$t0$f1 Terminated Abnormally with status: %i$t0\n", *status);
			exit(0);
		}
		else
			debugger -> debug(1, "$f4[Main | Thread]$f0: Joined Thread $t1Information Desk$t0\n");

		// Join the Announcer Thread
		if(pthread_join(thread_announcer, (void**) &status))
		{
			debugger -> debug(0, "$f1Failed to Join $f0$t1Announcer$t0$f1 Thread$t0\n");
			exit(0);
		}

		// Check the Status of the Information Desk Thread
		if(*status != 0)
		{
			debugger -> debug(0, "$f1Thread $f0$t1Announcer$t0$f1 Terminated Abnormally with status: %i$t0\n", *status);
			exit(0);
		}
		else
			debugger -> debug(1, "$f4[Main | Thread]$f0: Joined Thread $t1Announcer$t0\n");

		// Cycle through all Customer Threads
		for(int i = 0; i < COUNT_CUSTOMER; i++)
		{
			// Join with each Thread
			if(pthread_join(thread_customer[i], (void**) &status))
			{
				debugger -> debug(0, "$f1Failed to Join $f0$t1Customer %i$t0$f1 Thread$t0\n", i);
				exit(0);
			}

			// Check the Status of Each Thread
			if(*status != 0)
			{
				debugger -> debug(0, "$f1Thread $f0$t1Customer %i$t0$f1 Terminated Abnormally with status: %i$t0\n", i, *status);
				exit(0);
			}
			else
				debugger -> debug(1, "$f4[Main | Thread]$f0: Joined Thread $t1Customer %i$t0\n", i);
		}

		// Wait for the Agents to finish Working
		debugger -> debug(1, "$f4[Main | Thread]$f0: $f1Waiting$f0 on Semaphore $t1sem_main_terminate$t0\n");
		sem_wait(&sem_main_terminate);
		debugger -> debug(1, "$f4[Main | Thread]$f0: $f3Passed$f0 through Semaphore $t1sem_main_terminate$t0\n");

		// Cycle through all Agent Threads
		for(int i = 0; i < COUNT_AGENT; i++)
		{
			// Cancel each Thread
			pthread_cancel(thread_agent[i]);

			// Join with each Thread
			//if(pthread_join(thread_agent[i], (void**) &status))
			//{
			//	debugger -> debug(0, "$f1Failed to Join $f0$t1Agent %i$t0$f1 Thread$t0\n", i);
			//	exit(0);
			//}

			// Check the Status of Each Thread
			//if(*status != 0)
			//{
			//	debugger -> debug(0, "$f1Thread $f0$t1Agent %i$t0$f1 Terminated Abnormally with status: %i$t0\n", i, *status);
			//	exit(0);
			//}
			//else
			//	debugger -> debug(1, "$f4[Main | Thread]$f0: Joined Thread $t1Agent %i$t0\n", i);
		}

		// Kill the Agent Objects (Threads and Objects may not be Linked)
		for(int i = 0; i < COUNT_AGENT; i++)
			delete agent[i];
	}
}

//* End of Header Definition *//
#endif
