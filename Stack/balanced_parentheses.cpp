#include <iostream>
#include <stack>

using namespace std;

// CHECK FOR BALANCED PARENTHESES
// LOGIC : Last unclosed must be first closed

/* SOLUTION :
Scan from left to right
If opening symbol, add it to a list (PUSH)
If closing symbol, remove last opening symbol in list (POP)
We'll have an empty list at the end
*/

bool CheckBalancedParentheses(char *exp, int n)
{
    stack<char> S;
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            S.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (S.empty() || (S.top() != exp[i])) //last unclosed must be first closed
                return true;
            else
                S.pop();
        }
    }
    if (S.empty())
        return true;
    else
        return false;
}
