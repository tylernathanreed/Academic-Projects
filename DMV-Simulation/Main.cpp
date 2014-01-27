//* Description *//
// Title: Main
// Author: Tyler Reed
// Simulates the DMV

//* Libraries *//
#include <queue>
#include "Debug.h"
#include "Customer.h"
#include "Definitions.h"
#include "Semaphores.h"
#include "Threads.h"

//* Namespaces *//
using namespace std;
using namespace Thread;
using namespace Semaphore;

//* Global Variables *//
// Tracking Variables
int customer_count = 0;
int agent_count = 0;
int customers_processed = 0;

queue<Customer*> *informationQueue;
queue<int> *waitingAreaQueue;
queue<int> *agentQueue;

// Debug Variables
int debug_main = 0;
Debug* debugger;

//* Function Headers *//
// Utility Methods
void initialize(int argc, char* argv[]);
void parseCommandLineArguments(int argc, char* argv[]);

//* Main Method *//
int main(int argc, char* argv[])
{
	// Initialize the Debugger and interpret the Command Line
	initialize(argc, argv);

	//* Create Simulation Resources *//
	debugger -> debug(1, "$f4[Main]$f0: Allocating Resources$t0\n");
	createThreads(debugger);

	// Create the Queues
	informationQueue = new queue<Customer*>();
	waitingAreaQueue = new queue<int>();
	agentQueue = new queue<int>();

	//* Delete Simulation Resources *//
	joinThreads(debugger);

	//* Simuluation Cleanup *//
	debugger -> debug(1, "$f4[Main]$f0: Freeing Resources$t0\n");

	// Delete the Main Debugger
	delete debugger;

	// Delete the Queues
	delete informationQueue;
	delete waitingAreaQueue;
	delete agentQueue;

	return 0;
}

//* Utility Methods *//
// Initializes the Debugger and Interprets the Command Line
void initialize(int argc, char* argv[])
{
	// Create the Main Debugger
	debugger = new Debug(debug_main);

	// Parse Command Line Arguments
	parseCommandLineArguments(argc, argv);
	debugger -> setDebugMode(debug_main);

	// Initialize the Semaphores
	initializeSemaphores(debugger);
}


// Parses the Command Line Arguments
void parseCommandLineArguments(int argc, char* argv[])
{
	// Loop through all Arguments
	for(int i = 0; i < argc; i++)
	{
		// Check for Argument Flag
		if(argv[i][0] == '-')
		{
			// Determine the Argument
			switch(argv[i][1])
			{
				// Debug Argument
				case 'd':
				{
					// Determine the Debug Values for each Class
					switch(argv[i][2])
					{

						// Customer
						case 'C':
							debug_customer = atoi(argv[++i]);
							break;

						// Information Desk
						case 'I':
							debug_informationDesk = atoi(argv[++i]);
							break;

						// Announcer
						case 'A':
							debug_announcer = atoi(argv[++i]);
							break;

						// Agent
						case 'G':
							debug_agent = atoi(argv[++i]);
							break;

						// Main
						case 'M':
							debug_main = atoi(argv[++i]);
							break;

						// Unknown Class Type
						default:
							debugger -> debug(0, "$t1$f1Unknown Class Type '$f0%c$f1'!$t0\n\t$t1$f0-> $f4Applicable Class Types are: C ($f0Customer$f4), I ($f0Information Desk$f4), A ($f0Announcer$f4), G ($f0Agent$f4), M ($f0Main$f4)$t0\n", &argv[i][2]);
							break;

					}

					break;
				}

				// Unknown Argument
				default:
					debugger -> debug(0, "$t1$f1Unknown Argument '$f0%c)$f1'!\n\t$f0-> $f4Applicable Arguments are: -dX <$f5Value$f4> ($f0Debug with Type X$f4)$t0\n", &argv[i][1]);
					break;
			}
		}
	}
}

