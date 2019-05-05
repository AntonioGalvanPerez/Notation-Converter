//
//  main.cpp
//  Notation Calc
//
//  Created by Antonio Galvan perez on 5/3/19.
//  Copyright © 2019 Antonio Galvan Perez. All rights reserved.
//

#include <iostream>
#include "NotationConverter.cpp"

std::string readLine(){
    std::string returnString;
    char c = getchar();
    while (c != '\n'){
        returnString = returnString + c;
        c = getchar();
    }
    return returnString;
}

int main(int argc, const char * argv[]) {
    const std::string infix1 = "(A + B)";
    std::string convertingString;
    int input = 0;
    
    NotationConverter nc;
    std::cout << "What is the format of the input?\nEnter: \n1: Postfix\n2: Prefix\n3: Infix\n\n\nInput: ";
    std::cin >> input;
    
    switch (input) {
        case 1:
            std::cin.ignore();
            std::cout << "please enter in Infix in following format V C +: ";
            convertingString = readLine();
            
            std::cout<<"\nInfix: " << nc.postfixToInfix(convertingString) << std::endl;
            std::cout<<"Prefix: " << nc.postfixToPrefix(convertingString) << std::endl;
            break;
            
            
        case 2:
            std::cin.ignore();
            std::cout << "please enter in Prefix in following format + / * x y g h: ";
            convertingString = readLine();
            
            std::cout<<"\nInfix: " << nc.prefixToInfix(convertingString) << std::endl;
            std::cout<<"Postfix: " << nc.prefixToPostfix(convertingString) << std::endl;
            break;
        case 3:
            std::cin.ignore();
            std::cout << "please enter in Infix in following format (A + B): ";
            convertingString = readLine();
            
            std::cout<<"\nPrefix: " << nc.infixToPrefix(convertingString) << std::endl;
            std::cout<<"Postfix: " << nc.infixToPostfix(convertingString) << std::endl;
            break;
            
        default:
            std::cout << "Incorrect input.\n";
            break;
    }
    
    return 0;
}

