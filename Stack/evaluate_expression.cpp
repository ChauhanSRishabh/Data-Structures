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

INFIX TO POSTFIX
A*B+C*D-E
(A*B)+(C*D)-E
(AB*)+(CD*)-E
{(AB*)(CD*)+}-E
{(AB*)(CD*)+}E-
AB*CD*+E-

How is evaluation done?
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
get a token of either operator or operand
List : 2 3 
Now * operator, pop preceding 2 and perform operation
List : 6 5 4
Now * operator, pop preceding 2 and perform operation
List : 6 20
and so on..........

What comes in last, goes out first.
Our List is nothing but a Stack. Draw the logical implementation.

This is an efficient algo as we are doing just one pass on the expression
*/