#include <bits/stdc++.h>
using namespace std;

/**
 * BF=height of LS-height of RS
 * BF>1 left heavy
 * BF<-1 right heavy
 */

class Node
{
public:
    int val, height;
    Node *leftChild;
    Node *rightChild;

    Node(int val)
    {
        this->val = val;
        leftChild = rightChild = nullptr;
        height = 1;
    }
};

class AVLTree
{
public:
    Node *insert(Node *root, int val);
    Node *remove(Node *root, int val);
    void inorder(Node *root);
    AVLTree():root(nullptr){};

    ~AVLTree(){
        // clearTree(root);
    }

private:
    Node* root;
    int nodeHeight(Node *n);
    int balanceFact(Node *n);
    Node *rotateRight(Node *a);
    Node *rotateLeft(Node *b);
    Node *balance(Node *node);
    
};

int AVLTree::nodeHeight(Node *n)
{
    return n ? n->height : 0;
}

int AVLTree::balanceFact(Node *n)
{   //if n not null!
    return n ? nodeHeight(n->leftChild) - nodeHeight(n->rightChild) : 0;
}

Node* AVLTree::insert(Node* root,int val){
    if(!root)
        return new Node(val);
    
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}