//* Description *//
// Title: Server
// Author: Tyler Reed
// Defines the Server portion of the Example

//* Libraries *//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>

//* Definitions *//
#define BUFFER_SIZE 80

//* Function Headers *//
void* handleClient(void *);

//* Main Method *//
int main(int argc, char *argv[])
{
	char host_name[80];
	int sd, sd_current;
	int port;
	int *sd_client;
	int addrlen;
	struct sockaddr_in sin;
	struct sockaddr_in pin;
	pthread_t tid;
	pthread_attr_t attr;

	// Check for Command Line Arguments
	if(argc != 2)
	{
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}

	// Get Port from Command Line Arguments
	port = atoi(argv[1]);

	// Create an Internet Domain Socket Stream
	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Error creating Socket");
		exit(1);
	}

	// Fill the Socket Address Structure
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(port);

	// Bind the Socket to the Address and Port Number
	if(bind(sd, (struct sockaddr*) &sin, sizeof(sin)) == -1)
	{
		perror("Error on bind() Call");
		exit(1);
	}

	// Set the Client Limit
	if(listen(sd, 5) == -1)
	{
		perror("Error on listen() Call");
		exit(1);
	}

	// Announce that the Server is Running
	gethostname(host_name, 80); 
	printf("Server is running on %s:%d\n", host_name, port);

	// Wait for a Client to Connect
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	addrlen = sizeof(pin);

	// Loop Indefinately
	while(true)
	{
		// Accept pending Connections
		if((sd_current = accept(sd, (struct sockaddr*) &pin, (socklen_t*) &addrlen)) == -1) 
		{
			perror("Error on accept() call");
			exit(1);
		}

		sd_client = (int*) (malloc(sizeof(sd_current)));
		*sd_client = sd_current;

		// Create a Thread for the Client
		pthread_create(&tid, &attr, handleClient, sd_client);
	}

	// Close the Socket
	close(sd);
}

// Handles Client Connections
void* handleClient(void *arg)
{
	int count = 0;
	char buf[BUFFER_SIZE];
	char temp[BUFFER_SIZE]; 

	// Determine the Socket Descriptor
	int sd = *((int*) arg);
	free(arg);

	// Read a Message from the Client
	if((count = read(sd, buf, sizeof(buf))) == -1)
	{
		perror("read");
		exit(1);
	}

	// Display the Received Byte Count
	printf("Server read %d Bytes\n", count);

	// Print a Message to the User
	sprintf(temp, "Hi %s", buf);	

	// Send a Message back to the Client
	if((count = write(sd, temp, strlen(temp) + 1)) == -1)
	{
		perror("write");
		exit(1);
	}

	// Display the Sent Byte Count
	printf("Server sent %d Bytes\n", count);

	// Close the Socket
	close(sd); 
}
