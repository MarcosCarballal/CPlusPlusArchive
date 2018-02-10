// Lab 11 application program
// uthor: Marcos Carballal
// Data: Spring 2017
// Description: This program is designed to test the LList2 class.
#include <iostream>
#include <fstream>
#include "LList2.hpp"
#include "Fraction.h"

using namespace std;

// Add a global variable for holding the sum of the fractions here
fraction sumofvalues;
// Add function prototype here
void PrintVal (const int & value);
void Sum (const fraction & value);
int main ()
{
        ifstream input ("Lab11.in");
        fraction one;
        LList2 <fraction> FL;

        while (input >> one)
                FL.InsertLast (one);
              cout << "The fractions are: ";
        cout << FL << endl;

// Add code to find the sum of the fractions in the list FL here
	FL.Forward(Sum); // Forward/Backwards should not matter here
// Add code to print the sum here
	cout << "The total is " << sumofvalues << endl;
        return 0;
}

// Add function implementation here

void PrintVal (const int & value)
{
	cout << "The value in the list is"
	<< value << endl;
}

void Sum (const fraction & value)
{
	sumofvalues = value + sumofvalues;
}

