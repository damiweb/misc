#include "vector.h"

using namespace std;

void Vector::display(){
	cout << endl;
	for(int i = 0; i < dim; i++) cout << fields[i] << endl;
}
void Vector::valuesAdd(){
	cout << "Type vector coords values:" << endl;
	for(int n = 0; n<dim; n++) cin >> fields[n]; 
}

Vector operator+(const Vector &vec1, const Vector &vec2){
	int dimen = vec1.dim;
	if(vec2.dim > dimen) dimen = vec2.dim;
	Vector *sup = new Vector(dimen);
	for(int i = 0; i < dimen; i++){
		int nfv = 0;
		if(vec1.dim > i) {nfv += vec1.fields[i];}
		if(vec2.dim > i) {nfv += vec2.fields[i];}
		sup->fields[i] = nfv;
	}
	return *sup;
}
Vector operator-(const Vector &v1, const Vector &v2){
	int dimen = v1.dim;
	if(v2.dim > dimen) dimen = v2.dim;
	Vector *sup = new Vector(dimen);
	for(int i = 0; i < dimen; i++){
		int nfv = 0;
		if(v1.dim > i) {nfv = v1.fields[i];}
		if(v2.dim > i) {nfv -= v2.fields[i];}
		sup->fields[i] = nfv;
	}
	return *sup;
}

void Vector::operator=(const Vector &v1){
	int dimen = dim;
	if(v1.dim > dimen) cout << "Vector wil become trimmed";
	for(int i = 0; i < dimen; i++){
		if(i >= v1.dim) fields[i] = 0;
		else fields[i] = v1.fields[i];
	}
}

Vector::Vector(int d)
{
	dim = d;
	fields = new int[dim];
	for(int i = 0; i<dim; i++) fields[i] = 0;
}
Vector::~Vector()
{
	cout << "Wektor usunięty." << endl;
}
