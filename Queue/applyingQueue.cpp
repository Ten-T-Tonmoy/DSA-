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
        rear=-1;
        size=0;

    }

    ~Queue(){
        delete[] data;
    }
    void enqueue(int val){
        if(isFull){
            cout<<"Shiii Queue Overflowd!";
            return;
        }
        data[size]=val;
        size++;
    }

    void display(){
        if(isEmpty){
            cout<<"Shiii the Queue Dry af";
            return;
        }
        cout<<"The Queue items are : ";
        for(int i=0;i<size;i++){
            cout<<data[i]<<" ";
        }

    }
    void dequeue(){
        if(isEmpty){
            cout<<"Shiii the Queue Dry af";
            return;
        }


    }
    bool isEmpty(){
        return size==0;
    }
    bool isFull(){
        if(size>=storage) return true;
        return false;

    }
    int front(){
        if(isEmpty){
            cout<<"Shiii the Queue Dry af";
            return;
        }
        return data[front];
    }
    int last(){
        if(isEmpty){
            cout<<"Shiii the Queue Dry af";
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




    return 0;
}