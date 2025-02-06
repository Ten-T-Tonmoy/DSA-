#include<iostream>
using namespace std;
#define HIGH 100

class Stack{
    private:
        int top;
        int arr[HIGH];

    public:
        Stack(){
            top=-1;
        }
    
    bool isEmpty(){
        return top==-1;
    }

    bool isFull(){
        return top==HIGH-1;
    }

    void push(int i){

        if(isFull()){
            cout<<"Stack Overflow!"<<endl;
            return;
        }
        arr[++top]=i;

    }
    void pop(){
        if(isEmpty()){

            cout<<"Stack's empty already!"<<endl;
            return;
        }
        top--;
    }

    int peek(){
        if(isEmpty()){
            cout<<"Stack's empty already!"<<endl;
            return -1;
        }
        return arr[top];
    }

    void display(){
        if(isEmpty()){
            cout<<"Stack's empty already!"<<endl;
            return ;
        }

        cout<<"The Stack values are : ";
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }



};



int main()
{   Stack s;
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