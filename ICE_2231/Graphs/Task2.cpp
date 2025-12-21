#include <iostream>
using namespace std;

class Heap
{
    int arr[100];
    int n;

    void heapifyMax(int i, int size)
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
            heapifyMax(largest, size);
        }
    }

    void heapifyMin(int i, int size)
    {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && arr[l] < arr[smallest])
            smallest = l;
        if (r < size && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapifyMin(smallest, size);
        }
    }

public:
    void input()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    void buildMaxHeap()
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapifyMax(i, n);
    }

    void buildMinHeap()
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapifyMin(i, n);
    }

    void print()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Heap h;
    bool isRunning = true;

    while (isRunning)
    {
        cout << "\n=========================================\n";
        cout << "|           Heap Operations Menu         |\n";
        cout << "=========================================\n";
        cout << "|  1 | Input Array                      |\n";
        cout << "|  2 | Build Max Heap                   |\n";
        cout << "|  3 | Build Min Heap                   |\n";
        cout << "|  4 | Exit                             |\n";
        cout << "=========================================\n";
        cout << "Choose an option: ";

        int opt;
        cin >> opt;

        switch (opt)
        {
        case 1:
            h.input();
            break;
        case 2:
            h.buildMaxHeap();
            cout << "Max Heap: ";
            h.print();
            break;
        case 3:
            h.buildMinHeap();
            cout << "Min Heap: ";
            h.print();
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
