// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _INTEGER_COMMAND_H_
#define _INTEGER_COMMAND_H_

#include "Expression_Command.h"
#include "Stack.h"
/**
 * @class Integer_Command
 *
 *  Allows for division in calculator
 */

class Integer_Command : public Expression_Command
{
public:
  /// Constructor
  Integer_Command (void);

  /// Initial Value Constructor
  Integer_Command (int initial);

  /// Destructor
   virtual ~Integer_Command (void);

  /**
   * execute
   *
   * @param[in]       &stack    a reference to the stack
   * @return          a boolean
   */
  virtual bool execute (Stack <int> & stack);
   /**
   * Priority
   *
   *
   * @return          priority  an integer giving the priority of the operator
   */
  virtual int Priority (void);

private:

  int int_value;

};


#endif   // !defined _INTEGER_COMMAND_H_
