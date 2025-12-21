#include <iostream>
using namespace std;

void sortArray(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binarySearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[10] = {45, 12, 78, 34, 23, 56, 89, 10, 67, 1};
    int key;

    sortArray(arr, 10);
    printArray(arr, 10);

    cin >> key;

    int result = binarySearch(arr, 10, key);

    if (result != -1)
        cout << "value found" << endl;
    else
        cout << "value not found" << endl;

    return 0;
}
