#include <iostream>

using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        this->left = nullptr;
        this->right = nullptr;
        this->data = val;
    }
};

class BinaryTree
{
private:
    //----------------------------insert helper-------------------------------
    Node *insertHelper(Node *node, int val)
    {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data)
        {
            node->left = insertHelper(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insertHelper(node->right, val);
        }

        // returning cause of total reconstruction!
        return node;
    }
    //-------------------------search helper------------------------------------

    Node *searchHelper(Node *node, int key)
    {
        if (!node || node->data == key)
            return node;

        if (key > node->data)
            return searchHelper(node->right, key);
        else
            return searchHelper(node->left, key);
    }

    //-------------------------search helper------------------------------------
    int pathLengthHelper(Node *node, int key)
    {
        if (!node)
            return 0;
        if (node->data == key)
            return node->data;

        if (key > node->data)
        {
            int leftPath = pathLengthHelper(node->right, key);
            if (leftPath == 0)
                return 0;
            return node->data + leftPath;
        }
        else
        {
            int rightPath = pathLengthHelper(node->left, key);
            if (rightPath == 0)
                return 0;
            return node->data + rightPath;
        }
    }

public:
    Node *root;

    BinaryTree()
    {
        this->root = nullptr;
    }

    //---------------------insert-------------------------------
    void insert(int val)
    {
        root = insertHelper(root, val);
    }

    //------------------in order traversal ----------------------------

    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void inorderTraversal()
    {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    //------------------pre order traversal ----------------------------

    void preorder(Node *node)
    {
        if (!node)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void preorderTraversal()
    {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }
    //------------------post order traversal ----------------------------

    void postorder(Node *node)
    {
        if (!node)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void postorderTraversal()
    {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }

    //-------------------search------------------------

    void search(int key)
    {
        Node *res = searchHelper(root, key);
        if (res)
            cout << "Value has been found " << res->data << endl;
        else
            cout << "Not found" << endl;
    }

    //-----------------path Length-----------------------------
    void pathLength(int key)
    {
        int total = pathLengthHelper(root, key);
        if (total == 0)
            std::cout << "Key not found.\n";
        else
            std::cout << "Path length to key: " << total << "\n";
    }
};

int main()
{

    BinaryTree bst;
    bst.insert(4);
    bst.insert(3);
    bst.insert(5);
    bst.insert(2);
    bst.inorderTraversal();
    bst.search(3);
    bst.pathLength(3);
    return 0;
}
