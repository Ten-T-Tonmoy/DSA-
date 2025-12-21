#include <bits/stdc++.h>
using namespace std;

// ---------------- simple rec ----------------
long long fibRecursive(int n)
{
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// ----------------dp memo----------------
long long fibMemoHelper(int n, vector<long long> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fibMemoHelper(n - 1, dp) + fibMemoHelper(n - 2, dp);
    return dp[n];
}

long long fibMemo(int n)
{
    vector<long long> dp(n + 1, -1);
    return fibMemoHelper(n, dp);
}

// ---------------- dp tabulation ----------------
long long fibTab(int n)
{
    if (n <= 1)
        return n;
    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n <= 40)
    {
        auto start = chrono::high_resolution_clock::now();
        cout << "recursive: " << fibRecursive(n) << endl;
        auto end = chrono::high_resolution_clock::now();
        cout << "time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " us\n";
    }
    else
    {
        cout << "recur skipped for n > 40 (too slow)\n";
    }

    // memo timing
    auto startMemo = chrono::high_resolution_clock::now();
    cout << "memoization: " << fibMemo(n) << endl;
    auto endMemo = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(endMemo - startMemo).count() << " us\n";

    // tab timing
    auto startTab = chrono::high_resolution_clock::now();
    cout << "tabulation: " << fibTab(n) << endl;
    auto endTab = chrono::high_resolution_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::microseconds>(endTab - startTab).count() << " us\n";

    return 0;
}
