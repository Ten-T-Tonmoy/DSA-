#include <bits/stdc++.h>
using namespace std;

void showAsTree(const vector<int> &heapNec)
{
    int n = heapNec.size();
    int levels = log2(n) + 1;

    int idx = 0;
    int level = 0;
    // x<<n == x*(2^n) 2^level

    while (idx < n)
    {
        int currentLevelEl = 1 << level;
        for (int i = 0; i < currentLevelEl; i++)
        {
            if (idx == n)
                break;
            cout << heapNec[idx++] << " ";
        }
        cout << endl;
        level++;
    }
}

void heapifyDown(int i, vector<int> &heap, int n)
{
    // /arr = [4, 10, 3, 5, 1]
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (right < n && heap[smallest] > heap[right])
        smallest = right;
    if (left < n && heap[smallest] > heap[left])
        smallest = left;

    if (smallest != i)
    {
        swap(heap[smallest], heap[i]);
        heapifyDown(smallest, heap, n);
    }
}

/**
 *
 *       76
     23      9
   23  8   8   7
 1  2  7  4

 this formation ok tho
 *
 */

void heapSort(vector<int> arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i > 0; i--)
        heapifyDown(i, arr, n);

    cout << "Initial Heap : " << endl;
    showAsTree(arr);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapifyDown(0, arr, i);
    }

    cout << "After Heap Sorting is done : ";
    for (const auto &el : arr)
        cout << el << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> try1 = {1, 2, 7, 23, 7, 8, 9, 23, 76, 8, 4};
    heapSort(try1);

    return 0;
}