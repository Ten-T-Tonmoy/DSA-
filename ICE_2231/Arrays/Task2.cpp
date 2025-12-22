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

void bubbleSort(vector<int> arr)
{
    // bubble=>Repeatedly swaps adjacent elements if they are in the wrong order.
    // flag using incase shit alreaady sorted out

    int flag;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        //21  6 1 13 52  55
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
    cout << "Bubble sort applied  \n";
    arrayPrinter(arr);
}

void selectionSort(vector<int> arr)
{
    // not stable be aware
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
    cout << "Selection sort applied \n";
    arrayPrinter(arr);
}

void insertionSort(vector<int> arr)
{
    // Builds a sorted array one element at a
    // time by inserting elements at the correct position.
    // for sorting linked list its good

    // 21 25 24 225 26 45 88 62 11 26
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

    cout << "Insertion sort applied  \n";
    arrayPrinter(arr);
    // by nature it is adaptive unlike bubble sort
}

//---------------------------entry point -------------------------------
int main()
{
    vector<int> array;
    cout << "Enter size of the array : ";
    int n;
    cin >> n;
    cout << "Enter elements : ";
    // 4 3 2 1 0
    while (n--)
    {
        int a;
        cin >> a;
        array.push_back(a);
        // a[i]=input;
    }
    bool isRunning = true;
    while (isRunning)
    {
        cout << "\n";
        cout << "=========================================\n";
        cout << "|          Sorting Algorithms            |\n";
        cout << "=========================================\n";
        cout << "|  1 | Apply Bubble Sort                 |\n";
        cout << "|  2 | Apply Selection Sort              |\n";
        cout << "|  3 | Apply Insertion Sort              |\n";
        cout << "|  4 | Show unsorted array               |\n";
        cout << "|  5 | ************* Exit *************  |\n";
        cout << "=========================================\n";
        cout << "Choose an option: ";
        int opt, tempPos;
        string temp;
        cin >> opt;
        switch (opt)
        {
        case 1:
            bubbleSort(array);

            break;
        case 2:
            selectionSort(array);

            break;
        case 3:
            insertionSort(array);

            break;
        case 4:
            arrayPrinter(array);
            break;
        case 5:
            isRunning = false;
            break;

        default:
            break;
        }
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}