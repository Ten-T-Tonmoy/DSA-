#include<iostream>
using namespace std;


class Node{
    public:
        int data;
        Node* next;

};

// if linkedlist then node is must shit

class Stack{
    private:
        Node* top;

    public:
        Stack(){
            top=NULL;
        }

        bool isEmpty(){
            if(top==NULL)   return true;
            return false;
        }

        void push(int value){
            //instead of next prev would make more sense
            //bt anyways does makes sense
            Node* newNode=new Node();
            newNode->data=value;
            newNode->next=top;
            top=newNode;
        }

        void pop(){
            if(top==NULL){
                cout<<"Shit's empty!\n";
                return;
            }
            Node* temp=top;
            top=top->next;
            //actually going prev
            delete temp;

        }
        void display(){
            if(top==NULL){
                cout<<"Shit's empty!\n";
                return;
            }
            Node* temp=top;
            
            cout<<"The values stored in Stacks are: ";
            
            while(temp){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }

        int peek(){
            if(top==NULL){
                cout<<"Shit's empty!\n";
                return -1;
            }
            return top->data;
        }

};


int main()
{
    Stack s;
    s.push(10);
    s.push(3);
    s.push(3);
    s.pop();
    s.push(50);
    s.push(16);
    s.pop();

    s.display();
    cout << "Top element: " << s.peek() << endl;
    
    return 0;
}