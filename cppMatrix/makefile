main: matrix.h vector.o matrix.o main.o main.cpp
	g++ vector.o matrix.o main.o -o main
maino: main.cpp vector.h matrix.h vector.o matrix.o
	g++ -c main.cpp -o main.o
vector: vector.h vector.cpp
	g++ -c vector.cpp -o vector.o
matrix: vector.h matrix.h vector.o matrix.cpp
	g++ -c matrix.cpp -o matrix.o