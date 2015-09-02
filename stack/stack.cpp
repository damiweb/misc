#include "header.hpp"

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
/* function which clear a stack */
void Stack::clr(){
	delete val;
	index = 0;
	val = new int[max];
	for(int i = 0; i < max; i++) val[i] = 0;
}