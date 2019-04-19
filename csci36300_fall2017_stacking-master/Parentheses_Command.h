// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _PARENTHESES_COMMAND_H_
#define _PARENTHESES_COMMAND_H_

#include "Binary_Operation_Command.h"
#include "Stack.h"
/**
 * @class Parentheses_Command
 *
 *  Allows for division in calculator
 */

class Parentheses_Command : public Binary_Operation_Command
{
public:
  /// Constructor
  Parentheses_Command (void);

  /// Destructor
   virtual ~Parentheses_Command (void);

   /**
   * Priority
   *
   *
   * @return          priority  an integer giving the priority of the operator
   */
  /**
  *
  * evaluate
  *
  *  @param[in]     int leftside integer
  *  @param[in]     int rightside integer
  *  return         int the operated integers
  */
  virtual int evaluate (int n1, int n2); 
  virtual int Priority (void);
private:

  /// No private members

};


#endif   // !defined _PARENTHESES_COMMAND_H_
