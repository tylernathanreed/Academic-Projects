//* Description *//
// Title: Rover
// Author: Tyler Reed
// Defines the Rover Header

//* Header Declaration *//
#ifndef ROVER_H
#define ROVER_H

//* Libraries *//
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

//* Namespaces *//
using namespace std;

//* Type Definitions *//
typedef unsigned char byte;

//* Rover Class *//
class Rover
{
	//* Class Variables *//
	// Public Variables
	public:
		enum Direction {NORTH, EAST, SOUTH, WEST};

	// Private Variables
	private:
		Direction direction;

	//* Class Methods *//
	// Public Methods
	public:
		// Constructor and Destructor
		Rover();
		~Rover();

		// Command Methods
		string turnLeft();
		string turnRight();
		byte* takePicture(int* size);
		string getDirection();
		int getAirTemperature();

	// Private Methods
	private:
		// Conversion Methods
		string directionToString(int direction);

		// File Methods
		int getFileSize(FILE* file);
};

//* Constructor *//
// Default Constructor
inline Rover::Rover()
{
	// Set the Default Direction
	direction = NORTH;

	// Set the Seed for the Random Number Generation
	srand(time(NULL));
}

//* Deconstructor *//
// Deletes the Rover
inline Rover::~Rover()
{
	// Nothing to Delete
}

//* Commands *//
// Turns the Rover 90 Degrees to the Left
inline string Rover::turnLeft()
{
	// Determine the Direction
	switch(direction)
	{
		case NORTH:
			direction = WEST;
			break;

		case EAST:
			direction = NORTH;
			break;

		case SOUTH:
			direction = EAST;
			break;

		case WEST:
			direction = SOUTH;
			break;
	}

	return directionToString(direction);
}

// Turns the Rover 90 Degrees to the Right
inline string Rover::turnRight()
{
	// Determine the Direction
	switch(direction)
	{
		case NORTH:
			direction = EAST;
			break;

		case EAST:
			direction = SOUTH;
			break;

		case SOUTH:
			direction = WEST;
			break;

		case WEST:
			direction = NORTH;
			break;
	}

	return directionToString(direction);
}

// Takes a Picture and Returns the Photo
inline byte* Rover::takePicture(int* size)
{
	// Open the Picture File
	//string filepath = "./Server/Pictures/Test.png";
	string filepath = "./Server/Pictures/" + getDirection() + ".png";
	byte *buffer;
	FILE *file = NULL;

	// Open the File in Binary Mode
	if((file = fopen(filepath.c_str(), "rb")) == NULL)
		return NULL;

	// Get the Size of the File
	*size = getFileSize(file);

	// Allocate the space in the Buffer for the entire File
	buffer = new byte[*size];
	fread(buffer, *size, 1, file);

	// Close the File
	fclose(file);

	// Return the Buffer
	return buffer;
}

// Returns the current Direction of the Rover
inline string Rover::getDirection()
{
	return directionToString(direction);
}

// Returns the current Air Temperature near the Rover
inline int Rover::getAirTemperature()
{
	// Because there aren't any real instruments on this Rover,
	// this method is just going to return a random number.

	return rand() % 100 - 50;
}

//* Conversion Methods *//
// Returns the Name of the specified Direction
inline string Rover::directionToString(int direction)
{
	// Determine the Direction
	switch(direction)
	{
		case NORTH:
			return "North";

		case EAST:
			return "East";

		case SOUTH:
			return "South";

		case WEST:
			return "West";

		default:
			return "Unknown";
	}
}

//* File Methods *//
// Returns the Size of the specified File
inline int Rover::getFileSize(FILE* file)
{
	int cursorPosition, endPosition;

	// Store the Cursor Position and move to the End of the File
	cursorPosition = ftell(file);
	fseek(file, 0, 2);

	// Store the End Position and restore the Cursor Position
	endPosition = ftell(file);
	fseek(file, cursorPosition, 0);

	return endPosition;
}

//* End of Header Declaration *//
#endif
