#ifndef MATRIX
#define MATRIX
#include "vector.h"

class Matrix : public Vector{
	// klasa wektor z kolei zawiera dowolna liczbe elementow typu calkowitego.
	Vector *vec;
	int dim;
public:
	friend bool operator!=(Vector v1, Vector v2);
};

#endif