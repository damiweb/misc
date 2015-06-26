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

/* ------------- CALCULATOR CLASS --------------- */

class Calculator{
	Stack calcstack;
	int result;
	int cont;
	/*	ErrorDATA variable:
		0 - no errors
		1 - Too few operands to continue calculation!
		2 - Invalid operator!
		3 - Too few operators to continue calculation!
	 */
	int errordata; 
	char quit;
public:
	Calculator();
	void program();
	bool endtest(); // 0 - OK; 1 - Too few operators to continue calculation!
	bool addition(); // 0 - OK; 1 - too few operands
	bool substraction(); // 0 - OK; 1 - too few operands
	bool multiplication(); // 0 - OK; 1 - too few operands

};

/* ------------ METHODS DEFINITIONS ------------- */

Calculator::Calculator(){
	cont = 0;
	result = 0;
	errordata = 0;
	quit = 'c';
	calcstack = *(new Stack);
}

void Calculator::program(){
	do{
		errordata = 0;
		cont = 1;
		do{
			cin >> ws; /* ignore whitespaces */
			if (isdigit(cin.peek())){
				int n = 0;
				cin >> n;
				calcstack.push(n);
			}
			else {
				char c = '0';
				cin >> c;
				if(c == '+'){
					if(addition()) break;
				}
				else if(c == '-'){
					if(substraction()) break;
				}
				else if(c == '*'){
					if(multiplication()) break;
				}
				else {
					errordata = 2;
					break;
				}
			}

			if(cin.get() != '\n'){
				cont = 1;
			} else cont = 0;
		}while(cont);
		switch(errordata)
		{
			case 0:
				if(endtest()){
					if(errordata==3) cout << "Too few operators to continue calculation!" << endl;
				} else{
					result = calcstack.top();
					cout << "Wynik działania to: " << result << endl;
				}	
				break;
			case 1:
				cout << "Too few operands to continue calculation!" << endl;
				break;
			case 2:	
				cout << "Invalid operator!" << endl;
				break;
			default:
				cout << "Unknown issue, try again." << endl;
				break;
		}
		cout << "Continue / Quit? [c/q]" << endl;
		cin >> quit;
	} while(quit != 'q' and quit != 'Q');
}

bool Calculator::endtest(){
	if(!calcstack.isempty()){
		int temp = calcstack.top();
		calcstack.pop();
		if(calcstack.isempty()){
			calcstack.push(temp);
			return 0;
		} else {
			errordata = 3;
			return 1;
		}
	}	
}

bool Calculator::addition(){
	int a = calcstack.top();
	calcstack.pop();
	if(calcstack.isempty()) {
		errordata = 1;
		return 1;
	}
	int b = calcstack.top();
	calcstack.pop();
	calcstack.push(a + b);
	return 0;
}
bool Calculator::substraction(){
	int a = calcstack.top();
	calcstack.pop();
	if(calcstack.isempty()) {
		errordata = 1;
		return 1;
	}
	int b = calcstack.top();
	calcstack.pop();
	calcstack.push(a - b);
	return 0;
}
bool Calculator::multiplication(){
	int a = calcstack.top();
	calcstack.pop();
	if(calcstack.isempty()) {
		errordata = 1;
		return 1;
	}
	int b = calcstack.top();
	calcstack.pop();
	calcstack.push(a * b);
	return 0;
}



/* ------------ MAIN PROGRAM LOOP --------------- */

int main()
{
	Calculator calc1;
	calc1.program();
	return 0;
}