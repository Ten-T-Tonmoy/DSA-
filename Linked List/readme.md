# Linked Lists

## Table of Contents

1. [Introduction](#introduction)
2. [Types of Linked Lists](#types-of-linked-lists)
   - [Singly Linked List](#singly-linked-list)
   - [Doubly Linked List](#doubly-linked-list)
   - [Circular Linked List](#circular-linked-list)
   - [Circular Doubly Linked List](#circular-doubly-linked-list)
   - [XOR Linked List](#xor-linked-list)
   - [Skip List](#skip-list)
   - [Unrolled Linked List](#unrolled-linked-list)
3. [Basic Operations](#basic-operations)
   - [Insertion](#insertion)
   - [Deletion](#deletion)
   - [Traversal](#traversal)
   - [Searching](#searching)
4. [Advanced Operations](#advanced-operations)
   - [Reversing a Linked List](#reversing-a-linked-list)
   - [Detecting Cycles](#detecting-cycles)
   - [Finding the Middle Node](#finding-the-middle-node)
   - [Merging Two Linked Lists](#merging-two-linked-lists)
   - [Sorting Linked Lists](#sorting-linked-lists)
5. [Time and Space Complexity](#time-and-space-complexity)
6. [Implementations](#implementations)
   - [Singly Linked List Implementation](#singly-linked-list-implementation)
   - [Doubly Linked List Implementation](#doubly-linked-list-implementation)
   - [Circular Linked List Implementation](#circular-linked-list-implementation)
   - [XOR Linked List Implementation](#xor-linked-list-implementation)
7. [Common Problems and Solutions](#common-problems-and-solutions)
8. [Memory Management](#memory-management)
9. [Comparison with Other Data Structures](#comparison-with-other-data-structures)
10. [Applications](#applications)
11. [Further Reading](#further-reading)

## Introduction

A linked list is a linear data structure where elements are stored in nodes. Unlike arrays, linked list elements are not stored at contiguous memory locations. Instead, each node contains data and a reference (pointer) to the next node in the sequence.

Key characteristics of linked lists:

- Dynamic size (can grow or shrink during program execution)
- Efficient insertion and deletion operations
- Random access is not allowed (sequential access only)
- No memory wastage (memory is allocated as needed)
- Each element (node) requires extra memory for storing references

## Types of Linked Lists

### Singly Linked List

A singly linked list is the simplest type of linked list, where each node contains data and a pointer to the next node. The last node points to NULL.

```cpp
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};
```

**Characteristics:**

- Unidirectional traversal (forward only)
- Less memory per node (one pointer)
- Cannot directly access the previous node

**Memory representation:**

```
+------+------+    +------+------+    +------+------+
| data | next |--->| data | next |--->| data | NULL |
+------+------+    +------+------+    +------+------+
```

### Doubly Linked List

In a doubly linked list, each node contains data and two pointers: one to the next node and one to the previous node. The first node's previous pointer and the last node's next pointer point to NULL.

```cpp
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
```

**Characteristics:**

- Bidirectional traversal (both forward and backward)
- More memory per node (two pointers)
- Can directly access both previous and next nodes
- Simplifies certain operations (like deletion)

**Memory representation:**

```
+------+------+------+    +------+------+------+    +------+------+------+
| NULL | data | next |--->| prev | data | next |--->| prev | data | NULL |
+------+------+------+    +------+------+------+    +------+------+------+
        ^                   |                         |
        |                   |                         |
        +-------------------+                         |
                                                      |
        +---------------------------------------------------+
```

### Circular Linked List

A circular linked list is a variation of a linked list where the last node points back to the first node, creating a circle. It can be based on either a singly linked list or a doubly linked list.

**Singly Circular Linked List:**

```cpp
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};
```

**Characteristics:**

- No NULL pointers
- Any node can be a starting point
- Useful for applications that require cycling through a list repeatedly

**Memory representation:**

```
    +----------------+
    |                |
    v                |
+------+------+    +------+------+    +------+------+
| data | next |--->| data | next |--->| data | next |
+------+------+    +------+------+    +------+------+
```

### Circular Doubly Linked List

A circular doubly linked list combines features of both doubly linked lists and circular linked lists. The last node's next pointer points to the first node, and the first node's previous pointer points to the last node.

```cpp
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
```

**Characteristics:**

- No NULL pointers
- Bidirectional traversal
- Can traverse the entire list starting from any node in either direction
- More flexible than both doubly linked lists and circular linked lists

**Memory representation:**

```
    +-----------------------------+
    |                             |
    v                             |
+------+------+------+    +------+------+------+
| prev | data | next |--->| prev | data | next |
+------+------+------+    +------+------+------+
    ^                         |
    |                         |
    +-------------------------+
```

### XOR Linked List

An XOR linked list is a memory-efficient variation of a doubly linked list that uses the XOR operation to store both previous and next pointers in a single pointer field.

```cpp
struct Node {
    int data;
    Node* npx; // XOR of previous and next node addresses

    Node(int val) : data(val), npx(nullptr) {}
};
```

**Characteristics:**

- Memory efficient (only one pointer per node)
- Bidirectional traversal
- More complex implementation
- Requires careful memory management

**Memory representation:**

```
+------+------+    +------+------+    +------+------+
| data |  npx |<-->| data |  npx |<-->| data |  npx |
+------+------+    +------+------+    +------+------+
```

### Skip List

A skip list is a probabilistic data structure that allows for O(log n) search complexity within an ordered sequence. It's essentially a linked list with multiple levels, where each level acts as an "express lane" for the lists below.

```cpp
struct SkipNode {
    int data;
    std::vector<SkipNode*> forward; // Array of pointers for different levels

    SkipNode(int val, int level) : data(val), forward(level, nullptr) {}
};
```

**Characteristics:**

- Probabilistic data structure
- O(log n) average search time
- More complex than simple linked lists
- Combines advantages of arrays and linked lists

**Memory representation:**

```
Level 3: +---+                                   +---+
         | 1 |---------------------------------->| ∞ |
         +---+                                   +---+
Level 2: +---+                +---+              +---+
         | 1 |--------------->| 4 |------------->| ∞ |
         +---+                +---+              +---+
Level 1: +---+     +---+      +---+      +---+   +---+
         | 1 |---->| 2 |----->| 4 |----->| 6 |--->| ∞ |
         +---+     +---+      +---+      +---+   +---+
Level 0: +---+     +---+      +---+      +---+   +---+
         | 1 |---->| 2 |----->| 4 |----->| 6 |--->| ∞ |
         +---+     +---+      +---+      +---+   +---+
```

### Unrolled Linked List

An unrolled linked list is a variation where each node contains an array of elements rather than a single element, combining advantages of arrays and linked lists.

```cpp
struct UnrolledNode {
    int numElements;
    int elements[ARRAY_SIZE]; // Fixed-size array of elements
    UnrolledNode* next;

    UnrolledNode() : numElements(0), next(nullptr) {
        std::fill(elements, elements + ARRAY_SIZE, 0);
    }
};
```

**Characteristics:**

- Better cache performance
- Reduced memory overhead for pointers
- Faster traversal than regular linked lists
- Still maintains O(1) insertion and deletion
- Good balance between arrays and linked lists

**Memory representation:**

```
+------------------+    +------------------+    +------------------+
| [1,2,3,4,5] next |--->| [6,7,8,9,10] next |--->| [11,12,13] NULL |
+------------------+    +------------------+    +------------------+
```

## Basic Operations

### Insertion

Linked lists support several types of insertion operations:

#### 1. Insertion at the Beginning

**Singly Linked List:**

```cpp
void insertAtBeginning(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
```

**Doubly Linked List:**

```cpp
void insertAtBeginning(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
}
```

**Time Complexity:** O(1)

#### 2. Insertion at the End

**Singly Linked List:**

```cpp
void insertAtEnd(Node* &head, int data) {
    Node* newNode = new Node(data);

    // If the list is empty
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}
```

**Doubly Linked List:**

```cpp
void insertAtEnd(Node* &head, int data) {
    Node* newNode = new Node(data);

    // If the list is empty
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}
```

**Time Complexity:** O(n) for singly linked list, O(n) for doubly linked list without tail pointer, O(1) with tail pointer

#### 3. Insertion at a Given Position

**Singly Linked List:**

```cpp
void insertAtPosition(Node* &head, int data, int position) {
    // If position is 0, insert at the beginning
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;

    // Traverse to the node at position-1
    for (int i = 0; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // If position is beyond the list length
    if (temp == nullptr) {
        std::cout << "Position out of range" << std::endl;
        delete newNode;
        return;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;
}
```

**Doubly Linked List:**

```cpp
void insertAtPosition(Node* &head, int data, int position) {
    // If position is 0, insert at the beginning
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;

    // Traverse to the node at position-1
    for (int i = 0; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // If position is beyond the list length
    if (temp == nullptr) {
        std::cout << "Position out of range" << std::endl;
        delete newNode;
        return;
    }

    // Insert the new node
    newNode->next = temp->next;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
    newNode->prev = temp;
}
```

**Time Complexity:** O(n)

### Deletion

Linked lists support several types of deletion operations:

#### 1. Deletion at the Beginning

**Singly Linked List:**

```cpp
void deleteAtBeginning(Node* &head) {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}
```

**Doubly Linked List:**

```cpp
void deleteAtBeginning(Node* &head) {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
}
```

**Time Complexity:** O(1)

#### 2. Deletion at the End

**Singly Linked List:**

```cpp
void deleteAtEnd(Node* &head) {
    if (head == nullptr) {
        return;
    }

    // If there's only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    // Traverse to the second-to-last node
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}
```

**Doubly Linked List:**

```cpp
void deleteAtEnd(Node* &head) {
    if (head == nullptr) {
        return;
    }

    // If there's only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}
```

**Time Complexity:** O(n) for singly linked list, O(n) for doubly linked list without tail pointer, O(1) with tail pointer

#### 3. Deletion at a Given Position

**Singly Linked List:**

```cpp
void deleteAtPosition(Node* &head, int position) {
    if (head == nullptr) {
        return;
    }

    // If position is 0, delete the first node
    if (position == 0) {
        deleteAtBeginning(head);
        return;
    }

    // Traverse to the node at position-1
    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != nullptr && temp->next != nullptr; i++) {
        temp = temp->next;
    }

    // If position is beyond the list length or the next node is NULL
    if (temp == nullptr || temp->next == nullptr) {
        std::cout << "Position out of range" << std::endl;
        return;
    }

    // Delete the node at position
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}
```

**Doubly Linked List:**

```cpp
void deleteAtPosition(Node* &head, int position) {
    if (head == nullptr) {
        return;
    }

    // If position is 0, delete the first node
    if (position == 0) {
        deleteAtBeginning(head);
        return;
    }

    // Traverse to the node at position
    Node* temp = head;
    for (int i = 0; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    // If position is beyond the list length
    if (temp == nullptr) {
        std::cout << "Position out of range" << std::endl;
        return;
    }

    // Update the pointers
    temp->prev->next = temp->next;

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}
```

**Time Complexity:** O(n)

### Traversal

Traversal involves visiting each node in the linked list exactly once.

#### Forward Traversal

**Singly Linked List:**

```cpp
void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
```

**Doubly Linked List:**

```cpp
void traverseForward(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
```

**Time Complexity:** O(n)

#### Backward Traversal (Doubly Linked List)

```cpp
void traverseBackward(Node* head) {
    if (head == nullptr) {
        return;
    }

    // Find the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Traverse backward
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
    std::cout << std::endl;
}
```

**Time Complexity:** O(n)

### Searching

Searching involves finding a node with a specific value in the linked list.

```cpp
bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
```

**Time Complexity:** O(n)

## Advanced Operations

### Reversing a Linked List

#### Iterative Approach

**Singly Linked List:**

```cpp
void reverse(Node* &head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead
        prev = current;
        current = next;
    }

    head = prev;
}
```

**Doubly Linked List:**

```cpp
void reverse(Node* &head) {
    Node* temp = nullptr;
    Node* current = head;

    while (current != nullptr) {
        // Swap next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node (which is now current->prev due to swapping)
        current = current->prev;
    }

    // Update head to point to the last node
    if (temp != nullptr) {
        head = temp->prev;
    }
}
```

**Time Complexity:** O(n)

#### Recursive Approach

**Singly Linked List:**

```cpp
Node* reverseRecursive(Node* head) {
    // Base case
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recursive call
    Node* rest = reverseRecursive(head->next);

    // Reverse the pointers
    head->next->next = head;
    head->next = nullptr;

    return rest;
}
```

**Time Complexity:** O(n)

### Detecting Cycles

#### Floyd's Cycle-Finding Algorithm (Tortoise and Hare)

```cpp
bool hasCycle(Node* head) {
    if (head == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // Move one step
        fast = fast->next->next;    // Move two steps

        // If slow and fast meet, there's a cycle
        if (slow == fast) {
            return true;
        }
    }

    return false;
}
```

**Time Complexity:** O(n)

#### Finding the Start of the Cycle

```cpp
Node* detectCycleStart(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;
    bool hasCycle = false;

    // Detect cycle using Floyd's algorithm
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // Move one step
        fast = fast->next->next;    // Move two steps

        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    // If there's no cycle, return nullptr
    if (!hasCycle) {
        return nullptr;
    }

    // Find the start of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
```

**Time Complexity:** O(n)

### Finding the Middle Node

#### Using Two Pointers (Slow and Fast)

```cpp
Node* findMiddle(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // Move one step
        fast = fast->next->next;    // Move two steps
    }

    return slow;
}
```

**Time Complexity:** O(n)

### Merging Two Linked Lists

#### Merging Two Sorted Linked Lists

```cpp
Node* mergeSortedLists(Node* l1, Node* l2) {
    // Create a dummy node to serve as the head of the merged list
    Node dummy(0);
    Node* tail = &dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining nodes
    if (l1 != nullptr) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next;
}
```

**Time Complexity:** O(n + m), where n and m are the lengths of the two lists

### Sorting Linked Lists

#### Merge Sort for Linked Lists

```cpp
Node* mergeSort(Node* head) {
    // Base case: empty list or single node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Find the middle of the list
    Node* middle = findMiddle(head);
    Node* secondHalf = middle->next;
    middle->next = nullptr;  // Split the list

    // Recursively sort both halves
    Node* left = mergeSort(head);
    Node* right = mergeSort(secondHalf);

    // Merge the sorted halves
    return mergeSortedLists(left, right);
}
```

**Time Complexity:** O(n log n)

## Time and Space Complexity

### Time Complexity

| Operation          | Singly Linked List   | Doubly Linked List   | Circular Linked List |
| ------------------ | -------------------- | -------------------- | -------------------- |
| Access             | O(n)                 | O(n)                 | O(n)                 |
| Search             | O(n)                 | O(n)                 | O(n)                 |
| Insert (beginning) | O(1)                 | O(1)                 | O(1)                 |
| Insert (end)       | O(n), O(1) with tail | O(n), O(1) with tail | O(1)                 |
| Insert (middle)    | O(n)                 | O(n)                 | O(n)                 |
| Delete (beginning) | O(1)                 | O(1)                 | O(1)                 |
| Delete (end)       | O(n), O(1) with tail | O(n), O(1) with tail | O(1) with tail       |
| Delete (middle)    | O(n)                 | O(n)                 | O(n)                 |

### Space Complexity

| List Type                   | Space Complexity per Node              |
| --------------------------- | -------------------------------------- |
| Singly Linked List          | O(n) for n nodes + 1 pointer per node  |
| Doubly Linked List          | O(n) for n nodes + 2 pointers per node |
| Circular Linked List        | O(n) for n nodes + 1 pointer per node  |
| Circular Doubly Linked List | O(n) for n nodes + 2 pointers per node |
| XOR Linked List             | O(n) for n nodes + 1 pointer per node  |

## Implementations

### Singly Linked List Implementation

```cpp
#include <iostream>

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;

        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;  // Optional: for O(1) insertion at the end
    int size;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~SinglyLinkedList() {
        clear();
    }

    // Insert at the beginning
    void pushFront(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;

        if (head == nullptr) {
            tail = newNode;
        }

        head = newNode;
        size++;
    }

    // Insert at the end
    void pushBack(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    // Insert at a specific position
    void insertAt(int data, int position) {
        if (position < 0 || position > size) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        if (position == 0) {
            pushFront(data);
            return;
        }

        if (position == size) {
            pushBack(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* current = head;

        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

    // Delete from the beginning
    void popFront() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        size--;
    }

    // Delete from the end
    void popBack() {
        if (head == nullptr) {
            return;
        }

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return;
        }

        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = nullptr;
        size--;
    }

    // Delete at a specific position
    void deleteAt(int position) {
        if (position < 0 || position >= size) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        if (position == 0) {
            popFront();
            return;
        }

        if (position == size - 1) {
            popBack();
            return;
        }

        Node* current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }

    // Search for a value
    bool search(int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Get the value at a specific position
    int valueAt(int position) {
        if (position < 0 || position >= size) {
            std::cout << "Invalid position" << std::endl;
            return -1;
        }

        Node* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }

        return current->data;
    }

    // Get the size of the list
    int getSize() {
        return size;
    }

    // Check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Clear the list
    void clear() {
        Node* current = head;
        Node* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Reverse the list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        tail = head;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    // Print the list
    void display
```
