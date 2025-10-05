#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// ------------------------------Prefix to Infix------------------------------------------
string prefixToInfix(const string &prefix)
{
    stack<string> s;
    for (int i = prefix.length() - 1; i >= 0; --i)
    {
        char c = prefix[i];
        if (isOperator(c))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string expr = "(" + op1 + c + op2 + ")";
            s.push(expr);
        }
        else
        {
            s.push(string(1, c));
        }
    }
    return s.top();
}

// ----------------------------------Infix to Prefix------------------------------------------
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

string infixToPrefix(const string &infix)
{
    string revInfix = infix;
    reverse(revInfix.begin(), revInfix.end());

    for (char &c : revInfix)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    stack<char> ops;
    string result;

    for (char c : revInfix)
    {
        if (isalnum(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            ops.push(c);
        }
        else if (c == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                result += ops.top();
                ops.pop();
            }
            if (!ops.empty())
                ops.pop();
        }
        else if (isOperator(c))
        {
            while (!ops.empty() && precedence(ops.top()) > precedence(c))
            {
                result += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }
    while (!ops.empty())
    {
        result += ops.top();
        ops.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

// -----------------------Postfix to Infix--------------------------------------
string postfixToInfix(const string &postfix)
{
    stack<string> s;
    for (char c : postfix)
    {
        if (isOperator(c))
        {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();
            string expr = "(" + op1 + c + op2 + ")";
            s.push(expr);
        }
        else
        {
            s.push(string(1, c));
        }
    }
    return s.top();
}

string infixToPostfix(const string &infix)
{
    stack<char> ops;
    string result;

    for (char c : infix)
    {
        if (isalnum(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            ops.push(c);
        }
        else if (c == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                result += ops.top();
                ops.pop();
            }
            if (!ops.empty())
                ops.pop();
        }
        else if (isOperator(c))
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(c))
            {
                result += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }
    while (!ops.empty())
    {
        result += ops.top();
        ops.pop();
    }
    return result;
}

string prefixToPostfix(const string &prefix)
{
    stack<string> s;
    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        char c = prefix[i];
        if (isOperator(c))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string expr = op1 + op2 + c;
            s.push(expr);
        }
        else
        {
            s.push(string(1, c));
        }
    }
    return s.top();
}

string postfixToPrefix(const string &postfix)
{
    stack<string> s;
    for (char c : postfix)
    {
        if (isOperator(c))
        {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();
            string expr = c + op1 + op2;
            s.push(expr);
        }
        else
        {
            s.push(string(1, c));
        }
    }
    return s.top();
}

int main()
{
    // Prefix:  + 3 * 4 5
    // Infix:   3 + (4 * 5)
    // Postfix: 3 4 5 * +

    cout << "choose option:\n";
    cout << "1. Prefix to Infix\n2. Infix to Prefix\n3. Postfix to Infix\n4. Infix to Postfix\n5. Prefix to Postfix\n6. Postfix to Prefix\n";
    int choice;
    cin >> choice;
    cout << "Enter expression:\n";
    string expr;
    cin >> expr;

    switch (choice)
    {
    case 1:
        cout << "Infix: " << prefixToInfix(expr) << endl;
        break;
    case 2:
        cout << "Prefix: " << infixToPrefix(expr) << endl;
        break;
    case 3:
        cout << "Infix: " << postfixToInfix(expr) << endl;
        break;
    case 4:
        cout << "Postfix: " << infixToPostfix(expr) << endl;
        break;
    case 5:
        cout << "Postfix: " << prefixToPostfix(expr) << endl;
        break;
    case 6:
        cout << "Prefix: " << postfixToPrefix(expr) << endl;
        break;
    default:
        cout << "Invalid choice\n";
        break;
    }

    return 0;
}
