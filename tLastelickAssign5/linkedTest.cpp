//**********************************************************************
//Name: Trevor Lastelick
//Class: COSC 2437 Fall20
//Instructor: Marwa Hassan
//Assignment 5
//Date: 10/23/20
//Program Description: This program creates a stack st1 and initializes it with some variables. It creates another stack, st2, with the exact same variables as st1. It then tests the overloaded operator== which returns true if all elements are the same in both stacks. It tests overloaded operator== with an if condition that couts "it worked" if both stacks are equal. 
#include <iostream>

using namespace std;
#include "LinkedStack.h"

int main()
{
    LinkedStack<int> st1;
    stack1.push(5);
    stack1.push(55);
    stack1.push(999);
    
    LinkedStack<int> st2 = st1;
    
    if (st1==st2)
    cout << "it worked";
       
    
    
    
    
    return 0;
}
