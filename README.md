# Data-Structures
Implementing Data Structures in C/C++

## Concepts

###### ADT - Abstract Data Type
When we talk about a data structure as ADT, we only talk about the features/operations available with the data structure. We do not go into the implementation details. So, basically we define the data structure as a mathematical/logical model.


## Stacks

###### Stack ADT
A list with the restriction that insertion and deletion can only be performed from one end, called **Top**
Stack is also called **Last In First Out(LIFO)** structure. What goes in last, comes out first.

###### Operations
**Push()** - Inserting an element into a stack.
**Pop()** - Removing the most recent element from the stack.
**Top()** - Returns the element at top of the stack
**IsEmpty** - Checks whether the stack is empty or not. Returns *True* if empty, *False* otherwise.

All the operations mentioned above can be performed in constant time, i.e., their time-complexity is O(1)

