

// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#include "Stack_Expression_Command_Factory.h"

//
// Stack Expression Command Factory Constructor
//

Stack_Expression_Command_Factory::Stack_Expression_Command_Factory (void)
{
    // No member variables to initialize
}

//
// Stack Expression Command Factory Destructor
//
Stack_Expression_Command_Factory::~Stack_Expression_Command_Factory (void)
{
    //No member variables to delete
}

//
// Build add command function
//
Add_Command * Stack_Expression_Command_Factory::build_add_command (void)
{
  //concrete factory creates Add_Command object
  return new Add_Command();
}

//
// Build subtract command function
//
Subtract_Command * Stack_Expression_Command_Factory::build_subtract_command (void)
{
  //concrete factory creates Subtract_Command object
  return new Subtract_Command();
}

//
// Build multiply command function
//
Multiply_Command * Stack_Expression_Command_Factory::build_multiply_command (void)
{
  //concrete factory creates Multiply_Command object
  return new Multiply_Command();
}

//
// Build divide command function
//
Divide_Command * Stack_Expression_Command_Factory::build_divide_command (void)
{
  //concrete factory creates Divide_Command object
  return new Divide_Command();
}

//
// Build mod command function
//
Mod_Command * Stack_Expression_Command_Factory::build_mod_command (void)
{
  //concrete factory creates Mod_Command object
  return new Mod_Command();
}

//
// Build parentheses command function
//
Parentheses_Command * Stack_Expression_Command_Factory::build_parentheses_command (void)
{
  //concrete factory creates Parentheses_Command object
  return new Parentheses_Command();
}

//
// Build integer command function
//
Integer_Command * Stack_Expression_Command_Factory::build_integer_command (int integer)
{
  //concrete factory creates Integer_Command object
  return new Integer_Command(integer);
}
