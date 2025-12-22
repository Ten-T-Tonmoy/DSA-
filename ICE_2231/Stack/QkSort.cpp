#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // pick first element
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        // Move i to the right
        do
        {
            i++;
        } while (arr[i] < pivot);

        // Move j to the left
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j; // partition point

        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        //part index
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {2, 5, 2, 6, 3, 84, 32, 35, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "After sorting: ";
    printArray(arr, n);
}
