# Data-Structures
Implementing Data Structures in C/C++

## Concepts

### ADT - Abstract Data Type
When we talk about a data structure as ADT, we only talk about the features/operations available with the data structure. We do not go into the implementation details. So, basically we define the data structure as a mathematical/logical model.

### NULL
NULL is basically assigned to a pointer to specify that the pointer points to no valid memory location.

## Stacks

### Stack ADT
A list with the restriction that insertion and deletion can only be performed from one end, called **Top**

Stack is also called **Last In First Out(LIFO)** structure. What goes in last, comes out first.

### Operations
1. **Push()** - Inserting an element into a stack.
2. **Pop()** - Removing the most recent element from the stack.
3. **Top()** - Returns the element at top of the stack
4. **IsEmpty()** - Checks whether the stack is empty or not. Returns *True* if empty, *False* otherwise.

All the operations mentioned above can be performed in constant time, i.e., their time-complexity is O(1)

### Applications of Stack
1. **Function calls/Recursion**
2. **undo operation in an editor**
3. **Balanced Parenthesis** - a compiler verifies whether the parenthesis are balanced or not, i.e., to each opening  parenthesis in a source code, there must be a closing parenthesis. Eg- {()}

### Where to use a Stack?
1. Reversal of string
2. Reversal of LL

### Stack STL

When we use #include <stack>, we have a 'stack' class available to us.  
To create an object of this class, we write **stack<data_type> name/identifier**  
Eg : stack <char> S; creates a stack of characters named S using STL  

#### Functions Available:
1. **S.push(num/char)** - Inserting an element into a stack.
2. **S.pop()** - Removing the most recent element from the stack.
3. **S.top()** - Returns the element at top of the stack
4. **S.empty()** - Checks whether the stack is empty or not. Returns *True* if empty, *False* otherwise.
