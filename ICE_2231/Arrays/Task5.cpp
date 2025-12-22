#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillArray(int arr[][4], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
}

void printArray(int arr[][4], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void searchArray(int arr[][4], int rows, int cols, int key)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == key)
            {
                cout << "Found at row " << i << " column " << j << endl;
                return;
            }
        }
    }
    cout << "Not found" << endl;
}

int main()
{
    srand(time(0));

    int arr[3][4];
    int key;

    fillArray(arr, 3, 4);
    printArray(arr, 3, 4);

    cin >> key;

    searchArray(arr, 3, 4, key);

    return 0;
}

/*
 1 8
 2 4
*/