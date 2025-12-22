#include <bits/stdc++.h>
using namespace std;

void arrayPrinter(vector<int> arr)
{
    cout << "The elements of the array are: ";
    for (auto el : arr)
    {
        cout << el << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> &arr)
{
    int flag;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
    cout << "Bubble sort applied  \n";
    arrayPrinter(arr);
}

void selectionSort(vector<int> &arr)
{
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
    cout << "Selection sort applied \n";
    arrayPrinter(arr);
}

void insertionSort(vector<int> arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int tem = arr[i], j = i - 1;

        while (j >= 0 && arr[j] > tem)
        {
            arr[j + 1] = arr[j];
            j--;
        }
    }
}

int main()
{
    vector<int> array = {2, 5, 22, 362, 7, 32, 324, 7, 8, 3, 5, 2, 7};
    bubbleSort(array);
    selectionSort(array);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}