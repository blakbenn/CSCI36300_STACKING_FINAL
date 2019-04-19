
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Operation_Command.h"
#include "Stack.h"
/**
 * @class Multiply_Command
 *
 *  Allows for multiplication in calculator
 */

// Ryan: Why not inherit from a Binary Command here?
// Fixed: Inheriting from Binary Operation Command
class Multiply_Command : public Binary_Operation_Command
{
public:
  /// Constructor
  Multiply_Command (void);

  /// Destructor
   virtual ~Multiply_Command (void);


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


#endif   // !defined _MULTIPLY_COMMAND_H_
