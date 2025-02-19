#include<bits/stdc++.h>
using namespace std;

int binSearch(int arr[],int tar,int st,int ed){
    if(st<=ed){
    int mid=(st+ed)/2;

    if(arr[mid]==tar)   
        return mid;
    else if(arr[mid]<tar)
        return  binSearch(arr,tar,mid+1,ed);
    else
        return  binSearch(arr,tar,st,mid-1);
    }

    return 0;

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int tar=11;
    if(binSearch(arr,tar,0,9)){
        cout<<"The found items index : "<<binSearch(arr,tar,0,9)<<endl;
    }
    else{
        cout<<"The Item not Found"<<endl;
    }


    return 0;
}