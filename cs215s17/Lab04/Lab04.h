// File : Lab 4 WordData class and implementation
// Author: Marcos Carballal
// Description: This program will institute worddata
// as a class, eliminating the need for the struct

#ifndef WORDDATA
#define WORDDATA
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class WordData
{
	public:
		WordData ();
		WordData (const WordData  & OtherWord);
		~WordData ();
		void SetWord (const string & InWord);
		string GetWord () const;
		void WriteData (ostream & outs ) const;
	private:
		string word; // C++ string to hold the word
		int vowels; // vowel counter
		int consonants; // consonant counter
		int digits; // digitcounter
		int specialchars; // special character counter

};

// Funtion implementations will be placed after this line
// Sets all counters to 0
WordData :: WordData ()
{
	vowels = 0;
	consonants = 0;
	digits = 0;
	specialchars = 0;
}

WordData :: WordData (const WordData & OtherWord)
{
	word = OtherWord.word;
	vowels = OtherWord.vowels;
	consonants = OtherWord.consonants;
	digits = OtherWord.digits;
	specialchars = OtherWord.digits;

}
WordData :: ~WordData ()
{
}
bool isvowel (char aletter)
{
        char upper = toupper (aletter);
        if ( upper == 'A' or upper =='E' or upper == 'I' or upper == 'O' or upper == 'U')
                return true;
        return false;
}

void WordData :: SetWord (const string & InWord)
{
	word = InWord;
	for (int i = 0; i < InWord.length(); i++)
	{       
		if (isalpha (InWord[i]))
                {       
                	if (isvowel (InWord[i]))
                        {       
                        	vowels++;
                        }
                        else
                        {       
                        	consonants++;
                        }
                } else
                {       
                        if (isdigit(InWord[i]))
                        {       
                        	digits++;
                        }
                        else
                        {       
                        	specialchars++;
			}
		}
	}
};
string WordData :: GetWord () const
{
	return word;
}
void WordData :: WriteData (ostream & outs) const
{
	outs << setw(12) << left << word
	<< setw(8) << right << vowels <<
	setw(8) << consonants <<
	setw(8) << digits << 
	setw(8) << specialchars;
}
#endif 
