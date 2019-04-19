// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

//include .h file
#include "Integer_Command.h"

//
// Integer_Command constructor
//
Integer_Command::Integer_Command(void)
{

}

//
// Integer_Command initial value constructor
//
// Uses initialization list.
Integer_Command::Integer_Command(int initial):
    int_value(initial)
{

}

//
// Integer_Command destructor
//
Integer_Command::~Integer_Command(void)
{

}

//
// execute
//
bool Integer_Command::execute (Stack <int> & s)
{
    s.push(this->int_value);
}

//
// Priority
//
int Integer_Command::Priority (void)
{
    return 0;
}
