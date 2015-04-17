#include "header.h"

Node* root = NULL;

/* getch implementation */
char getch(){
  /* following function is not my property. It has been founded somewhere in network... */
  char buf=0;
  struct termios old={0};
  fflush(stdout);
  if(tcgetattr(0, &old)<0)
  perror("tcsetattr()");
  old.c_lflag&=~ICANON;
  old.c_lflag&=~ECHO;
  old.c_cc[VMIN]=1;
  old.c_cc[VTIME]=0;
  if(tcsetattr(0, TCSANOW, &old)<0)
  perror("tcsetattr ICANON");
  if(read(0,&buf,1)<0)
  perror("read()");
  old.c_lflag|=ICANON;
  old.c_lflag|=ECHO;
  if(tcsetattr(0, TCSADRAIN, &old)<0)
  perror ("tcsetattr ~ICANON");
  /*printf("%c\n",buf);*/
  return buf;
}

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
if (child->surname[sign] == '\0') isChildChar = 0; /* it means that child has no more signs in array */
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
int checkNameBoS(Node* child, Node* parent, int sign, char* alphaLC, char* alphaUC)
{
  int parentPos = -1;
  int childPos = -1;
  int i;
  int isParChar = 1;
  int isChildChar = 1;
if (child->name[sign] == '\0') isChildChar = 0; /* it means that child has no more signs in array */
if (parent->name[sign] == '\0') isParChar = 0;
if(isChildChar < isParChar) return 2; /* it means right child */
if(isChildChar < isParChar) return 1; /* it means left child */
if(isChildChar == 0 && isParChar == 0) return 0; /* it means EQUIVALENT SURNAMES*/
  for (i = 0; alphaLC[i] != '\0'; ++i)
  {
    if(alphaLC[i] == parent->name[sign]) parentPos = i;
    if(alphaUC[i] == parent->name[sign]) parentPos = i;
    if(alphaLC[i] == child->name[sign]) childPos = i;
    if(alphaUC[i] == child->name[sign]) childPos = i;
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
  if(origin != NULL){ 
    if(origin->leftChild != NULL) inOrder(origin->leftChild);
    printf("\n");
    fputs(origin->name, stdout);
    printf("\n");
    fputs(origin->surname, stdout);
    printf("\n");
    fputs(origin->phoneNumber, stdout);
    printf("\n");
    if(origin->rightChild != NULL){
      inOrder(origin->rightChild);
    }
  }
}
void measure(Node* origin, int* length, int current)
{
  if(current > *length) {
    *length = current;
    printf("length: %d", *length);
  }
  if(origin != NULL){ 
    if(origin->leftChild != NULL) {
      printf("obecnie: %d, długość dotychczasowa: %d\n", current, *length);
      measure(origin->leftChild, length, current+1);
      printf("obecnie: %d, długość dotychczasowa: %d\n", current, *length);
    }
    if(origin->rightChild != NULL){
      printf("obecnie: %d, długość dotychczasowa: %d\n", current, *length);
      measure(origin->rightChild, length, current+1);
      printf("obecnie: %d, długość dotychczasowa: %d\n", current, *length);
    }
  }
}
int tree_height(Node* origin)
{
  int len = 1;
  if(origin != NULL){
    measure(origin, &len, 1);
    return len;
  }else return -1; /* No root available */
}

/* By default function place second identical record in the right branch */

int find_node_place(Node* origin, Node* fresh, char* alphaLC, char* alphaUC){
  int insert = checkSurnameBoS(fresh, origin, 1, alphaLC, alphaUC);
  if(insert == 0){
    insert = checkNameBoS(fresh, origin, 1, alphaLC, alphaUC);
  }
  if(insert == 1){ 
    if(origin->leftChild == NULL) {
      printf("leftEmpty\n");
      origin->leftChild = fresh;
      return 1;
    } else find_node_place(origin->leftChild, fresh, alphaLC, alphaUC);
  }
  if(insert == 2) { 
    if(origin->rightChild == NULL) {
      printf("rightEmpty\n");
      origin->rightChild = fresh;
      return 2;
    } else find_node_place(origin->rightChild, fresh, alphaLC, alphaUC);
  }
  if(insert == 0) { 
    if(origin->rightChild == NULL) {
      printf("rightEmpty\n");
      origin->rightChild = fresh;
      return 2;
    } else find_node_place(origin->rightChild, fresh, alphaLC, alphaUC);
  }
}

int add(Node* origin, char* alphaLC, char* alphaUC)
{
  if(origin == NULL) {
    printf("Define First entry (root):\n");
    root = create();
    return 0; /* Root initialized */
  }
  Node* new_record = create();
  int result = find_node_place(origin, new_record, alphaLC, alphaUC); /* left(1) or right(2) */
  return result;
}

main()
{
  system("clear");
  
  // root = create();
  // Node* c2 = create();
  // int insert = checkSurnameBoS(c2, root, 1, alphaLC, alphaUC);
  // if(insert == 1) root->leftChild = c2;
  // if(insert == 2) root->rightChild = c2;
  int terminate = 1;
  do{

    printf("Welcome to contact book. Choose option you want:\n");
    printf("- Initialize manually (M),\n");
    printf("- Add new record (A),\n");
    printf("- Display by order (surname ascending) (D),\n");
    printf("- Measure tree height (temporarly this option terminate program) (H),\n");
    printf("- Terminate program (ESC)\n");
    int option;
    option = getch();
    int res;
    int height;
    switch(option){
      case 97: /* add new record */
        system("clear");
        res = add(root, alphaLC, alphaUC);
        printf("\nLast record status: %d (1 left branch, 2 right branch, 0 root initialized)\n", res);
        inOrder(root);
        break;
      case 100:
        system("clear");
        inOrder(root);
        break;
      case 109: /* manual initialization */
        root = create();
        system("clear");
        break;
      case 104:
        height = tree_height(root);
        printf("Tree proper: %d levels.\n", height);
        break;
      case 27:
        terminate = 0;
        break;
    }

  } while(terminate);
// printf("\nFunkcja zwróciła: %d\n", insert);
// printf("%d \n", root->rightChild);
// printf("%d \n", root->leftChild);
// fputs(root->surname, stdout);
// printf("\n");
// fputs(root->name, stdout);
// printf("\n");
// fputs(root->phoneNumber, stdout);
// printf("\n");
// if(origin->rightChild != NULL)
// {
// Node* lc= origin->rightChild;
// printf("%d\n", lc);
// }
}
