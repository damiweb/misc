all: sort
sort: main.o sortlib.o
	gcc -o sort main.o sortlib.o
main.o: main.c sortlib.h
	gcc -c main.c
sortlib.o: sortlib.c sortlib.h
	gcc -c sortlib.c
clean:
	rm *.o