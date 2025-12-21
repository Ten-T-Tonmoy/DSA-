#include <bits/stdc++.h>
using namespace std;

// ---------------- 0/1 knapsack ----------------
int knapsack(int n, int W, vector<int> &weights, vector<int> &values)
{
    // table making (n+1) x (W+1)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // table filling
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // returning max val
}

int main()
{
    int n, W;
    cout << "number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);
    cout << " weights: ";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    cout << "enter vals: ";
    for (int i = 0; i < n; i++)
        cin >> values[i];

    cout << "enter max cap W: ";
    cin >> W;

    int maxValue = knapsack(n, W, weights, values);
    cout << "Max gotten value: " << maxValue << endl;

    return 0;
}
