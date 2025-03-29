#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int front, back, size, cap;

public:
    CircularQueue(int cap)
    {
        this->cap = cap;
        arr = new int[cap];
        front = back = -1;
        // elegance
        size = 0;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }
    // manual garbage coll must man

    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return cap == size;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << " Cmon bro u got no place asf! " << endl;
            return;
        }
        if (isEmpty())
            front = back = 0;
        else
            back = (back + 1) % cap; // tot cap

        arr[back] = val;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << " Cmon bro u are poor asf! " << endl;
            return;
        }
        // dequeues from front always
        front = (front + 1) % cap;
        size--;
        if (size == 0)
            front = back = -1; // reseting
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << " Cmon bro u are poor asf! " << endl;
            return -1;
        }

        return arr[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << " Cmon bro u are poor asf! " << endl;
            return;
        }
        cout << "Queue Elements are : ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[(front + i) % cap] << " "; // start from front
        }
        cout << endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(60);
    q.enqueue(70);
    q.display();

    cout << "Front: " << q.peek() << endl;
    return 0;
}