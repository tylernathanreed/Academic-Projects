//* Description *//
// Title: Data Link Layer
// Author: Tyler Reed
// Defines the Data Link Layer of a Node

//* Notes *//
// The Data Link Layer is responsible for Reading and Writing
// Messages from and to Channels (from[X]to[X].txt).

//* Libraries *//
#include "Node.h"

//* Data Link Methods *//
// Reads and Returns the Contents of the specified Channel
string Node::DataLink_readFromChannel(int channel)
{
	debugL(4, "Data Link | Channel", "Reading from Channel $f1%i$f0\n", channel);

	// Make sure the Channel Exists
	if(readers -> find(channel) == readers -> end())
	{
		debugL(1, "Data Link | Channel", "Missing Requested Reader Channel $f1%i$f0\n", channel);
		return "";
	}

	return (readers -> at(channel)) -> readMessage();
}

// Writes the Message to the specified Channel
void Node::DataLink_writeToChannel(string message, int channel)
{
	debugL(4, "Data Link | Channel", "Writing to '$t1%s$t0' to Channel $f1%i$f0\n", message.c_str(), channel);

	// Make sure the Channel Exists
	if(writers -> find(channel) == writers -> end())
	{
		debugL(1, "Data Link | Channel", "Missing Requested Writer Channel $f1%i$f0 {Message = '$f1%s$f0'}\n", channel, message.c_str());
		return;
	}

	(writers -> at(channel)) -> writeMessage(message);
}

// Returns the Check Sum (Modulo 100) of the specified Message
int Node::DataLink_getCheckSum(string message)
{
	// Initialize the Sum
	int sum = 0;

	debugL(4, "Data Link", "Performing Checksum for '$f1%s$f0'\n", message.c_str());

	// Determine the ASCII Sum of the Message
	for(int i = 0; i < message.length(); i++)
	{
		debugL(4, "Data Link", " -> [%i]: '$f1%c$f0': $f1%i$f0 {$f1%i$f0 -> $f1%i$f0}\n", i, message[i], (int) message[i], sum, sum + (int) message[i]);
		sum += (int) message[i];
	}

	// Determine the Sum Modulo 100
	int mod = sum % 100;

	// Only use Positive Values
	while(mod < 0)
		mod += 100;

	debugL(4, "Data Link", " -> Final Value: $f1%i$f0\n", mod);

	// Return the Checksum
	return mod;
}

// Packages and Returns the specified Network Message
string Node::DataLink_packageNetworkMessage(string message)
{
	// Data Messages are of the Form:
	// S [1] + Size [2] + Payload [Size - 3] + Check Sum [2]
	// where the specified Message is the Payload

	debugL(2, "Data Link | Packager", "$f5Packaging Message '$f0%s$f5'\n", message.c_str());

	// Create the Package Stream
	stringstream ss;
	ss << "S" << message.length() + 5 << message;

	// Determine the Check Sum
	int checksum = DataLink_getCheckSum(ss.str());

	// Add the Check Sum to the Stream
	ss << setw(2) << setfill('0') << checksum;

	debugL(2, "Data Link | Packager", "$f5 -> Packaged to '$f0%s$f5'\n", ss.str().c_str());

	// Return the Package
	return ss.str();
}

// Unpackages the specified Message and Returns the Payload
bool Node::DataLink_unpackageChannelMessage(string package, string &message)
{
	// Data Messages are of the Form:
	// Size [2] + Payload [Size - 3] + Check Sum [2]

	debugL(2, "Data Link | Unpackager", "$f4Unpackaging Message '$f0%s$f4'\n", package.c_str());

	// Determine the Size of the Message
	int size = atoi(package.substr(0, 2).c_str());

	// Make sure the Message is the correct Size
	if(size - 1 > package.length())
	{
		debugL(2, "Data Link | Unpackager", "$f4 -> Size Failed\n");
		return false;
	}

	// Determine the Checksum of the Message
	int checksum = atoi(package.substr(size - 3).c_str());

	// Substract the Trimmed 'S' Type Character
	checksum = (checksum - 'S') % 100;

	// Make Checksum Positive
	while(checksum < 0)
		checksum += 100;

	// Determine the Checksum-less Part of the Message
	string data = package.substr(0, size - 3);

	// Determine the Matching Checksum
	int match = DataLink_getCheckSum(data);

	// Make sure the Checksum Matches
	if(checksum != match)
	{
		debugL(1, "Data Link | Unpackager", "$f4 -> Checksum for '$f0%s$f4' Failed ($f0%i$f4 != $f0%i$f4)\n", data.c_str(), checksum, match);
		return false;
	}

	// Determine the Payload
	message = package.substr(2, size - 5);

	debugL(2, "Data Link | Unpackager", "$f4 -> Unpackaged to {Message = '$f0%s$f4'}\n", message.c_str());

	// Unpackaging Successful
	return true;
}

// Sends a Message from the Data Link Layer to the Channel
void Node::DataLink_sendToChannel(string message, int channel)
{
	debugL(3, "Data Link | Sender", "$f1Sending '$f0%s$f1' to Channel $f0%i$f1\n", message.c_str(), channel);

	// Call the Channel Writer
	DataLink_writeToChannel(message, channel);
}

// Sends a Message from the Data Link Layer to the Network Layer
void Node::DataLink_sendToNetwork(string message, int channel)
{
	debugL(3, "Data Link | Sender", "$f1Sending {Message = '$f0%s$f1', Channel = $f0%i$f1} to Network Layer\n", message.c_str(), channel);

	// Call the Network Layer's Receiver
	Network_receiveFromDataLink(message, channel);
}

// Receives Incoming Channel Message
bool Node::DataLink_receiveFromChannel(string data, int channel)
{
	debugL(3, "Data Link | Receiver", "$f2Received {Message = '$f0%s$f2', Channel = $f0%i$f2} from Channel\n", data.c_str(), channel);

	// Determine the Data Type
	char type = data[0];

	switch(type)
	{
		case 'S':
		{
			// Initialize the Message
			string message = "";

			// Unpackage the Channel Data
			if(!DataLink_unpackageChannelMessage(data.substr(1), message))
				return false;

			// Send the Message to the Network Layer
			DataLink_sendToNetwork(message, channel);
			return true;
		}

		default:
			debugL(1, "Data Link | Receiver", "$f2 -> Unrecognized Package Type '$f0%c$f2'\n", type);
			return false;
	}
}

// Receives Incoming Network Messages (Packages the Message and Writes to Channel)
void Node::DataLink_receiveFromNetwork(string message, int channel)
{
	debugL(3, "Data Link | Receiver", "$f2Received {'$f0%s$f2', $f0%i$f2} from Network\n", message.c_str(), channel);

	// Package the Message
	string package = DataLink_packageNetworkMessage(message);

	// Write the Package to the specified Channel
	DataLink_sendToChannel(package, channel);
}
