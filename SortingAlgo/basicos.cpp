#include <bits/stdc++.h>
using namespace std;

/**------------------------------------------
 * criteria for sorting technique
 * number of comparisons
 * number of swaps
 * Adaptive (obostha buje bebostha)
 * stable  (incase of duplicate shits)
 * extra memory(does it need new spaces)
 */

/** ----------------------------------------
 * Sorting methods
 *     comparision based=> O(n2) O(nlogn)
 * Bubble sort
 * Insertion Sort
 * Selection sort
 * Heap sort
 * Merge sort
 * quick sort
 * tree sort
 * Shell sort
 *     index basec sorting=>o(n) bt more space
 * count sort
 * Bucket/bin sort
 * Radix sort
 */
void bubbleSort(vector<int> arr)
{
    // bubble=>Repeatedly swaps adjacent elements if they are in the wrong order.
    // flag using incase shit alreaady sorted out

    int flag;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
                flag = 1;
            } // boro gula last e pathano
        }
        if (flag)
            break;
    }
    for (auto a : arr)
        cout << a << " ";
}

void selectionSort()
{
    // not stable be aware
    vector<int> arr = {8, 3, 5, 8, 4, 2, 7};
    // selection=>Finds the minimum element and swaps it to the beginning.
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[minIdx], arr[i]);
    }
    for (auto a : arr)
        cout << a << " ";
}

void insertionSort(vector<int> arr)
{
    // Builds a sorted array one element at a
    // time by inserting elements at the correct position.
    // for sorting linked list its good
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int tem = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > tem)
        {
            arr[j + 1] = arr[j]; // one shift
            j--;
        }
        // j+1 will be the new free place?
        arr[j + 1] = tem;
    }
    for (auto a : arr)
        cout << a << " ";

    // by nature it is adaptive unlike bubble sort
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    do
    {
        // damn do while loops cool
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] >= pivot);
        if (i < j)
            swap(arr[i], arr[j]);

    } while (i < j);
    swap(arr[low], arr[j]);
    return j;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr = {1, 5, 2, 67, 8, 2, 4, 64, 7, 89, 4};
    insertionSort(arr);

    return 0;
}