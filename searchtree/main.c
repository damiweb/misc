#include "header.h"

/* To simplify, program will only support standard alphabetic without acute's or other diacritic characters */


char alphaLC[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};
char alphaUC[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};

/* check bigger or smaller
	This function makes an order by assigning letters from a to left part of tree
 */

char* get_string(){
	char* inbuffer = (char*) malloc(MAX_INPUT * sizeof(char));
	fgets(inbuffer, (MAX_INPUT-1), stdin);
	/*fputs(inbuffer, stdout);*/
	int len = strlen(inbuffer);
	/*printf("Dlugosc nazwy pliku: %d\n", len);*/
	char* fname = (char*) malloc(len * sizeof(char)); 
	strncpy(fname, inbuffer, (len-1));
	fname[len-1] = '\0';
	/*fputs(fname, stdout);*/
	free(inbuffer);
	return fname;
}

int checkSurnameBoS(Node* child, Node* parent, int sign, char* alphaLC, char* alphaUC)
{
	int parentPos = -1;
	int childPos = -1;
	int i;
	int isParChar = 1;
	int isChildChar = 1;
	if (child->surname[sign] == '\0') isChildChar = 0;; /* it means that child has no more signs in array */
	if (parent->surname[sign] == '\0') isParChar = 0;
	if(isChildChar < isParChar) return 2; /* it means right child */
	if(isChildChar < isParChar) return 1; /* it means left child */
	if(isChildChar == 0 && isParChar == 0) return 0; /* it means EQUIVALENT SURNAMES*/
	for (i = 0; alphaLC[i] != '\0'; ++i)
	{
		if(alphaLC[i] == parent->surname[sign]) parentPos = i;
		if(alphaUC[i] == parent->surname[sign]) parentPos = i;
		if(alphaLC[i] == child->surname[sign]) childPos = i;
		if(alphaUC[i] == child->surname[sign]) childPos = i;
		if((parentPos != -1) && (childPos != -1)) break;
	}
	if(childPos > parentPos) return 2; /* it means right child */
	if(childPos < parentPos) return 1; /* it means left child */
	if(childPos == parentPos) checkSurnameBoS(child, parent, (sign+1), alphaLC, alphaUC);
}



Node* create()
{
	printf("Type name:\n");
	char* name = get_string();
	printf("\nType surname:\n");
	char* sname = get_string();
	printf("\nType phone number: \n");
	char* phnumber = get_string();
	Node* new_contact = (Node*) malloc(sizeof(Node));
	new_contact->name = name;
	new_contact->surname = sname;
	new_contact->phoneNumber = phnumber;
	new_contact->leftChild = NULL;
	new_contact->rightChild = NULL;
	return new_contact;
}

void inOrder(Node* origin)
{
	if(origin->leftChild != NULL) inOrder(origin->leftChild);
	else{
		printf("\n");
		//fputs(origin->name, stdout);
		printf("\n");
		// fputs(origin->surname, stdout);
		printf("\n");
		// ``fputs(origin->phoneNumber, stdout);
		printf("\n");
		inOrder(origin->rightChild);
	}
}


main()
{
	Node* origin = create();
	Node* c2 = create();
	int insert = checkSurnameBoS(c2, origin, 1, alphaLC, alphaUC);
	if(insert == 1) origin->leftChild = c2;
	if(insert == 2) origin->rightChild = c2;
	printf("\nFunkcja zwróciła: %d\n", insert);
	fputs(origin->surname, stdout);
	printf("\n");
	fputs(origin->name, stdout);
	printf("\n");
	fputs(origin->phoneNumber, stdout);
	printf("\n");
	// inOrder(origin);
	// if(origin->rightChild != NULL) 
	// {
	// 	Node* lc= origin->rightChild;
	// 	printf("%d\n", lc);
	// }


}