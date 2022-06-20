#include <iostream>
#include <stack> //stack from STL
// when we use the above method, we have a 'stack' class available to us
// To create an object of this class, we write stack<data_type> name/identifier

using namespace std;

// STRING REVERSAL USING STACK

void Reverse(char C[], int n) 
// We could have written char* C instead of char C[], as it is interpretd as char* C by the compiler
// Time Complexity = O(n)
// Space Complexity = O(n)
// can be improved to O(n/2)
{
    stack<char> S; // Created a stack of characters named S using STL
    // Loop for Push
    // Time Complexity = O(n)
    for (int i = 0; i < n; i++)
    {
        S.push(C[i]);
    }
    // Loop for Pop
    // Time Complexity = O(n)
    for (int i = 0; i < n; i++)
    {
        C[i] = S.top(); // Overwrite the character at index i
        S.pop();        // perform Pop Operation
    }
}

int main()
{
    char C[51];
    printf("Enter a string : ");
    gets(C);
    Reverse(C, strlen(C));
    printf("Output = %s", C);
    return 0;
}
