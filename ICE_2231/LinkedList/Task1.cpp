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
        cout << "\n Value of the linked list are : \n";
        cout << "(start)";
        while (tempNode != nullptr)
        {
            cout << " -> " << tempNode->value;
            tempNode = tempNode->next;
        }
        cout << " -> (end)\n";
        cout << "\n";
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
    /**
     *
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
     */

    bool isRunning = true;
    while (isRunning)
    {
        cout << "\n";
        cout << "=========================================\n";
        cout << "|         Linked List Operations        |\n";
        cout << "=========================================\n";
        cout << "|  1 | Insert at end                    |\n";
        cout << "|  2 | Insert at beginning              |\n";
        cout << "|  3 | Insert at specific position      |\n";
        cout << "|  4 | Delete element by value          |\n";
        cout << "|  5 | Length of the Linked List        |\n";
        cout << "|  6 | Display the Linked List          |\n";
        cout << "|  7 | ************ Exit ************** |\n";
        cout << "=========================================\n";
        cout << "Choose an option: ";
        int opt, tempPos;
        string temp;
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "Enter the string value: ";
            cin >> temp;
            linkedlist.push_back(temp);
            break;
        case 2:
            cout << "Enter the string value: ";
            cin >> temp;
            linkedlist.push_front(temp);
            break;
        case 3:
            cout << "Enter the string value: ";
            cin >> temp;
            cout << "Enter the position you want to insert at: ";
            cin >> tempPos;
            linkedlist.insertAt(tempPos, temp);
            break;
        case 4:
            cout << "Enter the string value you want to Delete: ";
            cin >> temp;
            linkedlist.deleteNode(temp);
            break;
        case 5:
            linkedlist.size();
            break;
        case 6:
            linkedlist.printList();
            break;
        case 7:
            isRunning = false;
            break;

        default:
            break;
        }
    }

    return 0;
}