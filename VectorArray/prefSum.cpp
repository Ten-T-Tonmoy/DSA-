#include<bits/stdc++.h>
using namespace std;


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    vector<int> arr={1,2,3,4,5,6,7,8,9};
    //doing prefSum array
    vector<int> pref(arr.size(),0);
    pref[0]=arr[0];
    for(int i=1;i<arr.size();i++){
        pref[i]=pref[i-1]+arr[i];
    }
    for(auto a:pref)
        cout<<a<<" ";

    return 0;
}