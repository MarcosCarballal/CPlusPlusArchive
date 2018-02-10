// Assignment : Lab03a
// File : CarballalL03a.cpp
// Author : Marcos Carballal
// Date : February 10th, 2017
// Description : This program reads from a file and prints the number of vowels, consonants. At first it will 
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// MAXWORDS contains the maximum number of words
const int MAXWORDS = 100;
bool isvowel (char aletter);
int main ()
{
	// Declare and open an input file
	ifstream input ("words.txt");
	// Array for storing words
	string words [MAXWORDS];
	// Read the words in the file into the array]
	int count = 0;
	while (input >> words[count])
	{
		count++;
	}
	// Close the input file
	input.close ();
	cout << count << " words read from the file\n";
	// Read the words and their vowel, consonany, digit
	// and special character counts
	// Starting with the last word in the arra
		// Declares all the constants
	int w = count -1;
	int vowelcount = 0;
	int consonantcount = 0;
	int digitcount = 0;
	int scharactercount = 0;
	int j = 0;
		
	while ( w >= 0)
	{
		// Analyze the letters in the word
		// Reset letter count to 0
		j = 0;
		while (j < words[w].length())
		{
			if (isalpha (words[w][j]))
			{
				if (isvowel (words[w][j]))
				{
					vowelcount++;
				}
				else
				{
					consonantcount++;
				}
			}
			else
			{
				if (isdigit(words[w][j]))
				{
					digitcount++;
				}
				else
				{
					scharactercount++;
				}
			}
			// Incrementing the letter count
			j++;				
		}
		// Printing
		cout << words[w]<< '\t' << vowelcount
			<< '\t' << consonantcount
			<< '\t' << digitcount
			<< '\t' << scharactercount << endl;
		// Reset the counts for each counter
		vowelcount = 0;
		consonantcount = 0;
		digitcount = 0;
		scharactercount = 0;
		w--;
	}
	// Starting with the first word in the array
	w = 0;
	
	while ( w < count)
	{
		// Analyze the letters in the word
		// Reset letter count to 0
		j = 0;
		while (j < words[w].length())
		{
			if (isalpha (words[w][j]))
			{
				if (isvowel (words[w][j]))
				{
					vowelcount++;
				}
				else
				{
					consonantcount++;
				}
			}
			else
			{
				if (isdigit(words[w][j]))
				{
					digitcount++;
				}
				else
				{
					scharactercount++;
				}
			}
			// Incrementing the letter count
			j++;				
		}
		// Printing
		cout << words[w]<< '\t' << vowelcount
			<< '\t' << consonantcount
			<< '\t' << digitcount
			<< '\t' << scharactercount << endl;
		// Reset the counts for each counter
		vowelcount = 0;
		consonantcount = 0;
		digitcount = 0;
		scharactercount = 0;
		w++;
	}	
	return 0;
}

bool isvowel (char aletter)
{
	char upper = toupper(aletter);
	if ( upper == 'A' or upper == 'E' or upper == 'I' or upper == 'O' or upper == 'U')
		return true;
	return false;
}

