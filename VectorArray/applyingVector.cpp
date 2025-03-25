#include<iostream>
using namespace std;

class Vector{
private:
    int* arr;
    int capacity;
    int size;
    
    //bruh just for  naming conflict we use this->
    
    void reAllocate(){
        capacity*=2;
        int* tempArr=new int[capacity];
        for(int i=0;i<size;i++){
            tempArr[i]=arr[i];
        }
        delete[] this->arr;
        arr=tempArr;
        //same shit done in java
    }

public:
    //member initializer
    // className():member1(value1),member2(value2){}
    Vector():capacity(2),size(0){
        arr=new int[capacity];
    }
    /*
        Vector(){
        this->capacity=2;
        this->size=0;
        this->arr=new int[capacity];
        }
    */

    ~Vector(){
        delete[] this->arr; //this.arr is in java
    }

    void push_back(int val){
        if(size==capacity){
            reAllocate();
        }
        arr[size++]=val;
    }
    //always pops the last value
    void pop(){
        if(size > 0){
            size--;
        }
    }

    int getAt(int idx) const {
        if(idx<0 || idx>=size)
            __throw_out_of_range("Index out of range bruh");
        return arr[idx];
    }

    int getSize() const {
        //in const u can only return create new and read
        //kinda safe shit
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    bool isEmpty(){
        return size==0;
    }
    void print(){
        cout<<"SO the vector is : ";
        for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Vector vec;
    // class* obj=new Class; must dynamically delete
    //use basic Class objname; is enough Class obj(param)
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(22);
    vec.push_back(11);
    vec.push_back(19);
    vec.pop();
    vec.print();
    cout<<"The value at idx 2 is : "<<vec.getAt(2)<<endl;

        return 0;
    }