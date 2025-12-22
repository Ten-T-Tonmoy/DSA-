#include <iostream>
using namespace std;

// Merge two sorted subarrays: A[low..mid] and A[mid+1..high]
void merge(int A[], int low, int mid, int high)
{
    int n1 = mid - low + 1; // size of left subarray
    int n2 = high - mid;    // size of right subarray

    int L[n1], R[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = A[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = low;

    // Merge L[] and R[] back into A[]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k++] = L[i++];
        }
        else
        {
            A[k++] = R[j++];
        }
    }

    // Copy remaining elements of L[]
    while (i < n1)
        A[k++] = L[i++];
    // Copy remaining elements of R[]
    while (j < n2)
        A[k++] = R[j++];
}

// Merge Sort function
void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2; // avoid overflow
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main()
{
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    mergeSort(A, 0, n - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
