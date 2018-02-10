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
class WordData
{
	public:
		WordData ();
		WordData (const WordData  & OtherWord);
		~WordData ();
		void SetWord (const string & InWord);
		string GetWord () const;
		void WriteData (ostream & outs ) const;
		int GetNumVowels () const;
		int GetNumConsonants () const;
		int GetNumDigits () const;
		int GetNumSpecialChars() const;
		bool operator > (const WordData & OtherWord) const;
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
{// The default constructor
	if (testing)
		cout << "The default constructor has been called "
		     << "for address: " << this << endl;
	vowels = 0;
	consonants = 0;
	digits = 0;
	specialchars = 0;

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
#endif 
