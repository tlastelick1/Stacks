//*************************************************************
// Author: D.S. Malik
// Edited by Marwa Hassan
// This class specifies the basic operation on a stack as a
// linked list.
//*************************************************************

#ifndef H_StackType
#define H_StackType
 
#include <iostream>
#include <cassert>

#include "stackADT.h"

using namespace std;

template <class Type>
class LinkedStack: public stackADT<Type>
{

private:
    
    struct nodeType
    {
        Type info;
        nodeType *next;
    };
    
    nodeType *stackTop; //pointer to the stack
    
    void copyStack(const LinkedStack<Type>& otherStack);
    //Function to make a copy of otherStack.
    //Postcondition: A copy of otherStack is created and
    //    assigned to this stack.
public:
    LinkedStack();
    //Default constructor
    //Postcondition: stackTop = NULL;
    
    bool isEmptyStack() const;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty;
      //    otherwise returns false.

    bool isFullStack() const;
      //Function to determine whether the stack is full.
      //Postcondition: Returns false.

    void initializeStack();
      //Function to initialize the stack to an empty state. 
      //Postcondition: The stack elements are removed; 
      //    stackTop = NULL;

    void push(const Type& newItem);
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem is 
      //    added to the top of the stack.

    Type top() const;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program 
      //    terminates; otherwise, the top element of
      //    the stack is returned.

    void pop();
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top 
      //    element is removed from the stack.


    LinkedStack(const LinkedStack<Type>& otherStack);
      //Copy constructor

    ~LinkedStack();
      //Destructor
      //Postcondition: All the elements of the stack are removed.
    
    const LinkedStack<Type>& operator=
    (const LinkedStack<Type>&);
    //Overload the assignment operator.

    void display();
    //Function to display the contents of a stack
    //Postcondition: displays each node's info contents starting with top
    
    bool operator==(const LinkedStack<Type>& lhs, const LinkedStack<Type>& rhs);
    //overloaded == operator returns true if both stacks are the same
    

};

    //Default constructor
template <class Type> 
LinkedStack<Type>::LinkedStack()
{
    stackTop = NULL;
}

template <class Type>
bool LinkedStack<Type>::isEmptyStack() const
{
    return(stackTop == NULL);
} //end isEmptyStack

template <class Type>
bool LinkedStack<Type>:: isFullStack() const
{
    return false;
} //end isFullStack

template <class Type>
void LinkedStack<Type>:: initializeStack()
{
    nodeType *temp; //pointer to delete the node

    while (stackTop != NULL)  //while there are elements in 
                              //the stack
    {
        temp = stackTop;    //set temp to point to the 
                            //current node
        stackTop = stackTop->next;  //advance stackTop to the
                                    //next node
        delete temp;    //deallocate memory occupied by temp
    }
} //end initializeStack


template <class Type>
void LinkedStack<Type>::push(const Type& newElement)
{
    nodeType *newNode;  //pointer to create the new node

    newNode = new nodeType; //create the node

    newNode->info = newElement; //store newElement in the node
    newNode->next = stackTop; //insert newNode before stackTop
    stackTop = newNode;       //set stackTop to point to the 
                              //top node
} //end push


template <class Type>
Type LinkedStack<Type>::top() const
{
    assert(stackTop != NULL); //if stack is empty,
                              //terminate the program
    return stackTop->info;    //return the top element 
}//end top

template <class Type>
void LinkedStack<Type>::pop()
{
    nodeType *temp;   //pointer to deallocate memory

    if (stackTop != NULL)
    {
        temp = stackTop;  //set temp to point to the top node

        stackTop = stackTop->next;  //advance stackTop to the
                                    //next node
        delete temp;    //delete the top node
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class Type> 
void LinkedStack<Type>::copyStack
                     (const LinkedStack<Type>& otherStack)
{
    nodeType *newNode, *current, *last;

    if (stackTop != NULL) //if stack is nonempty, make it empty
        initializeStack();

    if (otherStack.stackTop == NULL)
        stackTop = NULL;
    else
    {
        current = otherStack.stackTop;  //set current to point
                                   //to the stack to be copied

            //copy the stackTop element of the stack 
        stackTop = new nodeType;  //create the node

        stackTop->info = current->info; //copy the info
        stackTop->next = NULL;  //set the next field of the
                                //node to NULL
        last = stackTop;        //set last to point to the node
        current = current->next;    //set current to point to
                                    //the next node

            //copy the remaining stack
        while (current != NULL)
        {
            newNode = new nodeType;

            newNode->info = current->info;
            newNode->next = NULL;
            last->next = newNode;
            last = newNode;
            current = current->next;
        }//end while
    }//end else
} //end copyStack

    //copy constructor
template <class Type>   
LinkedStack<Type>::LinkedStack(
                      const LinkedStack<Type>& otherStack)
{
    stackTop = NULL;
    copyStack(otherStack);
}//end copy constructor

    //destructor
template <class Type> 
LinkedStack<Type>::~LinkedStack()
{
    initializeStack();
}//end destructor

    //overloading the assignment operator
template <class Type>   
const LinkedStack<Type>& LinkedStack<Type>::operator=
    			  (const LinkedStack<Type>& otherStack)
{ 
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this; 
}//end operator=


template <class Type>
bool LinkedStack<Type>::operator==(const LinkedStack<Type>& lhs, const LinkedStack<Type>& rhs)
{
    nodeType *nodePtr, *otherPtr = nullptr;    
    nodePtr = this;
    otherPtr = otherStack;
    bool balance = true;
    
     while (balance == true)
     {
     if (nodePtr->info == otherPtr->info)
     {
     balance = true;
     nodePtr = nodePtr->next;
     otherPtr = otherPtr->next;
     }
     
     else 
     balance = false;
     }
             
     return balance;
            
}

template <class Type>
void LinkedStack<Type>::display()
{
    nodeType *nodePtr = nullptr;
    nodePtr = stackTop; // start at top of the list
    // traverse the list
    if (!nodePtr)
    cout << "Is an empty list.";
    
    while (nodePtr != nullptr)
    {
        cout << nodePtr->info << endl;
        nodePtr = nodePtr->next;
    }
}

#endif
