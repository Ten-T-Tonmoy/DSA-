#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        // constructor when node is created
        data = x;
        next = NULL;
    }
};
class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    // Node tempNode(val);  // Creates the object on the stack
    // Node* ptr = &tempNode;  // Pointer to the object
    void push_front(int val)
    {                                   // o(1)
        Node *tempNode = new Node(val); // dynamic object
        //@@ this basically allocates memory in  heap and returns pointero to that memory
        // Node newNode(val); will create static object and
        // will be deleted after scope ends
        if (head == NULL)
        {
            head = tail = tempNode;
            return;
        }
        if (head != NULL)
        {
            tempNode->next = head;
            //*(tempNode).next=head;
            //-> means basically stuffs within this pointer
            head = tempNode;
        }
    }
    void push_back(int val)
    { // o(1)
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print_list()
    { // o(n)
        // 1->2->3->4->6
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
            // after printing each will move forward
        }
    }

    void pop_front()
    { // o(1)
        Node *temp = head;
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head != NULL)
        {
            head = head->next;
            temp->next = NULL;
            // make sure to derefence pointers within temp
            delete temp;
            // since dynamically allocated so i gotta delete manually
        }
    }
    void pop_back()
    { // o(n)
        Node *temp = head;
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        while (temp->next != tail)
        {
            // temp->next->next!=NULL will also work bruh
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    void insert(int val, int pos)
    { // o(n)
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        Node *temp1 = head;
        // be efficient
        while (pos-- > 1)
        {
            if (temp1 == NULL)
            {
                cout << "Dude out of bound" << endl;
            }
            temp1 = temp1->next;
        }
        Node *newNode = new Node(val);
        newNode->next = temp1->next;
        temp1->next = newNode;

        // 1->2->3->4
    }

    // d ,c 

    void search(int val)
    { // o(n)
        int nodeNum = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                cout << "Found that mf! on " << nodeNum << "th node" << endl;
            }
            temp = temp->next;
            nodeNum++;
        }
        cout << "Not found beatch" << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    List ll;
    int a;
    cin>>a;
    ll.push_back(a);
    ll.push_back(3);
    ll.push_back(7);
    ll.push_back(9);
    cout << "Before Inserting  stuffs :";
    ll.print_list();
    cout << endl;
    ll.insert(8, 2);
    cout << "Before Poping stuffs :";
    ll.print_list();
    cout << endl;
    ll.pop_front();
    ll.pop_back();

    cout << "After Poping stuffs :";
    ll.print_list();
    cout << endl;
    ll.search(7);
    return 0;
}