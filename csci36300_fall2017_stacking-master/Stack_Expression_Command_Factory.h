
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _Stack_Expression_Command_Factory_H_
#define _Stack_Expression_Command_Factory_H_

#include "Abstract_Expression_Command_Factory.h"
/**
 * @class Stack_Expression_Command_Factory
 *
 * Stack Factory to create expressions
 *
 * Stack factory inherits from Abstract factory so that virtual functions can be altered by the derived class
 */

class Stack_Expression_Command_Factory : public Abstract_Expression_Command_Factory
{
public:
  /// Expression Command Factory constructor
  Stack_Expression_Command_Factory (void);

  /// virtual destructor for our Expression Command Factory (because functions are virtual)
  virtual ~Stack_Expression_Command_Factory (void);

  //*********** Creating our expressions using the Stack Factory Pattern
  /// Add Command
  virtual Add_Command * build_add_command (void);
  /// Subtract Command
  virtual Subtract_Command * build_subtract_command (void);
  /// Multiply Command
  virtual Multiply_Command * build_multiply_command (void);
  /// Divide Command
  virtual Divide_Command * build_divide_command (void);
  /// Mod Command
  virtual Mod_Command * build_mod_command (void);
  /// Parentheses Command
  virtual Parentheses_Command * build_parentheses_command (void);
  /// Integer Command
  virtual Integer_Command * build_integer_command (int integer);


private:

  /// No private members

};


#endif   // !defined _Stack_Expression_Command_Factory_H_
