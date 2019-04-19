// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Operation_Command.h"
#include "Stack.h"
/**
 * @class Add_Command
 *
 *  Allows for addition in calculator
 */

class Add_Command : public Binary_Operation_Command
{
public:
  /// Constructor
  Add_Command (void);

  /// Destructor
  virtual ~Add_Command (void);

// Ryan: We should abstract out the Stack to the Binary Command
// level of inheritance.
// Fixed: Abstracted execute out to the Binary Operation Command level
  /**
   * evaluate
   *
   *
   * @param[in]        int    the first integer
   * @param[in]        int    the second integer
   * @return           int    an integer after the two params have been operated on
   */
  virtual int evaluate(int n1, int n2);

   /**
   * Priority
   *
   *
   * @return          priority  an integer giving the priority of the operator
   */
  virtual int Priority (void);

private:

  /// No private members

};


#endif   // !defined _ADD_COMMAND_H_
