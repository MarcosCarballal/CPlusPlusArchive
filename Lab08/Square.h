#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
using namespace std;

class Square
{
	public:
		Square();
		Square(const Square & S);
		Square(float L);
		~Square();
		Square & operator = (const Square & S);
		string GetType () const;
		void SetLength (float L);
		float GetLength () const;
		float GetArea () const;
		float GetPerimeter () const;
		bool operator == (const Square & S) const;
		bool operator < (const Square & S) const;
		friend ostream & operator << (ostream & outs, const Square & S);
	private:
		float length;
};

#endif
