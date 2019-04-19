// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _BINARY_OPERATION_COMMAND_H_
#define _BINARY_OPERATION_COMMAND_H_

#include "Expression_Command.h"
#include "Stack.h"
/**
 * @class Binary_Operation_Command
 *
 *  Allows for subtraction in calculator
 */

class Binary_Operation_Command : public Expression_Command
{
public:
  /// Constructor
  Binary_Operation_Command (void);

  /// Destructor
   virtual ~Binary_Operation_Command (void);


  /**
   * execute
   *
   * @param[in]       &stack    a reference to the stack
   * @return          a boolean
   */
  virtual bool execute (Stack <int> & stack);

  /**
   * evaluate
   * Pure virtual because it will not be defined except in children classes
   *
   * @param[in]        int    the first integer
   * @param[in]        int    the second integer
   * @return           int    an integer after the two params have been operated on
   */
  virtual int evaluate(int n1, int n2) = 0;
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


#endif   // !defined _SUBTRACT_COMMAND_H_
