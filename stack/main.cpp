/**************************************************************\           
    * POSTFIX CALCULATOR - OBJECTIVE IMPLEMENTATION        *   
    *                                                      *   
    * Language:  C++                                       *   
    *                                                      *   
    * Author:  Daniel Miksa                                *   
    *                                                      *   
    * Purpose:  Educational purpose                        *   
    *                                                      *   
    * Usage:                                               *   
    *      Program is  starting  with welcome  message and *  
    * asks about equation to calculate.  User have to type *   
    * the equation   in  postfix form. Any other form will *   
    * cause  that  the  program  display an error message. *    
    * Be careful when you are  typing to  do not leave any *    
    * additional space  after  equation, otherwise program *    
    * can work unstable.                                   *    
    *                                                      *    
\**************************************************************/  

#include "header.hpp"

/* ------------ MAIN PROGRAM LOOP --------------- */

int main()
{
	Calculator calc1;
	calc1.program();
	return 0;
}