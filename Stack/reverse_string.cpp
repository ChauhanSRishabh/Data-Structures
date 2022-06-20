#include <iostream>
#include <stack> //stack from STL
// when we use the above method, we have a 'stack' class available to us
// To create an object of this class, we write stack<data_type> name/identifier

using namespace std;

// STRING REVERSAL USING STACK

void Reverse(char C[], int n) // We could have written char* C instead of char C[], as it is interpretd as char* C by the compiler
// n is the4 length of string
{
    stack<char> S; // Created a stack of characters named S using STL
    //Loop for Push
    for (int i = 0; i < n; i++)
    {
        S.push(C[i]);
    }
    //Loop for Pop
    for (int i = 0; i < n; i++)
    {
        C[i]=S.top(); //Overwrite the character at index i
        S.pop(); //perform Pop Operation
    }    
}

