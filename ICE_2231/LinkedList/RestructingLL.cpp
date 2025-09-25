#include <iostream>
using namespace std;

// class with all public
struct Node
{
    int val;
    Node *next;
    Node(int v) : val(v), next(nullptr) {}
};
void printList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->val;
        if (curr->next)
            cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}
//------------------------main shi---------------------------------------

Node* listReverser(Node* head){
    Node* prev=nullptr;
    Node* curr=head;
    while (curr)
    {
        //temp to change dir
        Node* nextNode=curr->next;
        curr=
    }
    
}
void restructingList(Node* head){

}
int main()
{
    // array to LL creation 999 -> 888 -> 777 -> ... -> 111
    int arr[] = {999, 888, 777, 666, 555, 444, 333, 222, 111};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = new Node(arr[0]);
    Node *curr = head;
    for (int i = 1; i < n; i++)
    {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    cout << "Original List:\n";
    printList(head);

    return 0;
}