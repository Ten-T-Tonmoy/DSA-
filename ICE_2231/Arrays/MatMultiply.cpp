#include <iostream>
using namespace std;

int main()
{
    // Matrix A (2x3)
    int A[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    // Matrix B (3x2)
    int B[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}};

    // Result matrix C (2x2)
    int C[2][2] = {0}; // initialize all to 0

    int rowsA = 2, colsA = 3;
    int rowsB = 3, colsB = 2;

    // Check if multiplication possible
    if (colsA != rowsB)
    {
        cout << "Matrix multiplication not possible!\n";
        return 0;
    }

    // Multiply A * B = C
    for (int i = 0; i < rowsA; i++)
    { // row of A
        for (int j = 0; j < colsB; j++)
        { // column of B
            for (int k = 0; k < colsA; k++)
            { // sum over shared dimension
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print result
    cout << "Result of A * B:\n";
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
