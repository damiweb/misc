#ifndef POSTFIX_HEADER
#define POSTFIX_HEADER

#include <iostream>
#include <cstdlib>
#include "colours.h"

using namespace std;

/* ----------- STACK CLASS DECLARATION ---------- */

class Stack{
    int *val;
    int index;
    int max;
public:
    Stack(int maxsize = 128); // constructor
    Stack(const Stack &ref); // copy constructor
    ~Stack(); // destructor

    void push(int element); // insert element to a stack
    void pop(); // remove top element
    int top(); // return top value without removing it
    bool isempty(); // check stack caption
    int size(); // check stack size
    void clr(); // Stack reset

};

/* ------------- CALCULATOR CLASS --------------- */

class Calculator{
    Stack calcstack;
    /*  ErrorDATA variable:
        0 - no errors
        1 - Too few operands to continue calculation!
        2 - Invalid operator!
        3 - Too few operators to continue calculation!
     */
    int errordata; 
    char quit;
public:
    Calculator(); // Constructor
    void program(); // main calculator loop
    void endtest(); // 0 - OK; 1 - Too few operators to continue calculation!
    bool addition(); // 0 - OK; 1 - too few operands
    bool substraction(); // 0 - OK; 1 - too few operands
    bool multiplication(); // 0 - OK; 1 - too few operands

};


#endif