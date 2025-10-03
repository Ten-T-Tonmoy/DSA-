# 📌 Heap Data Structure (C++)

## 1. What is a Heap?

A **heap** is a special tree-based data structure that satisfies the **heap property**:

- **Max-Heap**: Every parent node is **greater than or equal to** its children.
- **Min-Heap**: Every parent node is **less than or equal to** its children.

👉 Usually implemented as a **complete binary tree** stored in an array/vector.

---

## 2. Heap Properties

- Shape Property: Always a **complete binary tree** (all levels filled except possibly last, which is filled left to right).
- Heap Property: Parent is ≥ (max-heap) or ≤ (min-heap) compared to children.
- Stored efficiently in an array:

  - For node at index `i`:

    - Left child → `2*i + 1`
    - Right child → `2*i + 2`
    - Parent → `(i-1)/2`

---

## 3. Types of Heaps

- **Binary Heap** (most common)
- **Binomial Heap**
- **Fibonacci Heap**
- **Pairing Heap**

_(But in C++ we mostly use **Binary Heap**)_

---

## 4. Heap Operations

### On Binary Heap:

- **Insert (push)**: O(log n)
- **Delete (pop max/min)**: O(log n)
- **Peek (get max/min)**: O(1)
- **Heapify**: O(n)
- **Build Heap**: O(n)

---

## 5. Implementing Heap in C++ (Manual)

### Max Heap Class

```cpp
#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        int largest = i;
        int left = 2 * i + 1, right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest])
            largest = left;
        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        if (!heap.empty()) return heap[0];
        throw runtime_error("Heap is empty!");
    }

    bool empty() { return heap.empty(); }
    int size() { return heap.size(); }
};
```

---

## 6. Using C++ STL Heap Functions

C++ provides heap utilities in `<algorithm>` and `priority_queue` in `<queue>`.

### 6.1 Priority Queue (most common)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Max heap by default
    priority_queue<int> maxHeap;

    maxHeap.push(10);
    maxHeap.push(4);
    maxHeap.push(15);

    cout << maxHeap.top() << endl; // 15

    maxHeap.pop();
    cout << maxHeap.top() << endl; // 10

    // Min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(4);
    minHeap.push(15);

    cout << minHeap.top() << endl; // 4
}
```

### 6.2 Heap Utilities in `<algorithm>`

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {3,1,4,1,5,9};

    make_heap(v.begin(), v.end()); // build max-heap
    cout << v.front() << endl; // largest element

    pop_heap(v.begin(), v.end()); // moves max to end
    v.pop_back();

    v.push_back(10);
    push_heap(v.begin(), v.end()); // re-heapify

    sort_heap(v.begin(), v.end()); // converts heap to sorted array
}
```

---

## 7. Heap Applications

- **Priority Queues** (job scheduling, OS process scheduling, event-driven simulations)
- **Heap Sort**
- **Graph Algorithms**:

  - Dijkstra’s shortest path
  - Prim’s MST

- **Median Maintenance** (using two heaps)
- **Top K elements** problems

---

## 8. Heap Sort

```cpp
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);
    for (int x : arr) cout << x << " ";
}
```

---

## 9. Common Heap Problems (Practice)

1. Kth Largest/Smallest Element
2. Merge K Sorted Arrays
3. Median in Data Stream
4. Top K Frequent Elements
5. Sliding Window Maximum
6. Minimum Cost to Connect Ropes

---

✅ So in summary:

- Heap = CBT + Heap Property
- Insert/Delete → log n
- STL provides **priority_queue** and heap functions
- Used in sorting + graph algorithms + streaming problems

---
