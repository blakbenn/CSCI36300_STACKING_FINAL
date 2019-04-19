// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

//include .h file
#include "Add_Command.h"

//
// Add_Command constructor
//
Add_Command::Add_Command(void)
{

}

//
// Add_Command destructor
//
Add_Command::~Add_Command(void)
{

}

// Ryan: We should abstract out the Stack to the Binary Command
// level of inheritance.
// Fixed: Abstracted execute to the Binary Operation Command

//
// evaluate
//
int Add_Command::evaluate (int n1, int n2)
{
    int result = n1 + n2;
    return result;
}

//
// Priority
//
int Add_Command::Priority (void)
{
    return 1;
}
