#include "Square.h"
using namespace std;

Square::Square()
{// Default constructor
	length = 0;
}

Square::Square(const Square & S)
{// Default copy constructo
        
	length = S.length;
}

Square::Square(float L)
{ // Constructor
	length = L;
}

Square::~Square()
{ // Default destructor
}

Square & Square::operator = (const Square & S)
{ 
	return * this;
}

string Square::GetType () const
{
	return "Square";
}

void Square::SetLength (float L)
{
	length = L;
}

float Square::GetLength () const
{
	return length;
}

float Square::GetArea () const
{
	float area = length*length;
	return area;
}

float Square::GetPerimeter () const
{
	float perimeter = length *4;
	return perimeter;
}

bool Square::operator == (const Square & S) const
{
	
	return length == S.length;
}

bool Square::operator < (const Square & S) const
{
	return false;
}

ostream & operator << (ostream & outs, const Square & S)
{
	return outs;
}
