//**********************************************************************
//Name: Trevor Lastelick
//Class: COSC 2437 Fall20
//Instructor: Marwa Hassan
//Assignment 5
//Date: 10/23/20
//Program Description: This program creates a stack st1 and initializes it with some variables. It then creates stack st2 and uses the function evenList to fill st2 with all the even varaibles of st1. It also runs the function toBinary on st1 which displays all the elements of st1 converted into binary, maintaining the original values of st1. 

#include <iostream>
#include <vector>
#include "LinkedStack.h"
using namespace std;

template <class Type>
void toBinary(LinkedStack<Type> &otherStack);

template <class Type>
LinkedStack<Type> evenList(LinkedStack<Type> &otherStack);

int main()
{

    
    LinkedStack<int> st1; 
    st1.push(10);
   // st1.push(11);
    st1.push(5);
    st1.push(2);
    st1.push(7);
    st1.push(8);
    LinkedStack<int> st2;
    st2 = evenList(st1);
    st2.display();
    toBinary(st1);

    return 0;
}

/*  
TEACHER NOTE: I tried many different things. I concluded there's something wrong with my math. I'm not very good at math. I cannot figure it out. 
template <class Type>
void toBinary(LinkedStack<Type> &otherStack)
{
    Type num;
    Type temp; // to be pushed into vector
    vector<Type> vec;
    num = otherStack.top(); // num equals decimal number to convert 
    cout << 1%2 << endl;
    cout << (1/2)%2;
    //cout << 1/2;
    // traverse the stack 
  // while (!otherStack.isEmptyStack())
   // {
   // num = otherStack.top(); // num equals decimal number to convert 
    // convert decimal to binary
   // cout << "Decimal Number " << otherStack.top() << " converted into binary = ";
   // while (num >= 1)
   // {
       // cout << num%2;
        
   //     num = num/2;
   //     temp = num%2;
   //     cout << temp;
   //     vec.push_back(temp);
       //cout << num << endl;
        //cout << num%2;
   // }
    // display vector and then pop contents
    //for (int i=vec.size(); i>0; i--)
      //  cout << vec[i];
   
   vec.clear(); // clear all contents of vector. sets vec.size() back to 0
    otherStack.pop(); // move onto next number in stack
    cout << endl;
   // }

}
*/

// toBinary function converts a decimal number into its equivalent binary representation.
// Precondition: a non-empty stack as the argument
// Postcondition: each number is converted (does not permanently change argument stack) and is displayed
template <class Type>
void toBinary(LinkedStack<Type> &otherStack)
{
    Type num;
    num = otherStack.top(); // num equals decimal number to convert 
    // traverse the stack 
    while (!otherStack.isEmptyStack())
    {
    num = otherStack.top(); // num equals decimal number to convert 
    // convert decimal to binary
    cout << "Decimal Number " << otherStack.top() << " converted into binary = ";
    while (num != 0)
    {
        cout << num%2;
        num = num/2;
    }
    otherStack.pop();
    cout << endl;
    }
}
// evenList Function receives a stack of integers and returns a new stack withall the even values from the passed stack (preserving the original order).
// Precondition: An empty stack exists to = the argument stack
// Postcondition: The empty stack is filled with every even number in the argument stack

template <class Type>
LinkedStack<Type> evenList(LinkedStack<Type> &otherStack)
{
    LinkedStack<Type> catStack = otherStack; // creates stack to be popped
    LinkedStack<Type> returnStack;
    // if top is odd, pop
    while (!catStack.isEmptyStack())
    {
    if (catStack.top()%2==1)
        catStack.pop();
    
    // else add to a new stack
    else
        {
        returnStack.push(catStack.top());
        catStack.pop();
        }
    //returnStack.display();   
    }
    return returnStack; 
}

