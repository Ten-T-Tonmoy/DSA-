#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int ed)
{
    int i = st, j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= ed)
    {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= ed)
    {
        temp.push_back(arr[j++]);
    }

    for (int i = 0; i < temp.size(); i++)
    {   // 5 2 6 3 9 4 11 8   => for left 
        // 5 2 6
        // 5 2 
        // 2 5  
        arr[i + st] = temp[i];
    }
}

void mergeSort(vector<int> &arr, int st, int ed)
{
    if (st < ed)
    {
        int mid = st + (ed - st) / 2;

        mergeSort(arr, st, mid);     // left half
        mergeSort(arr, mid + 1, ed); // right half

        merge(arr, st, mid, ed);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> unSorted = {4, 2, 5, 6, 2, 5, 16, 63, 1, 36, 7};
    mergeSort(unSorted, 0, unSorted.size() - 1);
    for (auto n : unSorted)
        cout << n << " ";
    return 0;
}