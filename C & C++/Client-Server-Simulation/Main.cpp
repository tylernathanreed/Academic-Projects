//* Description *//
// Title: Main
// Author: Tyler Reed
// Runs the Program

//* Libraries *//
#include <string>
#include <stdarg.h>
#include "./Server/Server.h"
#include "./Client/Client.h"
#include "./Utilities/Debug.h"

//* Namespaces *//
using namespace std;

//* Global Variables *//
// Debugger
Debug* debugger = new Debug();

//* Function Headers *//
// Network Functions
void runServer(int port);
void runClient(string host, int port);

// Utility Functions
void parseCommandLineArguments(int argc, char* argv[]);

// Debug Functions
void debug(int access, string message, ...);

//* Main Method *//
int main(int argc, char* argv[])
{
	// Parse the Command Line
	parseCommandLineArguments(argc, argv);

	// Delete the Debugger
	delete debugger;

	return 0;
}

//* Network Functions *//
// Runs the Program as a Server
void runServer(int port)
{
	Server* server = new Server(port, debugger -> getDebugMode());

	delete server;
}

// Runs the Program as a Client
void runClient(string host, int port)
{
	Client* client = new Client(host, port, debugger -> getDebugMode());

	delete client;
}

//* Utility Functions *//
// Parses the Command Line Arguments
void parseCommandLineArguments(int argc, char* argv[])
{
	// Initialize Flags
	bool server = false;
	bool client = false;

	// Connection Variables
	string host;
	int port;

	// Loop through all Arguments
	for(int i = 0; i < argc; i++)
	{
		// Check for Argument Flag
		if(argv[i][0] == '-')
		{
			// Determine the Argument
			switch(argv[i][1])
			{
				// Server Argument
				case 's':
					server = true;

					// Make sure another Argument Exists
					if(i == argc - 1)
					{
						debug(0, "$f1Error: $f0Server must be specified with a Port Number\n");
						exit(1);
					}

					port = atoi(argv[++i]);
					break;

				// Client Argument
				case 'c':
					client = true;

					// Make sure another Two Arguments Exist
					if(i >= argc - 2)
					{
						debug(0, "$f1Error: $f0Client must be specified with a Host Name and Port Number\n");
						exit(1);
					}

					host = argv[++i];
					port = atoi(argv[++i]);
					break;

				// Debug Argument
				case 'd':
					// Make sure another Argument Exists
					if(i == argc - 1)
					{
						debug(0, "$f1Error: $f0Debug Mode must be specified with an Access Level\n");
						exit(1);
					}

					debugger -> setDebugMode(atoi(argv[++i]));
					break;

				// Unknown Argument
				default:
					debug(0, "$f1Error: $f0Unknown Argument '$f0%c$f1'\n", &argv[i][1]);
					exit(1);
					break;
			}
		}
	}

	// Make sure either Server or Client was specified
	if(!server && !client)
	{
		debug(0, "$f1Error: $f0Program must be specified as Server (-s) or Client (-c)\n");
		exit(1);
	}

	// Make sure that Server and Client were not both specified
	if(server && client)
	{
		debug(0, "$f1Error: $f0Program may not be specified as both Server and Client\n");
		exit(1);
	}

	// Determine how to Run the Program
	if(server)
		runServer(port);
	else
		runClient(host, port);
}

//* Debug Functions *//
// Calls the Debugger
void debug(int access, string message, ...)
{
	if(access > debugger -> getDebugMode())
		return;

	va_list args;
	va_start(args, message);
	va_end(args);

	string prefix = "$t1 + $t0$f4[Main]$t0: ";

	debugger -> debug(access, prefix + message, args);
}
