//* Description *//
// Title: Debug
// Author: Tyler Reed
// Creates C++ Debugger Support for the Bash Console
// Version 1.2 (11/18/2013)

//* Header Definition *//
#ifndef DEBUG_H
#define DEBUG_H

//* Libraries *//
#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string>

//* Namespaces *//
using namespace std;

//* Debug Class *//
class Debug
{
	//* Class Variables *//
	// Private Variables
	private:
		int debug_mode;
		map<string, int>* debug_map;

	//* Class Methods *//
	// Public Methods
	public:
		// Constructor and Destructor
		Debug(int debug_mode);
		~Debug();

		// Debug Methods
		int getDebugMode();
		int setDebugMode(int debug_mode);
		int getDebugMode(string name);
		int setDebugMode(string name, int debug_mode);
		void debug(int access, string message, ...);
		void debug(int access, string message, va_list args);
		void debug(string name, int access, string message, ...);
		void debug(string name, int access, string message, va_list args);

	// Private Methods
	private:
		// Formatting Methods
		string parseFormatting(string s);
		string vformat(const char* message, va_list args);
};

//* Constructor and Destructor *//
// Default Constructor
inline Debug::Debug(int debug_mode = 0)
{
	this -> debug_mode = debug_mode;
	this -> debug_map = new map<string, int>();
}

// Deconstructor
inline Debug::~Debug()
{
	// Delete the Debug Map
	delete debug_map;
}

//* Debug Methods *//
// Returns the Debug Mode
inline int Debug::getDebugMode()
{
	return this -> debug_mode;
}

// Sets the Debug Mode to the specified Mode
inline int Debug::setDebugMode(int debug_mode)
{
	int old = this -> debug_mode;
	this -> debug_mode = debug_mode;
	return old;
}

// Returns the Debug Mode with the specified Name
inline int Debug::getDebugMode(string name)
{
	// Make sure the Name Exists
	if(debug_map -> count(name) == 0)
		return 0;
	else
		return debug_map -> find(name) -> second;
}

// Sets the Debug Mode with the specified Name to the specified Mode
inline int Debug::setDebugMode(string name, int debug_mode)
{
	debug_map -> insert(pair<string, int>(name, debug_mode));
}

// Prints the specified String with Arguments to the Bash Console
inline void Debug::debug(int access, string message, ...)
{
	va_list args;
	va_start(args, message);
	va_end(args);

	debug(access, message, args);
}

// Prints the specified String with Arguments to the Bash Console
inline void Debug::debug(int access, string message, va_list args)
{
	if(debug_mode < access)
		return;

	cout << parseFormatting(vformat(message.c_str(), args)) << "\033[0m";
}

// Prints the specified String with Arguments to the Bash Console
inline void Debug::debug(string name, int access, string message, ...)
{
	va_list args;
	va_start(args, message);
	va_end(args);

	debug(name, access, message, args);
}

// Prints the specified String with Arguments to the Bash Console
inline void Debug::debug(string name, int access, string message, va_list args)
{
	if(debug_map -> find(name) -> second < access)
		return;

	cout << parseFormatting(vformat(message.c_str(), args)) << "\033[0m";
}

//* Formatting Methods *//
// Converts Debug Formatting into Bash Formatting
inline string Debug::parseFormatting(string s)
{
	// Debug Formatting:
	// $tX : Type X
	// $bX : Background X
	// $fX : Foreground X
	// $$ : $ Escape

	string bash_format = "";

	for(int i = 0; i < s.length(); i++)
	{
		char c = s[i];

		// Check for % Character
		if(c == '$')
		{
			char next = s[i + 1];

			// Check for Escape Character
			if(next == '$')
			{
				// Add the % to the String
				bash_format += c;

				// Skip the Escape Character
				i++;
			}
			else if(next == 't' || next == 'b' || next == 'f') // Check for Format Characters
			{
				// Convert Value to Format
				char num[3] = {'\0'};

				// Check for Type Format
				if(next == 't')
					num[0] = s[i + 2];
				else if(next == 'b') // Check for Background Format
				{
					num[0] = '4';
					num[1] = s[i + 2];
				}
				else // Check for Foreground Format
				{
					num[0] = '3';
					num[1] = s[i + 2];
				}

				// Add Bash Formatting
				string format = "\033[";
				format.append(num);
				format.append("m");

				// Add the Formatting to the String
				bash_format.append(format);

				// Skip the Formatting
				i += 2;
			}
			else // Non-Formatting Character, add % to the String
				bash_format += c;
		}
		else // Non-Command Character, add it to the String
			bash_format += c;
	}

	return bash_format;
}

// Formats the specified String using the printf Library
inline string Debug::vformat(const char* format, va_list args)
{
	// Allocate a Buffer on the Stack that's big enough
	// almost all of the time. Should it not fit, the
	// buffer will be dynamically allocated.

	// Stack Buffer
	size_t size = 1024;
	char stackBuffer[size];

	// Dynamic Buffer
	vector<char> dynamicBuffer;

	// Current Buffer
	char* buffer = &stackBuffer[0];

	// Loop until the Buffer is Cleared
	while(true)
	{
		// Try to vsnprintf into the Buffer
		int needed = vsnprintf(buffer, size, format, args);

		// Check if the String fit
		if(needed <= (int) size && needed >= 0)
			return string (buffer, (size_t) needed);

		// The String didn't fit, so try again using a larger
		// dynamic buffer. This shouldn't happen too often.

		// The new size is determined by the return value of needed
		// In a Windows environment, needed returns -1 for a failure,
		// so the new size is just guess work.
		// In a Linux and OXS environment, needed returns the actual
		// amount needed, so that becomes the new size
		size = (needed > 0) ? (needed + 1) : (size * 2);

		dynamicBuffer.resize(size);
		buffer = &dynamicBuffer[0];
	}
}

//* End of Header Definition *//
#endif
