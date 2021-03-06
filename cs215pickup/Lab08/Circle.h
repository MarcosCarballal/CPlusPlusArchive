#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
using namespace std;

const float PI = 3.14159;

class Circle
{
	public:
		Circle();
		Circle(const Circle & C);
		Circle(float L);
		~Circle();
		Circle & operator = (const Circle & C);
		string GetType () const;
		void SetLength (float L);
		float GetLength () const;
		float GetArea () const;
		float GetPerimeter () const;
		bool operator == (const Circle & C) const;
		bool operator < (const Circle & C) const;
		friend ostream & operator << (ostream & outs, const Circle & C);
	private:
		float length;
};

#endif
