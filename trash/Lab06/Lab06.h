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
		int GetNumVowels () const;
		int GetNumConsonants () const;
		int GetNumDigits () const;
		int GetNumSpecialChars() const;
		bool operator > (const WordData & OtherWord) const;
		WordData & operator = (const WordData & OtherWord) const;
		bool operator == (const WordData & OtherWord) const;
		WordData operator + (const WordData & OtherWord) const;
		friend istream & operator >> (istream & ins, WordData & w);
		friend ostream & operator << (ostream & outs, const WordData & w);
	private:
		string word; // C++ string to hold the word
		int vowels; // vowel counter
		int consonants; // consonant counter
		int digits; // digitcounter
		int specialchars; // special character counter

};
/*
WordData & WordData::operator =(const WordData & OtherWord)
{
	// Test for self-assignment. If this and the address of OtherWord
	// are the same, return the object referenced by this:
	if (this == &OtherWord)
		return * this;
	// Copy the attributes of OtherWord into the corresponding
	// attributes of this:
	word = OtherWord.word;
	vowels = OtherWord.vowels;
	consonants = OtherWord.consonants;
	digits = OtherWord.digits;
	specialchars = OtherWord.specialchars;
	// Return the object referenced by this:
	return * this;
}
*/
/*bool WordData::operator == (const WordData & OtherWord) const
{
	return word == OtherWord.word;
}*/
/*WordData WordData::operator +(const WordData & OtherWord) const
{
	WordData sum;
	sum.word = word + OtherWord.word;
	sum.vowels = vowels + OtherWord.vowels;
	sum.consonants = consonants + OtherWord.consonants;
	sum.digits = digits + OtherWord.digits;
	sum.specialchars = specialchars + OtherWord.specialchars;
	return sum;
}*/
/*ifstream & operator << (ostream & outs, const WordData & w)
{
	outs << left << setw(12) << w.word;
	outs << setw(8) << w.vowels;
	outs << setw(8) << w.consonants;
	outs << setw(8) << w.digits;
	outs << setw(8) << w.specialchars;
	return outs; 
}
ifstream & operator >> (istream & ins, WordData & w)
{
	string astring;
	ins >> astring;
	if(!ins.fail())
		w.SetWord(astring);
	return ins;

}*/
#endif 
