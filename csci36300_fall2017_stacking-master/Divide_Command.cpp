// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

//include .h file
#include "Divide_Command.h"

//
// Divide_Command constructor
//
Divide_Command::Divide_Command(void)
{

}

//
// Divide_Command destructor
//
Divide_Command::~Divide_Command(void)
{

}

// Ryan: We should abstract out the Stack to the Binary Command
// level of inheritance.
// Fixed: Abstracted execute to the Binary Operation Command

//
// evaluate
//
int Divide_Command::evaluate (int n1, int n2)
{
    if (n1 == 0)
    {
        throw divide_by_zero_exception();
            return 0;
    }
    int result = n2 / n1;
    return result;
}


//
// Priority
//
int Divide_Command::Priority (void)
{
    return 2;
}
