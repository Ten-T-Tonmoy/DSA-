#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class Queue
{
private:
    Node *front;
    Node *back;
    int size;

public:
    Queue()
    {
        front = back = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int val)
    {
        Node *temp = new Node(val);
        if (back == nullptr)
            front = back = temp;
        else
        {
            back->next = temp;
            back = temp;
        }
        // delete temp; //should i ? no cause it got added
        size++;
    }

    void dequeue()
    { // from front shit will go
        if (isEmpty())
        {
            cout << " Cmon bro u are poor asf! " << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == nullptr)
            back = nullptr;
        delete temp;
        size--;
    }

    int peek()
    { // to see the last val without poping
        if (isEmpty())
        {
            cout << " Cmon bro u are poor asf! " << endl;
            return -1;
        }
        return front->data;
    }

    int sizeQ()
    {
        return size;
    }

    void printQueue()
    {
        if (isEmpty())
        {
            cout << " Cmon bro u are poor asf! " << endl;
            return;
        }

        Node *temp = front;
        cout << "The elements of the queue are : ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        // delete temp; dont delete cause it isn occupying
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Queue q;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(1);
    q.enqueue(8);
    q.enqueue(4);
    q.dequeue();
    q.printQueue();
    cout<<"The front element is : "<<q.peek()<<endl;
    return 0;
}