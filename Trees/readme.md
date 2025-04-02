# Binary Search Trees

## Table of Contents

1. [Introduction](#introduction)
2. [Basic Concepts](#basic-concepts)
3. [Structure and Properties](#structure-and-properties)
4. [Operations](#operations)
   - [Searching](#searching)
   - [Insertion](#insertion)
   - [Deletion](#deletion)
   - [Traversal](#traversal)
5. [Balanced BSTs](#balanced-bsts)
   - [AVL Trees](#avl-trees)
   - [Red-Black Trees](#red-black-trees)
   - [Splay Trees](#splay-trees)
6. [Time and Space Complexity](#time-and-space-complexity)
7. [Applications](#applications)
8. [Implementation](#implementation)
9. [Common Problems and Solutions](#common-problems-and-solutions)
10. [Further Reading](#further-reading)

## Introduction

A Binary Search Tree (BST) is a node-based binary tree data structure that has the following properties:

- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees are also binary search trees.

BSTs allow for efficient operations like searching, insertion, and deletion, making them valuable in a wide range of applications.

## Basic Concepts

### Node Structure

A binary search tree node typically contains:

- A key (the value stored in the node)
- Pointers to the left and right child nodes
- (Optionally) A pointer to the parent node

```cpp
struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent; // Optional

    Node(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}
};
```

### Root, Leaf, and Internal Nodes

- **Root**: The topmost node of the tree.
- **Leaf Node**: A node with no children.
- **Internal Node**: A node with at least one child.

### Subtree

Any node in a binary tree, together with all its descendants, forms a subtree.

## Structure and Properties

### Binary Search Property

For every node in the tree:

- All nodes in its left subtree have keys less than the node's key.
- All nodes in its right subtree have keys greater than the node's key.

This property enables efficient searching by allowing approximately half of the remaining tree to be eliminated at each step.

### Height and Depth

- **Height of a node**: The number of edges on the longest path from the node to a leaf.
- **Depth of a node**: The number of edges from the root to the node.
- **Height of the tree**: The height of the root node.

### Balanced vs. Unbalanced Trees

- **Balanced BST**: A tree where the heights of the left and right subtrees of every node differ by at most a small amount.
- **Unbalanced BST**: A tree that doesn't maintain this balance property, potentially leading to poor performance.

## Operations

### Searching

The search operation in a BST follows these steps:

1. Start at the root.
2. Compare the search key with the current node's key.
3. If they match, return the current node.
4. If the search key is less than the current node's key, search in the left subtree.
5. If the search key is greater than the current node's key, search in the right subtree.
6. If you reach a null pointer, the key is not in the tree.

```cpp
Node* search(Node* root, int key) {
    // Base case: root is null or key is present at root
    if (root == nullptr || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}
```

### Insertion

Insertion follows a similar path to searching:

1. Start at the root.
2. Compare the new key with the current node's key.
3. If the new key is less than the current node's key, go to the left subtree.
4. If the new key is greater than the current node's key, go to the right subtree.
5. Repeat until you reach a null pointer.
6. Insert the new node at that position.

```cpp
Node* insert(Node* root, int key) {
    // If the tree is empty, return a new node
    if (root == nullptr)
        return new Node(key);

    // Otherwise, recur down the tree
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    // Return the (unchanged) node pointer
    return root;
}
```

### Deletion

Deletion is more complex and follows these steps:

1. Find the node to be deleted.
2. If the node is a leaf node, simply remove it.
3. If the node has one child, replace the node with its child.
4. If the node has two children:
   a. Find the node's in-order successor (the smallest node in its right subtree).
   b. Replace the node's key with its in-order successor's key.
   c. Delete the in-order successor.

```cpp
// Function to find the node with minimum key value in a BST
Node* minValueNode(Node* node) {
    Node* current = node;

    // Find the leftmost leaf
    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

// Function to delete a node with given key from BST
Node* deleteNode(Node* root, int key) {
    // Base case
    if (root == nullptr) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // If key is same as root's key, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
```

### Traversal

There are three common ways to traverse a BST:

#### In-order Traversal

Visit the left subtree, then the current node, then the right subtree.
This produces nodes in ascending order.

```cpp
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->key << " ";
        inorderTraversal(root->right);
    }
}
```

#### Pre-order Traversal

Visit the current node, then the left subtree, then the right subtree.
This is useful for creating a copy of the tree.

```cpp
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        std::cout << root->key << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
```

#### Post-order Traversal

Visit the left subtree, then the right subtree, then the current node.
This is useful for deleting the tree.

```cpp
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout << root->key << " ";
    }
}
```

### Additional Operations

#### Finding Minimum and Maximum

- **Minimum**: The leftmost node in the tree.
- **Maximum**: The rightmost node in the tree.

```cpp
Node* findMin(Node* root) {
    if (root == nullptr)
        return nullptr;

    Node* current = root;
    while (current->left != nullptr)
        current = current->left;

    return current;
}

Node* findMax(Node* root) {
    if (root == nullptr)
        return nullptr;

    Node* current = root;
    while (current->right != nullptr)
        current = current->right;

    return current;
}
```

#### Finding Successor and Predecessor

- **Successor**: The node with the smallest key greater than the given node's key.
- **Predecessor**: The node with the largest key less than the given node's key.

```cpp
// Function to find successor of a given node in BST
Node* successor(Node* root, Node* p) {
    // If right subtree exists, then successor is the leftmost node in right subtree
    if (p->right != nullptr)
        return findMin(p->right);

    // Otherwise, it is the lowest ancestor whose left child is also an ancestor
    Node* succ = nullptr;

    while (root != nullptr) {
        if (p->key < root->key) {
            succ = root;
            root = root->left;
        }
        else if (p->key > root->key)
            root = root->right;
        else
            break;
    }

    return succ;
}

// Function to find predecessor of a given node in BST
Node* predecessor(Node* root, Node* p) {
    // If left subtree exists, then predecessor is the rightmost node in left subtree
    if (p->left != nullptr)
        return findMax(p->left);

    // Otherwise, it is the lowest ancestor whose right child is also an ancestor
    Node* pred = nullptr;

    while (root != nullptr) {
        if (p->key > root->key) {
            pred = root;
            root = root->right;
        }
        else if (p->key < root->key)
            root = root->left;
        else
            break;
    }

    return pred;
}
```

## Balanced BSTs

Standard BSTs can degenerate into linear structures (essentially linked lists) in the worst case, leading to O(n) time complexity for operations. Balanced BSTs maintain a balance factor to ensure O(log n) operations.

### AVL Trees

AVL trees (named after inventors Adelson-Velsky and Landis) are self-balancing BSTs where the heights of the left and right subtrees of every node differ by at most 1.

#### Balance Factor

For any node N: Balance Factor = Height(Left Subtree) - Height(Right Subtree)

If the balance factor becomes 2 or -2, rebalancing operations (rotations) are performed.

```cpp
struct AVLNode {
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

// Get height of the tree
int height(AVLNode* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Get balance factor
int getBalance(AVLNode* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}
```

#### Rotations

- **Left Rotation**: When a node becomes right-heavy.
- **Right Rotation**: When a node becomes left-heavy.
- **Left-Right Rotation**: A left rotation followed by a right rotation.
- **Right-Left Rotation**: A right rotation followed by a left rotation.

```cpp
// Right rotation
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotation
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}
```

### Red-Black Trees

Red-black trees are balanced BSTs with the following properties:

1. Every node is either red or black.
2. The root is black.
3. All NULL pointers (leaves) are black.
4. If a node is red, both its children are black.
5. Every simple path from a node to any of its descendant NULL pointers contains the same number of black nodes.

```cpp
enum Color { RED, BLACK };

struct RBNode {
    int key;
    Color color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;

    RBNode(int k) : key(k), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};
```

Red-black trees guarantee O(log n) performance for operations while requiring less rotations than AVL trees, making them more efficient for insertion and deletion.

### Splay Trees

Splay trees are self-adjusting BSTs that move recently accessed nodes closer to the root. This provides good amortized performance and adapts to access patterns.

After any operation (search, insert, delete), a "splaying" operation is performed to bring the accessed node to the root.

```cpp
struct SplayNode {
    int key;
    SplayNode* left;
    SplayNode* right;

    SplayNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Right rotation (zig)
SplayNode* rightRotate(SplayNode* x) {
    SplayNode* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Left rotation (zag)
SplayNode* leftRotate(SplayNode* x) {
    SplayNode* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splay operation brings the target node to the root
SplayNode* splay(SplayNode* root, int key) {
    // Base cases
    if (root == nullptr || root->key == key)
        return root;

    // Key lies in left subtree
    if (root->key > key) {
        // Key is not in tree
        if (root->left == nullptr)
            return root;

        // Zig-Zig (Left Left)
        if (root->left->key > key) {
            // Recursively bring the key as root of left-left
            root->left->left = splay(root->left->left, key);
            // First rotation for root, second rotation is done after else
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (root->left->key < key) {
            // Recursively bring the key as root of left-right
            root->left->right = splay(root->left->right, key);
            // First rotation for root->left
            if (root->left->right != nullptr)
                root->left = leftRotate(root->left);
        }

        // Second rotation for root (if left child exists)
        return (root->left == nullptr) ? root : rightRotate(root);
    }
    // Key lies in right subtree
    else {
        // Key is not in tree
        if (root->right == nullptr)
            return root;

        // Zag-Zig (Right Left)
        if (root->right->key > key) {
            // Recursively bring the key as root of right-left
            root->right->left = splay(root->right->left, key);
            // First rotation for root->right
            if (root->right->left != nullptr)
                root->right = rightRotate(root->right);
        }
        // Zag-Zag (Right Right)
        else if (root->right->key < key) {
            // Recursively bring the key as root of right-right
            root->right->right = splay(root->right->right, key);
            // First rotation for root
            root = leftRotate(root);
        }

        // Second rotation for root (if right child exists)
        return (root->right == nullptr) ? root : leftRotate(root);
    }
}
```

## Time and Space Complexity

### Time Complexity

| Operation | Average Case | Worst Case |
| --------- | ------------ | ---------- |
| Search    | O(log n)     | O(n)       |
| Insert    | O(log n)     | O(n)       |
| Delete    | O(log n)     | O(n)       |

The worst-case occurs in an unbalanced tree. Balanced BSTs guarantee O(log n) operations.

### Space Complexity

- The space complexity for all BST operations is O(n) for storing the tree.
- The recursive implementation of operations uses O(h) extra space for the recursion stack, where h is the height of the tree.

## Applications

Binary Search Trees are used in various applications including:

1. **Database Indexing**: BSTs are used to implement indexes in databases for fast data retrieval.

2. **Symbol Tables**: Compilers and interpreters use BSTs to store variable names and their attributes.

3. **Priority Queues**: BSTs can be used to implement priority queues, particularly when balanced.

4. **Sorting Algorithms**: An in-order traversal of a BST produces sorted elements.

5. **Spell Checkers**: BSTs can efficiently store and search dictionaries.

6. **Router Algorithms**: IP routing uses tree-like data structures for prefix matching.

7. **Expression Evaluation**: Syntax trees for parsing and evaluating expressions.

## Implementation

### Complete BST Implementation in C++

```cpp
#include <iostream>
#include <algorithm>

class BST {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;

        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper functions
    Node* insertRecursive(Node* root, int key) {
        if (root == nullptr)
            return new Node(key);

        if (key < root->key)
            root->left = insertRecursive(root->left, key);
        else if (key > root->key)
            root->right = insertRecursive(root->right, key);

        return root;
    }

    Node* searchRecursive(Node* root, int key) {
        if (root == nullptr || root->key == key)
            return root;

        if (key < root->key)
            return searchRecursive(root->left, key);

        return searchRecursive(root->right, key);
    }

    Node* minValueNode(Node* node) {
        Node* current = node;

        while (current && current->left != nullptr)
            current = current->left;

        return current;
    }

    Node* deleteRecursive(Node* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteRecursive(root->left, key);
        else if (key > root->key)
            root->right = deleteRecursive(root->right, key);
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteRecursive(root->right, temp->key);
        }
        return root;
    }

    void inorderRecursive(Node* root) {
        if (root != nullptr) {
            inorderRecursive(root->left);
            std::cout << root->key << " ";
            inorderRecursive(root->right);
        }
    }

    void preorderRecursive(Node* root) {
        if (root != nullptr) {
            std::cout << root->key << " ";
            preorderRecursive(root->left);
            preorderRecursive(root->right);
        }
    }

    void postorderRecursive(Node* root) {
        if (root != nullptr) {
            postorderRecursive(root->left);
            postorderRecursive(root->right);
            std::cout << root->key << " ";
        }
    }

    void destroyRecursive(Node* root) {
        if (root != nullptr) {
            destroyRecursive(root->left);
            destroyRecursive(root->right);
            delete root;
        }
    }

    int heightRecursive(Node* root) {
        if (root == nullptr)
            return -1;

        return 1 + std::max(heightRecursive(root->left), heightRecursive(root->right));
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        destroyRecursive(root);
    }

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    bool search(int key) {
        return searchRecursive(root, key) != nullptr;
    }

    void remove(int key) {
        root = deleteRecursive(root, key);
    }

    void inorder() {
        inorderRecursive(root);
        std::cout << std::endl;
    }

    void preorder() {
        preorderRecursive(root);
        std::cout << std::endl;
    }

    void postorder() {
        postorderRecursive(root);
        std::cout << std::endl;
    }

    int height() {
        return heightRecursive(root);
    }

    bool isEmpty() {
        return root == nullptr;
    }
};
```

### Example Usage

```cpp
#include <iostream>

int main() {
    BST tree;

    // Insert elements
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Display traversals
    std::cout << "Inorder traversal: ";
    tree.inorder();  // 20 30 40 50 60 70 80

    std::cout << "Preorder traversal: ";
    tree.preorder();  // 50 30 20 40 70 60 80

    std::cout << "Postorder traversal: ";
    tree.postorder();  // 20 40 30 60 80 70 50

    // Search for elements
    std::cout << "Is 20 present? " << (tree.search(20) ? "Yes" : "No") << std::endl;
    std::cout << "Is 25 present? " << (tree.search(25) ? "Yes" : "No") << std::endl;

    // Delete elements
    std::cout << "Deleting 20\n";
    tree.remove(20);
    std::cout << "Inorder traversal after deletion: ";
    tree.inorder();  // 30 40 50 60 70 80

    // Get tree height
    std::cout << "Tree height: " << tree.height() << std::endl;

    return 0;
}
```

## Common Problems and Solutions

### Problem 1: Checking if a Binary Tree is a BST

A common problem is determining whether a given binary tree satisfies the BST property.

```cpp
bool isBSTUtil(Node* root, int min, int max) {
    // Empty tree is a BST
    if (root == nullptr)
        return true;

    // Check if the current node violates the min/max constraints
    if (root->key < min || root->key > max)
        return false;

    // Check the subtrees recursively
    // Allow only distinct values
    return isBSTUtil(root->left, min, root->key - 1) &&
           isBSTUtil(root->right, root->key + 1, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
```

### Problem 2: Finding the Lowest Common Ancestor

Finding the lowest common ancestor (LCA) of two nodes in a BST.

```cpp
Node* lowestCommonAncestor(Node* root, int p, int q) {
    if (root == nullptr)
        return nullptr;

    // If both p and q are less than root, then LCA lies in left
    if (p < root->key && q < root->key)
        return lowestCommonAncestor(root->left, p, q);

    // If both p and q are greater than root, then LCA lies in right
    if (p > root->key && q > root->key)
        return lowestCommonAncestor(root->right, p, q);

    // If one key is smaller and one is larger, or one of them is equal to root,
    // then current node is LCA
    return root;
}
```

### Problem 3: Constructing a BST from a Sorted Array

Creating a balanced BST from a sorted array.

```cpp
Node* sortedArrayToBST(int arr[], int start, int end) {
    // Base case
    if (start > end)
        return nullptr;

    // Get the middle element and make it root
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    // Recursively construct the left subtree and make it left child of root
    root->left = sortedArrayToBST(arr, start, mid - 1);

    // Recursively construct the right subtree and make it right child of root
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}
```

### Problem 4: Handling Duplicates

Several approaches exist for handling duplicate keys in a BST:

1. Allow duplicates in the right (or left) subtree.
2. Add a count field to nodes to track duplicates.
3. Create a linked list at nodes with duplicate keys.

```cpp
// Example with count field
struct NodeWithCount {
    int key;
    int count;
    NodeWithCount* left;
    NodeWithCount* right;

    NodeWithCount(int k) : key(k), count(1), left(nullptr), right(nullptr) {}
};

// Insert with count for duplicates
NodeWithCount* insertWithCount(NodeWithCount* root, int key) {
    if (root == nullptr)
        return new NodeWithCount(key);

    if (key == root->key)
        root->count++;
    else if (key < root->key)
        root->left = insertWithCount(root->left, key);
    else
        root->right = insertWithCount(root->right, key);

    return root;
}
```

## Further Reading

For more in-depth understanding of Binary Search Trees and related data structures, consider exploring:

1. **Advanced Data Structures**: B-trees, 2-3 trees, 2-3-4 trees, etc.
2. **Self-Balancing BSTs**: Detailed explanations of AVL trees, Red-Black trees, etc.
3. **Applications in Real-World Systems**: Database systems, file systems, etc.
4. **Algorithmic Analysis**: Amortized analysis of tree operations.
5. **Memory-Efficient Implementations**: Practical considerations for implementing trees in memory-constrained environments.
6. **STL Implementations**: Studying C++ Standard Template Library containers like `std::set` and `std::map` which are typically implemented as balanced BSTs.
