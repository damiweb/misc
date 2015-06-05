#ifndef MY_VECTOR
#define MY_VECTOR
#include <iostream>

class Vector{
	int dim;
	int *fields;
	// display method
public:
	// methods interface
	void display();
	void valuesAdd();
	// constructor
	Vector(int d = 1);
	// destructor
	~Vector();
	// overloaded operators
	friend Vector operator+(const Vector &vec1, const Vector &vec2);
	friend Vector operator-(const Vector &v1, const Vector &v2);
	void operator=(const Vector &v1);

};


#endif