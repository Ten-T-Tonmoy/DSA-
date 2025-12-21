#include <iostream>
using namespace std;

void fillArray(int arr[][3], int rows, int cols, int start)
{
    int val = start;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = val++;
        }
    }
}

void printArray(int arr[][3], int rows, int cols)
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

void mergeArrays(int a[][3], int b[][3], int c[][3], int r1, int r2, int cols)
{
    int k = 0;

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            c[k][j] = a[i][j];
        }
        k++;
    }

    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            c[k][j] = b[i][j];
        }
        k++;
    }
}

int main()
{
    int a[2][3];
    int b[2][3];
    int c[4][3];

    fillArray(a, 2, 3, 1);
    fillArray(b, 2, 3, 100);

    mergeArrays(a, b, c, 2, 2, 3);

    printArray(c, 4, 3);

    return 0;
}
