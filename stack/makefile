program: header.hpp stack.o calculator.o main.o
	g++ stack.o calculator.o main.o -o app
stack: header.hpp stack.cpp
	g++ -c stack.cpp -o stack.o
calc: header.hpp calculator.cpp
	g++ -c calculator.cpp -o calculator.o
main: header.hpp main.cpp
	g++ -c main.cpp -o main.o
clean:
	rm *.o