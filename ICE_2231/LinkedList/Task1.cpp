#include <iostream>
#include <unordered_set>
#include <stack>

using namespace std;

class Node
{
public:
    string value;
    Node *next;

    Node(string val)
    {
        this->value = val;
        this->next = NULL;
    }
};

class List
{

public:
    Node *start;
    Node *end;
    int length = 0;

    string value;

    List()
    {
        start = end = nullptr;
        length = 0;
    }

    //---------------------inserting at specific position--------------------

    void insertAt(int pos, string val)
    {
        // after that position will be inserted
        Node *tempNode = start;
        Node *newNode = new Node(val);

        if (pos == 0)
        {
            newNode->next = start->next;
            start->next = newNode;
            return;
        }
        while (tempNode->next != nullptr && pos > 0)
        {
            pos--;
            tempNode = tempNode->next;
        }
        newNode->next = tempNode->next;
        tempNode->next = newNode;

        length++;
    }

    //----------------------- inserting at front ------------------------

    void push_front(string val)
    {
        Node *tempNode = new Node(val);
        if (start == nullptr)
        {
            start = end = tempNode;
        }
        else
        {
            tempNode->next = start;
            this->start = tempNode;
        }
        length++;
    }

    // ----------------------inserting in the end-----------------------------------

    void push_back(string val)
    {
        Node *tempNode = new Node(val);
        if (start == nullptr)
        {
            start = end = tempNode;
        }
        else
        {
            // reverse than push front cuase it wont be reverse direction
            // this->end = tempNode;
            // tempNode->next = this->end;

            this->end->next = tempNode;
            this->end = tempNode;
        }
        length++;
    }

    //------------------display the contents----------------------------

    void printList()
    {
        Node *tempNode = start;
        cout << "Value of the linked list are : \n";
        cout << "(start)";
        while (tempNode != nullptr)
        {
            cout << " -> " << tempNode->value;
            tempNode = tempNode->next;
        }
        cout << " -> (end)\n";
    }

    //------------------length of the LL-----------------------------------

    void size()
    {
        cout << "The length of the linked list is : " << this->length << endl;
    }

    int isFound(string val)
    {
        int idx = 0;
        if (val != "")
        {
            Node *tempNode = start;
            while (tempNode != nullptr)
            {
                idx++;
                if (val == tempNode->value)
                    return true;
                tempNode = tempNode->next;
            }
        }
        return -1;
    }

    //-------------------------- delete node from LL--------------------------

    void deleteNode(string val)
    {
        int idx = this->isFound(val);
        if (idx < 0)
        {
            cout << "Value not found ! invalid credentials \n";
            return;
        }
        Node *tempNode = start;
        while (tempNode->next->next != nullptr)
        {
            if (tempNode->next->value == val)
                break;
            tempNode = tempNode->next;
        }
        Node *oldPos = tempNode->next;
        tempNode->next = tempNode->next->next;
        delete oldPos;
    }
};

int main()
{
    List linkedlist;
    linkedlist.push_front("first");
    linkedlist.insertAt(0, "fifth");
    linkedlist.push_back("second");
    linkedlist.push_front("third");
    linkedlist.insertAt(1, "fourth");
    linkedlist.insertAt(0, "fifth");
    linkedlist.push_front("second");
    linkedlist.push_front("fifth");
    linkedlist.push_back("second");
    linkedlist.printList();
    linkedlist.deleteNode("third");
    cout << "\n After deleting :\n";
    linkedlist.printList();

    int opt = 0;
    while (opt == 0)
    {
        cout << "Choose an option: \n"
             << "1/Insert at end\n"
             << "2/Insert at beginning\n"
             << "3/Insert at specific position\n"
             << "4/Delete element by value\n"
             << "5/Length of the Linked List\n"
             << "6/Display the Linked List\n"
             << "**********Exit**************\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            /* code */
            break;

        default:
            break;
        }
    }

    return 0;
}