#include <iostream>
using namespace std;

class MaxHeap
{
    int arr[100];
    int size;

    void heapifyDown(int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && arr[l] > arr[largest])
            largest = l;
        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i)
    {
        if (i == 0)
            return;
        int parent = (i - 1) / 2;
        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);
            heapifyUp(parent);
        }
    }

public:
    MaxHeap()
    {
        size = 0;
    }

    void inputHeap()
    {
        cin >> size;
        for (int i = 0; i < size; i++)
            cin >> arr[i];
    }

    void printHeap()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void insert(int key)
    {
        cout << "Before Insertion: ";
        printHeap();

        arr[size] = key;
        size++;
        heapifyUp(size - 1);

        cout << "After Insertion: ";
        printHeap();
    }

    void deleteRoot()
    {
        if (size == 0)
            return;

        cout << "Before Deletion: ";
        printHeap();

        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);

        cout << "After Deletion: ";
        printHeap();
    }
};

int main()
{
    MaxHeap h;
    bool isRunning = true;

    while (isRunning)
    {
        cout << "\n=========================================\n";
        cout << "|        Max Heap Operations Menu        |\n";
        cout << "=========================================\n";
        cout << "|  1 | Input Max Heap                   |\n";
        cout << "|  2 | Insert Element                   |\n";
        cout << "|  3 | Delete Root                      |\n";
        cout << "|  4 | Exit                             |\n";
        cout << "=========================================\n";
        cout << "Choose an option: ";

        int opt, key;
        cin >> opt;

        switch (opt)
        {
        case 1:
            h.inputHeap();
            break;
        case 2:
            cin >> key;
            h.insert(key);
            break;
        case 3:
            h.deleteRoot();
            break;
        case 4:
            isRunning = false;
            break;
        default:
            cout << "Invalid option\n";
        }
    }

    return 0;
}
