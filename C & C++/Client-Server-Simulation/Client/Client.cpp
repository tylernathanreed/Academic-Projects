//* Description *//
// Title: Client
// Author: Tyler Reed
// Defines the Client portion of the Project

//* Libraries *//
#include <iostream>
#include "Client.h"

//* Namespaces *//
using namespace std;
using namespace ITOA;
using namespace HTOB;

//* Type Definitions *//
typedef unsigned char byte;

//* Static Variables *//
Debug* Client::debugger = NULL;
int Client::client_count = 0;

//* Static Methods *//
// Sends a Data Packet to the specified Socket
int Client::send(int socket, void* data, int size)
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
int Client::receive(int socket, void* data, int size)
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
void Client::sendMessage(int socket, string message, bool data = false)
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
string Client::receiveMessage(int socket)
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
void* Client::client_handleServer(void* arg)
{
	// Define Socket Variables
	int socket = *((int*) arg);
	char input;

	do
	{
		// Display the Options
		print("=====================================\n");
		print("Choose one of the following Commands:\n");
		print("-------------------------------------\n");
		print("\t$f4A) $t0Turn Left 90 Degrees\n");
		print("\t$f4B) $t0Turn Right 90 Degrees\n");
		print("\t$f4C) $t0Take a Picture\n");
		print("\t$f4D) $t0Get Current Direction\n");
		print("\t$f4E) $t0Get the Air Temperature\n");
		print("\t$f4F) $t0Exit\n");
		print("-------------------------------------\n");
		print("$f1Enter Choice: $t0");

		cin >> input;
		cout << endl;
		cin.clear();
		string message;

		// Perform the various Actions
		switch(input)
		{
			// Turn Left Command
			case 'A':
			case 'a':
			{
				// Tell the Server to turn the Rover
				sendMessage(socket, "CMD TURN LEFT");

				// Report the new Direction
				message = receiveMessage(socket);
				print("The Rover has turned $t1Left$t0 and is now facing $t1%s$t0\n", message.c_str());
				break;
			}

			// Turn Right Command
			case 'B':
			case 'b':
			{
				// Tell the Server to turn the Rover
				sendMessage(socket, "CMD TURN RIGHT");

				// Report the new Direction
				message = receiveMessage(socket);
				print("The Rover has turned $t1Right$t0 and is now facing $t1%s$t0\n", message.c_str());
				break;
			}

			// Take Picture Command
			case 'C':
			case 'c':
			{
				// Tell the Server to send a Picture
				sendMessage(socket, "CMD PICTURE");

				// Receive the Picture in Hex Format Packets
				string hexString;
				string packet = receiveMessage(socket);

				while(packet != "END OF FILE")
				{
					hexString += packet;
					packet = receiveMessage(socket);
				}

				// Convert the Hexadecimal String into a Byte Array
				int size = hexString.length()/2;
				char* bytes = new char[size + 1];
				bytes[size] = '\0';

				for(int i = 0; i < size; i++)
					bytes[i] = htob(hexString[i*2], hexString[i*2+1]);

				// Export the Picture to the Client's Directory
				ofstream file;
				char path[] = "./Client/Pictures/Picture 0.png";

				file.open(path, std::ofstream::binary);

				// Create a New Numbered File
				for(int i = 0; !file.is_open() && i < 100; i++)
				{
					// Close the Existing File
					file.close();

					// Determine the new Filepath
					sprintf(path, "./Client/Pictures/Picture %i.png", i);
					file.open(path, std::ofstream::binary);
				}

				// Write to the File and Close it
				print("Saved Image to '$t1%s$t0'\n", path);
				file.write(bytes, size);
				file.close();

				break;
			}

			// Get Direction Command
			case 'D':
			case 'd':
			{
				// Ask the Server for the Rover's Direction
				sendMessage(socket, "CMD DIRECTION");

				// Report the Rover's Direction
				message = receiveMessage(socket);
				print("The Rover is facing $t1%s$t0\n", message.c_str());
				break;
			}

			// Get Air Temperature Command
			case 'E':
			case 'e':
			{
				// Ask the Server for a Temperature Reading
				sendMessage(socket, "CMD TEMPERATURE");

				// Report the Reading
				message = receiveMessage(socket);
				print("The Air Temperature at the Rover is $t1%s C$t0\n", message.c_str());
				break;
			}

			// Exit Command
			case 'F':
			case 'f':
			{
				// Tell the Server to Terminate
				sendMessage(socket, "CMD EXIT");

				// Report the Termination
				print("Disconnected from Rover\n");
				break;
			}

			// Unknown Command
			default:
			{
				print("Unknown Command '$t1%c$t0'. Please try again.\n");
				break;
			}
		}

		cout << endl;
	}
	while(input != 'F' && input != 'f');

	// Close the Socket
	debug(1, "Closing Socket $t1%i$t0\n", socket);
	close(socket);
}

