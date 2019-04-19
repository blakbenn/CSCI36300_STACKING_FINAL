// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// blakbenn

//********* Stack, Array, and Base Array **********
#include "BaseArray.h"
#include "Array.h"
#include "Stack.h"

//********* include commands **********************
#include "Binary_Operation_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Mod_Command.h"
#include "Parentheses_Command.h"
#include "Integer_Command.h"

//********** Factories ****************************
#include "Abstract_Expression_Command_Factory.h"
#include "Stack_Expression_Command_Factory.h"

//********** C++ libraries ************************
#include "stdio.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cstring>          // for size_t definition
#include <sstream>
//
// main
//


bool infix_to_postfix (const std::string & infix, Stack_Expression_Command_Factory & factory, Array <Expression_Command *> & postfix);
bool checkIsValidExpression(const std::string & inputStr);
bool calculate(Array <Expression_Command *> & postfix, Stack <int> & result);

int main (int argc, char * argv [])
{
    std::string inputStr;
    std::string quitStr;
    std::string postFixStr;
    std::string tempStr;
    Stack_Expression_Command_Factory factory;
    Array<Expression_Command *> postfix(50);
    quitStr = "QUIT";
    Stack<int> result;
  printf("Please enter a valid expression or 'QUIT' to quit:\n");
    getline(std::cin, inputStr);
    while (inputStr.compare(quitStr) != 0)
    {
        //check for a valid expression
	if (checkIsValidExpression(inputStr) == true)
	{
		//convert infix to postfix and then calculate results
		//print results to the screen, pop the result stack and exit to get new line
        	if(infix_to_postfix(inputStr, factory, postfix) == true)
		{
			if(calculate(postfix, result))
			{
				printf("Result: %d \n", result.top());
				result.pop();
			}
			else
			{
				//remove extra commands from the stack
				while (result.is_empty() == false)
				{
					result.pop();
				}
			}
		} 
	

	}
	else
	{
		//print this message if we dont have a valid expression, get new line
		printf("Invalid Expression, please retype. \n");
	}
	//resize array (to a large number, 50 is just a placeholder)  and get a new line
        postfix.resize(50);
	printf("Please enter a valid expression or 'QUIT' to quit:\n");
	getline(std::cin, inputStr);
    }


	
}



//
//infix_to_postfix
//
bool infix_to_postfix (const std::string & infix, Stack_Expression_Command_Factory & factory, Array <Expression_Command *> & postfix)
 {
	std::istringstream input(infix); // create a input stream parser
	std::string token; // current token in string/stream
	Expression_Command * cmd = 0; // created command object
	Stack<Expression_Command *> temp;
	std::string postFixString;
	Stack<std::string> StringStack;;
	int count = 0; //count the position in the array
	int number = 0;
	//loop until the end of the string
	while (!input.eof()) 
	{
		//parse the istringstream
		input >> token;
		//create our command based on the token
		if (token == "+")
			cmd = factory.build_add_command();
		else if (token == "-")
			cmd = factory.build_subtract_command();
		else if (token == "*")
			cmd = factory.build_multiply_command();
		else if (token == "/")
                        cmd = factory.build_divide_command();
		else if (token == "%")
                        cmd = factory.build_mod_command();
		else if (token == "(")
			cmd = factory.build_parentheses_command();
		else if (token == ")")
		        cmd = factory.build_parentheses_command();
		//uses stoi to convert the string to an integer to be used as input for build_integer_command(int integer)
		else 
		{
			number = std::stoi(token.c_str());
			cmd = factory.build_integer_command(number);
			
		}
		//if the stack is empty
		if (temp.is_empty() == false)
		{
			//check if cmd is an integer command
			if(cmd->Priority() == 0) 	
			{
				//append to the end of our postfix string and set it in the next array position
				postfix.set(count, cmd);
				postFixString += token + " ";
				count++;
			}
			//check if cmd is a paranetheses
			else if(cmd->Priority() == 4)
			{
				//open arrays get pushed to the front of the stack
				if(token == "(")
				{
					temp.push(cmd);
				}
				//if not an open paren, its a closed paren, pop things from the stack until we find the open paren
				else
				{
					//while we havent found the open paraentheses
					 while(temp.top()->Priority() != 4) 
					{
						//append stack top to the postfix string and add to next position of postfix Array
						postFixString += StringStack.top() + " ";
						StringStack.pop();
						postfix.set(count, temp.top());
						count++;
						temp.pop();
					
					}
					//pops the open paren off the stack
					temp.pop();
				}
			}		
			//checks for multiply/divide/mod operators while add/subtract are on the stack or if we have a closed parentheses
			else if(cmd->Priority() > temp.top()->Priority() || temp.top()->Priority() == 4)
			{
				//in this case, push the higher priority operators onto the stack
				temp.push(cmd);
				StringStack.push(token);
			}
			//checks for add/subtract while mult/divide/mod operators are on the stack or for same priority operators on stack
			else if(cmd->Priority() == temp.top()->Priority())
			{
				//push operator onto the stack after placing the last equal priority operator into the string and popping ti from the stack
				postFixString += StringStack.top() + " ";
                                StringStack.pop();
                                postfix.set(count, temp.top());
                                count++;
                                temp.pop();
				temp.push(cmd);
				StringStack.push(token);
				
			}
			else
			{

				//pops the higher priority (or equal priority) operators off the stack and appends to the postFixString and adds them to postfix array
				while(temp.is_empty() == false)
				{
			                postFixString += StringStack.top() + " ";
                                        StringStack.pop();
					postfix.set(count, temp.top());
                                        count++;
					temp.pop();  
			
				}
				//push current operator to stack
				temp.push(cmd);
				StringStack.push(token);
			}
		}
		//check for integer if stack is empty
		else if(cmd->Priority() == 0)
		{
			postfix.set(count, cmd);
                        postFixString += token + " ";
                        count++;
		}
		//check for parentheses if stack is empty
		else if(cmd->Priority() == 4)
		{
			temp.push(cmd);
		}
		//if none of the above and stack is empty, just push operator onto the stack
		else
		{
			temp.push(cmd);
			StringStack.push(token);
		}
	}
	//pop stack when we reach the end of the file if things are still on the stack
	while(temp.is_empty() == false)
	{
		postFixString += StringStack.top() + " ";
                StringStack.pop();

		postfix.set(count, temp.top());
		count++;
                temp.pop();
	}
	//print our postfix string (COMMENTED OUT, BUT LEFT FOR ERROR CHECKING)
	//printf("Postfix String: %s \n", postFixString.c_str());
	//resize the array so we don't have overflow
	postfix.resize(count);
	 return true;
 };

//
//Calculate
//

//Calculate's result will be the top of the Stack result after completing this function
bool calculate(Array <Expression_Command *> & postfix, Stack <int> & result)
{
	//execute returns a bool, so i created this to set it equal to the execute return
	bool x =true;
	//iterate through the array
	for(size_t i = 0; i < postfix.size(); i++)
	{
		//execute each command one at a time
		try
		{
			x = postfix.get(i)->execute(result);
		}
		// catch "divide by" exceptions
		catch(divide_by_zero_exception)
		{
			printf("Divide by zero error, try again.\n");
			return false;
		}
		catch(mod_by_zero_exception)
		{
			printf("Mod by zero error, try again.\n");
			return false;
		}
	}
	return true;
} 


//
//checkIsValidExpression
//
bool checkIsValidExpression(const std::string & inputStr)
{
        std::istringstream input(inputStr); // create a input stream parser
        std::string token; // current token in string/stream
	// Flags to check if we have two operators next to each other or two operands next to each other
	bool SecondOperatorFlag = false;
	bool SecondOperandFlag = false;
	bool firstToken = true;
	//counts parantheses both opened and closed
	int numOpenParen = 0;
	int numCloseParen = 0;
	int number = 0;
	//loop until the end of file
        while (!input.eof())
        {
        	input >> token;
		//check to ensure the first token is an integer or an open paren
		if (firstToken == true)
		{
			firstToken = false;
			if(token == "(")
			{
				//do nothing
			}
			else
			{
				SecondOperandFlag == true;
				try
                        	{
                                	//convert a string into an integer
                                        number = std::stoi(token.c_str());
                                }
                                catch(const std::invalid_argument& err)
                                {
 	                               return false;
                                }
                        }                                                                                                                                                                
		}
		
		//check if token is an operator token
        	if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "(" || token == ")")
        	{
			if(SecondOperatorFlag && token != "(")
			{
				return false;
			}
			//set operator flag to true and operand flag to false (next token we want is an operand)
			SecondOperandFlag = false;
			SecondOperatorFlag = true;
			//increment respective parentheses counter
			if(token == "(")
			{
				numOpenParen++;	
			}
			else if(token == ")")
			{
				numCloseParen++;
				SecondOperatorFlag = false; // this is done to ensure an operator can follow a closed paren
				SecondOperandFlag = true; // this is done to ensure an operand may not follow a cloden paren
			}
			//if we have more closed parentheses than open at any time it cannot be a valid expression
			if(numOpenParen < numCloseParen)
			{
				return false;
			}
			if(numCloseParen == 1)
			{
				//remove a close and open parentheses from our count
				numCloseParen--;
				numOpenParen--;
			}
		}	
		//if it is not an operator token it must be an operand token
        	else
       		{
			//check for two operands in a row, if found return false
                	if(SecondOperandFlag)
			{
				return false;
			}
			//this try catch will cause this function to return false for any invalid input ie: "1 ++ 1"
			try 
			{
				//convert a string into an integer
				number = std::stoi(token.c_str());
			}
			catch(const std::invalid_argument& err)
			{
				return false;
			}
			//set operand flag to true and operator flag to false (next token we want is an operator)
        		SecondOperandFlag = true;
			SecondOperatorFlag = false;

		}
	}	
	//check the number of close parentheses matches the number of open parentheses
	//last token should be an integer or a closen parentheses, so this will check that and return false if that is not the case
	if(token != ")")
	{
		try
        	{
        		//convert a string into an integer
        		number = std::stoi(token.c_str());
        	}
        	catch(const std::invalid_argument& err)
        	{
      			return false;
        	}	
	}
	//check the number of closed parentheses matches the number of open parentheses
        if(numCloseParen != numOpenParen)
	{
		return false;
	}
	//return true if the expression passes all of the tests
	return true;
}
