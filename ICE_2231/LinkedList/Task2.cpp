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

    //------------------utility----------------------------

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

    //------------------duplicate remover---------------------------------------------

    void removeDuplicates()
    {
        if (this->length < 2)
            return;
        unordered_set<string> vals;
        Node *prevNode = this->start;
        Node *presentNode = prevNode->next;

        vals.insert(prevNode->value);

        // delete while travesing on mono direction
        while (prevNode != nullptr && prevNode->next != nullptr)
        {
            if (vals.count(presentNode->value))
            {

                // ig i gotta use own delete algorithm
                prevNode->next = presentNode->next;
                delete presentNode;
                presentNode = prevNode->next;
                length--;
            }
            else
            {
                vals.insert(presentNode->value);
                presentNode = presentNode->next;
                prevNode = prevNode->next;
            }
        }
    }

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

    //---------------------------------------couple swapping---------------------------------

    void coupleSwapping()
    {
        if (this->length < 2)
        {
            cout << "Unable to swap !" << endl;
        }
        Node *first = start;
        Node *second = start->next;
        while (second != nullptr && first != nullptr)
        {
            swap(first->value, second->value);
            // swap logic here
            first = first->next;
            if (first != nullptr)
            {
                second = first->next;
            }
        }
    }

    void swinging()
    {
        if (this->length < 2)
        {
            cout << "Unable to swap !" << endl;
            return;
        }
        Node *prev = nullptr;
        Node *first = start;
        Node *second = start->next;

        start = second;

        while (first != nullptr && second != nullptr)
        {
            // swap logic here
            first->next = second->next;
            second->next = first;

            if (prev != nullptr)
            {
                prev->next = second;
            }

            prev = first;
            first = first->next;
            if (first != nullptr)
            {
                second = first->next;
            }
        }
    }

    //-------------------------------insert between 2--------------------------------------------

    void insertBetweenHelper(Node *left, Node *right, Node *tempNode)
    {
        // temp will get inserted between left and right
        /**
         * right->next will be unchanged
         */
        tempNode->next = left->next;
        left->next = tempNode;
    }

    //-----------------------------List restructue-----------------------------------------------------

    void restructuring()
    {
        if (!start || !start->next || length < 3)
            return;
        // find half
        Node *slow = start;
        Node *fast = start;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        stack<Node *> lastHalf;

        // splitting time
        Node *second = slow->next;
        slow->next = nullptr;

        while (second != nullptr)
        {
            lastHalf.push(second);
            second = second->next;
        }

        // inserting betweeen
        Node *left = start;
        while (left != nullptr && !lastHalf.empty())
        {
            Node *topNode = lastHalf.top();
            lastHalf.pop();

            Node *nextLeft = left->next;
            left->next = topNode;
            topNode->next = nextLeft;
            left = nextLeft;
        }
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
    cout << "\n After swapping \n";
    linkedlist.coupleSwapping();
    linkedlist.printList();
    cout << "\n After removing duplicates \n";
    linkedlist.removeDuplicates();
    linkedlist.printList();
    cout << "\n After swapping again \n";
    linkedlist.swinging();
    linkedlist.printList();
    cout << "\n After restructuring \n";
    linkedlist.restructuring();
    linkedlist.printList();
    return 0;
}