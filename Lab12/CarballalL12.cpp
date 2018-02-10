#include <iostream>
#include <fstream>
#include "LList2.hpp"
#include "card.h"

using namespace std;

int main ()
{
	LList2 <card> allCards; // Initial list that will contain all cards
	LList2 <card> L1; // LList to contain first half of cards
	LList2 <card> L2; // LList to contain second half of cards.
	ifstream cardinput; // creating input stream
	cardinput.open ("cards.in"); // referencing file
	card acard;
	card newcard;
	while (cardinput >> acard) // Populate allcards
		allCards.InsertLast(acard);

	cout << "The cards: " << allCards << endl; // Should match input directly
	
        for (LList2<card>::Iterator itr = allCards.begin(); itr != allCards.end(); itr++) // as in the testing application
        {
		if (L1.Size() < allCards.Size()/2)
		{
			L1.InsertLast(*itr);
		}
		else
		{
			L2.InsertLast(*itr);
		}
        	//cout << "Value: " << *itr << endl;	
	}
	
	cout << "First half: " << L1 << endl; 
	cout << "Second half: " << L2 << endl;
	
	LList2 <card> ShuffledList;
	LList2 <card>::Iterator L1Current = L1.begin();
	LList2 <card>::Iterator L2Current = L2.begin();
	while (ShuffledList.Size() < allCards.Size())
	{
		if(ShuffledList.Size() % 2) // Alternates between placing 
		{
			ShuffledList.InsertLast(*L1Current);
			L1Current++; // Moves pointers to next item in list
		}
		else
		{
			ShuffledList.InsertLast(*L2Current); 
			L2Current++; // Moves pointer to next itme in list
		}
	}
	cout << "Shuffled cards: " << ShuffledList << endl;
}
