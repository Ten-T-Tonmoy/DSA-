#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int val)
    {
        key = val;
        left = right = NULL;
    }
};

class Tree
{
    Node *root;
    //  5
    //      7

    // void insert(int key)
    // {
    //     root = insertNode(root, key);
    // }

    Node *insertNode(Node *node, int key)
    {
        if (node == NULL)
            return new Node(key);
        if (key < node->key)
            node->left = insertNode(node->left, key);
        else
            node->right = insertNode(node->right, key);
        return node;
    }

    void preorderTrav(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->key << " ";
        preorderTrav(node->left);
        preorderTrav(node->right);
    }

    void inorderTrav(Node *node)
    {
        if (node == NULL)
            return;
        inorderTrav(node->left);
        cout << node->key << " ";
        inorderTrav(node->right);
    }

    void postorderTrav(Node *node)
    {
        if (node == NULL)
            return;
        postorderTrav(node->left);
        postorderTrav(node->right);
        cout << node->key << " ";
    }

    bool searchNode(Node *node, int key)
    {
        if (node == NULL)
            return false;
        if (node->key == key)
            return true;
        if (key < node->key)
            return searchNode(node->left, key);
        else
            return searchNode(node->right, key);
    }

    int pathLen(Node *node, int depth)
    {
        if (node == NULL)
            return 0;
        return depth + pathLen(node->left, depth + 1) + pathLen(node->right, depth + 1);
    }

public:
    Tree()
    {
        root = NULL;
    }

    void insert(int key)
    {
        root = insertNode(root, key);
    }

    void preorder()
    {
        preorderTrav(root);
        cout << endl;
    }

    void inorder()
    {
        inorderTrav(root);
        cout << endl;
    }

    void postorder()
    {
        postorderTrav(root);
        cout << endl;
    }

    void search(int key)
    {
        if (searchNode(root, key))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    void printPathLength()
    {
        cout << pathLen(root, 0) << endl;
    }
};

int main()
{
    Tree t;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        t.insert(x);
    }

    t.preorder();
    t.inorder();
    t.postorder();

    int key;
    cin >> key;
    t.search(key);

    int newKey;
    cin >> newKey;
    t.insert(newKey);

    t.inorder();
    t.printPathLength();

    return 0;
}
