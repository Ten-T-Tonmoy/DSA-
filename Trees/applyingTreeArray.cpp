#include <bits/stdc++.h>
using namespace std;

class BinaryTree{

    public:

    int* tree; //shiiis array
    int size;   //current elements num
    int storage;

    BinaryTree(int len){
        storage=len;
        tree= new int[storage+1];//for 1 based indexing
        //dynamic array making
        size=0;
        for(int i=0;i<=storage;i++){
            tree[i]=-1;
        }
    }

    //insertion order root ->left=>right repeat
    void insert(int val){
        if(size>=storage){
            cout<<"Housefull tree"<<endl;
            return;
        }
        tree[size++]=val;
    }

    // traversal type root->left->right
    void preorder(int idx){

    }
    
    // traversal type left->right->root
    void postorder(int idx){

    }
    
    // traversal type left->root->right
    void inorder(int idx){
        if(idx>=size || tree[idx]==-1) return;

        // 1    2 3     4 5 6 7
        inorder(2*idx+1);
        cout<<tree[idx]<<" "; //left
        
        inorder(2*idx+2);   //right
    }
    

    //array view pretty shitty tbh
    void display(){
        cout<<"Tree array form: ";

        for(int i=0;i<size;i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }

    //Destructor
    ~BinaryTree(){
        delete[] tree;
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    BinaryTree bt(10);
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);
    bt.insert(8);

    bt.display();



    return 0;
}