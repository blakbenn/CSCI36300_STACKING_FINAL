// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _MOD_COMMAND_H_
#define _MOD_COMMAND_H_

#include "Binary_Operation_Command.h"
#include "Stack.h"
/**
 * @class Mod_Command
 *
 *  Allows for modulus in calculator
 */
/**
 *@class mod_by_zero_exception
 *
 *Exception thrown to indicate a divide by zero error
 */

class mod_by_zero_exception : public std::exception
  {
  public:
        mod_by_zero_exception (void):
                std::exception()
                {
                }
  };
class Mod_Command : public Binary_Operation_Command
{
public:
  /// Constructor
  Mod_Command (void);

  /// Destructor
   virtual ~Mod_Command (void);

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


#endif   // !defined _MOD_COMMAND_H_
