#include<bits/stdc++.h>
using namespace std;

//checking sorted with recursion
bool isSorted(int arr[],int size){
    if(size==0 || size==1)
        return true;
    
    return arr[size-1] >= arr[size-2] && isSorted(arr,size-1);
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    
    if(isSorted(arr,10))    
        cout <<"Yea the array is sorted"<<endl;    
    else    
        cout <<"Yea the array is not sorted"<<endl;


    return 0;
}