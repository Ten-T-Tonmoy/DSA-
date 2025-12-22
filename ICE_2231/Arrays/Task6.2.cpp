#include <bits/stdc++.h>
using namespace std;

void populateArray(int row, int col, int *array)
{
    srand(time(0));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            array[i * col + j] = rand() % 90 + 10;
}

void printArray(int row, int col, int *array)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << array[i * col + j] << " ";
        cout << endl;
    }
}

void mergeRows(int *arr, int l, int m, int r, int cols, int targetCol)
{
    int n1 = m - l + 1, n2 = r - m;
    vector<vector<int>> L(n1, vector<int>(cols));
    vector<vector<int>> R(n2, vector<int>(cols));
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < cols; j++)
            L[i][j] = arr[(l + i) * cols + j];
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < cols; j++)
            R[i][j] = arr[(m + 1 + i) * cols + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i][targetCol] <= R[j][targetCol])
        {
            for (int c = 0; c < cols; c++)
                arr[k * cols + c] = L[i][c];
            i++;
        }
        else
        {
            for (int c = 0; c < cols; c++)
                arr[k * cols + c] = R[j][c];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        for (int c = 0; c < cols; c++)
            arr[k * cols + c] = L[i][c];
        i++;
        k++;
    }
    while (j < n2)
    {
        for (int c = 0; c < cols; c++)
            arr[k * cols + c] = R[j][c];
        j++;
        k++;
    }
}

void mergeSortRows(int *arr, int l, int r, int cols, int targetCol)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSortRows(arr, l, m, cols, targetCol);
        mergeSortRows(arr, m + 1, r, cols, targetCol);
        mergeRows(arr, l, m, r, cols, targetCol);
    }
}

int main()
{
    int rows, cols;
    cout << "Rows: ";
    cin >> rows;
    cout << "Cols: ";
    cin >> cols;
    int arr[rows][cols];
    populateArray(rows, cols, *arr);
    printArray(rows, cols, *arr);
    int targetCol;
    cout << "Enter column to sort by (0-indexed): ";
    cin >> targetCol;
    mergeSortRows(*arr, 0, rows - 1, cols, targetCol);
    printArray(rows, cols, *arr);
}
