#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

/*
Scan from right to left (because it’s prefix).

Operands → push onto stack.

Operators → pop two operands a and b from stack,
 combine as (a operator b), then push back.

Repeat until the whole expression is processed
*/
string prefixToInfix(string exp)
{
    stack<string> s;
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        if (!isOperator(exp[i]))
        {
            s.push(string(1, exp[i]));
        }
        else
        {
            string a = s.top();
            s.pop();
            string b = s.top();
            s.pop();
            s.push("(" + a + exp[i] + b + ")");
        }
    }
    return s.top();
}
/*
Scan from left to right (because it’s postfix).

Operands → push onto stack.

Operators → pop two operands a
(first popped is b, second popped is a)
 → combine (a operator b) → push back
*/

string postfixToInfix(string exp)
{
    stack<string> s;
    for (int i = 0; i < exp.length(); i++)
    {
        if (!isOperator(exp[i]))
        {
            s.push(string(1, exp[i]));
        }
        else
        {
            string b = s.top();
            s.pop();
            string a = s.top();
            s.pop();
            s.push("(" + a + exp[i] + b + ")");
        }
    }
    return s.top();
}

/*
Scan right to left (prefix).

Operands → push.

Operators → pop two operands 
a & b → combine a + b + operator → push back.
*/

string prefixToPostfix(string exp)
{
    stack<string> s;
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        if (!isOperator(exp[i]))
        {
            s.push(string(1, exp[i]));
        }
        else
        {
            string a = s.top();
            s.pop();
            string b = s.top();
            s.pop();
            s.push(a + b + exp[i]);
        }
    }
    return s.top();
}

string postfixToPrefix(string exp)
{
    stack<string> s;
    for (int i = 0; i < exp.length(); i++)
    {
        if (!isOperator(exp[i]))
        {
            s.push(string(1, exp[i]));
        }
        else
        {
            string b = s.top();
            s.pop();
            string a = s.top();
            s.pop();
            s.push(exp[i] + a + b);
        }
    }
    return s.top();
}

int main()
{
    string prefix = "*+AB-CD";
    string postfix = "AB+CD-*";

    cout << prefixToInfix(prefix) << endl;
    cout << postfixToInfix(postfix) << endl;
    cout << prefixToPostfix(prefix) << endl;
    cout << postfixToPrefix(postfix) << endl;

    return 0;
}
