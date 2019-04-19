// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

//include .h file
#include "Mod_Command.h"

//
// Mod_Command constructor
//
Mod_Command::Mod_Command(void)
{

}

//
// Mod_Command destructor
//
Mod_Command::~Mod_Command(void)
{

}

// Ryan: We should abstract out the Stack to the Binary Command
// level of inheritance.
// Fixed: Abstracted execute to the Binary Operation Command

//
// evaluate
//
int Mod_Command::evaluate (int n1, int n2)
{
    if (n1 == 0)
    {
        throw mod_by_zero_exception();
            return 0;
    }
    int result = n2 % n1;
    return result;
}
//
// Priority
//
int Mod_Command::Priority (void)
{
    return 2;
}
