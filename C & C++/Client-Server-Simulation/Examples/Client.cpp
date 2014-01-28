//* Description *//
// Title: Client
// Author: Tyler Reed
// Defines the Client portion of the Example

//* Libraries *//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

//* Definitions *//
#define BUFFER_SIZE 80

//* Main Method *//
int main(int argc, char* argv[])
{
	char hostname[100];
	char buffer[BUFFER_SIZE];
	char name[100];
	int socket_descriptor;
	int port;
	int count;
	struct sockaddr_in socket_info;
	struct hostent *host_info;

	// Check for Command Line Arguments
	if(argc != 3)
	{
		printf("Usage: %s <client> <host> <port>\n", argv[0]);
		exit(1);
	}

	// Get Host Name and Part from Command Line Arguments
	strcpy(hostname, argv[1]);
	port = atoi(argv[2]);

	// Create an Internet Domain Stream Socket
	if((socket_descriptor = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
	{
		perror("Error creating Socket");
		exit(1);
	}

	// Lookup Host Machine Information
	if((host_info = gethostbyname(hostname)) == 0)
	{
		perror("Error on gethostbyname() Call");
		exit(1);
	}

	// Fill the Socket Address Structure with the Host Information
	memset(&socket_info, 0, sizeof(socket_info));
	socket_info.sin_family = AF_INET;
	socket_info.sin_addr.s_addr = ((struct in_addr*) (host_info -> h_addr)) -> s_addr;
	socket_info.sin_port = htons(port);

	// Connect Socket Port to Host
	printf("Connecting to %s:%d\n\n", hostname, port); 

	if(connect(socket_descriptor,(struct sockaddr*) &socket_info, sizeof(socket_info)) == -1)
	{
		perror("Error on connect() Call");
		exit(1);
	}

	// Prompt the User for their Name
	printf("Enter your name: ");
	scanf("%s", name);

	// Send the Name to the Server
	if((count = write(socket_descriptor, name, strlen(name) + 1)) == -1)
	{
		perror("Error on write() Call");
		exit(1);
	}

	// Display sent Byte Count
	printf("Client sent %d Bytes\n", count);

	// Wait for a Message to come back from the Server
	if((count = read(socket_descriptor, buffer, BUFFER_SIZE)) == -1)
	{
		perror("Error on read() Call");
		exit(1);
	}

	// Display received Byte Count
	printf("Client read %d Bytes\n", count);

	// Print the Received Message
	printf("\n\n%s\n\n", buffer);

	// Close the Socket
	close(socket_descriptor);
}

