//
//  NotationConverter.hpp
//  NotationConverter
//
//  Created by Antonio Galvan Perez on 9/22/18.
//  Copyright © 2018 Antonio Galvan perez. All rights reserved.
//

#ifndef NotationConverter_hpp
#define NotationConverter_hpp
#include <iostream>
#include <stdio.h>
#include <string.h>



class NotationConverter{
public:

/***************************************Constructor***********************************************/
    NotationConverter();
/***************************************Destructor************************************************/
    ~NotationConverter();
/*********************************************Setter**********************************************/
        //This method takes in a string of POSTFIX notation and return a string in th INFIX notation
    std::string postfixToInfix(std::string inStr);

    //This method takes in a string of POSTFIX notation and returns a string in the PREFIX notation
    std::string postfixToPrefix(std::string inStr);

    //This method takes in a string of INFIX notation and returns a string in the POSTFIX notation
    std::string infixToPostfix(std::string inStr);

    //This method takes in a string of INFIX notation and returns a string in the PREFIX notatation
    std::string infixToPrefix(std::string inStr);

    //This method takes in a string of PREFIX notation and returns a string in INFIX notation
    std::string prefixToInfix(std::string inStr);

    //This method takes in a string of PREFIX notation and returns a string in POSTFIX notatation
    std::string prefixToPostfix(std::string inStr);
private:
    
};



#endif /* NotationConverter_h */
