// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _Abstract_Expression_Command_Factory_H_
#define _Abstract_Expression_Command_Factory_H_

//including all expression .h files
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Mod_Command.h"
#include "Parentheses_Command.h"
#include "Integer_Command.h"
/**
 * @class Abstract_Expression_Command_Factory
 *
 * Abstract Factory to create expressions
 */

class Abstract_Expression_Command_Factory
{
public:
  /// Expression Command Factory constructor
  Abstract_Expression_Command_Factory (void);

  /// virtual destructor for our Expression Command Factory
  virtual ~Abstract_Expression_Command_Factory (void) = 0;

  //*********** Creating our expressions using the Abstract Factory Pattern
  // "= 0" indicates a pure virtual function
  /// Add Command
  virtual Add_Command * build_add_command (void) = 0;
  /// Subtract Command
  virtual Subtract_Command * build_subtract_command (void) = 0;
  /// Multiply Command
  virtual Multiply_Command * build_multiply_command (void) = 0;
  /// Divide Command
  virtual Divide_Command * build_divide_command (void) = 0;
  /// Mod Command
  virtual Mod_Command * build_mod_command (void) = 0;
  /// Parentheses Command
  virtual Parentheses_Command * build_parentheses_command (void) = 0;
  /// Integer Command
  virtual Integer_Command * build_integer_command (int integer) = 0;


private:

  /// No private members

};


#endif   // !defined _Abstract_Expression_Command_Factory_H_

