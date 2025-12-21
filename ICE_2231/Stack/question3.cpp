#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

int applyOp(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
        return a / b;
    return 0;
}

int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int solveInfix(string expr)
{
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < expr.length(); i++)
    {
        if (isspace(expr[i]))
            continue;

        if (isdigit(expr[i]))
        {
            int val = 0;
            while (i < expr.length() && isdigit(expr[i]))
            {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        }
        else if (expr[i] == '(')
        {
            ops.push(expr[i]);
        }
        else if (expr[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.pop();
        }
        else
        {
            while (!ops.empty() && priority(ops.top()) >= priority(expr[i]))
            {
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.push(expr[i]);
        }
    }

    while (!ops.empty())
    {
        int b = values.top();
        values.pop();
        int a = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(a, b, op));
    }

    return values.top();
}

int solvePostfix(string expr)
{
    stack<int> s;
    for (int i = 0; i < expr.length(); i++)
    {
        if (isdigit(expr[i]))
            s.push(expr[i] - '0');
        else
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            s.push(applyOp(a, b, expr[i]));
        }
    }
    return s.top();
}

int solvePrefix(string expr)
{
    stack<int> s;
    for (int i = expr.length() - 1; i >= 0; i--)
    {
        if (isdigit(expr[i]))
            s.push(expr[i] - '0');
        else
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(applyOp(a, b, expr[i]));
        }
    }
    return s.top();
}

int evaluate(string expr)
{
    if (expr.empty())
        return 0;
    if (expr[0] == '+' || expr[0] == '-' || expr[0] == '*' || expr[0] == '/')
        return solvePrefix(expr);
    else if (!isdigit(expr.back()))
        return solvePostfix(expr);
    else
        return solveInfix(expr);
}

int main()
{
    string tests[5] = {"23+5*", "+34", "2+3*5", "84/", "((2+3)*5)"};
    for (int i = 0; i < 5; i++)
    {
        cout << "Test " << i + 1 << " result: " << evaluate(tests[i]) << endl;
    }
    return 0;
}
