//* Description *//
// Title: Client
// Author: Tyler Reed
// Defines the Client portion of the Project

//* Header Definition *//
#ifndef CLIENT_H
#define CLIENT_H

//* Libraries *//
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "Utilities.h"

//* Namespaces *//
using namespace std;

//* Client Class *//
class Client
{
	//* Class Variables *//
	// Private Variables
	private:
		// Connection Variables
		string host;
		int port;
		int socket_descriptor;
		int address_length;
		struct sockaddr_in socket_information;
		struct hostent* host_information;

		// Debug Variables
		static Debug* debugger;
		static int client_count;

	//* Class Methods *//
	// Public Methods
	public:
		// Constructors and Destructor
		Client(string host, int port, int debug_mode);
		~Client();

		// Connection Methods
		void connectToServer();
		static int send(int socket, void* data, int size);
		static int receive(int socket, void* data, int size);
		static void sendMessage(int socket_descriptor, string message, bool data);
		static string receiveMessage(int socket_descriptor);
		static void* client_handleServer(void* arg);

	// Private Methods
	private:
		// Debug Methods
		static void debug(int access, string message, ...);
		static void debug(int access, string message, va_list args);
		static void print(string message, ...);
};

//* Constructors *//
// Creates a Client connected to the specified Host and Port
inline Client::Client(string host, int port, int debug_mode = 0)
{
	// Set the Host Port
	this -> host = host;
	this -> port = port;

	// Create the Debugger if it does not already Exist
	if(debugger == NULL)
		debugger = new Debug(debug_mode);

	// Increase the Client Count
	client_count++;

	// Connect to the specified Host and Port
	connectToServer();
}

//* Destructor *//
// Deletes the Client
inline Client::~Client()
{
	// Close the Socket
	close(socket_descriptor);

	// Decrease the Client Count
	client_count--;

	// Delete the Debugger if this is the Last Client
	if(client_count == 0)
		delete debugger;
}

//* Connection Methods *//
// Creates the Client Connection
inline void Client::connectToServer()
{
	// Create an Internet Domain Stream Socket
	if((socket_descriptor = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
	{
		print("$f1Error: $f0Unable to create Socket\n");
		exit(1);
	}
	else
		debug(1, "Created Socket $t1%i$t0\n", socket_descriptor);

	// Lookup Host Machine Information
	if((host_information = gethostbyname(host.c_str())) == 0)
	{
		print("$f1Error: $f0Unable to get Host Name\n");
		exit(1);
	}

	// Fill the Socket Address Structure with the Host Information
	memset(&socket_information, 0, sizeof(socket_information));
	socket_information.sin_family = AF_INET;
	socket_information.sin_addr.s_addr = ((struct in_addr*) (host_information -> h_addr)) -> s_addr;
	socket_information.sin_port = htons(port);

	// Connect Socket Port to Host
	print("Connected to $t1%s:%i$t0\n", host.c_str(), port); 

	if(connect(socket_descriptor,(struct sockaddr*) &socket_information, sizeof(socket_information)) == -1)
	{
		print("$f1Error: $f0Unable to connect to Socket $t1%i$t0\n", socket_descriptor);
		exit(1);
	}
	else
		debug(1, "Connected to Socket $t1%i$t0\n", socket_descriptor);

	// Interact with the Server
	client_handleServer(&socket_descriptor);
}

//* Debug Methods *//
// Prints a Debug Message to the Console
inline void Client::debug(int access, string message, ...)
{
	// Interpret Variable List
	va_list args;
	va_start(args, message);
	va_end(args);

	// Call the Debugger with the Variable List
	debug(access, message, args);
}

// Prints a Debug Message to the Console
inline void Client::debug(int access, string message, va_list args)
{
	// Set the Message Prefix
	string prefix = "$t1 + $t0$f2[Client]$f0: ";

	// Call the Debugger
	debugger -> debug(access, prefix + message, args);
}

// Prints a Formatted Message to the Console
inline void Client::print(string message, ...)
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
