# Algorithm Practice: Fibonacci & 0/1 Knapsack

## 1. Fibonacci Number Calculation

### Problem Statement

Compute the n-th Fibonacci number using different approaches:

1. Simple Recursion
2. Dynamic Programming (Memoization)
3. Dynamic Programming (Tabulation)

### Approaches

#### a) Simple Recursion

- Formula: `fib(n) = fib(n-1) + fib(n-2)`
- **Pros:** Simple and intuitive.
- **Cons:** Exponential time complexity; very slow for large `n`.

#### b) DP (Memoization)

- Store previously computed Fibonacci numbers in an array or dictionary to avoid redundant computation.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

#### c) DP (Tabulation)

- Build the sequence iteratively from the base cases.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n) (can be optimized to O(1) using two variables)

### Execution Time Comparison

| Method           | n = 40 | n = 100 | n = 1000 | n = 100000 |
| ---------------- | ------ | ------- | -------- | ---------- |
| Simple Recursion |        |         |          |            |
| DP (Memoization) |        |         |          |            |
| DP (Tabulation)  |        |         |          |            |

> Fill in the table with measured execution times for your implementation.

---

## 2. 0/1 Knapsack Problem

### Problem Statement

Given `n` items, each with a weight and a value, and a maximum capacity `W` of a knapsack, select items to maximize the total value without exceeding the weight.

- **Input:**

  - `weights[]` – array of item weights
  - `values[]` – array of item values
  - `W` – maximum knapsack capacity

- **Output:** Maximum achievable value.

### Dynamic Programming Approach

- Use a DP table where `dp[i][w]` represents the maximum value achievable using the first `i` items and capacity `w`.
- Transition:
