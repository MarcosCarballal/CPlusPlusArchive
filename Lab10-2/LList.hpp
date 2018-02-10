#ifndef LLIST_HPP
#define LLIST_HPP

#include <iostream>

using namespace std;

enum dtype { FORWARD, BACKWARD };

template <class LT> class LList;
template <class LT> ostream & operator << (ostream & outs, const LList<LT> & L);

template <class LT>
class LList
{
   private:
      struct LNode // Seems like LList functions are unable to acccess 
      {
         LNode ();
	 void PrintNode (ostream & output);
         LT data;
         LNode * next;
      };
   public:
      LList ();
      LList (const LList & other);
      ~LList ();
      LList & operator = (const LList & other);
      bool operator == (const LList & other);
      int Size () const;
      void SetDirection (dtype dir);
      dtype GetDirection () const;
      friend ostream & operator << <>
			 (ostream & outs, const LList<LT> & L); // complaints on not enough argumetns, changing <> to <LT>
      bool InsertFirst (const LT & value);
      bool InsertLast (const LT & value);
      bool DeleteFirst ();
      bool DeleteLast ();
      void Forward (void function (const LT & param));
   private:
      LNode * first;
      LNode * last;
      int size;
      dtype direction;
};

template <class LT>
LList<LT>::LNode::LNode ()
{ // This function will set the value of data to 0 and set the pointer to NULL
	next = NULL;
}
template <class LT>
void LList<LT>::LNode::PrintNode (ostream & output)
{
	if (next != NULL)
		next -> PrintNode (output);
	if (next != NULL)
		output << ' ';
	output << data;

}
template <class LT>
LList<LT>::LList ()
{ // This function will se the value of size to 0 and set the value of next to NULL
	 size = 0;
	 first = NULL;
	 direction = FORWARD;
}
template <class LT>
LList<LT>::LList (const LList & other)
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
LList<LT>::~LList ()
{ // This function will destruct the list
	while (first)
	{
		DeleteFirst();
	}
}
template <class LT>
LList<LT> & LList<LT>::operator = (const LList<LT> & other)
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
bool LList<LT>::operator == (const LList & other)
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
int LList<LT>::Size () const
{ // This function will return the value of size.
	return size;
}
template <class LT>
void LList<LT>::SetDirection (dtype dir)
{
	direction = dir;
}
template <class LT>
dtype LList<LT>::GetDirection () const
{
	return direction;
}
template <class LT>
ostream & operator << (ostream & outs, const LList<LT> & L)
{ // This function will traverse the list, output all the data values and then return outs.

	if (L.first == NULL)
		return outs;
	if (L.direction == FORWARD)
	{// print the list from beginnning (first) to end
		outs << L.first -> data;

		typename LList<LT>::LNode * n;
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
	LList ::LNode * np = L.first;
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
bool LList<LT>::InsertFirst (const LT & value)
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

template <class LT>
bool LList<LT>::InsertLast (const LT & value)
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

template <class LT>
bool LList<LT>::DeleteFirst ()
{ // This function will remove the first element of the linked list.
	if (size == 0 or first == NULL)
		return false; // part a
	LNode * n  = first; // part b
	first = n -> next;// part c
	delete n;
	size--;
	
	return true; //part h
}

template <class LT>
bool LList<LT>::DeleteLast ()
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
template <class LT>
void LList<LT>::Forward (void function (const LT & param))
{
	for (LNode * n = first; n; n = n->next)
		function (n->data);
}
#endif
