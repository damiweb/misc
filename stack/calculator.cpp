#include "header.hpp"

/* ------------ METHODS DEFINITIONS ------------- */

Calculator::Calculator(){
	errordata = 0;
	quit = 'c';
	calcstack = *(new Stack);
}

void Calculator::program(){
	do{
		system("clear");
		cout << "WELCOME TO POSTFIX CALCULATOR. ALLOWED OPERATIONS ARE +, -, *." << endl
		<< "PLEASE TYPE YOUR EQUATION:" << endl;
		errordata = 0;
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
				else{
					errordata = 2;
					break;
				}
			}
		}while(cin.get() != '\n');
		endtest();
		cout << "Continue / Quit? [c/q]" << endl;
		cin >> quit;
	}while(quit != 'q' and quit != 'Q');
}

void Calculator::endtest(){
	if(!calcstack.isempty() and errordata == 0){
		cout << endl << "Stack size: " << calcstack.size() << endl;
		if(calcstack.size() == 1){
			cout << "wynik działania to: " << FG_LIGHT_GREEN << calcstack.top() << RST << endl;
		} else{ 
			errordata = 3;
			cout << FG_LIGHT_RED << "Too few operators to continue calculation!" << RST << endl;
		}
	} else if(errordata == 1){
		cout << FG_LIGHT_RED << "Too few operands to continue calculation!" << RST << endl;
	} else if(errordata == 2){
		cout << FG_LIGHT_RED << "Invalid character has been used instead of allowed operators!" << RST << endl;
	} else cout << "Unknown issue, try again." << endl;
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