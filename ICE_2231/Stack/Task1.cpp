#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

enum Mode
{
    STACK_MODE,
    QUEUE_MODE
};

int main()
{
    Mode mode = STACK_MODE;
    stack<int> s;
    queue<int> q;
    string cmd;
    int val;

    while (true)
    {
        cin >> cmd;
        if (cmd == "Q")
        {
            cout << "Exiting..." << endl;
            break;
        }
        else if (cmd == "s")
        {
            mode = STACK_MODE;
            stack<int> temp = s;
            cout << "STACK MODE: ";
            vector<int> tempVec;
            while (!temp.empty())
            {
                tempVec.push_back(temp.top());
                temp.pop();
            }
            for (int i = tempVec.size() - 1; i >= 0; i--)
                cout << tempVec[i] << " ";
            cout << endl;
        }
        else if (cmd == "q")
        {
            mode = QUEUE_MODE;
            queue<int> temp = q;
            cout << "QUEUE MODE: ";
            while (!temp.empty())
            {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        }
        else if (cmd == "p")
        {
            if (mode == STACK_MODE)
            {
                if (!s.empty())
                {
                    cout << "Popped from stack: " << s.top() << endl;
                    s.pop();
                }
            }
            else
            {
                if (!q.empty())
                {
                    cout << "Removed from queue: " << q.front() << endl;
                    q.pop();
                }
            }
        }
        else
        {
            try
            {
                val = stoi(cmd);
                if (mode == STACK_MODE)
                {
                    s.push(val);
                    cout << "Pushed onto stack: " << val << endl;
                }
                else
                {
                    q.push(val);
                    cout << "Inserted into queue: " << val << endl;
                }
            }
            catch (...)
            {
                cout << "Invalid input!" << endl;
            }
        }
    }
    return 0;
}
