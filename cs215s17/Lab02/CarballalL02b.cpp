// Assignment : Lab02 b
// File : CarballalL02b.cpp
// Author : Marcos Carballal
// Date : January 31st, 2017
// Description : COME BACK TO

#include <iostream>
#include <fstream>
using namespace std;

bool isvowel (char aletter);

int main() 
{
	ifstream input;
	string aword;
	input.open ("words.txt");
	while(input >> aword)
	{
		// Determines number of vowels
		int vowelcount = 0;
		int i = 0;
		while (i < aword.length())
		{
			if (isvowel(aword[i]))
				vowelcount++;
			i++;
		}
		// Determines number of consonants and resets i to 0
		i = 0;
		int consonantcount = 0;
		while (i < aword.length())
		{
			if(not isvowel(aword[i]) && isalpha(aword[i]))
				consonantcount++;
			i++;				
		}
		// Determines number of digits and resets i to 0
		int digitcount = 0;
		i = 0;
		while (i < aword.length())
		{
			if (isdigit(aword[i]))
				digitcount++;
			i++;
		}
		// Determines number of special characters and resets i to 0
		int scharactercount = 0;
		i = 0;
		while (i < aword.length())
		{
			if (not(isdigit(aword[i]) || isalpha(aword[i])))
				scharactercount++;
			i++;
		}


		// Prints word, word length, vowel count, consonant count,
		// digit count, and special character count
		cout << aword << '\t' << aword.length()
			<< '\t' << vowelcount
			<< '\t' << consonantcount
			<< '\t' << digitcount
			<< '\t' << scharactercount << endl;			
	}
	
	
	return 0;
}

bool isvowel (char aletter)
{
	char upcase = toupper (aletter);
	if (upcase == 'A' || upcase == 'E' || upcase == 'I'
		|| upcase == 'O' || upcase == 'U')
			return true;
		return false;
}
