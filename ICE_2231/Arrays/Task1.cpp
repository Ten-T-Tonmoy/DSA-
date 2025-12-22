#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int inp;
        cin>> inp;
        arr[i] =inp;
    }
}

void printArray(int arr[], int size)
{
    cout << "Array elements are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sumArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int maxArray(int arr[], int size)
{
    // 2 4 6 4 2 5 3 2 3 
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int minArray(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

float averageArray(int arr[], int size)
{
    float sum = sumArray(arr, size);
    return sum / size;
}

int main()
{
    srand(time(0));

    int arr[10];

    fillArray(arr, 10);
    printArray(arr, 10);

    cout << "sum of the elements :" << sumArray(arr, 10) << endl;
    cout << "max of the elements :" << maxArray(arr, 10) << endl;
    cout << "min of the elements :" << minArray(arr, 10) << endl;
    cout << "avg of the elements :" << averageArray(arr, 10) << endl;

    return 0;
}
