#include <iostream>
#include "LList2.hpp"
using namespace std;

int main()
{
	LList2<int> L;
	L.InsertFirst(3);
	L.InsertFirst(6);
	L.InsertLast(7);
	L.InsertLast(8);
	L.DeleteFirst();
	L.DeleteLast();
	// [6 3 7 8]
	cout << "[" << L << "]" << endl;
}
