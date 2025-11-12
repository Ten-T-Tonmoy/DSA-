#include <bits/stdc++.h>

using namespace std;

void countSort(vector<int> &arr)
{
    if (arr.empty())
        return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> countBucket(range, 0), result(arr.size());


    // step-1 freq counting
    // step-2 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countSort(arr);

    cout << "After Counting Sort: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}