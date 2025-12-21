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
        cout << "Path Length: " << pathLen(root, 0) << endl;
    }
};

int main()
{
    Tree tree;
    bool isRunning = true;

    while (isRunning)
    {
        cout << "\n";
        cout << "=========================================\n";
        cout << "|        Binary Search Tree Menu         |\n";
        cout << "=========================================\n";
        cout << "|  1 | Insert a key                     |\n";
        cout << "|  2 | Preorder Traversal               |\n";
        cout << "|  3 | Inorder Traversal                |\n";
        cout << "|  4 | Postorder Traversal              |\n";
        cout << "|  5 | Search a key                     |\n";
        cout << "|  6 | Path Length of Tree              |\n";
        cout << "|  7 | ************ Exit ************** |\n";
        cout << "=========================================\n";
        cout << "Choose an option: ";

        int opt, key;
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            tree.insert(key);
            break;

        case 2:
            cout << "PreOrder traversal:";
            tree.preorder();
            break;

        case 3:
            cout << "InOrder traversal:";
            tree.inorder();
            break;

        case 4:
            cout << "PostOrder traversal:";
            tree.postorder();
            break;

        case 5:
            cout << "Enter key to search: ";
            cin >> key;
            tree.search(key);
            break;

        case 6:
            cout << "Path length: ";
            tree.printPathLength();
            break;

        case 7:
            isRunning = false;
            break;

        default:
            cout << "Invalid option" << endl;
        }
    }

    return 0;
}
