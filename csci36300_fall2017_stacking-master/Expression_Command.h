// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _EXPRESSION_COMMAND_H_
#define _EXPRESSION_COMMAND_H_

#include "Stack.h"
/**
 * @class Expression_Command
 *
 *  Allows for addition in calculator
 */

class Expression_Command
{
public:
  /// Constructor
  Expression_Command (void);

  /// Destructor
   virtual ~Expression_Command (void)=0;

  /**
   * execute
   *
   * @param[in]       &stack    a reference to the stack
   * @return          a boolean
   */
  virtual bool execute (Stack <int> & stack) = 0;

  /**
   * Priority
   *
   *
   * @return          priority  an integer giving the priority of the operator
   */
  virtual int Priority (void) = 0;

private:

  /// No private members

};


#endif   // !defined _EXPRESSION_COMMAND_H_
