// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_
#include "Binary_Operation_Command.h"
#include "Stack.h"
#include <exception>
/**
 * @class Divide_Command
 *
 *  Allows for division in calculator
 */

 // Ryan: Good use of exceptions here!

 /**
 *@class divide_by_zero_exception
 *
 *Exception thrown to indicate a divide by zero error
 */

class divide_by_zero_exception : public std::exception
  {
  public:
        divide_by_zero_exception (void):
                std::exception()
                {
                }
  };
class Divide_Command : public Binary_Operation_Command
{
public:

  /// Constructor
  Divide_Command (void);

  /// Destructor
   virtual ~Divide_Command (void);


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


#endif   // !defined _DIVIDE_COMMAND_H_
