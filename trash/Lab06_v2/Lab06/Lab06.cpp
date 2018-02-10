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

const bool testing = false;
#include "Lab06.h"

WordData :: WordData ()
{
	word = "";
	vowels = consonants = digits = specialchars = 0;
}
WordData :: WordData (const WordData & OtherWord)
{
       /* if (testing)
                cout << "The default copy constructor has been called "
                     << "for address: " << this << endl;
	cout << setw (15) << left << "Word";
        cout << setw (8) << right << "Vowels";
        cout << setw (8) << right << "Const.";
        cout << setw (8) << right << "Digits";
        cout << setw (8) << right << "Special";
        cout << endl;
	*/
	word = OtherWord.word;
	vowels = OtherWord.vowels;
	consonants = OtherWord.consonants;
	digits = OtherWord.digits;
	specialchars = OtherWord.specialchars;

}
WordData :: ~WordData ()
{
        if (testing)
                cout << "The default destructor has been called "
                     << "for address: " << this << endl;
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
        if (testing)
                cout << "The SetWord function has been called "
                     << "for address: " << this << endl;
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
        if (testing)
                cout << "The GetWord function has been called "
                     << "for address: " << this << endl;
	return word;
}
int WordData :: GetNumVowels () const
{
	return vowels;
}
int WordData :: GetNumConsonants () const
{
	return consonants;
}
int WordData :: GetNumDigits () const
{
	return digits;
}

int WordData :: GetNumSpecialChars () const
{
	return specialchars;
}
bool WordData :: operator > (const WordData & OtherWord) const
{
	if (word.length() > OtherWord.GetWord().length())
	{
		return true;
	}
        if (word.length() < OtherWord.GetWord().length())
        {
                return false;
        }
	if (word > OtherWord.GetWord())
	{
		return true;
	}
	if (word <= OtherWord.GetWord())
	{
		return false;
	}
}

void WordData :: WriteData (ostream & outs) const
{
        if (testing)
                outs << "The WriteData function has been called "
                     << "for address: " << this << endl;
	outs << setw(15) << left << word
	<< setw(8) << right << vowels <<
	setw(8) << consonants <<
	setw(8) << digits << 
	setw(8) << specialchars;
}

// Beginning of the implementations of overloaded operators.

WordData & WordData :: operator = (const WordData & OtherWord)
{
	// Test for self-assignment. If this and the address of OtherWord
	// are the same, return the object referenced by this:
	if (this == &OtherWord)
		return * this;

	// Copy the attributes of OtherWord into the corresponding
	// attributes of this:
	word == OtherWord.word;
	vowels = OtherWord.vowels;
	consonants = OtherWord.consonants;
	digits = OtherWord.digits;
	specialchars = OtherWord.specialchars;

	// Return the object referenced by this
	
	return * this;
}

bool WordData :: operator == (const WordData & OtherWord) const
{
	return word == OtherWord.word;
}
WordData WordData :: operator + (const WordData & OtherWord) const
{
	WordData sum;
	
	sum.word = word + OtherWord.word;
	sum.vowels = vowel + OtherWord.vowels;
	sum.consonants = consonants + OtherWord.consonants;
	sum.digits = digits + OtherWord.digits;
	sum.specialchars = specialchars + OtherWord.specialchars;

	return sum;
}

ostream & operator << (ostream & outs, const WordData & w)
{
	outs << left << setw(12) << w.word
	<< right << setw(8) << w.vowels << w.consonants << w.digits << w.specialchars << endl;

	return outs;
}

istream & operator >> (istream & ins, const WordData & w)
{
	string astring;
	ins >> astring;
	if (!ins.fail())
	{
		w.SetWord(astring)
	}
	return ins;
}


















#endif 
