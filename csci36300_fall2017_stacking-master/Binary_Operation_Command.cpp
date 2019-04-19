// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

//include .h file
#include "Binary_Operation_Command.h"

//
// Binary_Operation_Command constructor
//
Binary_Operation_Command::Binary_Operation_Command(void)
{

}

//
// Binary_Operation_Command destructor
//
Binary_Operation_Command::~Binary_Operation_Command(void)
{

}

//
// execute
//
bool Binary_Operation_Command::execute (Stack <int> & s)
{

    int n1 = s.top();
    s.pop();
    int n2 = s.top();
    s.pop();
    int n3 = this->evaluate(n1, n2); //evaluate the values popped from the stack
    s.push(n3);
    return true;
}


