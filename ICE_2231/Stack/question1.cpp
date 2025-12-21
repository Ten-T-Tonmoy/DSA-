#include <iostream>
using namespace std;

//------------------------Stack------------------------------
class Stack
{
    char arr[100];
    int topIndex;

public:
    Stack()
    {
        topIndex = -1;
    }

    void push(char x)
    {
        topIndex++;
        arr[topIndex] = x;
    }

    void pop()
    {
        if (topIndex >= 0)
            topIndex--;
    }

    char top()
    {
        return arr[topIndex];
    }

    bool empty()
    {
        return topIndex == -1;
    }
};

//------------------------------------Queue------------------------------
class Queue
{
    char arr[100];
    int frontIndex;
    int rearIndex;

public:
    Queue()
    {
        frontIndex = 0;
        rearIndex = -1;
    }

    void push(char x)
    {
        rearIndex++;
        arr[rearIndex] = x;
    }

    void pop()
    {
        if (frontIndex <= rearIndex)
            frontIndex++;
    }

    char front()
    {
        return arr[frontIndex];
    }

    bool empty()
    {
        return frontIndex > rearIndex;
    }
};

void usingQueue()
{
    Queue q;
    char popped[10];
    int k = 0;

    q.push('d');
    q.push('h');
    popped[k++] = q.front();
    q.pop();

    q.push('f');
    q.push('s');
    popped[k++] = q.front();

    q.pop();
    popped[k++] = q.front();

    q.pop();
    q.push('m');

    cout << "Sequence of popped vals : ";
    for (int i = 0; i < k; i++)
        cout << popped[i] << " ";
    cout << endl;
}

void usingStack()
{
    Stack s;
    char popped[10];
    int k = 0;

    s.push('d');
    s.push('h');
    popped[k++] = s.top();
    s.pop();

    s.push('f');
    s.push('s');
    popped[k++] = s.top();

    s.pop();
    popped[k++] = s.top();

    s.pop();
    s.push('m');

    cout << "Sequence of popped vals : ";
    for (int i = 0; i < k; i++)
        cout << popped[i] << " ";
    cout << endl;
}

int main()
{
    usingQueue();
    usingStack();
    return 0;
}
