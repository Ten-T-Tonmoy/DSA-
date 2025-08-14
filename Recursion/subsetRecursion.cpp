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
    // 1 2 3N 4
        // 1 2 3 5
        // 1 2 3
    
    // 1 2 3
        // 1 2 4 5
        // 1 2 4
            // 1 2 5
    // 1 2
        // 1 3 4 5
        // 1 3 4


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