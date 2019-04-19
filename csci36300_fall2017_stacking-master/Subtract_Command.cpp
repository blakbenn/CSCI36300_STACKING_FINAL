// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

//include .h file
#include "Subtract_Command.h"

//
// Subtract_Command constructor
//
Subtract_Command::Subtract_Command(void)
{

}

//
// Subtract_Command destructor
//
Subtract_Command::~Subtract_Command(void)
{

}

// Ryan: We should abstract out the Stack to the Binary Command
// level of inheritance.
// Fixed: Abstracted execute to the Binary Operation Command

//
// evaluate
//
int Subtract_Command::evaluate (int n1, int n2)
{
    int result = n2 - n1;
    return result;
}
//
// Priority
//
int Subtract_Command::Priority (void)
{
    return 1;
}
