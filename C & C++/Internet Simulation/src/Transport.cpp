//* Description *//
// Title: Transport Layer
// Author: Tyler Reed
// Defines the Transport Layer of a Node

//* Notes *//
// The Transport Layer handles End-to-End Communication
// by using a Negative Acknowledgement Protocol for Messages
// that it has not received.

//* Libraries *//
#include "Node.h"

//* Transport Layer Methods *//
// Sends a Message to the specified Destination
void Node::Transport_sendMessage(string message, int destination)
{
	debugL(2, "Transport", "Sending Message '$f1%s$f0' to Node $f1%i$f0\n", message.c_str(), destination);

	// Create the Message Buffer
	map<int, string*>* partials = new map<int, string*>();

	for(int i = 0; i < message.length(); i += LIMIT_WINDOW)
	{
		// Determine the Message Partial
		string partial = message.substr(i, LIMIT_WINDOW);

		// Determine the Message Sequence
		int sequence = i/LIMIT_WINDOW;

		debugL(3, "Transport", " -> Sending Partial Message $f1%i$f0: '$f1%s$f0'\n", sequence, partial.c_str());

		// Insert the Partial message into the Message Buffer
		partials -> insert(pair<int, string*>(sequence, new string(partial)));

		// Package the Partial Message
		string package = Transport_packagePartialMessage(partial, destination, sequence);

		// Send the Package
		send_buffer -> push(new pair<int, string*>(destination, new string(package)));
	}

	// Store the Message in the Sent Buffer
	sent -> insert(pair<int, map<int, string*>*>(destination, partials));
}

// Receives a Message from the specified Destination
void Node::Transport_receiveMessage(string message, int source, int sequence)
{
	debugL(2, "Transport", "Received Partial Message $f1%i$f0: '$f1%s$f0' from Node $f1%i$f0\n", sequence, message.c_str(), source);
	debugL(3, "Transport", " -> Expected Sequence: $f1%i$f0\n", *(expected -> at(source)));

	// Determine the Received Map
	if(received -> find(source) == received -> end())
		debugL(1, "Transport", "Missing Received Map for Node $f1%i$f0!\n", source);

	map<int, string*>* rcv = received -> at(source);

	// Insert the Partial Message
	if(rcv -> find(sequence) != rcv -> end())
		delete rcv -> at(sequence);

	rcv -> insert(pair<int, string*>(sequence, new string(message)));

	// Match the Sequence against the Expected Value
	if(*(expected -> at(source)) == sequence)
	{
		// Determine the Next Expected Value
		int exp;

		for(exp = sequence + 1; rcv -> find(exp) != rcv -> end(); exp++);

		debugL(3, "Transport", " -> New Expected Sequence: $f1%i$f0\n", exp);

		// Increase the Expected Value
		expected -> insert(pair<int, int*>(source, &exp));
		timeout -> insert(pair<int, int*>(source, &lifetime));
	}
	//
	//else if(*(expected -> at(source)) < sequence)
	//{
	//	// Something was Missed. Send Negative Acknowledgements
	//	for(int i = *(expected -> at(source)); i < sequence; i++)
	//		Transport_sendAcknowledgement(source, i);
	//}
	//else if(expected -> at(source) > sequence)
	//{
	//	// Message already Received. Ignore it
	//}

}

// Send the specified Acknowledgement to the specified Node
void Node::Transport_sendAcknowledgement(int destination, int acknowledgement)
{
	debugL(2, "Transport", "Sending Negative Acknowledgement $f1%i$f0 to Node $f1%i$f0\n", acknowledgement, destination);

	// Package the Acknowledgement
	string package = Transport_packageAcknowledgement(destination, acknowledgement);

	// Send the Acknowledgment to the Network Layer
	send_buffer -> push(new pair<int, string*>(destination, new string(package)));
}

// Packages and Returns the specified Partial Message
string Node::Transport_packagePartialMessage(string message, int destination, int sequence)
{
	// Partial Message are of the Form:
	// D [1] + Source ID [1] + Destination ID [1] + Sequence [2] + Partial [Up to 5]

	debugL(2, "Transport | Packager", "$f5Packaging Partial Message {Message = '$f0%s$f5', Destination = $f0%i$f5, Sequence = $f0%i$f5}\n", message.c_str(), destination, sequence);

	// Create the Package Stream
	stringstream ss;
	ss << "D" << id << destination << setw(2) << setfill('0') << sequence << message;

	debugL(2, "Transport | Packager", "$f5 -> Packaged into '$f0%s$f5'\n", ss.str().c_str());

	// Return the Package
	return ss.str();
}

// Packages and Returns the specified Acknowledgement
string Node::Transport_packageAcknowledgement(int destination, int sequence)
{
	// Acknowledgements are of the Form:
	// N [1] + Source ID [1] + Destination ID [1] + Sequence [2]

	debugL(2, "Transport | Packager", "$f5Packaging Negative Acknowledgement {Destination = $f0%i$f5, Sequence = $f0%i$f5}\n", destination, sequence);

	// Create the Package Stream
	stringstream ss;
	ss << "N" << id << destination << setw(2) << setfill('0') << sequence;

	debugL(2, "Transport | Packager", "$f5 -> Packaged into '$f0%s$f5'\n", ss.str().c_str());

	// Return the Package
	return ss.str();
}

// Unpackages a Partial message and Returns whether or not the Process was Successful
bool Node::Transport_unpackagePartialMessage(string package, int &source, int &sequence, string &message)
{
	// Partial Messages are of the Form:
	// Source ID [1] + Destination ID [1] + Sequence [2] + Partial [Up to Window Size]

	debugL(2, "Transport | Unpackager", "$f4Unpackaging Partial Message '$f0%s$f4'\n", package.c_str());

	// Make sure the Package is the correct Size
	if(package.length() < 4)
		return false;

	// Determine the Source ID
	source = atoi(package.substr(0, 1).c_str());

	// Determine the Destination ID
	int destination = atoi(package.substr(1, 1).c_str());

	// Make sure the Destination ID matches the Node ID
	if(destination != id)
		return false;

	// Determine the Sequence ID
	sequence = atoi(package.substr(2, 2).c_str());

	// Determine the Partial Message
	message = package.substr(4, LIMIT_WINDOW);

	debugL(2, "Transport | Unpackager", "$f4 -> Unpackaged into {Source = $f0%i$f4, Sequence = $f0%i$f4, Message = '$f0%s$f4'}\n", source, sequence, message.c_str());

	// Unpackaging Successful
	return true;
}

// Unpackages an Acknowledgement and Returns whether or not the Process was Successful
bool Node::Transport_unpackageAcknowledgement(string package, int &source, int &sequence)
{
	// Acknowledgements are of the Form:
	// Source ID [1] + Destination ID [1] + Sequence [2]

	debugL(2, "Transport | Unpackager", "$f4Unpackaging Negative Acknowledgement '$f0%s$f4'\n", package.c_str());

	// Make sure the Package is the correct Size
	if(package.length() != 4)
		return false;

	// Determine the Source ID
	source = atoi(package.substr(0, 1).c_str());

	// Determine the Destination
	int destination = atoi(package.substr(1, 1).c_str());

	// Make sure the Destination ID matches the Node ID
	if(destination != id)
		return false;

	// Determine the Sequence
	sequence = atoi(package.substr(2, 2).c_str());

	debugL(2, "Transport | Unpackager", "$f4 -> Unpackaged into {Source = $f0%i$f4, Sequence = $f0%i$f4}\n", source, sequence);

	// Unpackaging Successful
	return true;
}

// Passes a Message from the Transport Layer to the Network Layer
void Node::Transport_sendToNetwork(string message, int destination)
{
	debugL(3, "Transport | Sender", "$f1Sending {Message = '$f0%s$f1', Destination = $f0%i$f1} to Network Layer\n", message.c_str(), destination);

	// Call the Network Layer's Receiver
	Network_receiveFromTransport(message, destination);
}

// Called by the Network Layer to Handle Incoming Messages
bool Node::Transport_receiveFromNetwork(string package)
{
	debugL(3, "Transport | Receiver", "$f2Received {Package = '$f0%s$f2'} from Network Layer\n", package.c_str());

	// Determine the Package Type
	char type = package[0];

	switch(type)
	{
		// Data Message
		case 'D':
		{
			// Initialize the Source, Sequence, and Message
			int source = -1; int sequence = -1; string message = "";

			// Unpackage the Partial Message
			if(!Transport_unpackagePartialMessage(package.substr(1), source, sequence, message))
				return false;

			// Receive the Message
			Transport_receiveMessage(message, source, sequence);
			break;
		}

		// Acknowledgement
		case 'N':
		{
			// Initialize the Source and Sequence
			int source = -1; int sequence = -1;

			// Unpackage the Acknowledgement
			if(!Transport_unpackageAcknowledgement(package.substr(1), source, sequence))
				return false;

			// Resend the Lost Message
			if(sent -> find(source) != sent -> end())
			{
				map<int, string*>* entry = sent -> at(source);

				if(entry -> find(sequence) != entry -> end())
				{
					string message = *(entry -> at(sequence));
					Transport_sendMessage(message, source);
					return true;
				}
				else
					debugL(1, "Transport | Receiver", "$f2 -> Missing Requested Message $f0%i$f2!\n", sequence);
			}
			else
				debugL(1, "Transport | Receiver", "$f2 -> Missing Sent Map for Node $f0%i$f2!\n", source);
	
			return false;
		}

		default:
			debugL(1, "Transport | Receiver", "$f2 -> Unknown Package Type '$f0%c$f1'\n", type);
			return false;
	}
}
