#include<bits/stdc++.h>

using namespace std;

void subSets(vector <int> given,vector<int> &sub,int i){

    if(i==given.size()){
        cout<<"The subsets are : ";
        for(auto c:sub)
            cout<<c<<" ";
        cout<<endl;
        return;
    }

    sub.push_back(given[i]);
    subSets(given,sub,i+1);
    
    // 1 2 3 4 5

    sub.pop_back();
    subSets(given,sub,i+1);

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
    vector<int> given={1,2,3,4,5}; //2^5=32?
    vector<int> sub;
    int i=0;    //?initial index?
    subSets(given,sub,i);

    return 0;
}