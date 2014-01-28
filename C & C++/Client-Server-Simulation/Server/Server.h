//* Description *//
// Title: Server
// Author: Tyler Reed
// Defines the Server portion of the Project

//* Header Definition *//
#ifndef SERVER_H
#define SERVER_H

//* Libraries *//
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "Utilities.h"
#include "Rover.h"

//* Namespaces *//
using namespace std;

//* Server Class *//
class Server
{
	//* Class Variables *//
	// Private Variables
	private:
		// Connection Variables
		char host_name[SIZE_HOST];
		int port;
		int socket_descriptor;
		int address_length;
		struct sockaddr_in socket_information;
		struct sockaddr_in port_information;

		// Debug Variables
		static Debug* debugger;
		static int server_count;

	//* Class Methods *//
	// Public Methods
	public:
		// Constructors and Destructor
		Server(int port, int debug_mode);
		~Server();

	// Private Methods
	private:
		// Connection Methods
		void connectToPort();
		static int send(int socket, void* data, int size);
		static int receive(int socket, void* data, int size);
		static void sendMessage(int socket_descriptor, string message, bool data);
		static string receiveMessage(int socket_descriptor);
		static void* server_handleClient(void*);

		// Debug Methods
		static void debug(int access, string message, ...);
		static void debug(int access, string message, va_list args);
		static void print(string message, ...);
};

//* Constructors *//
// Creates a Server connected to the specified Port
inline Server::Server(int port, int debug_mode = 0)
{
	// Set the Port
	this -> port = port;

	// Create the Debugger if it does not already Exist
	if(debugger == NULL)
		debugger = new Debug(debug_mode);
	else
		debugger -> setDebugMode(debug_mode);

	// Increase the Server Count
	server_count++;

	// Connect to the specified Port
	connectToPort();
}

//* Destructor *//
// Deletes the Server
inline Server::~Server()
{
	// Close the Socket
	close(socket_descriptor);

	// Decrease the Server Count
	server_count--;

	// Delete the Debugger if this is the Last Server
	if(server_count == 0)
		delete debugger;
}

//* Connection Methods *//
// Creates the Server Connection
inline void Server::connectToPort()
{
	// Create an Internet Domain Socket Stream
	if((socket_descriptor = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		print("$f1Error: $f0Unable to create Socket\n");
		delete this;
	}
	else
		debug(1, "Connected to Socket $t1%i$t0\n", socket_descriptor);

	// Fill the Socket Address Structure
	memset(&socket_information, 0, sizeof(socket_information));
	socket_information.sin_family = AF_INET;
	socket_information.sin_addr.s_addr = INADDR_ANY;
	socket_information.sin_port = htons(port);

	// Bind the Socket to the Address and Port Number
	if(bind(socket_descriptor, (struct sockaddr*) &socket_information, sizeof(socket_information)) == -1)
	{
		print("$f1Error: $f0Unable to bind Connection to Socket\n");
		print("\t$t1->$t0 Family: $t1%i$t0\n", socket_information.sin_family);
		print("\t$t1->$t0 Port: $t1%hu$t0\n", ntohs(socket_information.sin_port));
		print("\t$t1->$t0 Address: $t1%lu$t0\n", socket_information.sin_addr.s_addr);

		delete this;
		exit(1);
	}

	// Set the Client Limit
	if(listen(socket_descriptor, LIMIT_CLIENT) == -1)
	{
		print("$f1Error: $f0Client was not Accepted\n");
		exit(1);
	}

	// Announce that the Server is Running
	gethostname(host_name, SIZE_HOST);
	print("Running on $t1%s:%i$t0\n", host_name, port);

	// Define the Thread Attribute
	//pthread_attr_t thread_attribute;
	//pthread_attr_init(&thread_attribute);
	//pthread_attr_setdetachstate(&thread_attribute, PTHREAD_CREATE_DETACHED);

	// Wait for a Client to Connect
	address_length = sizeof(port_information);

	// Loop Indefinately
	while(true)
	{
		// Accept pending Connections
		int sd_current = accept(socket_descriptor, (struct sockaddr*) &port_information, (socklen_t*) &address_length);

		// Make sure the Connection was Accepted
		if(sd_current == -1)
		{
			print("$f1Error: $f0Connection was not Accepted\n");
			exit(1);
		}
		else
			print("Connection $t1%i$t0 was Accepted\n", sd_current);

		int *sd_client = (int*) (malloc(sizeof(sd_current)));
		*sd_client = sd_current;

		// Create a Thread for the Client
		pthread_t thread_id;
		pthread_create(&thread_id, NULL, server_handleClient, sd_client);
		//pthread_create(&thread_id, &thread_attribute, server_handleClient, sd_client);

		// Join and Break if only allowing one Client
		//int detachState;
		//pthread_attr_getdetachstate(&thread_attribute, &detachState);

		// Check the Detach State (if threads are not required to join back, multiple clients are being allowed)
		//if(detachState != PTHREAD_CREATE_DETACHED)
		//{
			int* status = NULL;

			// Attempt to Join with the Thread
			if(pthread_join(thread_id, (void**) &status))
			{
				print("$f1Error: $f0Failed to join Thread\n");
				exit(0);
			}

			// Check the Status of the Thread
			if(!status || *status != 0)
			{
				// Make sure that status points to something before referencing it
				if(status)
					print("$f1Error: $f0Thread Terminated Abnormally with status: %i\n", *status);
				else
					print("$f1Error: $f0Thread Terminated Abnormally without status");

				exit(0);
			}
			else
				debug(1, "Joined Thread\n");

			break;
		//}
	}
}

//* Debug Methods *//
// Prints a Debug Message to the Console
inline void Server::debug(int access, string message, ...)
{
	// Interpret Variable List
	va_list args;
	va_start(args, message);
	va_end(args);

	// Call the Debugger with the Variable List
	debug(access, message, args);
}

// Prints a Debug Message to the Console
inline void Server::debug(int access, string message, va_list args)
{
	// Set the Message Prefix
	string prefix = "$t1 + $t0$f2[Server]$f0: ";

	// Call the Debugger
	debugger -> debug(access, prefix + message, args);
}

// Prints a Formatted Message to the Console
inline void Server::print(string message, ...)
{
	// Interpret Variable List
	va_list args;
	va_start(args, message);
	va_end(args);

	// Call the Debugger with Default Access
	debug(0, message, args);
}

//* End of Header Definition *//
#endif
