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
*/