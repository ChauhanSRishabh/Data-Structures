#include<iostream>
#include<stack>

using  namespace std;

//EVALUATION OF EXPRESSIONS

/*
INFIX : <operand> <operator> <operand>
Operator is placed in between operands
Operand : object on which operation is performed
does not need to be a constant/variable, it can be an expression itself
(p+q)*(r+s)

Order of Operation:
1) Parentheses (), {}, []
2) Exponents : ^ ; right to left/Right Associative ; => 2^3^2 = 2^9 = 512
3) Division and Multiplication : left to right/Left Associative ; If both are present, evaluate leftmost first as precedence is same. Also called Operator Associativity
4) Addition and Subtraction : left to right ; If both are present, evaluate leftmost first as precedence is same

Even though infix is most common way of writing expressions, it's not easy to parse and evaluate an infix exression without ambiguity. Hence, mathematicians came up with 2 other ways of writing expressions:
1) POSTFIX
2) PREFIX

PREFIX : <operator> <operand> <operand>
Also called Polish notation
Operator is placed before operands
2+3 in Infix will be written as +23 in Prefix
a+b*c will be +a*bc 
Just like Infix, Operand does not need to be a constant/variable, it can be an expression itself
In Prefix form, an operand can only be associated with 1 operator, unlike Infix

POSTFIX : <operand> <operand> <operator>
Also called  Reverse Polish notation
Operator is placed after the operands
2+3 in Infix will be written as 23+ in Prefix
a+b*c will be abc*+ 

CONVERSIONS :
PREFIX : a + b * c => a + (b*c) => a + (*bc) => +a (*bc) => +a*bc
POSTFIX : a + b * c => a + (b*c) => a + (bc*) => a(bc*)+ => abc*+

Infix : most human-readable
Prefix and Postfix : good for machines
*/

/*
POSTFIX EVALUATION

A*B+C*D-E
(A*B)+(C*D)-E
(AB*)+(CD*)-E
{(AB*)(CD*)+}-E
{(AB*)(CD*)+}E-
AB*CD*+E-

If given a postfix expression, how is evaluation done?
AB*CD*+E-
A=2 B=3 C=5 D=4 E=9
23*54*+9-
In Postfix expression, operands of an operator lie to it's left
<op1> <op2> <operator>
=> 6 54* +9-
=> 6 20 + 9-
=> 26 9-
=> 17

ALGORITHM
Parse from Left to Right
if operand, push it on to the stack
List : 2 3 
When operator, pop preceding 2 and perform operation,push the result of the operation
List : 6

Keep doing the above steps for the entire length of the expression
List : 6 5 4
operator *, pop 5 and 4, perform 5*4, push result
List : 6 20
and so on..........
Ultimately, top of stack will have the result

What comes in last, goes out first.
Our List is nothing but a Stack. Draw the logical implementation.

This is an efficient algo as we are doing just one pass on the expression
*/

/*
PREFIX EVALUATION

Infix : A*B+C*D-E
Prefix form : (*AB)+(*CD)-E => +(*AB)(*CD)-E => -+*AB*CDE
A=2 B=3 C=5 D=4 E=9

If given a prefix expression, how will evaluation proceed?
-+*23*549
In a prefix expression, operands of an operator lie to it's right.
<operator> <op1> <op2>

ALGORITHM
Scan from Right to left
We will use a stack
if operand, push it on to the stack
when operator encountered, pop 2 elements, 1st element popped will be <op1> and 2nd will be <op2>.......order matters if subtraction is to be done
perform operation,push the result of the operation into the stack

Keep doing the above steps for the entire length of the expression
Ultimately, top of stack will have the result
*/