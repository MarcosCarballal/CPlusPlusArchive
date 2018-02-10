// Assignment : Lab04c
// File : CarballalL04c.cpp
// Author : Marcos Carballal
// Date : February 13th, 2017
// Description : This program will read an input from a file and store each.GetWord()
// into an array. Each.GetWord() is given a WordData type (see struct) in which the values
// for the number of vowels, consonants, digits and special characters is stored. It
// then prints them out in a formatted way along with the total number of vowels, consonants
// digits and special characters in the file.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Lab04.h"
using namespace std;

// Prototypes for functions used by this program
int ReadFile (ifstream & input, WordData * & Words);
void WriteReport (ostream & output, WordData Words [], int count);
void Swap (WordData & a, WordData & b);
void WordSort (WordData Words [], int N);
bool isvowel (char aletter);
int main (int argc, char * argv [])
{
	// Check to see if the user entered an input file name
	// and an output file name. Exit if no file name
	if (argc < 3)
	{
		cout << "Usage: " << argv[0] << " <input-file><output-file>\n";
		exit (1);
	}
	// Open the input file
	ifstream input (argv[1]);

	// Check to see if the file was successfully opened
	// Exit if no file found
	if (input.fail())
	{
		cout << "File: " << argv[1] << " not found\n";
		exit (2);
	}
	// Open the output file
	ofstream output (argv[2]);
	
	// Check to see if the output file was successfully opened
	// Exit if the file could not be opened
	if (output.fail())
	{
		cout << "File: " << argv[2] << "could not be opened\n";
		exit(3);
	}
	// Declare an array of WordData objects to hold the.GetWord()s
	// and their vowel, consonant, digit, and special
	// character counts
	WordData * WordArray;
	
	// Call the ReadFile function to read the file, store the
	//.GetWord()s in the array and return the number of.GetWord()s read
	// from the file
	int count = ReadFile (input, WordArray);
	// Call the WriteReport function to write the data
	// stored in the array in a formatted fashion.
	WriteReport (output, WordArray, count);

	// Call the WordSort function to sort the.GetWord()s into
	// alphabetical order.
	WordSort (WordArray, count);

	// Call the WriteReport function to write the data
	// stored in the array in a formatted fashion.
	WriteReport (output, WordArray, count);
	output.close();
	return 0;
}
// Implementations for functions used by this program
int ReadFile (ifstream & input, WordData * & Words)
{
	int count = 0;
	// Read and count the words in the file
	string oneword;
	while (input >> oneword)
	{
		count++;
	} 
	// Allocate space for the number of.GetWord()s counted by the previous loop
	Words = new WordData[count];
	// Clear the fail flag
	input.clear();
	// Reposition the file pointer to the beginning fo the file
	input.seekg ( 0, ios :: beg);
	count = 0;
	while (input >> oneword)
	{
		Words[count].SetWord(oneword);
		count++;
	}
	input.close();
	return count;
} 
void WriteReport (ostream & output, WordData Words [], int count)
{
	int totalvowels = 0, totalconsonants = 0;
	int totaldigits = 0, totalspecialchars = 0;

	output << setw (15) << left << "Words";
	output << setw (8) << right << "Vowels";
	output << setw (8) << "Const.";
	output << setw (8) << "Digits";
	output << setw (8) << "Special" << endl;
	for ( int i = 0; i < count; i++)
	{
		Words[i].WriteData(output);
		output << endl;
		/* Formatted output for the values	
		output << setw (15) << left << Words[i].GetWord();
		output << setw (8) << right << Words[i].vowels;
		output << setw (8) << Words[i].consonants;
		output << setw (8) << Words[i].digits;
		output << setw (8) << Words[i].specialchars << endl;
		 Calculates the total for each type over each iteration
		totalvowels += Words[i].vowels;
		totalconsonants += Words[i].consonants;
		totaldigits += Words[i].digits;
		totalspecialchars += Words[i].specialchars; */
	}	
	
	// Overcomplicated way to print the dashes	
	output << setw (15) << left << "";
	output << setw (8) << right << "---";
	output << setw (8) << "---";
	output << setw (8) << "---";
	output << setw (8) << "---" << endl;

	
	// Printing out "Totals" along with totals
	output << setw (15) << left << "Totals";
	output << setw (8) << right << totalvowels;
	output << setw (8) << totalconsonants;
	output << setw (8) << totaldigits;
	output << setw (8) << totalspecialchars << endl; 
}
void Swap (WordData & a, WordData & b)
{
	WordData temp;
	temp = a;
	a = b;
	b = temp;	
}
void WordSort (WordData Words[], int N)
{
	int i = 1;
	while (i < N)
	{
		int j = i;
		while ( j > 0 && Words[j].GetWord() < Words[j-1].GetWord())
		{
			Swap ( Words[j], Words [j-1]);
			j--;
		}
		i++;
	}
}
