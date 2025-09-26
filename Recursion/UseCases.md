# Recursion Use Cases: Execution Flow Analysis

## 1. Mathematical Sequences & Calculations

### Use Case: Factorial Calculation

**Problem**: Calculate n! = n × (n-1) × (n-2) × ... × 1

```python
def factorial(n):
    # Base case: factorial of 0 or 1 is 1
    if n <= 1:
        return 1

    # Recursive case: n! = n × (n-1)!
    return n * factorial(n - 1)
```

**Execution Flow for `factorial(4)`:**

```
DESCENT PHASE (Building the call stack):
┌─────────────────────────────────────┐
│ Call factorial(4)                   │
├─────────────────────────────────────┤
│ n = 4, not <= 1                    │
│ Need: 4 * factorial(3)              │
│ Stack: [factorial(4)]               │
└──────────────┬──────────────────────┘
               │
               ▼
┌─────────────────────────────────────┐
│ Call factorial(3)                   │
├─────────────────────────────────────┤
│ n = 3, not <= 1                    │
│ Need: 3 * factorial(2)              │
│ Stack: [factorial(4), factorial(3)] │
└──────────────┬──────────────────────┘
               │
               ▼
┌─────────────────────────────────────┐
│ Call factorial(2)                   │
├─────────────────────────────────────┤
│ n = 2, not <= 1                    │
│ Need: 2 * factorial(1)              │
│ Stack: [factorial(4),               │
│         factorial(3),               │
│         factorial(2)]               │
└──────────────┬──────────────────────┘
               │
               ▼
┌─────────────────────────────────────┐
│ Call factorial(1)                   │
├─────────────────────────────────────┤
│ n = 1, BASE CASE!                  │
│ Return 1                            │
│ Stack: [factorial(4),               │
│         factorial(3),               │
│         factorial(2),               │
│         factorial(1)]               │
└──────────────┬──────────────────────┘
               │
               ▼

ASCENT PHASE (Unwinding and calculating):
┌─────────────────────────────────────┐
│ Back to factorial(2)                │
├─────────────────────────────────────┤
│ Result: 2 * 1 = 2                  │
│ Return 2                            │
│ Stack: [factorial(4), factorial(3)] │
└──────────────┬──────────────────────┘
               │
               ▼
┌─────────────────────────────────────┐
│ Back to factorial(3)                │
├─────────────────────────────────────┤
│ Result: 3 * 2 = 6                  │
│ Return 6                            │
│ Stack: [factorial(4)]               │
└──────────────┬──────────────────────┘
               │
               ▼
┌─────────────────────────────────────┐
│ Back to factorial(4)                │
├─────────────────────────────────────┤
│ Result: 4 * 6 = 24                 │
│ Return 24                           │
│ Stack: []                           │
└─────────────────────────────────────┘

Final Result: 24
```

**Key Insight**: Work happens during the **ascent phase** - multiplication occurs as the stack unwinds.

---

## 2. Tree Data Structure Operations

### Use Case: Binary Tree Traversal

**Problem**: Visit all nodes in a binary tree

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def inorder_traversal(root):
    if root is None:  # Base case
        return []

    result = []
    result.extend(inorder_traversal(root.left))   # Visit left subtree
    result.append(root.val)                       # Visit root
    result.extend(inorder_traversal(root.right))  # Visit right subtree
    return result
```

**Tree Structure Example:**

```
        4
       / \
      2   6
     / \ / \
    1  3 5  7
```

**Execution Flow for Inorder Traversal:**

```
CALL TREE VISUALIZATION:
inorder_traversal(4)
├── inorder_traversal(2) [left subtree]
│   ├── inorder_traversal(1) [left subtree]
│   │   ├── inorder_traversal(None) → return []
│   │   ├── append 1
│   │   └── inorder_traversal(None) → return []
│   │   Result: [1]
│   ├── append 2
│   └── inorder_traversal(3) [right subtree]
│       ├── inorder_traversal(None) → return []
│       ├── append 3
│       └── inorder_traversal(None) → return []
│       Result: [3]
│   Combined result: [1, 2, 3]
├── append 4
└── inorder_traversal(6) [right subtree]
    ├── inorder_traversal(5) [left subtree]
    │   ├── inorder_traversal(None) → return []
    │   ├── append 5
    │   └── inorder_traversal(None) → return []
    │   Result: [5]
    ├── append 6
    └── inorder_traversal(7) [right subtree]
        ├── inorder_traversal(None) → return []
        ├── append 7
        └── inorder_traversal(None) → return []
        Result: [7]
    Combined result: [5, 6, 7]

FINAL RESULT: [1, 2, 3, 4, 5, 6, 7]
```

**Key Insight**: The recursive structure of the algorithm mirrors the recursive structure of the tree data itself.

---

## 3. Divide and Conquer Algorithms

### Use Case: Merge Sort

**Problem**: Sort an array by dividing it into halves, sorting each half, then merging

```python
def merge_sort(arr):
    # Base case: arrays of length 0 or 1 are already sorted
    if len(arr) <= 1:
        return arr

    # Divide: split the array into two halves
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    # Conquer: merge the sorted halves
    return merge(left, right)

def merge(left, right):
    result = []
    i, j = 0, 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])
    return result
```

**Execution Flow for `merge_sort([38, 27, 43, 3])`:**

```
DIVIDE PHASE (Top-down breakdown):
merge_sort([38, 27, 43, 3])
├── Split into: [38, 27] and [43, 3]
│
├── merge_sort([38, 27])
│   ├── Split into: [38] and [27]
│   ├── merge_sort([38]) → [38] (base case)
│   ├── merge_sort([27]) → [27] (base case)
│   └── merge([38], [27]) → [27, 38]
│
└── merge_sort([43, 3])
    ├── Split into: [43] and [3]
    ├── merge_sort([43]) → [43] (base case)
    ├── merge_sort([3]) → [3] (base case)
    └── merge([43], [3]) → [3, 43]

CONQUER PHASE (Bottom-up merging):
merge([27, 38], [3, 43])
├── Compare 27 vs 3: take 3 → result: [3]
├── Compare 27 vs 43: take 27 → result: [3, 27]
├── Compare 38 vs 43: take 38 → result: [3, 27, 38]
└── Take remaining 43 → result: [3, 27, 38, 43]

EXECUTION TREE:
                [38,27,43,3]
                /          \
          [38,27]            [43,3]
          /     \            /     \
      [38]     [27]      [43]     [3]
       |        |         |        |
      [38]     [27]      [43]     [3]
          \     /           \     /
          [27,38]           [3,43]
               \             /
               [3,27,38,43]
```

**Key Insight**: The problem is broken down until it reaches trivial cases (single elements), then solutions are built back up through merging.

---

## 4. Backtracking Problems

### Use Case: N-Queens Problem

**Problem**: Place N queens on an N×N chessboard so none attack each other

```python
def solve_n_queens(n):
    def is_safe(board, row, col):
        # Check column
        for i in range(row):
            if board[i] == col:
                return False

        # Check diagonal (top-left to bottom-right)
        for i in range(row):
            if board[i] - i == col - row:
                return False

        # Check diagonal (top-right to bottom-left)
        for i in range(row):
            if board[i] + i == col + row:
                return False

        return True

    def backtrack(board, row):
        if row == n:  # Base case: all queens placed
            return [board[:]]  # Found a valid solution

        solutions = []
        for col in range(n):
            if is_safe(board, row, col):
                board[row] = col          # Make choice
                solutions.extend(backtrack(board, row + 1))  # Recurse
                # Backtrack happens automatically

        return solutions

    return backtrack([-1] * n, 0)
```

**Execution Flow for 4-Queens (N=4):**

```
SEARCH TREE EXPLORATION:

backtrack([-1,-1,-1,-1], row=0)
├── Try col=0: board=[0,-1,-1,-1]
│   └── backtrack([0,-1,-1,-1], row=1)
│       ├── Try col=0: Not safe (same column)
│       ├── Try col=1: Not safe (diagonal)
│       ├── Try col=2: board=[0,2,-1,-1] ✓
│       │   └── backtrack([0,2,-1,-1], row=2)
│       │       ├── Try col=0: Not safe (same column)
│       │       ├── Try col=1: Not safe (diagonal)
│       │       ├── Try col=2: Not safe (same column)
│       │       └── Try col=3: Not safe (diagonal)
│       │       Return [] (no solutions)
│       └── Try col=3: board=[0,3,-1,-1] ✓
│           └── backtrack([0,3,-1,-1], row=2)
│               ├── Try col=0: Not safe (same column)
│               ├── Try col=1: board=[0,3,1,-1] ✓
│               │   └── backtrack([0,3,1,-1], row=3)
│               │       ├── Try col=0: Not safe
│               │       ├── Try col=1: Not safe
│               │       ├── Try col=2: Not safe
│               │       └── Try col=3: Not safe
│               │       Return [] (no solutions)
│               ├── Try col=2: Not safe (diagonal)
│               └── Try col=3: Not safe (same column)
│               Return [] (no solutions)
│
├── Try col=1: board=[1,-1,-1,-1]
│   └── backtrack([1,-1,-1,-1], row=1)
│       ├── Try col=0: Not safe (diagonal)
│       ├── Try col=1: Not safe (same column)
│       ├── Try col=2: Not safe (diagonal)
│       └── Try col=3: board=[1,3,-1,-1] ✓
│           └── backtrack([1,3,-1,-1], row=2)
│               ├── Try col=0: board=[1,3,0,-1] ✓
│               │   └── backtrack([1,3,0,-1], row=3)
│               │       ├── Try col=0: Not safe
│               │       ├── Try col=1: Not safe
│               │       ├── Try col=2: board=[1,3,0,2] ✓
│               │       │   └── ROW=4: SOLUTION FOUND!
│               │       │       Return [[1,3,0,2]]
│               │       └── Try col=3: Not safe
│               │       Return [[1,3,0,2]]
│               ├── Try col=1: Not safe
│               ├── Try col=2: Not safe
│               └── Try col=3: Not safe
│               Return [[1,3,0,2]]
│
└── ... (continue exploring other starting positions)

BACKTRACKING VISUALIZATION:
When a path leads to no solution:
1. Return empty list (no solutions found)
2. Automatically return to previous level
3. Try next possibility at that level
4. If no more possibilities, backtrack further

The recursion handles the backtracking automatically!
```

**Key Insight**: Recursion naturally handles the "undo" operation - when a recursive call returns, you're automatically back to the previous state.

---

## 5. Dynamic Programming with Recursion

### Use Case: Fibonacci with Memoization

**Problem**: Calculate Fibonacci numbers efficiently

```python
def fibonacci_memo(n, memo={}):
    # Base cases
    if n in memo:
        return memo[n]

    if n <= 1:
        return n

    # Recursive case with memoization
    memo[n] = fibonacci_memo(n-1, memo) + fibonacci_memo(n-2, memo)
    return memo[n]
```

**Execution Flow for `fibonacci_memo(5)`:**

```
WITHOUT MEMOIZATION (exponential calls):
fib(5)
├── fib(4)
│   ├── fib(3)
│   │   ├── fib(2)
│   │   │   ├── fib(1) → 1
│   │   │   └── fib(0) → 0
│   │   └── fib(1) → 1
│   └── fib(2) [RECOMPUTED!]
│       ├── fib(1) → 1
│       └── fib(0) → 0
└── fib(3) [RECOMPUTED!]
    ├── fib(2) [RECOMPUTED!]
    └── fib(1) → 1

WITH MEMOIZATION (linear calls):
fibonacci_memo(5, memo={})
├── Check memo: 5 not found
├── fibonacci_memo(4, memo={})
│   ├── Check memo: 4 not found
│   ├── fibonacci_memo(3, memo={})
│   │   ├── Check memo: 3 not found
│   │   ├── fibonacci_memo(2, memo={})
│   │   │   ├── Check memo: 2 not found
│   │   │   ├── fibonacci_memo(1, memo={}) → 1
│   │   │   ├── fibonacci_memo(0, memo={}) → 0
│   │   │   ├── memo[2] = 1 + 0 = 1
│   │   │   └── Return 1
│   │   ├── fibonacci_memo(1, memo={0:0, 1:1, 2:1}) → 1
│   │   ├── memo[3] = 1 + 1 = 2
│   │   └── Return 2
│   ├── fibonacci_memo(2, memo={0:0,1:1,2:1,3:2})
│   │   └── Check memo: 2 found! Return 1 (no recursion!)
│   ├── memo[4] = 2 + 1 = 3
│   └── Return 3
├── fibonacci_memo(3, memo={0:0,1:1,2:1,3:2,4:3})
│   └── Check memo: 3 found! Return 2 (no recursion!)
├── memo[5] = 3 + 2 = 5
└── Return 5

MEMO STATE EVOLUTION:
Initial: memo = {}
After fib(0): memo = {0: 0}
After fib(1): memo = {0: 0, 1: 1}
After fib(2): memo = {0: 0, 1: 1, 2: 1}
After fib(3): memo = {0: 0, 1: 1, 2: 1, 3: 2}
After fib(4): memo = {0: 0, 1: 1, 2: 1, 3: 2, 4: 3}
After fib(5): memo = {0: 0, 1: 1, 2: 1, 3: 2, 4: 3, 5: 5}
```

**Key Insight**: Memoization transforms exponential time complexity into linear by avoiding redundant calculations.

---

## 6. String Processing and Parsing

### Use Case: Palindrome Checking

**Problem**: Determine if a string reads the same forwards and backwards

```python
def is_palindrome(s, left=0, right=None):
    if right is None:
        right = len(s) - 1

    # Base case: pointers meet or cross
    if left >= right:
        return True

    # Recursive case: check ends and move inward
    if s[left] != s[right]:
        return False

    return is_palindrome(s, left + 1, right - 1)
```

**Execution Flow for `is_palindrome("racecar")`:**

```
STRING: "racecar"
INDICES: 0123456

is_palindrome("racecar", left=0, right=6)
├── s[0]='r', s[6]='r' → Match! ✓
└── is_palindrome("racecar", left=1, right=5)
    ├── s[1]='a', s[5]='a' → Match! ✓
    └── is_palindrome("racecar", left=2, right=4)
        ├── s[2]='c', s[4]='c' → Match! ✓
        └── is_palindrome("racecar", left=3, right=3)
            └── left >= right (3 >= 3) → BASE CASE: True

VISUALIZATION:
Step 1: r a c e c a r  (compare r ↔ r) ✓
        ↑           ↑
Step 2: r a c e c a r  (compare a ↔ a) ✓
          ↑       ↑
Step 3: r a c e c a r  (compare c ↔ c) ✓
            ↑   ↑
Step 4: r a c e c a r  (pointers meet) → TRUE
              ↑

RETURN PATH:
is_palindrome(left=3, right=3) → True
is_palindrome(left=2, right=4) → True
is_palindrome(left=1, right=5) → True
is_palindrome(left=0, right=6) → True
```

---

## 7. Graph Algorithms

### Use Case: Depth-First Search (DFS)

**Problem**: Explore all reachable nodes in a graph

```python
def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()

    # Base case: already visited this node
    if start in visited:
        return visited

    # Mark current node as visited
    visited.add(start)
    print(f"Visiting node: {start}")

    # Recursively visit all neighbors
    for neighbor in graph[start]:
        dfs(graph, neighbor, visited)

    return visited
```

**Graph Example:**

```
    A
   / \
  B   C
 /   / \
D   E   F
```

**Execution Flow for DFS starting from 'A':**

```
GRAPH: {
    'A': ['B', 'C'],
    'B': ['D'],
    'C': ['E', 'F'],
    'D': [],
    'E': [],
    'F': []
}

dfs(graph, 'A', visited=set())
├── 'A' not in visited → Add 'A', print "Visiting node: A"
├── visited = {'A'}
├── For neighbor 'B':
│   └── dfs(graph, 'B', visited={'A'})
│       ├── 'B' not in visited → Add 'B', print "Visiting node: B"
│       ├── visited = {'A', 'B'}
│       ├── For neighbor 'D':
│       │   └── dfs(graph, 'D', visited={'A', 'B'})
│       │       ├── 'D' not in visited → Add 'D', print "Visiting node: D"
│       │       ├── visited = {'A', 'B', 'D'}
│       │       └── No neighbors → Return visited
│       └── Return visited = {'A', 'B', 'D'}
└── For neighbor 'C':
    └── dfs(graph, 'C', visited={'A', 'B', 'D'})
        ├── 'C' not in visited → Add 'C', print "Visiting node: C"
        ├── visited = {'A', 'B', 'D', 'C'}
        ├── For neighbor 'E':
        │   └── dfs(graph, 'E', visited={'A', 'B', 'D', 'C'})
        │       ├── 'E' not in visited → Add 'E', print "Visiting node: E"
        │       ├── visited = {'A', 'B', 'D', 'C', 'E'}
        │       └── No neighbors → Return visited
        └── For neighbor 'F':
            └── dfs(graph, 'F', visited={'A', 'B', 'D', 'C', 'E'})
                ├── 'F' not in visited → Add 'F', print "Visiting node: F"
                ├── visited = {'A', 'B', 'D', 'C', 'E', 'F'}
                └── No neighbors → Return visited

OUTPUT SEQUENCE:
Visiting node: A
Visiting node: B
Visiting node: D
Visiting node: C
Visiting node: E
Visiting node: F

FINAL visited = {'A', 'B', 'C', 'D', 'E', 'F'}
```

---

## 8. Combinatorial Problems

### Use Case: Generate All Permutations

**Problem**: Generate all possible arrangements of elements

```python
def permutations(arr):
    # Base case: empty array or single element
    if len(arr) <= 1:
        return [arr]

    result = []
    for i in range(len(arr)):
        # Choose current element
        current = arr[i]
        remaining = arr[:i] + arr[i+1:]

        # Generate permutations of remaining elements
        for perm in permutations(remaining):
            result.append([current] + perm)

    return result
```

**Execution Flow for `permutations([1, 2, 3])`:**

```
permutations([1, 2, 3])
├── Choose 1, remaining=[2, 3]
│   └── permutations([2, 3])
│       ├── Choose 2, remaining=[3]
│       │   └── permutations([3]) → [[3]] (base case)
│       │   Result: [[2, 3]]
│       └── Choose 3, remaining=[2]
│           └── permutations([2]) → [[2]] (base case)
│           Result: [[3, 2]]
│       Combined: [[2, 3], [3, 2]]
│   Build: [[1, 2, 3], [1, 3, 2]]
│
├── Choose 2, remaining=[1, 3]
│   └── permutations([1, 3])
│       ├── Choose 1, remaining=[3]
│       │   └── permutations([3]) → [[3]] (base case)
│       │   Result: [[1, 3]]
│       └── Choose 3, remaining=[1]
│           └── permutations([1]) → [[1]] (base case)
│           Result: [[3, 1]]
│       Combined: [[1, 3], [3, 1]]
│   Build: [[2, 1, 3], [2, 3, 1]]
│
└── Choose 3, remaining=[1, 2]
    └── permutations([1, 2])
        ├── Choose 1, remaining=[2]
        │   └── permutations([2]) → [[2]] (base case)
        │   Result: [[1, 2]]
        └── Choose 2, remaining=[1]
            └── permutations([1]) → [[1]] (base case)
            Result: [[2, 1]]
        Combined: [[1, 2], [2, 1]]
    Build: [[3, 1, 2], [3, 2, 1]]

FINAL RESULT:
[
    [1, 2, 3], [1, 3, 2],
    [2, 1, 3], [2, 3, 1],
    [3, 1, 2], [3, 2, 1]
]

DECISION TREE:
                    [1,2,3]
                   /   |   \
              choose1  choose2  choose3
                 |       |       |
              [2,3]    [1,3]    [1,2]
              /  \      /  \     /  \
             2    3    1    3   1    2
            /      \  /      \ /      \
          [3]      [2] [3]   [1] [2]  [1]
           |        |   |     |   |    |
         [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,1,2] [3,2,1]
```

**Key Insight**: Each level of recursion represents making one choice, and the recursion explores all possible sequences of choices.

---

## Common Execution Patterns Across Use Cases

### 1. **Stack-Based Execution Pattern**

- **Descent**: Build up context, make smaller subproblems
- **Base Case**: Provide concrete answers for trivial cases
- **Ascent**: Combine results, do post-processing

### 2. **Choice and Exploration Pattern**

- Make a choice at current level
- Recursively explore consequences
- Backtrack automatically when recursion returns
- Try next choice

### 3. **Divide and Conquer Pattern**

- Split problem into independent subproblems
- Solve subproblems recursively
- Combine solutions to get final answer

### 4. **Memoization Pattern**

- Check if problem already solved
- If not, solve recursively and store result
- Return cached result for future calls

### 5. **State Threading Pattern**

- Pass mutable state through recursive calls
- State accumulates information across calls
- Final state contains complete result

The beauty of recursion lies in how these patterns naturally emerge from the problem structure, making complex algorithms feel almost inevitable once you see the recursive relationship.
