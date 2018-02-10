// Assignement : Lab01
// File : CarballalL01b.cpp
// Author : Marcos Carballal
// Date : Spring 2017
// Description : This program will request the user's name and write
// the message "Hello Name" on the standard console output screen


// Include input and output stream and string libraries.
#include <iostream>
#include <string>
#include <cmath>
// Use the standard namespace
// This will allow the program to write to cout and read from cin

using namespace std;

// Function to ask the user for their name.
// The input stream and the output stream are passed to this
// function. This function will write a message requesting the
// user's name to the output stream. It will the  read the user's
// name from the input stream and store it in a string variable,
// Finally, it will retrun the string
string GetName(ostream & outs, istream & ins)
{
	// Declare  a string variable to hold the user's name
	string name;
	// Request the user's name
	outs << "Please enter your name: " << endl;
	// Read the user's name from cin - the standard input -
	// generally the keyboard
	ins  >> name;
	return name;
}
// Functio to print the message.
// The message and the output stream are passed to this function
// This function will write the message to the output stream,
// There is no returned value
void PrintMessage (string message, ostream & outs)
{
	// Declare a variable to hold the desired number of lines.
	float maxAngle = 6.28;
	// Declare a variable to increment the angle
	float angle = 0.0;

	while (angle < maxAngle)
	{
		// Declare a variable to hold the desired number of spaces
		int numSpaces = int(20 + 20 * sin (angle));
		// Declare a variable to count the spaces as they are printed
		int spaceCount = 0;
		outs << "| ";	
		while (spaceCount < numSpaces)
		{
			// Write a single space to outs
			outs << ' ';
			// Increment the space counter
			spaceCount++;
		}
	 
		// Write the message to outs
		outs << message;
		// Calculates the amount of compensated space necessary.
		int compensatedSpaces = 40 - numSpaces;
		int compensatedSpaceCount = 0;
		// Types out the spaces from the end of the message until the
		// central divider
		while (compensatedSpaceCount <= compensatedSpaces)
		{
			// Write a single space to outs
			outs << " ";
			// Increment the compensated space counter
			compensatedSpaceCount++;
		}
		// Prints divider bar
		outs << "| ";
		//Resets counter to 0 and begins incrementing via the
		//trigonometric function "cosine"
		spaceCount = 0;
		numSpaces = int(20 + 20 * cos(angle));
		while (spaceCount < numSpaces)
		{
			// Write a single space to outs
			outs << " ";
			// Increment the space counter
			spaceCount++ ;
		}
		// Prints the message
		outs << message;
		// Resets the compensated space necessary so it can be recalculated
		// with cos
		compensatedSpaces = 40 - numSpaces;
		compensatedSpaceCount = 0;
		
		// Types out the spaces from the end of the message until the
		// central divider
	
		while (compensatedSpaceCount < compensatedSpaces)
		{
			// Write a single space to outs
			outs << " ";
			// Increment the compensated space counter
			compensatedSpaceCount++;
		}
		// Prints the final bar and ends the line
		outs << " |" << endl;
			
		// Write the message to outs followed by a blank line
			// Incrment the angle
		angle += 0.3;
	}
	
}
int main()
{
	// Declare a string variable to hold the user's name.
	// Call the GetName function to get the user's name
	// and store the returned value in usersname
	string usersname = GetName (cout, cin);
	//Create a message concatenating hello and the user's
	//name.
	string mymessage = "Hello " + usersname;
	//Call the PrintMessage fucntion to pring the message
	PrintMessage (mymessage, cout);
	// Exit from the program
	return 0;
}
