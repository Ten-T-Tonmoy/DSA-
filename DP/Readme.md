# Complete Guide to Dynamic Programming for Competitive Programming

Dynamic Programming (DP) is one of the most powerful techniques in competitive programming. Let me explain it systematically from fundamentals to advanced concepts.

## 1. What is Dynamic Programming?

Dynamic Programming is an algorithmic paradigm that solves complex problems by breaking them down into simpler subproblems. It stores the results of subproblems to avoid redundant calculations.

**Key Characteristics:**

- **Optimal Substructure**: The optimal solution can be constructed from optimal solutions of subproblems
- **Overlapping Subproblems**: The same subproblems are solved multiple times

## 2. DP vs Recursion vs Greedy

**Recursion** solves problems by breaking them down but recalculates the same subproblems repeatedly. **DP** optimizes recursion by storing (memoizing) results. **Greedy** makes locally optimal choices at each step, while DP considers all possibilities.

## 3. Two Approaches to DP

### Top-Down (Memoization)

Start with the original problem and recursively break it down, storing results in a cache.

```cpp
int fib(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib(n-1, memo) + fib(n-2, memo);
}
```

### Bottom-Up (Tabulation)

Start from the base cases and build up to the solution iteratively.

```cpp
int fib(int n) {
    if (n <= 1) return n;
    vector<int> dp(n+1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
```

## 4. Steps to Solve DP Problems

1. **Identify if it's a DP problem**: Look for optimal substructure and overlapping subproblems
2. **Define the state**: What parameters uniquely identify a subproblem?
3. **Formulate the recurrence relation**: How do states relate to each other?
4. **Identify base cases**: What are the simplest subproblems?
5. **Decide the order of computation**: Which states need to be computed first?
6. **Optimize space if possible**: Can you reduce memory usage?

## 5. Classic DP Patterns

### Pattern 1: Linear DP (1D)

**Example: Climbing Stairs**

```cpp
// You can climb 1 or 2 steps. How many ways to reach step n?
int climbStairs(int n) {
    if (n <= 2) return n;
    vector<int> dp(n+1);
    dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Space optimized
int climbStairsOptimized(int n) {
    if (n <= 2) return n;
    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
```

**Example: House Robber**

```cpp
// Rob houses, can't rob adjacent. Maximize money.
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[n-1];
}
```

### Pattern 2: 2D Grid DP

**Example: Unique Paths**

```cpp
// Robot moves right or down. Count paths from top-left to bottom-right.
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

// Space optimized (1D array)
int uniquePathsOptimized(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j-1];
        }
    }
    return dp[n-1];
}
```

**Example: Minimum Path Sum**

```cpp
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));

    dp[0][0] = grid[0][0];

    // First row
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    // First column
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    // Fill rest
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }

    return dp[m-1][n-1];
}
```

### Pattern 3: Knapsack Problems

**0/1 Knapsack**

```cpp
// Items with weight and value. Max capacity W. Maximize value.
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w],
                              val[i-1] + dp[i-1][w - wt[i-1]]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

// Space optimized
int knapsackOptimized(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<int> dp(W+1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) { // Reverse to avoid using updated values
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}
```

**Unbounded Knapsack**

```cpp
// Can use items unlimited times
int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<int> dp(W+1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = wt[i]; w <= W; w++) { // Forward direction
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}
```

**Subset Sum**

```cpp
// Can we achieve sum S using elements from array?
bool subsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true; // Sum 0 is always achievable
    }

    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= sum; s++) {
            dp[i][s] = dp[i-1][s]; // Don't take current element
            if (s >= arr[i-1]) {
                dp[i][s] = dp[i][s] || dp[i-1][s - arr[i-1]]; // Take it
            }
        }
    }
    return dp[n][sum];
}
```

### Pattern 4: Longest Common Subsequence (LCS)

```cpp
int lcs(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

// Print LCS
string printLCS(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Backtrack
    string result = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            result = s1[i-1] + result;
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    return result;
}
```

**Longest Increasing Subsequence (LIS)**

```cpp
// O(n^2) solution
int lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// O(n log n) solution using binary search
int lisOptimized(vector<int>& arr) {
    vector<int> tail; // tail[i] = smallest ending element of LIS of length i+1

    for (int num : arr) {
        auto it = lower_bound(tail.begin(), tail.end(), num);
        if (it == tail.end()) {
            tail.push_back(num);
        } else {
            *it = num;
        }
    }
    return tail.size();
}
```

### Pattern 5: String DP

**Edit Distance (Levenshtein Distance)**

```cpp
int editDistance(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    // Base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i-1][j],    // Delete
                                    dp[i][j-1],     // Insert
                                    dp[i-1][j-1]}); // Replace
            }
        }
    }
    return dp[m][n];
}
```

**Longest Palindromic Subsequence**

```cpp
int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Every single character is a palindrome of length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Fill for lengths 2 to n
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = 2 + (len == 2 ? 0 : dp[i+1][j-1]);
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}
```

**Word Break**

```cpp
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(n+1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.count(s.substr(j, i-j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}
```

### Pattern 6: Matrix Chain Multiplication

```cpp
int matrixChainMultiplication(vector<int>& dims) {
    int n = dims.size() - 1; // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // len is chain length
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] +
                          dims[i] * dims[k+1] * dims[j+1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n-1];
}
```

**Palindrome Partitioning (Min Cuts)**

```cpp
int minCut(string s) {
    int n = s.length();
    vector<vector<bool>> isPalin(n, vector<bool>(n, false));

    // Build palindrome table
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (len == 1) {
                isPalin[i][j] = true;
            } else if (len == 2) {
                isPalin[i][j] = (s[i] == s[j]);
            } else {
                isPalin[i][j] = (s[i] == s[j] && isPalin[i+1][j-1]);
            }
        }
    }

    vector<int> dp(n, INT_MAX);
    for (int i = 0; i < n; i++) {
        if (isPalin[0][i]) {
            dp[i] = 0;
        } else {
            for (int j = 0; j < i; j++) {
                if (isPalin[j+1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    return dp[n-1];
}
```

### Pattern 7: DP on Trees

**Binary Tree Maximum Path Sum**

```cpp
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int maxSum;

    int maxPathSumHelper(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, maxPathSumHelper(root->left));
        int right = max(0, maxPathSumHelper(root->right));

        maxSum = max(maxSum, left + right + root->val);

        return max(left, right) + root->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxPathSumHelper(root);
        return maxSum;
    }
};
```

**Diameter of Binary Tree**

```cpp
class Solution {
    int diameter;

    int height(TreeNode* root) {
        if (!root) return 0;

        int left = height(root->left);
        int right = height(root->right);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        height(root);
        return diameter;
    }
};
```

### Pattern 8: Digit DP

```cpp
// Count numbers from 1 to N with sum of digits = K
int dp[20][200][2]; // pos, sum, tight

int digitDP(string num, int pos, int sum, int tight, int K) {
    if (pos == num.length()) {
        return sum == K;
    }

    if (dp[pos][sum][tight] != -1) {
        return dp[pos][sum][tight];
    }

    int limit = tight ? (num[pos] - '0') : 9;
    int result = 0;

    for (int digit = 0; digit <= limit; digit++) {
        result += digitDP(num, pos + 1, sum + digit,
                         tight && (digit == limit), K);
    }

    return dp[pos][sum][tight] = result;
}

int countNumbers(int N, int K) {
    memset(dp, -1, sizeof(dp));
    return digitDP(to_string(N), 0, 0, 1, K);
}
```

### Pattern 9: Bitmask DP

**Traveling Salesman Problem**

```cpp
int tsp(vector<vector<int>>& dist, int mask, int pos,
        vector<vector<int>>& dp) {
    int n = dist.size();

    if (mask == (1 << n) - 1) { // All cities visited
        return dist[pos][0]; // Return to start
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { // City not visited
            int newAns = dist[pos][city] +
                        tsp(dist, mask | (1 << city), city, dp);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}
```

**Count Subsets with XOR = K**

```cpp
int countSubsetsXOR(vector<int>& arr, int K) {
    int maxXOR = 0;
    for (int x : arr) maxXOR ^= x;

    vector<int> dp(maxXOR + 1, 0);
    dp[0] = 1;

    for (int num : arr) {
        vector<int> temp = dp;
        for (int i = 0; i <= maxXOR; i++) {
            temp[i ^ num] += dp[i];
        }
        dp = temp;
    }

    return dp[K];
}
```

### Pattern 10: DP with State Compression

**Maximum Score from Performing Multiplication Operations**

```cpp
int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size(), m = multipliers.size();
    vector<vector<int>> dp(m+1, vector<int>(m+1, 0));

    for (int i = m - 1; i >= 0; i--) {
        for (int left = i; left >= 0; left--) {
            int right = n - 1 - (i - left);
            dp[i][left] = max(
                multipliers[i] * nums[left] + dp[i+1][left+1],
                multipliers[i] * nums[right] + dp[i+1][left]
            );
        }
    }

    return dp[0][0];
}
```

## 6. Advanced Optimization Techniques

### Space Optimization

Often you can reduce space complexity from 2D to 1D by noticing you only need the previous row/column.

### Coordinate Compression

When dealing with large ranges but few distinct values, map values to smaller indices.

### Convex Hull Trick (CHT)

Optimize DP transitions of form `dp[i] = min(dp[j] + cost(j, i))` where cost function has specific properties.

### Divide and Conquer Optimization

For DP with quadrangle inequality: `dp[i][j] = min(dp[i][k] + dp[k+1][j] + cost(i,j))`

### Knuth Optimization

Further optimizes matrix chain type problems from O(n³) to O(n²).

## 7. Common Mistakes to Avoid

1. **Incorrect base cases** - Always verify your base cases carefully
2. **Off-by-one errors** - Pay attention to array bounds and loop limits
3. **Integer overflow** - Use `long long` when dealing with large sums or products
4. **Wrong state definition** - Ensure your state uniquely identifies subproblems
5. **Forgetting to initialize** - Initialize DP arrays properly (often with `-1`, `0`, or `INF`)
6. **Not considering edge cases** - Empty arrays, single elements, etc.

## 8. Practice Strategy

Start with these problem categories in order:

1. **Basic 1D DP**: Fibonacci, climbing stairs, house robber
2. **2D Grid DP**: Unique paths, minimum path sum
3. **Knapsack Variants**: 0/1, unbounded, subset sum
4. **LCS/LIS Problems**: Various string problems
5. **String DP**: Edit distance, palindromes
6. **Matrix Chain**: Burst balloons, palindrome partitioning
7. **Advanced**: Digit DP, bitmask DP, DP on trees

## 9. Time Complexity Analysis

- **1D DP**: Usually O(n) or O(n²)
- **2D DP**: Usually O(n·m) or O(n²)
- **Knapsack**: O(n·W) where W is capacity
- **Matrix Chain**: O(n³)
- **Bitmask DP**: O(2ⁿ·n)

## 10. Final Template

```cpp
// Generic DP template
int solve(/* parameters defining state */) {
    // Base case
    if (/* base condition */) {
        return /* base value */;
    }

    // Check if already computed
    if (dp[/* state */] != -1) {
        return dp[/* state */];
    }

    // Compute answer for current state
    int ans = /* initial value (0, INF, -INF, etc.) */;

    // Try all possible transitions
    for (/* all choices */) {
        ans = /* combine */( ans, solve(/* new state */) );
    }

    // Store and return
    return dp[/* state */] = ans;
}
```

