#include <bits/stdc++.h>

using namespace std;

void populateArray(int m, int n, int *array);
void printArray(int m, int n, int *array);
void sortRowsOfArray(int m, int n, int *array, int tagetRow);
// void searchWithinArray(int m,int n,int *array,int target);
void mergeTwoArrays(int m, int n, int row2, int col2, int *arr1, int *arr2);
void sortRowsByColValues(int *arr,int rows,int cols,int targetCol){
    
}
int main()
{
    cout << "Enter dimensions of the 2d array .";
    int row1, col1;
    cout << "Enter row size of array1 : ";
    cin >> row1;

    cout << "Enter col size of array1: ";
    cin >> col1;

    int arr1[row1][col1];
    populateArray(row1, col1, *arr1);
    printArray(row1, col1, *arr1);

    return 0;
}

void populateArray(int row, int col, int *array)
{

    srand(time(0));

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

void sortRowsOfArray(int row, int col, int *array, int targetRow)
{
    for (int i = 0; i < row; i++)
    {
        sort(&array[i * col], &array[i * col + col]);
    }
}

void printArray(int row, int col, int *array)
{
    cout << "The elements of the array are : \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << array[i * col + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void mergeTwoArrays(int row1, int col1, int row2, int col2, int *arr1, int *arr2)
{

    int mergedArray[row1 + row2][col1];
}