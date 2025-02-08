#include <iostream>

using namespace std;

class Queue{
    private:
        int* data;
        int front,rear,storage,size;



    public:
    Queue(int storage)
    {
        this->storage=storage;
        //cause that shit was within private
        data =new int[storage];
        front=0;
        rear=0;
        size=0;

    }

    ~Queue(){
        delete[] data;
    }
    void enqueue(int val){
        if(isFull()){
            cout<<"Shiii Queue Overflowd!";
            cout<<endl;

            return;
        }
        
        data[rear]=val;
        rear++;
        size++;
    }

    void display(){
        if(isEmpty()){
            cout<<"Shiii the Queue Dry af";
            cout<<endl;

            return;
        }
        cout<<"The Queue items are : ";
        for(int i=front;i<=rear;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;

    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Shiii the Queue Dry af";
            cout<<endl;

            return;
        }
        front++;


    }
    bool isEmpty(){
        return size==0;
    }
    bool isFull(){
        if(size>=storage) return true;
        return false;

    }
    int getfront(){
        if(isEmpty()){
            cout<<"Shiii the Queue Dry af";
            cout<<endl;

            return -1;
        }
        return data[front];
    }
    int getlast(){
        if(isEmpty()){
            cout<<"Shiii the Queue Dry af";
            cout<<endl;

            return -1;
        }
        return data[rear];
    }
};

int main(){
    Queue q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    q.display();
    cout<<"The rear element is : "<<q.getfront();


    return 0;
}