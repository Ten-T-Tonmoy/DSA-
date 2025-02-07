#include<bits/stdc++.h>
using namespace std;

class BinaryTree{

    public:

    int* tree; //shiiis array
    int size;   //current elements num
    int storage;

    BinaryTree(int len){
        storage=len;
        tree= new int[storage];
        size=0;
        for(int i=0;i<storage;i++){
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

    void display(){
        cout<<"Tree array form:";

        for(int i=0;i<size;i++){
            cout<<tree[i];
        }
        cout<<endl;
    }

    ~BinaryTree(){
        delete[] tree;
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    BinaryTree bt(10);
    bt.insert



    return 0;
}