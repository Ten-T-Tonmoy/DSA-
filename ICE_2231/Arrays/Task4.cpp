#include <bits/stdc++.h>
using namespace std;

vector<int> mergeArraysSorted(vector<int> &a, vector<int> &b)
{
    vector<int> res;
    int i = 0, j = 0;
    int size1 = a.size(), size2 = b.size();

    while (i < size1 && j < size2)
    {
        if (a[i] <= b[j])
        {
            res.push_back(a[i++]);
        }
        else
        {
            res.push_back(b[j++]);
        }
    }
    while (i < size1)
        res.push_back(a[i++]);
    while (j < size2)
        res.push_back(b[j++]);

    return res;
}
int main()
{
    int n, m;
    cout << "Enter size of first array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements of first array:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // incase sorting
    sort(a.begin(), a.end());
    cout << "Enter size of second  array: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter elements of second sorted array:\n";
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(b.begin(), b.end());

    vector<int> merged = mergeArraysSorted(a, b);

    cout << "After merging the Merged array : ";
    for (int num : merged)
        cout << num << " ";
    cout << endl;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}