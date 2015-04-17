#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define MAX_INPUT 64


typedef struct Node{
	char* name;
	char* surname;
	char* phoneNumber;
	struct Node* leftChild;
	struct Node* rightChild;
}Node;