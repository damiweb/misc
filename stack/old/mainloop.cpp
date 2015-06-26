/**************************************************************\           
    * POSTFIX CALCULATOR - OBJECTIVE IMPLEMENTATION        *   
    *                                                      *   
    * Language:  C++                                       *   
    *                                                      *   
    * Author:  Daniel Miksa                                *   
    *                                                      *   
    * Purpose:  Educational purpose                        *   
    *                                                      *   
    * Usage:                                               *   
    *      Program is  starting  with welcome  message and *  
    * asks about equation to calculate.  User have to type *   
    * the equation   in  postfix form. Any other form will *   
    * cause  that  the  program  display an error message. *    
    * Be careful when you are  typing to  do not leave any *    
    * additional space  after  equation, otherwise program *    
    * can work unstable.                                   *    
    *                                                      *    
\**************************************************************/  

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "colours.h"

using namespace std;

/* ----------- STACK CLASS DECLARATION ---------- */

class Stack{
	int *val;
	int index;
	int max;
public:
	Stack(int maxsize = 128);
	Stack(const Stack &ref);
	~Stack();

	void push(int element);
	void pop();
	int top();
	bool isempty();
	int size();

};

/* ------------ METHODS DEFINITIONS ------------- */

Stack::Stack(int maxsize){
	index = 0;
	max = maxsize;
	val = new int[maxsize];
	for(int i = 0; i < maxsize; i++) val[i] = 0;
}

Stack::Stack(const Stack &ref){
	index = ref.index;
	max = ref.max;
	val = new int[max];
	for(int i = 0; i < max; i++) val[i] = ref.val[i];
}

Stack::~Stack(){
	delete val;
	cout << FG_DARK_GRAY << "(stack removed)" << RST << endl;
}


int Stack::size(){
	return index;
}

void Stack::push(int element){
	if(index < max){
		val[index] = element;
		index++;
	} else cout << "Stack overflowed! There is no place to another element." << endl;
}

void Stack::pop(){
	if (!isempty())
	{
		val[(index - 1)] = 0;
		index--;
	} else cout << FG_DARK_GRAY << "(stack empty)" << RST << endl;
}
int Stack::top(){
	if(isempty()) cout << "stack empty" << endl;
	else return val[(index - 1)];
}

bool Stack::isempty(){
	if(index == 0) {
		return 1;
	} else {
		return 0;
	}
}

/* ---------- END of CLASS DEFINITIONS ---------- */

/* ------------ MAIN PROGRAM LOOP --------------- */

int main( int argc, char* argv[] )
{
	cout << "WELCOME TO POSTFIX CALCULATOR. PERMITTED OPERATIONS ARE +, -, *." << endl
	<< "PLEASE TYPE YOUR EQUATION:" << endl;
	Stack calc;
	int error = 0;
	do{
		cin >> ws; /* ignore whitespaces */
		if (isdigit(cin.peek())){
			int n = 0;
			cin >> n;
			// cout << "wpisano liczbę:" << endl << n << endl;
			calc.push(n);
		}
		else {
			char c = '0';
			cin >> c;
			// cout << "wpisano znak:" << endl << c << endl;
			if(c == '+'){
				int a = calc.top();
				calc.pop();
				if(calc.isempty()) {
					cout << "Too few operands to continue calculation!" << endl;
					break;
				}
				int b = calc.top();
				calc.pop();
				calc.push(a + b);
			}
			else if(c == '-'){
				int a = calc.top();
				calc.pop();
				if(calc.isempty()) {
					cout << "Too few operands to continue calculation!" << endl;
					break;
				}
				int b = calc.top();
				calc.pop();
				calc.push(a - b);				
			}
			else if(c == '*'){
				int a = calc.top();
				calc.pop();
				if(calc.isempty()) {
					cout << "Too few operands to continue calculation!" << endl;
					break;
				}
				int b = calc.top();
				calc.pop();
				calc.push(a * b);				
			}
			else {
				error = 1;
				break;
			}

		}
	}while(cin.get() != '\n');
	if(!calc.isempty() and error == 0){
		int temp = calc.top();
		calc.pop();
		if(calc.isempty()){
			cout << "wynik działania to: " << temp << endl;
		} else cout << "Too few operators to continue calculation!";
	} else if(error == 1){
		cout << "Invalid character has been used instead of permitted operators!" << endl;
	}
}