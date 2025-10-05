#include <iostream>

using namespace std;

class Node
{
public:
    string data;
    Node *next;

    Node(string x)
    {
        this->data = x;
        this->next = NULL;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        this->top = nullptr;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(string val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << val << " pushed to stack.\n";
    }

    void pop()
    {
    }

    void stackPrint()
    {

        Node *tempNode = this->top;

        cout << "Stack: ";
        while (top != nullptr)
        {
            cout << tempNode->data << " ";
            tempNode = tempNode->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack st;
    st.push("first");
    st.push("second");
    st.push("last");
    st.stackPrint();

    return 0;
}