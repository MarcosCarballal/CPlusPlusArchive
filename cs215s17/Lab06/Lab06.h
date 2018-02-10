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
		WordData & operator = (const WordData & OtherWord);
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
#endif
