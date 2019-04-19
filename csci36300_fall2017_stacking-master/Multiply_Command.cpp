// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

//include .h file
#include "Multiply_Command.h"

//
// Multiply_Command constructor
//
Multiply_Command::Multiply_Command(void)
{

}

//
// Multiply_Command destructor
//
Multiply_Command::~Multiply_Command(void)
{

}

// Ryan: We should abstract out the Stack to the Binary Command
// level of inheritance.
// Fixed: Abstracted execute to the Binary Operation Command

//
// evaluate
//
int Multiply_Command::evaluate (int n1, int n2)
{
    int result = n1 * n2;
    return result;
}
//
// Priority
//
int Multiply_Command::Priority (void)
{
    return 2;
}
