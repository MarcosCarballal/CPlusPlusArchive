#include "LList.h"
LList::LNode::LNode ()
{ // This function will set the value of data to 0 and set the pointer to NULL
	data = 0;
	next = NULL;
}

LList::LList ()
{ // This function will se the value of size to 0 and set the value of next to NULL
	 size = 0;
	 first = NULL;
}

LList::LList (const LList & other)
{ // This function will copy one list into the other
//	cout << "The copy constructor is being called" << endl;
	size = 0;
	first = NULL;
	LNode * np  = other.first;
	for (int i = 0; i < other.size; i++)
	{
		InsertLast(np -> data);
		np = np -> next; 
	}
}

LList::~LList ()
{ // This function will destruct the list
	while (first != NULL)
	{
		DeleteFirst();
	}
}

LList & LList::operator = (const LList & other)
{ // This function will copy one list into an already initialized list
	size = 0; // Need to reset these values
        first = NULL; // Need to reset these values
        LNode * np  = other.first;
        for (int i = 0; i < other.size; i++)
        {
                InsertLast(np -> data);
                np = np -> next;
        }
}

bool LList::operator == (const LList & other)
{ // This function will
	if (size != other.size)
		return false;
	LNode * np = first;
	LNode * op = other.first;
	bool failFlag = false;
	for (int i = 0; i < size; i++)
	{
		if ((np -> data) != (op -> data))
		{
			failFlag = true;
		}
	}

	if (failFlag)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int LList::Size () const
{ // This function will return the value of size.
	return size;
}

ostream & operator << (ostream & outs, const LList & L)
{ // This function will traverse the list, output all the data values and then return outs.
	if (L.Size() == 0)
		return outs;
	LList ::LNode * np = L.first;
	outs << np -> data;
	np = np -> next;
	for(int i = 0; i < L.Size()-1;i++) // For loop runs to size -1 because it must be offset for priniting the first variable out of the loop.,
	{
		outs << " " << np -> data; // Puts the data value in the Lnode into the ostream
		np = np -> next; // Changes the pointer to the one stored in the next part of Lnode.
	}
	return outs;
}

bool LList::InsertFirst (const int & value)
{ // This function will create a new space in memory for a node, return false if
  // it can't and shift the remaining part of the LList.
	LNode * np = NULL;
	np = new LNode;
	if (np == NULL)
		return false;
	np -> data = value;
	np -> next = first;
	first = np;
	size++;
	return true;
}

bool LList::InsertLast (const int & value)
{ // This function will add an item to the end of the linked list
	if (size == 0) // Part a.
	{
		return InsertFirst(value);
	} //End of Part a.
	LNode * np = NULL; // Part b.
	np = new LNode; // End of Part b.
	if (np == NULL) // Part c
	{
		return false;
	} // End of part C
	np -> data = value; //Part d
	np -> next = NULL; // Part e
	LNode * mid = first;
	// cout << mid << " is the mid value" << endl;
	while ((mid -> next) != NULL)
	{
		mid = mid -> next;
	 //       cout << mid << " is the mid value during the while loop" << endl; 
	}
	   //     cout << mid << " is the mid value after the while loop" << endl;
	mid -> next = np;
	size++; // Part h
	return true; // Part i
}

bool LList::DeleteFirst ()
{ // This function will remove the first element of the linked list.
	if (size == 0 or first == NULL)
		return false; // part a
	LNode * n  = first; // part b
	first = n -> next;// part c
	delete n;
	size--;
	
	return true; //part h
}

bool LList::DeleteLast ()
{ // This function will remove the last element in the linked list
	if (size == 0 or first == NULL)
        {
	        return false; // part a
	}
	if (size == 1)
	{
		return DeleteFirst();
	}
	LNode * mid = first;
	LNode * n = NULL;
	while ((mid -> next) != NULL)
	{
		n = mid;
		mid = mid -> next;
	}
	delete mid;
	n -> next  = NULL;
	size--;
	return true; //part h
}

