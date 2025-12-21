#include <iostream>

using namespace std;

void warshalPathMat(int A[4][4], int n)
{
    int P[4][4];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            P[i][j] = A[i][j];

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                P[i][j] = P[i][j] || (P[i][k] && P[k][j]);

    cout << "calculated path Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << P[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n = 4;
    int A[4][4] = {
        {0, 0, 0, 1},
        {1, 0, 1, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 0}};

    warshalPathMat(A, n);
    return 0;
}
