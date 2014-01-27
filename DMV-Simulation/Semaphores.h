//* Description *//
// Title: Semaphores
// Author: Tyler Reed
// Defines all of the Semaphore Values

//* Header Definition *//
#ifndef SEMAPHORES_H
#define SEMAPHORES_H

//* Libraries *//
#include <semaphore.h>
#include <stdarg.h>
#include "Debug.h"
#include "Definitions.h"

//* Namespace *//
namespace Semaphore
{
	//* Namespace Variables *//
	// Main Semaphores
	static sem_t sem_main_terminate;

	// Capacity Semaphores
	static sem_t sem_informationLine;
	static sem_t sem_agentLine;

	// Customer Semaphores
	static sem_t sem_customer_arriveAtInformationLine;
	static sem_t sem_customer_arriveAtWaitingArea;
	static sem_t sem_customer_arriveAtAgentLine;
	static sem_t sem_customer_arriveAtAgent[COUNT_CUSTOMER];
	static sem_t sem_customer_takeExam[COUNT_CUSTOMER];
	static sem_t sem_customer_takeLicense[COUNT_CUSTOMER];
	static sem_t sem_customer_leaveDMV[COUNT_CUSTOMER];

	// Information Desk Semaphores
	static sem_t sem_informationDesk_callCustomer[COUNT_CUSTOMER];

	// Announcer Semaphores
	static sem_t sem_announcer_callCustomer[COUNT_CUSTOMER];

	// Agent Semaphores
	static sem_t sem_agent_callCustomer[COUNT_CUSTOMER];
	static sem_t sem_agent_giveExam[COUNT_CUSTOMER];
	static sem_t sem_agent_giveLicense[COUNT_CUSTOMER];

	// Mutual Exclusion Semaphores
	static sem_t sem_mutex_customerCount;
	static sem_t sem_mutex_agentCount;
	static sem_t sem_mutex_customersProcessed;
	static sem_t sem_mutex_informationQueue;
	static sem_t sem_mutex_waitingAreaQueue;
	static sem_t sem_mutex_agentQueue;

	//* Namespace Methods *//
	// Returns the Value of the Semaphore
	inline int sem_value(sem_t semaphore)
	{
		int value;
		sem_getvalue(&semaphore, &value);
		return value;
	}

	// Initializes all of the Semaphores
	inline void initializeSemaphores(Debug* debugger)
	{
		debugger -> debug(1, "$f4[Main]$f0: Initializing Semaphores$t0\n");

		//* Main Semaphores *//
		// Initialize sem_main_terminate
		if(sem_init(&sem_main_terminate, 0, 0) == -1)
			debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_main_terminate$t0\n");

		//* Capacity Semaphores *//
		// Initialize sem_informationLine
		if(sem_init(&sem_informationLine, 0, LINE_LIMIT_INFORMATION) == -1)
			debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_informationLine$t0\n");

		// Initialize sem_agentLine
		if(sem_init(&sem_agentLine, 0, LINE_LIMIT_AGENT) == -1)
			debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_agentLine$t0\n");

		//* Customer Semaphores *//
		// Initialize sem_customer_arriveAtInformationLine
		if(sem_init(&sem_customer_arriveAtInformationLine, 0, 0) == -1)
			debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_customer_arriveAtInformationLine$t0\n");

		// Initialize sem_customer_arriveAtWaitingArea
		if(sem_init(&sem_customer_arriveAtWaitingArea, 0, 0) == -1)
			debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_customer_arriveAtWaitingArea$t0\n");

		// Initialize sem_customer_arriveAtAgentLine
		if(sem_init(&sem_customer_arriveAtAgentLine, 0, 0) == -1)
			debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_customer_arriveAtAgentLine$t0\n");

		// Initialize sem_customer_arriveAtAgent[COUNT_CUSTOMER]
		for(int i = 0; i < COUNT_CUSTOMER; i++)
			if(sem_init(&sem_customer_arriveAtAgent[i], 0, 0) == -1)
				debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_customer_arriveAtAgent[%i]$t0\n", i);

		// Initialize sem_customer_takeExam[COUNT_CUSTOMER]
		for(int i = 0; i < COUNT_CUSTOMER; i++)
			if(sem_init(&sem_customer_takeExam[i], 0, 0) == -1)
				debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_customer_takeExam[%i]$t0\n", i);

		// Initialize sem_customer_takeLicense[COUNT_CUSTOMER]
		for(int i = 0; i < COUNT_CUSTOMER; i++)
			if(sem_init(&sem_customer_takeLicense[i], 0, 0) == -1)
				debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_customer_takeLicense[%i]$t0\n", i);

		// Initialize sem_customer_leaveDMV[COUNT_CUSTOMER]
		for(int i = 0; i < COUNT_CUSTOMER; i++)
			if(sem_init(&sem_customer_leaveDMV[i], 0, 0) == -1)
				debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_customer_leaveDMV[%i]$t0\n", i);

		//* Information Desk Semaphores *//
		// Initialize sem_informationDesk_callCustomer[COUNT_CUSTOMER]
		for(int i = 0; i < COUNT_CUSTOMER; i++)
			if(sem_init(&sem_informationDesk_callCustomer[i], 0, 0) == -1)
				debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_informationDesk_callCustomer[%i]$t0\n", i);

		//* Announcer Semaphores *//
		// Initialize sem_announcer_callCustomer[COUNT_CUSTOMER]
		for(int i = 0; i < COUNT_CUSTOMER; i++)
			if(sem_init(&sem_announcer_callCustomer[i], 0, 0) == -1)
				debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_announcer_callCustomer[%i]$t0\n", i);

		//* Agent Semaphores *//
		// Initialize sem_agent_callCustomer[COUNT_CUSTOMER]
		for(int i = 0; i < COUNT_CUSTOMER; i++)
			if(sem_init(&sem_agent_callCustomer[i], 0, 0) == -1)
				debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_agent_callCustomer[%i]$t0\n", i);
		// Initialize sem_agent_giveExam[COUNT_AGENT]
		for(int i = 0; i < COUNT_AGENT; i++)
			if(sem_init(&sem_agent_giveExam[i], 0, 0) == -1)
				debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_agent_giveExam[%i]$t0\n", i);

		// Initialize sem_agent_giveLicense[COUNT_AGENT]
		for(int i = 0; i < COUNT_AGENT; i++)
			if(sem_init(&sem_agent_giveLicense[i], 0, 0) == -1)
				debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_agent_giveLicense[%i]$t0\n");

		//* Mutual Exclusion Semaphores *//
		// Initialize sem_mutex_customerCount
		if(sem_init(&sem_mutex_customerCount, 0, 1) == -1)
			debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_mutex_customerCount$t0\n");

		// Initialize sem_mutex_agentCount
		if(sem_init(&sem_mutex_agentCount, 0, 1) == -1)
			debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_mutex_agentCount$t0\n");

		// Initialize sem_mutex_customersProcessed
		if(sem_init(&sem_mutex_customersProcessed, 0, 1) == -1)
			debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_mutex_customersProcessed$t0\n");

		// Initialize sem_mutex_informationQueue
		if(sem_init(&sem_mutex_informationQueue, 0, 1) == -1)
			debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_mutex_informationQueue$t0\n");

		// Initialize sem_mutex_waitingAreaQueue
		if(sem_init(&sem_mutex_waitingAreaQueue, 0, 1) == -1)
			debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_mutex_waitingAreaQueue$t0\n");

		// Initialize sem_mutex_agentQueue
		if(sem_init(&sem_mutex_agentQueue, 0, 1) == -1)
			debugger -> debug(-1, "$f4[Main]$f0: $f1Unable to create Semaphore $t1$f0sem_mutex_agentQueue$t0\n");

	}
}

//* End of Header Definition *//
#endif
