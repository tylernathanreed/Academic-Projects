//* Description *//
// Title: Debug
// Author: Tyler Reed
// Creates C++ Debugger Support for the Bash Console

//* Header Definition *//
#ifndef DEBUG_H
#define DEBUG_H

//* Libraries *//
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string>

//* Namespaces *//
using namespace std;

//* Debug Class *//
class Debug
{
	//* Private Variables *//
	private:
		int debug_mode;

	//* Public Methods *//
	public:
		// Constructor and Destructor
		Debug(int debug_mode);
		~Debug();

		// Debug Methods
		int getDebugMode();
		int setDebugMode(int debug_mode);
		void debug(int access, string message, ...);
		void debug(int access, string message, va_list args);

	//* Private Methods *//
	private:
		// Formatting Methods
		string parseFormatting(string s);
		string vformat(const char* message, va_list args);
};

//* Constructor and Destructor *//
// Default Constructor
Debug::Debug(int debug_mode = 0)
{
	this -> debug_mode = debug_mode;
}

// Deconstructor
Debug::~Debug()
{
	// Nothing to Delete
}

//* Debug Methods *//
// Returns the Debug Mode
int Debug::getDebugMode()
{
	return this -> debug_mode;
}

// Sets the Debug Mode to the specified Mode
int Debug::setDebugMode(int debug_mode)
{
	int old = this -> debug_mode;
	this -> debug_mode = debug_mode;
	return old;
}

// Prints the specified String with Arguments to the Bash Console
void Debug::debug(int access, string message, ...)
{
	if(this -> debug_mode < access)
		return;

	va_list args;
	va_start(args, message);
	va_end(args);

	cout << parseFormatting(vformat(message.c_str(), args)) << "\033[0m";
}

// Prints the specified String with Arguments to the Bash Console
void Debug::debug(int access, string message, va_list args)
{
	if(this -> debug_mode < access)
		return;

	cout << parseFormatting(vformat(message.c_str(), args)) << "\033[0m";
}

//* Formatting Methods *//
// Converts Debug Formatting into Bash Formatting
string Debug::parseFormatting(string s)
{
	// Debug Formatting:
	// $tX : Type X
	// $bX : Background X
	// $fX : Foreground X
	// $$ : % Escape

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
string Debug::vformat(const char* format, va_list args)
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
