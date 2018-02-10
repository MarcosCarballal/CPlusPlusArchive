#ifndef LLIST_HPP
#define LLIST_HPP

#include <iostream>

using namespace std;

enum dtype { FORWARD, BACKWARD };

template <class LT> class LList2;
template <class LT> ostream & operator << (ostream & outs, const LList2<LT> & L);

template <class LT>
class LList2
{
   private:
      struct LNode // Seems like LList2 functions are unable to acccess 
      {
         LNode ();
	 void PrintNode (ostream & output);
         LT data;
         LNode * next;
	 LNode * prev;
      };
   public:
      LList2 ();
      LList2 (const LList2 & other);
      ~LList2 ();
      LList2 & operator = (const LList2 & other);
      bool operator == (const LList2 & other);
      int Size () const;
      void SetDirection (dtype dir);
      dtype GetDirection () const;
      friend ostream & operator << <>
			 (ostream & outs, const LList2<LT> & L); // complaints on not enough argumetns, changing <> to <LT>
      bool InsertFirst (const LT & value);
      bool InsertLast (const LT & value);
      bool DeleteFirst ();
      bool DeleteLast ();
      void Forward (void function (const LT & param));
      void Backward (void function (const LT & param)); 
  private:
      LNode * first;
      LNode * last;
      int size;
      dtype direction;
};

template <class LT>
LList2<LT>::LNode::LNode ()
{ // This function will set the value of data to 0 and set the pointer to NULL
	next = NULL;
	prev = NULL;
}
template <class LT>
void LList2<LT>::LNode::PrintNode (ostream & output)
{
	if (next != NULL)
		next -> PrintNode (output);
	if (next != NULL)
		output << ' ';
	output << data;

}
template <class LT>
LList2<LT>::LList2 ()
{ // This function will se the value of size to 0 and set the value of next to NULL
	 size = 0;
	 first = NULL;
	 last = NULL;
	 direction = FORWARD; // Confusion on whether or not this should be included
}
template <class LT>
LList2<LT>::LList2 (const LList2 & other)
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
	direction = other.direction;
}
template <class LT>
LList2<LT>::~LList2 ()
{ // This function will destruct the list
	while (first)
	{
		DeleteFirst();
	}
}
template <class LT>
LList2<LT> & LList2<LT>::operator = (const LList2<LT> & other)
{ // This function will copy one list into an already initialized list
	size = 0; // Need to reset these values
        first = NULL; // Need to reset these values
        LNode * np  = other.first;
        for (int i = 0; i < other.size; i++)
        {
                InsertLast(np -> data);
                np = np -> next;
        }
	direction = other.direction;
}
template <class LT>
bool LList2<LT>::operator == (const LList2 & other)
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
template <class LT>
int LList2<LT>::Size () const
{ // This function will return the value of size.
	return size;
}
template <class LT>
void LList2<LT>::SetDirection (dtype dir)
{
	direction = dir;
}
template <class LT>
dtype LList2<LT>::GetDirection () const
{
	return direction;
}
template <class LT>
ostream & operator << (ostream & outs, const LList2<LT> & L)
{ // This function will traverse the list, output all the data values and then return outs.

	if (L.first == NULL)
		return outs;
	if (L.direction == FORWARD)
	{// print the list from beginnning (first) to end
		outs << L.first -> data;

		typename LList2<LT>::LNode * n;
		for (n = L.first -> next; n != NULL; n = n-> next)
				outs << ' ' << n -> data;
	}
	else // L.direction == BACKWARD
	{
		L.first -> PrintNode (outs);
	}
	return outs;

/*	if (L.Size() == 0)
		return outs;
	LList2 ::LNode * np = L.first;
	outs << np -> data;
	np = np -> next;
	for(int i = 0; i < L.Size()-1;i++) // For loop runs to size -1 because it must be offset for priniting the first variable out of the loop.,
	{
		outs << " " << np -> data; // Puts the data value in the Lnode into the ostream
		np = np -> next; // Changes the pointer to the one stored in the next part of Lnode.
	}
	return outs;
*/
}
template <class LT>
bool LList2<LT>::InsertFirst (const LT & value)
{ // This function will create a new space in memory for a node, return false if
  // it can't and shift the remaining part of the LList2.
	LNode * np = NULL;
	np = new LNode;
	if (np == NULL)
		return false;

	np -> data = value;
	
	if(size!=0)
		first -> prev = np;
	
	np -> next = first;
	first = np;
	
	size++;
	if (size == 1)
	{
		last = np;
	}
	return true;
}

template <class LT>
bool LList2<LT>::InsertLast (const LT & value)
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
	np -> prev = mid;
	size++; // Part h
	return true; // Part i
}

template <class LT>
bool LList2<LT>::DeleteFirst ()
{ // This function will remove the first element of the linked list.
	if (size == 0 or first == NULL)
		return false; // part a
	LNode * n  = first; // part b
//	first = n -> next;// part c
	if( size == 1)
	{
		n  = NULL;
		last = NULL;
	}
	else
	{
		n = n -> next;
		n -> prev = NULL;
	}
	delete first;
	first = n;
	size--;
/*
	LNode * n = first;
	if (first == NULL)
	{
		return false;
	}
	if (size == 1)
	{
		first = NULL;
		last = NULL;
	}
	return true; //part h
*/
}

template <class LT>
bool LList2<LT>::DeleteLast ()
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
	// Mo need to add anything as no previous values will change as a result of deleting the last LNode
	return true; //part h
}
template <class LT>
void LList2<LT>::Forward (void function (const LT & param))
{
	for (LNode * n = first; n; n = n->next)
		function (n->data);
}
template <class LT>
void LList2<LT> :: Backward (void function (const LT & param))
{
	for (LNode * n = last; n; n = n -> prev)
	{
		function (n -> data);
	}
}
#endif
