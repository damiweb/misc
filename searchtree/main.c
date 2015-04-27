#include <stdio.h>
#include <stdlib.h>


struct node
{
	char* name;
	char* surname;
	char* phoneNumber;
	node* leftChild;
	node* rightChild;
} node;

/* To simplify, program will only support standard alphabetic without acute's or other diacritic characters */


enum alphaLC{A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};
enum alphaUC{a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z};

int check(node* entry)
{
	
}

main()
{

}