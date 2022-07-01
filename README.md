# Stacks
Using Stacks and Overloaded == operator

Part1: File: assign5.cpp, LinkedStack.h

Write and demonstrate the following functions in assign5.cpp: 

a.evenNumbers:  the function receives a stack of integers and returns a new stack with all the even values from the passed stack (preserving the original order).For example, if the passed stack has the values { 4, 5, 3, 2, 6, 9, 2 } (where 4 is at thetop), the function returns a new stack with values { 4, 2, 6, 2 }. The initial stack should retain its original values.

b.toBinary: Write the function toBinary that uses a stack, instead of recursion, to convert a decimal number into itsequivalent binary representation.

Part2: Files: arrayTest.cpp, myStack.h, linkedTest.cpp, LinkedStack.h
Overload the == operator for both stackTypeclass andLinkedStack class so that true is returned if two stacks are exactly the same, or false otherwise.  You need to write two programs to demonstrate the operator; arrayTest.cpp and linkedTest.cpp.

-------------

FeedBack:

Part2: == operator was not overloaded correctly. Try to use the stack’s function to do it.
