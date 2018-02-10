// Assignment : Lab03a
// File : CarballalL03a.cpp
// Author : Marcos Carballal
// Date : February 13th, 2017
// Description : This program will read an input from a file and store each word
// into an array. Each word is given a worddata type (see struct) in which the values
// for the number of vowels, consonants, digits and special characters is stored. It
// then prints them out in a formatted way along with the total number of vowels, consonants
// digits and special characters in the file.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// MAXWORDS contains the maximum number of words
const int MAXWORDS = 100;
// Definition of the worddate structure

struct worddata
{
	worddata ();
	string word;
	int vowels;
	int consonants;
	int digits;
	int specialchars;
};
// Prototypes for functions used by this program
int ReadFile (ifstream & input, worddata Words []);
void WriteReport (ostream & output, worddata Words [], int count);
void Swap (worddata & a, worddata & b);
void WordSort (worddata Words [], int N);
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
	// Declare an array of worddata objects to hold the words
	// and their vowel, consonant, digit, and special
	// character counts
	worddata WordArray [MAXWORDS];
	
	// Call the ReadFile function to read the file, store the
	// words in the array and return the number of words read
	// from the file
	int count = ReadFile (input, WordArray);
	output << count << " words read from the file" << endl;
	// Call the WriteReport function to write the data
	// stored in the array in a formatted fashion.
	WriteReport (output, WordArray, count);

	// Call the WordSort function to sort the words into
	// alphabetical order.
	WordSort (WordArray, count);

	// Call the WriteReport function to write the data
	// stored in the array in a formatted fashion.
	WriteReport (output, WordArray, count);
	output.close();
	return 0;
}
// Implementations for functions used by this program
worddata :: worddata ()
{
	vowels = 0;
	consonants = 0;
	digits = 0;
	specialchars = 0;
}
int ReadFile (ifstream & input, worddata Words [])
{
	int count = 0;
	while (input >> Words[count].word)
	{
		// Counts the number of vowels, consonants, digits, and special characters
		// in the word and store them in the worddata object Words[count]
		for (int i = 0; i < Words[count].word.length(); i++)
		{
			if (isalpha (Words[count].word[i]))
			{
				if (isvowel (Words[count].word[i]))
				{
					Words[count].vowels++;
				}
				else
				{
					Words[count].consonants++;
				}
			} else
			{
				if (isdigit( Words[count].word[i]))
				{
					Words[count].digits++;
				}
				else
				{
					Words[count].specialchars++;
				}
			}		
		}
		count++;
	}
	input.close();
	return count;
} 
void WriteReport (ostream & output, worddata Words [], int count)
{
	int totalvowels = 0, totalconsonants = 0;
	int totaldigits = 0, totalspecialchars = 0;

	output << setw (12) << left << "Words";
	output << setw (8) << right << "Vowels";
	output << setw (8) << "Const.";
	output << setw (8) << "Digits";
	output << setw (8) << "Special" << endl;
	for ( int i = 0; i < count; i++)
	{
		// Formatted output for the values	
		output << setw (12) << left << Words[i].word;
		output << setw (8) << right << Words[i].vowels;
		output << setw (8) << Words[i].consonants;
		output << setw (8) << Words[i].digits;
		output << setw (8) << Words[i].specialchars << endl;
		// Calculates the total for each type over each iteration
		totalvowels += Words[i].vowels;
		totalconsonants += Words[i].consonants;
		totaldigits += Words[i].digits;
		totalspecialchars += Words[i].specialchars;
	}	
	
	// Overcomplicated way to print the dashes	
	output << setw (12) << left << "";
	output << setw (8) << right << "---";
	output << setw (8) << "---";
	output << setw (8) << "---";
	output << setw (8) << "---" << endl;

	
	// Printing out "Totals" along with totals
	output << setw (12) << left << "Totals";
	output << setw (8) << right << totalvowels;
	output << setw (8) << totalconsonants;
	output << setw (8) << totaldigits;
	output << setw (8) << totalspecialchars << endl;
}
void Swap (worddata & a, worddata & b)
{
	worddata temp;
	temp = a;
	a = b;
	b = temp;	
}
void WordSort (worddata Words[], int N)
{
	int i = 1;
	while (i < N)
	{
		int j = i;
		while ( j > 0 && Words[j].word < Words[j-1].word)
		{
			Swap ( Words[j], Words [j-1]);
			j--;
		}
		i++;
	}
}
bool isvowel (char aletter)
{
	char upper = toupper (aletter);
	if ( upper == 'A' or upper =='E' or upper == 'I' or upper == 'O' or upper == 'U')
		return true;
	return false;
}
