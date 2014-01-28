//* Description *//
// Title: Server
// Author: Tyler Reed
// Defines the Server portion of the Project

//* Libraries *//
#include "Server.h"

//* Namespaces *//
using namespace std;
using namespace ITOA;
using namespace HTOB;

//* Type Definitions *//
typedef unsigned char byte;

//* Static Variables *//
Debug* Server::debugger = NULL;
int Server::server_count = 0;

//* Static Methods *//
// Sends a Data Packet to the specified Socket
int Server::send(int socket, void* data, int size)
{
	// Write the Data to the Socket
	int count = write(socket, data, size);

	// Make sure the Write Succeeded
	if(count == -1)
	{
		print("$f1Error: $f0Unable to Write to Socket $t1%i$t0\n", socket);
		exit(1);
	}

	return count;
}

// Receives at Data Packet from the specified Socket
int Server::receive(int socket, void* data, int size)
{
	// Read the Data from the Socket
	int count = read(socket, data, size);

	// Make sure the Read Succeeded
	if(count == -1)
	{
		print("$f1Error: $f0Unable to Write to Socket $t1%i$t0\n", socket);
		exit(1);
	}

	return count;
}

// Sends a Message to the specified Socket
void Server::sendMessage(int socket, string message, bool data = false)
{
	// Resize the String
	//message.shrink_to_fit(); C++ 11 Only :(

	// Write the Message Size to the Socket
	debug(2, "Writing Size $t1%i$t0 [%i] to Socket $t1%i$t0\n", message.length() + 1, sizeof(size_t), socket);
	send(socket, itoa((message.length() + 1)), sizeof(size_t));

	// Wait for Write Confirmation
	bool response;
	receive(socket, &response, 2);
	debug(3, "Received Write Confirmation from Socket $t1%i$t0\n", response, sizeof(bool), socket);

	// Determine the Type of Data to Send
	if(data)
	{
		// Write the Message Data to the Socket
		debug(2, "Writing Message Data $t1%s$t0 [%i] to Socket $t1%i$t0\n", message.data(), message.length() + 1, socket);
		send(socket, (char*) message.data(), message.length() + 1);
	}
	else
	{
		// Write the Message to the Socket
		debug(2, "Writing Message $t1%s$t0 [%i] to Socket $t1%i$t0\n", message.c_str(), message.length() + 1, socket);
		send(socket, (char*) message.c_str(), message.length() + 1);
	}

	// Wait for Write Confirmation
	receive(socket, &response, 2);
	debug(3, "Received Write Confirmation from Socket $t1%i$t0\n", response, sizeof(bool), socket);
}

// Receives Message from the specified Socket
string Server::receiveMessage(int socket)
{
	// Read the Message Size from the Socket
	char size_c[sizeof(size_t)];
	receive(socket, size_c, sizeof(size_t));
	int size = atoi(size_c);

	debug(2, "Received Size $t1%i$t0 [%i] from Socket $t1%i$t0\n", size, sizeof(size_t), socket);

	// Send Write Confirmation
	debug(3, "Sending Write Confirmation to Socket $t1%i$t0\n", socket);
	send(socket, itoa(true), 2);

	// Receive the Message from the Socket
	char message[size];
	receive(socket, message, size);
	debug(2, "Received Message $t1%s$t0 [%i] from Socket $t1%i$t0\n", message, size, socket);

	// Send Write Confirmation
	debug(3, "Sending Write Confirmation to Socket $t1%i$t0\n", socket);
	send(socket, itoa(true), 2);

	// Return the Message as a String
	string msg(message);
	return msg;
}

// Handles each Client with a Thread 
void* Server::server_handleClient(void* arg)
{
	// Determine the Socket Descriptor
	int socket = *((int*) arg);
	free(arg);

	// Create the Rover
	Rover* rover = new Rover();

	// Loop Indefinitely
	while(true)
	{
		// Wait for a Command
		string command = receiveMessage(socket);

		// Perform the Command
		if(command == "CMD TURN LEFT")
		{
			// Turn the Rover and Send its new Direction
			print("Turning Rover $t1Left\n");
			sendMessage(socket, rover -> turnLeft());
		}
		else if(command == "CMD TURN RIGHT")
		{
			// Turn the Rover and Send its new Direction
			print("Turning Rover $t1Right\n");
			sendMessage(socket, rover -> turnRight());
		}
		else if(command == "CMD PICTURE")
		{
			// Take a Picture
			int size;
			byte* picture = rover -> takePicture(&size);
			print("Sending %s.png\n", rover -> getDirection().c_str());

			// Convert Byte Array to Hexadecimal String
			char hexString[size * 2 + 1];

			for(int i = 0; i < size; i++)
			{
				const char* hex = btoh(picture[i]);
				hexString[i*2] = hex[0];
				hexString[i*2+1] = hex[1];
			}

			hexString[size*2] = '\0';

			// Send the Hex String in Packets
			for(int i = 0; i < size*2; i += 128)
			{
				int packetSize = size*2 - i > 128 ? 128 : size*2 - i;
				char packet[128] = {'\0'};

				for(int j = 0; j < packetSize; j++)
					packet[j] = hexString[i + j];

				sendMessage(socket, packet);
			}

			// Send the End of the Hex string
			sendMessage(socket, "END OF FILE");
		}
		else if(command == "CMD DIRECTION")
		{
			// Send the Rover's Direction
			print("Sending Rover Direction ($t1%s$t0)\n", rover -> getDirection().c_str());
			sendMessage(socket, rover -> getDirection());
		}
		else if(command == "CMD TEMPERATURE")
		{
			// Send an Air Temperature Reading
			print("Sending Air Temperature Reading\n");
			sendMessage(socket, (string) itoa(rover -> getAirTemperature()));
		}
		else if(command == "CMD EXIT")
		{
			// Terminate the Server
			print("Terminating Server\n");
			break;
		}
		else
			print("$f1Error: $f0Unknown Command\n");
	}

	// Delete the Rover
	delete rover;

	// Close the Socket
	debug(1, "Closing $t1%i$t0\n", socket);
	close(socket);

	// Return a Successful Status
	return (void*) new int(0);
}

