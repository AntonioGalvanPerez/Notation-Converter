//
//  NotationConverter
//
//  Created by Antonio Galvan Perez on 9/21/18.
//  Copyright © 2018 Antonio Galvan perez. All rights reserved.
//
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "NotationConverter.hpp"

//Takes char returns 1 if is an operand
int isOperator(char Operand);
//Deque functions
void push_Back(char c);
void push_Front(char c);
char pop_Back();
char pop_Front();
void testInput(char c);

//counters are used to find a pair of left and right brackets to remove items from deque

struct node{
    char input;
    int isString;
    std::string set;
    node *next;
    node *prev;
};

node* head;
node* tail;

/***************************************Constructor***********************************************/
NotationConverter::NotationConverter(){
    //sets up sentinal nodes
    node * current;
    current = new node;
    current->input = 0;
    current->prev = nullptr;
    head = current;
    tail = current;
}
/*********************************Destructor************************************************/
NotationConverter::~NotationConverter(){
    node* current = head;
    node* next = nullptr;
    while(current->prev != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}
    //This method takes in a string of POSTFIX notation and return a string in th INFIX notation
std::string NotationConverter::postfixToInfix(std::string inStr){
    
    std::string inputString = inStr;
    std::string returnString;
    //Keeps track of how many items are in the deque
    int count = 1;
    //A for loop is used to increment through each character of the string
    
    for (int i = 0; i < inputString.length();++i){
        char testChar = inputString.at(i);
        testInput(testChar);
        //Test for a left and right bracket pairing
        if (testChar == ' '){
            //std::cout << "Space found\n";
        }
        
        else if(isOperator(testChar)){
            std::string tempstring =")";
            if (count > 0){
                if (tail->isString == 0){
                    tempstring.insert(0,1,pop_Back());
                    tempstring.insert(0,1,' ');
                }
                else if(tail->isString == 1){
                    tempstring.insert(0,tail->set);
                    tempstring.insert(0,1,' ');
                    pop_Back();
                }
                
                tempstring.insert(0,1,testChar);
                tempstring.insert(0,1,' ');
                
                if (tail->isString == 0){
                    tempstring.insert(0,1,pop_Back());
                }
                else if(tail->isString == 1){
                    tempstring.insert(0,tail->set);
                    pop_Back();
                }
                
                tempstring.insert(0,1,'(');
                push_Back('Z');
                tail->set = tempstring;
                tail->isString = 1;
            }

            //std::cout<<("Operator found (...string...)\n");
        }
        else{
            push_Back(testChar);
            //std::cout<<("Operand found (...Deque...)\n");
        }
    }
    returnString = tail->set;
    
    return (returnString);
}

    //This method takes in a string of POSTFIX notation and returns a string in the PREFIX notation
    std::string NotationConverter::postfixToPrefix(std::string inStr){
        std::string tempString = postfixToInfix(inStr);
        tempString = infixToPrefix(tempString);
        return tempString;
    }

//*******************This method takes in a string of INFIX notation and returns a string in the POSTFIX notation*************************************
    std::string NotationConverter::infixToPostfix(std::string inStr){
        int LeftBracketCount = 0;
        int RightBracketCount = 0;
        
        std::string inputString = inStr;
        std::string returnString;
        //Keeps track of how many items are in the deque
        int count = 0;
        //A for loop is used to increment through each character of the string
        
        for (int i = 0; i < inputString.length();++i){
            char testChar = inputString.at(i);
            testInput(testChar);
        //Test for a left and right bracket pairing
            if (testChar == ' '){
                //std::cout << "Space found\n";
            }
            else if(testChar == '('){
                LeftBracketCount ++;
                //std::cout<<("LeftBracket found\n");
            }
            else if (testChar ==')'){
                RightBracketCount++;
                //std::cout<<("RightBracket found\n");
            }
            else if(isOperator(testChar)){
                push_Back(testChar);
                count++;
                //std::cout<<("Operator found (...Deque...)\n");
            }
            else{
                returnString += testChar;
                returnString += ' ';
                //std::cout<<("Operand found (...String...)\n");
            }
            if (LeftBracketCount > 0 && RightBracketCount > 0){
                //std::cout<<("Bracket Pair found (...Pop...)\n");
                if (count > 0){
                returnString += pop_Back();
                returnString += ' ';
                count--;
                }
                LeftBracketCount --;
                RightBracketCount --;
            }
        }
        //checks if everything is out of deque
        while(count > 0 ){
            returnString += pop_Back();
            count --;
        //std::cout<<("Empty Deque\n");
        }
        //std::cout << "Return string....\n" << returnString << "\n\n";
        return returnString;
    }

//***************************This method takes in a string of INFIX notation and returns a string in the PREFIX notatation***************************
    std::string NotationConverter::infixToPrefix(std::string inStr){
        std::string inputString = inStr;
        std::string returnString;
        int LeftBracketCount = 0;
        int RightBracketCount = 0;
        int count = 0;
        int length = static_cast <int> (inputString.length());
        
        //A for loop is used to increment through each character of the string
        
        for (int i = ( length - 1); i >= 0; --i){
            char testChar = inputString.at(i);
            testInput(testChar);
            //Test for a left and right bracket pairing
            if (testChar == ' '){
                //std::cout << "Space found\n";
            }
            else if(testChar == '('){
                LeftBracketCount ++;
                //std::cout<<("LeftBracket found\n");
            }
            else if (testChar ==')'){
                RightBracketCount++;
                //std::cout<<("RightBracket found\n");
            }
            else if(isOperator(testChar)){
                push_Back(testChar);
                count++;
                //std::cout<<("Operator found (...String...)\n");
            }
            else{
                returnString.insert(0,1,testChar);
                returnString.insert(0,1,' ');

                //std::cout<<("Operand found (...Deque...)\n");
            }
            
            
            if (LeftBracketCount > 0 && RightBracketCount > 0){
                //std::cout<<("Bracket Pair found (...Pop...)\n");
                if (count > 0){
                    returnString.insert(0,1,pop_Back());
                    returnString.insert(0,1,' ');
                    count--;

                }
                LeftBracketCount --;
                RightBracketCount --;
            }
        }
        return (returnString);
    }

    //This method takes in a string of PREFIX notation and returns a string in INFIX notation
    std::string NotationConverter::prefixToInfix(std::string inStr){
            
            std::string inputString = inStr;
            std::string returnString;
            int length = static_cast <int> (inputString.length());
        //std::cout <<"Length......." << length << "/n";
            //Keeps track of how many items are in the deque
            int count = 1;
            //A for loop is used to increment through each character of the string
            
            for (int i = ( length - 1); i >= 0; --i){
                char testChar = inputString.at(i);
                testInput(testChar);
                //Test for a left and right bracket pairing
                if (testChar == ' '){
                    //std::cout << "Space found\n";
                }
                
                else if(isOperator(testChar)){
                    //std::cout<<("Operator found (...string...)\n");
                    std::string tempstring ="(";
                    if (count > 0){
                        if (tail->isString == 0){
                            tempstring += pop_Back();
                            tempstring += ' ';
                        }
                        else if(tail->isString == 1){
                            tempstring += tail->set;
                            tempstring += ' ';
                            pop_Back();
                        }
                        
                        tempstring += testChar;
                        tempstring += ' ';
                        
                        if (tail->isString == 0){
                            tempstring += pop_Back();
                        }
                        else if(tail->isString == 1){
                            tempstring += tail->set;
                            pop_Back();
                        }
                        
                        tempstring += ')';
                        push_Back('Z');
                        tail->set = tempstring;
                        tail->isString = 1;
                    }
                }
                else{
                    push_Back(testChar);
                    //std::cout<<("Operand found (...Deque...)\n");
                }
            }
            returnString = tail->set;
            
            return (returnString);
        }

    //This method takes in a string of PREFIX notation and returns a string in POSTFIX notatation
    std::string NotationConverter::prefixToPostfix(std::string inStr){
        std::string tempStr = prefixToInfix(inStr);
        tempStr = infixToPostfix(tempStr);
        return tempStr;
    }

/*Helper Functions*/

//Takes char returns 1 if is an operand
int isOperator(char Operand){
    char checkValue = Operand;
    
    if (checkValue == '+' || checkValue  == '-' || checkValue  == '/' || checkValue == '*'){
        return (1);
    }
    else{
        return (0);
    }
}
//Push_back Function adds node to tail of linked list
void push_Back(char c){
    node* current;
    current = new node;
    current->input = c;
    
    //sets precedence of operator
    current->isString = 0;
    
    
    current-> prev = tail;
    tail->next = current;
    tail = current;
}
//Push_front Function add node to head on linked list
void push_Front(char c){
    node* current;
    current = new node;
    current ->input = c;
    
    //sets precedence of operator
    current->isString = 0;
    
    current->next = head;
    head->prev = current;
    head = current;
}


//Pop_front Function removes head node
char pop_Front(){
    char returnChar;
    returnChar = head->input;
//removes first node
    node* current;
    current = new node;
    current = head->next;
    current->prev = nullptr;
    head = current;
    
    return (returnChar);
}

//pop_Back function removes tail node
char pop_Back(){
    
    char returnChar;
    returnChar = tail->input;
// Removes last node
    node * current;
    current = new node;
    current = tail->prev;
    current->next = nullptr;
    tail = current;

    return (returnChar);
}

void testInput(char c){
    if (c != '(' && c != ')' && c != '-' && c != '+' && c != '-' && c != '*' && c != '/' && isalpha(c) == 0 && c != ' '){
        std::cout << "Input Error\n\n";
    }
}
