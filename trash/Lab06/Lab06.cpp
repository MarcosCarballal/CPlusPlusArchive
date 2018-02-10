// File : Lab 4 WordData class and implementation
// Author: Marcos Carballal
// Description: This program will impement the functions used 
// within the WordData class
#include "Lab06.h"
WordData :: WordData ()
{// The default constructor
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
}
bool isvowel (char aletter)
{
        char upper = toupper (aletter);
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
WordData & WordData :: operator =(const WordData & OtherWord)
{
	// Test for self-assignment. If this and the address of OtherWord
	// are the same, return the object referenced by this:
	if (this == &OtherWord)
		return * this;
	// Copy the attributes of OtherWord into the corresponding
	// attributes of this:
	word = OtherWord.GetWord();
	vowels = OtherWord.GetNumVowels();
	consonants = OtherWord.GetNumConsonants();
	digits = OtherWord.GetNumDigits();
	specialchars = OtherWord.GetNumSpecialChars();
	return * this;
}
bool WordData::operator == (const WordData & OtherWord) const
{
	return word == OtherWord.word;
}
WordData & WordData::operator + (const WordData & OtherWord) const
{
	WordData sum;
	sum.word = word + OtherWord.GetWord();
	sum.vowels = vowels + OtherWord.GetNumVowels();
	sum.consonants = consonants + OtherWord.GetNumConsonants();
	sum.digits = digits + OtherWord.GetNumDigits();
	sum.specialchars = specialcharsa + OtherWord.GetNumSpecialChars();
	return * sum;
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
	string astring = "";
	ins >> astring;
	if (!ins.fail())
	{
		w.SetWord(astring);
	}
	return ins;
}
void WordData :: WriteData (ostream & outs) const
{
	outs << setw(15) << left << word
	<< setw(8) << right << vowels <<
	setw(8) << consonants <<
	setw(8) << digits << 
	setw(8) << specialchars;
}
