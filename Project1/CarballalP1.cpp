// Assignment : Project 1
// File : CarballalP1.cpp
// Author : Marcos Carballal
// Description : This program will read a set of strings and store them in an array. The
// program will then print the strings, information about strings and a sorted list of the
// strings 

#include <iostream>
#include <fstream>
#include <iomanip>
#include "similarity.hpp"

using namespace std;

int const MAXSTRINGS = 1000;
int const PERLINE = 7;

int GetStrings (string S []);
void PrintStrings (string S [], int C);
void PrintShortest (string S [], int C);
void PrintLongest (string S [], int C);
void GreatestSimilarity (string S [], int C);
void LeastSimilarity (string S [], int C);
void AscendingSequence (string S [], int C);
void DescendingSequence (string S [], int C);
void Sort (string S [], int C);
void Swap (string & a, string & b);

int main ()
{
	int count = 100;
	string strings [MAXSTRINGS];
	count = GetStrings (strings);
	cout << "The Strings: " << endl;
	PrintStrings (strings , count);
	PrintShortest (strings, count);
	PrintLongest (strings, count);
	LeastSimilarity (strings, count);
	GreatestSimilarity (strings, count);
	AscendingSequence (strings, count);
	DescendingSequence (strings, count);
	Sort (strings, count);
	return 0;
}
// This function inputs a blank array
// of string types, populates it with an
// input, and returns the number of words
// in the array.
int GetStrings (string S [])
{
	int count = 0;
	ifstream input ("strings.txt");
        while (input >> S[count])
        {
		count++;
	}
	return count;
}

// This function inputs an array of strings
// and a constant which is the length of the array
// and outputs the set of strings
void PrintStrings (string S [], int C)
{
	for (int i = 0; i < C; i++)
	{
	        cout  << setw (12) << left << S[i]; //This ensure that all words fit into a space 12 spaces wide and maintains formatting
		if ((i+1)%7 ==  0 and i != 0) // Clears the line if number of words is divisible by 7 (Every seven words
			cout << endl;
	}
	cout << endl << endl;
}
// This function inputs an array of strings
// and a constant which is the length of the array
// and outputs the longest word
void PrintLongest (string S [], int C)
{
	int LongestPosition = 0;
	for ( int i = 0; i < C; i++)
	{
		if ( S[i].length() > S[LongestPosition].length()) // If the length of this string is longer than the current one than it replaces it.
		{
			LongestPosition = i;
		}	
	}
	cout << "Longest String: " << S[LongestPosition] << endl << endl;
	


}
// This function inputs an array of strings
// and a constant which is the length of the array
// and outputs the shortest word
void PrintShortest (string S [], int C)
{
	int ShortestPosition = 0;
        for ( int i = 0; i < C; i++)
        {
                if ( S[i].length() < S[ShortestPosition].length()) // If the length of this string is shorter than the current one than it replaces it
                {
                        ShortestPosition = i;
                }
        }
        cout << "Shortest String: " << S[ShortestPosition] << endl << endl;

}
// This function inputs an array of strings
// and a constant which is the length of the array
// and outputs the couplet of words with the greatest similarity
void GreatestSimilarity (string S [], int C)
{
        // Float variable refers to the first string in the pair of the two
        // Each string from 0 to C -1 will be associated with a score because
        // you wouldn't need to double check the similarity between B and A if
        // you've already checked the similarity of A & B
        int GreatestSimPos = 0;
        float SimilarityRating = 0;
        for (int i = 0; i < (C-1); i++)
        {
                if ( similarity( S[i] , S[i+1]) > similarity (S[GreatestSimPos] , S[GreatestSimPos + 1])) // If the similarity is greater than it replaces the current set 
                {
                        GreatestSimPos = i;
                        SimilarityRating = similarity( S[i] , S[i+1]);
                }
        }
        cout << "Adjacent Strings with Greatest Similarity: " <<
      		  S[GreatestSimPos] << " " << S[GreatestSimPos + 1] <<
       		 " (" << fixed << setprecision(1) << SimilarityRating << "%)" << endl << endl;

}
// This function inputs an array of strings
// and a constant which is the length of the array
// and outputs the couplet of words with the least similarity
void LeastSimilarity (string S [], int C)
{
	// Float variable refers to the first string in the pair of the two
	// Each string from 0 to C -1 will be associated with a score because
	// you wouldn't need to double check the similarity between B and A if
	// you've already checked the similarity of A & B
	int LeastSimPos = 0;
	float SimilarityRating = 0;
	for (int i = 0; i < (C-1); i++)
	{
		if ( similarity( S[i] , S[i+1]) < similarity (S[LeastSimPos] , S[LeastSimPos + 1])) // If the similarity is less than it replaces the current set
		{	
			LeastSimPos = i; 
			SimilarityRating = similarity( S[i] , S[i+1]);
		}
	}
	// Prints out the least similar strings left justified 12 positions
	cout << "Adjacent Strings with Least Similarity: " <<
		S[LeastSimPos] << " " << S[LeastSimPos + 1] <<
		 " (" << fixed << setprecision(1) << SimilarityRating <<"%)" << endl << endl;
}
// This function inputs an array of strings
// and a constant which is the length of the array
// and outputs the longest ascending sequence
void AscendingSequence (string S [], int C)
{
        // Allocates space in memory for the starting postiion and
        // length of largest sequence of ascending characters
	int MaxStartPos = 0;
	int MaxLength = 1;
	for (int i =0; i < C; i++)
	{
		int TempMaxLength = 1;
		int j = i;
		while (S[j] < S[j+1])
		{
			TempMaxLength++;
			j++;
		}
		if (TempMaxLength > MaxLength)
		{
			MaxLength = TempMaxLength;
			MaxStartPos = i;
		}
	}
	// Printing Sequence
	cout << "Ascending Sequence:" << endl;
	for(int i = 0; i < MaxLength; i++)
	{
		 cout  << setw (12) << left << S[MaxStartPos + i];
		 // Clears the line every 7 words
                 if ((i+1)%7 ==  0 and i != 0) // Clears the line if number of words is divisible by 7 (Every seven words
                        cout << endl;

	}
	cout << endl << endl;
}
// This function inputs an array of strings
// and a constant which is the length of the array
// and outputs the longest descending sequence
void DescendingSequence (string S [], int C)
{
	// Allocates space in memory for the starting postiion and
	// Length of largest sequence of descending characters
        int MaxStartPos = 0;
        int MaxLength = 1;
        for ( int i = 0; i < C; i++)
        {
                int TempMaxLength = 1;
                int j = i;
                while (S[j] > S[j+1]) //Finds the length of a given descending sequence
                {
                        TempMaxLength++;
                        j++;
                }
                if (MaxLength  < TempMaxLength) // Changes MaxLength and MaxPos if
						// the new sequence is longer
                {
                        MaxLength = TempMaxLength;
                        MaxStartPos = i;
                }
        }
        cout << "Descending Sequence:" << endl;
        for(int i = 0; i < MaxLength ; i++)
        {
                 cout  << setw (12) << left << S[MaxStartPos + i];
                 if ((i+1)%7 ==  0 and i != 0) // Clears the line if number of words is divisible by 7 (Every seven words
                        cout << endl;

        }
        cout << endl ;

}
// This function inputs an array of strings
// and a constant which is the length of the array
// and sorts the array alphabetically.
void Sort (string S [], int C)
{
	cout << "Sorted Strings:" << endl;
	bool Unsorted = true;
	while (Unsorted) // Only when it is fully sorted will the while loop quit
	{
		Unsorted = false; // Assumes it is without errors.
		for (int i = 0; i < (C-1); i++)
		{
			if  (S[i] > S[i+1]) // As soon as it finds and error it 
						// swaps the two and changes the flag
			{
				Swap(S[i] , S[i+1]);
				Unsorted = true;
			}
		}
	}
	PrintStrings(S, C);

}
// This function inputs two strings by reference and swaps
// their positions in memory.
void Swap (string & a, string & b)
{
        string temp;
        temp = a;
        a = b;
        b = temp;
}

