#include <bits/stdc++.h>
using namespace std;

void arrayPrinter(int arr[], int rows, int cols)
{
    cout << "Merged 2D Array:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i * cols + j] << " ";
        }
        cout << endl;
        // 1 2 3 4
        // 6 7 8 5
    }
}

void populateArray(int row, int col, int *array)
{

    int lower = 10, upper = 99;
    int randomNum;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            randomNum = rand() % (upper - lower + 1) + lower;

            array[i * col + j] = randomNum;
        }
    }
}

int *arrayMerger(int arr1[], int arr2[], string mode,
                 int rows1, int cols1,
                 int rows2, int cols2,
                 int &mergedRows, int &mergedCols)
{
    if (mode == "row")
    {
        // vertical stacking | will go down
        mergedRows = rows1 + rows2;
        mergedCols = (cols1 > cols2) ? cols1 : cols2;
    }
    else
    { // col | will go side
        mergedRows = (rows1 > rows2) ? rows1 : rows2;
        mergedCols = cols1 + cols2;
    }
    // compile time vs runtime illegal variable array sizze shit
    int *merged = new int[mergedRows * mergedCols];

    for (int i = 0; i < mergedRows * mergedCols; i++)
        merged[i] = 0;

    if (mode == "row")
    {
        for (int i = 0; i < rows1; i++)
            for (int j = 0; j < cols1; j++)
                merged[i * mergedCols + j] = arr1[i * cols1 + j];
        for (int i = 0; i < rows2; i++)
            for (int j = 0; j < cols2; j++)
                merged[(rows1 + i) * mergedCols + j] = arr2[i * cols2 + j];
    }
    else
    {
        for (int i = 0; i < rows1; i++)
            for (int j = 0; j < cols1; j++)
                merged[i * mergedCols + j] = arr1[i * cols1 + j];
        for (int i = 0; i < rows2; i++)
            for (int j = 0; j < cols2; j++)
                merged[i * mergedCols + cols1 + j] = arr2[i * cols2 + j];
    }

    cout << "Array merging done ! \n";
    arrayPrinter(merged, mergedRows, mergedCols);
    return merged;
}

int main()
{
    srand(time(0));

    cout << "Enter dimensions of the 2d array . Either row or Coloumns must be same! >> \n";
    int row1, col1, row2, col2;
    cout << "Enter row size of array1 : ";
    cin >> row1;

    cout << "Enter col size of array1: ";
    cin >> col1;

    cout << "Enter row size of array2 : ";
    cin >> row2;
    /**
     * 1 2 3
     * 2 5 6
     *
     * 2 5 4
     * 2 8 6
     * 0 3 3
     */

    cout << "Enter col size of array2: ";
    cin >> col2;

    int arr1[row1][col1];
    int arr2[row2][col2];
    int mergedRows, mergedCols;
    populateArray(row1, col1, *arr1);
    populateArray(row2, col2, *arr2);
    arrayPrinter(*arr1, row1, col1);
    arrayPrinter(*arr2, row2, col2);
    int *merged = arrayMerger(*arr1, *arr2, "col", row1, col1, row2, col2, mergedRows, mergedCols);
    delete[] merged;
    return 0;
}