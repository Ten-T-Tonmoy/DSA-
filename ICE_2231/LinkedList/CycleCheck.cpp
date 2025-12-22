#include <iostream>
using namespace std;

/*
    Question: Detect cycle in a singly linked list

    Given a singly linked list, determine if it contains a cycle.
    A cycle exists if a node’s `next` pointer points to an earlier node in the list.

    Example 1:
    Input: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (cycle back to node with value 3)
    Output: Cycle detected

    Example 2:
    Input: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Output: No cycle

    Approach: Floyd’s Tortoise and Hare (slow & fast pointers)
    Time Complexity: O(n), Space Complexity: O(1)
*/

struct Node
{
    int val;
    Node *next;
    Node(int v) : val(v), next(nullptr) {}
};

bool hasCycle(Node *head)
{
    if (!head)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating a cycle: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    if (hasCycle(head))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}
