// File : Lab 4 WordData class and implementation
// Author: Marcos Carballal
// Description: This program will institute worddata
// as a class, eliminating the need for the struct

#include "WordData.h"
using namespace std;

WordData :: WordData ()
{
	length = 0;
	word = new char [1]; 
	word[0] = '\0';
	vowels = consonants = digits = specialchars = 0;
}
WordData :: WordData (const string & InWord)
{
	length = 0;
	word = new char [1];
	word[0] = '\0';
	vowels = consonants = digits = specialchars = 0;
	SetWord (InWord);
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
	length = OtherWord.length;
	word = new char [1 + length];
	strcpy ( word, OtherWord.word);
	vowels = OtherWord.vowels;
	consonants = OtherWord.consonants;
	digits = OtherWord.digits;
	specialchars = OtherWord.specialchars;
}
WordData :: ~WordData ()
{
	delete [] word;
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
	// delete word
	delete [] word;
	length = InWord.length();
	word = new char [1 + length];
	strcpy (word, InWord.c_str()); // Copies C++ style string into C style string
	
	vowels = consonants = digits = specialchars = 0;
	/*
	cout << "Word before function: " << *this << endl;
        cout << "Vowels: " << vowels << endl;
        cout << "Consonants:" << consonants << endl;
        cout << "Digits: " << digits << endl;
        cout << "Special Chars: " << specialchars << endl;
	*/
	for (int i = 0; i < length; i++)
	{       
		if (isalpha (word[i]))
                {       
                	switch (toupper (word[i]))
			{
				case 'A': case 'E': case 'I': case 'O': case 'U':
					vowels++;
					break;
				default:
					consonants++;
			}         
                
		} 
		else
                {       
                        if (isdigit(word[i]))
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
bool WordData :: operator < (const WordData & OtherWord) const
{
        if (length < OtherWord.length)
        {
                return true;
        }
        if (length > OtherWord.length)
        {
                return false;
        }
	string one = word; // why a c++ style string here?
	for (int i = 0; i < one.length(); i++)
		one[i] = tolower(one[i]); // Creates a new string which is just a lowercase version of word
	string two = OtherWord.word;
	for (int i = 0; i < two.length(); i++) // Creates a new string which is just a lowercase version of OtherWord.word
		two[i] = tolower(two[i]);
	// You must "Lowercase" the two strings to keep them from comparing ascii values which differ from upper case and lowercase
	return one < two;
}
WordData & WordData::operator = (const WordData & OtherWord)
{
	if (this == &OtherWord)
		return *this;
	// Delete the existing word
	delete [] word;

	length = OtherWord.length;
	// Allocating space for the new word.
	word = new char [1 + length];
	// Cop the new word from otherword into word
	strcpy ( word, OtherWord.word);
	// Copy remaining atributes
	vowels = OtherWord.vowels;
	consonants = OtherWord.consonants;
	digits = OtherWord.digits;
	specialchars = OtherWord.specialchars;
	// Return object referenced by this
	return *this;
}
bool WordData::operator == (const WordData & OtherWord) const
{
	if (strcmp (word, OtherWord.word) == 0)
		return true;
	return false;
}
WordData WordData::operator + (const WordData & OtherWord) const
{
	WordData sum;
	sum.length = length + OtherWord.length;

	sum.word = new char [1 + sum.length];
	strcpy (sum.word, word);
	strcat (sum.word, OtherWord.word);
	// Add all other components.
	sum.consonants = consonants + OtherWord.consonants;
	sum.digits = digits + OtherWord.digits;
	sum.vowels = vowels + OtherWord.vowels;
	sum.specialchars = specialchars + OtherWord.specialchars;
	
	return sum;
}
ostream & operator << (ostream & outs, const WordData & w)
{
        outs << setw(15) << left << w.word
        << setw(8) << right << w.vowels <<
        setw(8) << w.consonants <<
        setw(8) << w.digits <<
        setw(8) << w.specialchars;

	return outs;	
}

istream & operator >> (istream & ins, WordData & w) 
{
	string astring;
	ins >> astring;
	if (!ins.fail())
		w.SetWord(astring);
	return ins;		
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
