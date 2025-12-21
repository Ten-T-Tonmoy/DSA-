#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

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
