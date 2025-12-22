#include <iostream>
#include <stack>
using namespace std;

// Partition function (classic Lomuto partition)
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // choose last element as pivot
    int i = low - 1;       // index of smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Iterative Quick Sort using stack
void quickSortIterative(int arr[], int low, int high)
{
    stack<pair<int, int>> s;

    // push initial low and high
    s.push({low, high});

    while (!s.empty())
    {
        auto p = s.top();
        s.pop();
        int l = p.first;
        int h = p.second;

        if (l < h)
        {
            int pi = partition(arr, l, h); // partition index

            // push left subarray
            if (pi - 1 > l)
                s.push({l, pi - 1});
            // push right subarray
            if (pi + 1 < h)
                s.push({pi + 1, h});
        }
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSortIterative(arr, 0, n - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
