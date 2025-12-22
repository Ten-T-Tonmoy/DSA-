import React from "react";
import { Download, BookOpen } from "lucide-react";

const DSAQuizPDF = () => {
  const quizData = {
    array: {
      title: "Arrays",
      questions: [
        {
          q: "What is an array and how is it stored in memory?",
          a: "A contiguous block of memory that stores elements of the same type. Elements are stored sequentially at adjacent memory locations.",
        },
        {
          q: "What is the time complexity of accessing an element by index in an array?",
          a: "O(1) - Direct memory access using base_address + (index × element_size)",
        },
        {
          q: "What is the time complexity of inserting an element at the beginning of an array?",
          a: "O(n) - All existing elements must be shifted one position to the right",
        },
        {
          q: "What is the time complexity of inserting an element at the end of an array?",
          a: "O(1) if space is available, O(n) if array needs to be resized",
        },
        {
          q: "What is the time complexity of deleting an element from the middle of an array?",
          a: "O(n) - All elements after the deleted element must be shifted left",
        },
        {
          q: "What is the difference between static and dynamic arrays?",
          a: "Static arrays have fixed size at compile time, dynamic arrays can grow/shrink at runtime (like ArrayList in Java or vector in C++)",
        },
        {
          q: "Explain the two-pointer technique and give an example use case.",
          a: "Uses two pointers moving through array from different positions/directions. Example: Finding pairs with a given sum in sorted array, or removing duplicates in-place.",
        },
        {
          q: "What is Kadane's Algorithm and what problem does it solve?",
          a: "Finds the maximum sum of a contiguous subarray in O(n) time. Keeps track of current sum and maximum sum seen so far.",
        },
        {
          q: "What is the sliding window technique? Give an example.",
          a: "Maintains a window of elements and slides it across the array. Example: Finding maximum sum of k consecutive elements, or longest substring without repeating characters.",
        },
        {
          q: "Explain the Dutch National Flag problem and its solution.",
          a: "Sort array of 0s, 1s, and 2s in O(n) time and O(1) space using three pointers (low, mid, high) to partition the array.",
        },
        {
          q: "What is a prefix sum array? How is it useful?",
          a: "Array where each element stores sum of all previous elements. Allows range sum queries in O(1) time after O(n) preprocessing.",
        },
        {
          q: "What is the time complexity of binary search on a sorted array?",
          a: "O(log n) - Repeatedly divides search space in half",
        },
        {
          q: "How do you rotate an array by k positions efficiently?",
          a: "Reverse first k elements, reverse remaining elements, then reverse entire array - O(n) time, O(1) space",
        },
        {
          q: "What is the Boyer-Moore Majority Vote Algorithm?",
          a: "Finds majority element (appears > n/2 times) in O(n) time and O(1) space using a counter and candidate variable.",
        },
        {
          q: "Explain the concept of subarray vs subsequence.",
          a: "Subarray: contiguous elements maintaining order. Subsequence: elements maintaining order but not necessarily contiguous.",
        },
        {
          q: "What is the difference between finding the maximum subarray sum and maximum subarray product?",
          a: "Product can be affected by negative numbers, so we need to track both maximum and minimum products at each position.",
        },
        {
          q: "How do you merge two sorted arrays efficiently?",
          a: "Use two pointers, compare elements and place smaller one in result array - O(m+n) time",
        },
        {
          q: "What is the time and space complexity of creating a frequency map of array elements?",
          a: "O(n) time and O(n) space using a hash map",
        },
        {
          q: "Explain the concept of in-place algorithms with an array example.",
          a: "Algorithms that use O(1) extra space. Example: in-place array reversal using two pointers from both ends.",
        },
        {
          q: "What is the difference between stable and unstable sorting?",
          a: "Stable sorting maintains relative order of equal elements, unstable sorting may change their relative positions.",
        },
      ],
    },
    linkedlist: {
      title: "Linked Lists",
      questions: [
        {
          q: "What is a linked list and how does it differ from an array?",
          a: "A linear data structure where elements (nodes) are stored non-contiguously, each node contains data and pointer to next node. Unlike arrays, no random access but dynamic size.",
        },
        {
          q: "What are the types of linked lists?",
          a: "Singly Linked List (next pointer only), Doubly Linked List (next and prev pointers), Circular Linked List (last node points to first)",
        },
        {
          q: "What is the time complexity of inserting at the beginning of a singly linked list?",
          a: "O(1) - Just create new node and update head pointer",
        },
        {
          q: "What is the time complexity of inserting at the end of a singly linked list?",
          a: "O(n) without tail pointer, O(1) with tail pointer",
        },
        {
          q: "What is the time complexity of searching in a linked list?",
          a: "O(n) - Must traverse from head until element is found or end is reached",
        },
        {
          q: "What is the time complexity of deleting a node when you have a pointer to it?",
          a: "O(1) if you can copy next node's data, but O(n) to find the node first or to delete last node",
        },
        {
          q: "Explain Floyd's Cycle Detection Algorithm (Tortoise and Hare).",
          a: "Uses two pointers moving at different speeds (slow: 1 step, fast: 2 steps). If cycle exists, they will meet. Time: O(n), Space: O(1)",
        },
        {
          q: "How do you find the starting point of a cycle in a linked list?",
          a: "After detecting cycle with Floyd's algorithm, move one pointer to head, then move both at same speed - they meet at cycle start.",
        },
        {
          q: "How do you find the middle element of a linked list in one pass?",
          a: "Use slow and fast pointer technique - slow moves 1 step, fast moves 2 steps. When fast reaches end, slow is at middle.",
        },
        {
          q: "How do you reverse a singly linked list iteratively?",
          a: "Use three pointers (prev, current, next). Traverse and reverse pointers. Time: O(n), Space: O(1)",
        },
        {
          q: "How do you reverse a singly linked list recursively?",
          a: "Recursively reverse rest of list, then fix current node's pointer. Time: O(n), Space: O(n) for recursion stack",
        },
        {
          q: "How do you detect and remove a loop in a linked list?",
          a: "First detect loop using Floyd's algorithm, find loop start, then traverse to node before start and set its next to NULL.",
        },
        {
          q: "How do you find the nth node from the end in one traversal?",
          a: "Use two pointers separated by n nodes. When first reaches end, second is at nth from end.",
        },
        {
          q: "What is the time complexity of merging two sorted linked lists?",
          a: "O(m + n) where m and n are lengths. Compare nodes and link them in sorted order.",
        },
        {
          q: "How do you check if a linked list is a palindrome?",
          a: "Find middle, reverse second half, compare both halves. Time: O(n), Space: O(1)",
        },
        {
          q: "What is a doubly linked list? What are its advantages?",
          a: "Each node has next and prev pointers. Advantages: bidirectional traversal, easier deletion, but uses more memory.",
        },
        {
          q: "What is a circular linked list? Where is it useful?",
          a: "Last node points back to first node. Useful for: round-robin scheduling, music playlists, browser history.",
        },
        {
          q: "How do you delete a node without head pointer (given only node to delete)?",
          a: "Copy next node's data to current node, then delete next node. Won't work for last node.",
        },
        {
          q: "What is a skip list and what is its time complexity?",
          a: "Probabilistic data structure with multiple layers for faster search. Average time: O(log n) for search, insert, delete.",
        },
        {
          q: "How do you clone a linked list with random pointers?",
          a: "Three passes: 1) Create nodes interleaved, 2) Set random pointers, 3) Separate lists. Time: O(n), Space: O(1)",
        },
      ],
    },
    timeComplexity: {
      title: "Time Complexity Analysis",
      questions: [
        {
          q: "What is time complexity and why is it important?",
          a: "Measure of how algorithm's execution time grows with input size. Important for predicting performance and comparing algorithms.",
        },
        {
          q: "What does Big O notation represent?",
          a: "Upper bound or worst-case time complexity - maximum time an algorithm takes for any input of size n.",
        },
        {
          q: "What does Big Omega (Ω) notation represent?",
          a: "Lower bound or best-case time complexity - minimum time an algorithm takes.",
        },
        {
          q: "What does Big Theta (Θ) notation represent?",
          a: "Tight bound - both upper and lower bound, represents average case when best and worst cases are same.",
        },
        {
          q: "What is O(1) time complexity? Give examples.",
          a: "Constant time - independent of input size. Examples: array access by index, push/pop in stack, hash table insert (average)",
        },
        {
          q: "What is O(log n) time complexity? Give examples.",
          a: "Logarithmic time - problem size halves each iteration. Examples: binary search, balanced BST operations, heap insert",
        },
        {
          q: "What is O(n) time complexity? Give examples.",
          a: "Linear time - directly proportional to input size. Examples: linear search, traversing array/linked list, finding min/max",
        },
        {
          q: "What is O(n log n) time complexity? Give examples.",
          a: "Linearithmic time - common in efficient sorting. Examples: merge sort, heap sort, quick sort (average case)",
        },
        {
          q: "What is O(n²) time complexity? Give examples.",
          a: "Quadratic time - nested loops. Examples: bubble sort, selection sort, insertion sort, checking all pairs",
        },
        {
          q: "What is O(2^n) time complexity? Give examples.",
          a: "Exponential time - doubles with each input increase. Examples: recursive Fibonacci, subset generation, brute force TSP",
        },
        {
          q: "What is O(n!) time complexity? Give examples.",
          a: "Factorial time - extremely slow. Examples: generating all permutations, brute force traveling salesman",
        },
        {
          q: "How do you calculate time complexity of nested loops?",
          a: "Multiply complexities: outer loop O(n) × inner loop O(m) = O(n×m). If both iterate n times = O(n²)",
        },
        {
          q: "What is the time complexity of: for(i=1; i<=n; i*=2)?",
          a: "O(log n) - loop runs log₂(n) times as i doubles each iteration",
        },
        {
          q: "What is the time complexity of: for(i=n; i>=1; i/=2)?",
          a: "O(log n) - loop runs log₂(n) times as i halves each iteration",
        },
        {
          q: "What is amortized time complexity? Give an example.",
          a: "Average time per operation over a sequence of operations. Example: ArrayList add is O(1) amortized (occasional O(n) resize averaged out)",
        },
        {
          q: "What is the Master Theorem used for?",
          a: "Analyzing time complexity of divide-and-conquer algorithms. T(n) = aT(n/b) + f(n)",
        },
        {
          q: "Compare O(log n), O(n), O(n log n), O(n²) - which is fastest?",
          a: "O(log n) < O(n) < O(n log n) < O(n²). Logarithmic is fastest, quadratic is slowest.",
        },
        {
          q: "What is space complexity and how does it differ from time complexity?",
          a: "Space: amount of memory used. Time: execution duration. Trade-offs often exist between them.",
        },
        {
          q: "What does 'in-place' algorithm mean?",
          a: "Algorithm that uses O(1) extra space (constant space beyond input). Example: bubble sort, in-place array reversal",
        },
        {
          q: "What is the time complexity of recursive Fibonacci and how to optimize it?",
          a: "Naive recursion: O(2^n). Optimize using DP/memoization: O(n) time, O(n) space, or iterative: O(n) time, O(1) space",
        },
      ],
    },
    stack: {
      title: "Stack",
      questions: [
        {
          q: "What is a stack? Explain the LIFO principle.",
          a: "Linear data structure following Last In First Out (LIFO). Last element inserted is first to be removed, like a stack of plates.",
        },
        {
          q: "What are the basic operations of a stack and their time complexities?",
          a: "Push: O(1), Pop: O(1), Peek/Top: O(1), isEmpty: O(1), Size: O(1)",
        },
        {
          q: "How can you implement a stack using an array?",
          a: "Use array with top pointer. Push increments top and adds element. Pop returns element at top and decrements. Fixed size limitation.",
        },
        {
          q: "How can you implement a stack using a linked list?",
          a: "Use singly linked list with head as top. Push adds at head, Pop removes from head. Dynamic size advantage.",
        },
        {
          q: "What is stack overflow and underflow?",
          a: "Overflow: pushing to full stack (array implementation). Underflow: popping from empty stack. Both cause errors.",
        },
        {
          q: "How do you check for balanced parentheses using a stack?",
          a: "Push opening brackets, pop and match when closing bracket found. Stack empty at end means balanced. Time: O(n), Space: O(n)",
        },
        {
          q: "Explain how to evaluate a postfix expression using a stack.",
          a: "Scan left to right: push operands, pop two operands for each operator, compute, push result. Final stack element is answer.",
        },
        {
          q: "How do you convert infix to postfix using a stack?",
          a: "Use operator stack. Output operands directly, handle operators by precedence rules, pop higher/equal precedence operators first.",
        },
        {
          q: "What is the Next Greater Element problem? How is stack used?",
          a: "Find next greater element for each element. Use stack to maintain decreasing sequence, pop when greater element found. Time: O(n)",
        },
        {
          q: "How do you implement two stacks in one array?",
          a: "Start stack1 from left (index 0), stack2 from right (index n-1). They grow toward each other until they meet.",
        },
        {
          q: "What is a monotonic stack? Give an example use case.",
          a: "Stack maintaining elements in increasing or decreasing order. Used for: Next Greater Element, Stock Span Problem, Largest Rectangle in Histogram.",
        },
        {
          q: "How do you find the largest rectangular area in a histogram using a stack?",
          a: "Maintain increasing stack of indices. When smaller bar found, pop and calculate area with popped as smallest. Time: O(n)",
        },
        {
          q: "What is the Stock Span Problem? How is stack used?",
          a: "Find number of consecutive previous days with price ≤ current day. Use stack to store indices. Time: O(n), Space: O(n)",
        },
        {
          q: "How do you implement a Min Stack (stack with O(1) getMin)?",
          a: "Use two stacks: main stack and min stack. Min stack stores minimum at each level. Or use single stack storing pairs (value, current_min).",
        },
        {
          q: "How do you reverse a string using a stack?",
          a: "Push all characters to stack, then pop all. LIFO nature reverses the string. Time: O(n), Space: O(n)",
        },
        {
          q: "What is function call stack? How does recursion use it?",
          a: "System stack storing function calls and local variables. Each recursive call adds frame to stack, returns pop frames. Stack overflow possible with deep recursion.",
        },
        {
          q: "How do you sort a stack using recursion?",
          a: "Recursively pop all elements, then insert each element in sorted position while backtracking. Time: O(n²), Space: O(n) for recursion",
        },
        {
          q: "How do you implement a stack that supports getMax in O(1)?",
          a: "Similar to Min Stack - maintain auxiliary stack tracking maximum at each level.",
        },
        {
          q: "What is the Celebrity Problem? How is stack used?",
          a: "Find person known by all but knows none. Use stack to eliminate non-celebrities by comparing pairs. Time: O(n)",
        },
        {
          q: "How do you check if a stack sequence is valid pop sequence of another sequence?",
          a: "Simulate push/pop operations using a stack. If simulation succeeds without violation, sequence is valid.",
        },
      ],
    },
    queue: {
      title: "Queue",
      questions: [
        {
          q: "What is a queue? Explain the FIFO principle.",
          a: "Linear data structure following First In First Out (FIFO). First element inserted is first to be removed, like a line of people.",
        },
        {
          q: "What are the basic operations of a queue and their time complexities?",
          a: "Enqueue: O(1), Dequeue: O(1), Front/Peek: O(1), isEmpty: O(1), Size: O(1)",
        },
        {
          q: "How do you implement a queue using an array?",
          a: "Use front and rear pointers. Enqueue at rear, dequeue from front. Can implement as circular queue to avoid wasted space.",
        },
        {
          q: "What is a circular queue? Why is it better than linear queue?",
          a: "Rear wraps around to start when reaching end. Avoids wasted space in linear queue where dequeued positions can't be reused.",
        },
        {
          q: "How do you implement a queue using two stacks?",
          a: "Stack1 for enqueue, Stack2 for dequeue. Transfer from Stack1 to Stack2 when Stack2 empty. Enqueue: O(1), Dequeue: O(1) amortized",
        },
        {
          q: "How do you implement a queue using a linked list?",
          a: "Use head for dequeue, tail for enqueue. Both operations O(1) with proper pointers. Dynamic size advantage.",
        },
        {
          q: "What is a double-ended queue (deque)?",
          a: "Allows insertion and deletion at both ends. Can work as stack or queue. Operations: insertFront, insertRear, deleteFront, deleteRear - all O(1)",
        },
        {
          q: "What is a priority queue? How is it implemented?",
          a: "Elements have priorities, highest priority dequeued first. Best implemented using heap. Insert: O(log n), Delete: O(log n)",
        },
        {
          q: "What is the difference between queue and priority queue?",
          a: "Queue: FIFO order. Priority Queue: elements served based on priority, not arrival order. Regular queue is special case where priority = arrival time.",
        },
        {
          q: "Where are queues used in real applications?",
          a: "CPU scheduling, disk scheduling, BFS traversal, printer job scheduling, handling requests in web servers, message queues",
        },
        {
          q: "How is BFS (Breadth-First Search) implemented using a queue?",
          a: "Start with source in queue. Dequeue node, process it, enqueue all unvisited neighbors. Repeat until queue empty.",
        },
        {
          q: "What is a circular buffer? How does it relate to circular queue?",
          a: "Fixed-size buffer with wrap-around behavior. Same as circular queue, used in streaming, buffering data between producer-consumer.",
        },
        {
          q: "How do you implement a queue with O(1) getMax operation?",
          a: "Use deque to maintain decreasing order of elements. Remove elements from back if smaller than new element being enqueued.",
        },
        {
          q: "What is the sliding window maximum problem? How is deque used?",
          a: "Find maximum in each window of size k. Use deque to store indices in decreasing order of values. Time: O(n)",
        },
        {
          q: "How do you reverse a queue?",
          a: "Use stack: dequeue all to stack, then pop all back to queue. Or use recursion. Time: O(n), Space: O(n)",
        },
        {
          q: "How do you implement a stack using two queues?",
          a: "Q1 for storage, Q2 for temporary. Push: enqueue to Q1. Pop: move all but last to Q2, dequeue last, swap Q1 and Q2.",
        },
        {
          q: "What is queue overflow and underflow?",
          a: "Overflow: enqueuing to full queue (fixed size). Underflow: dequeuing from empty queue. Both cause errors if not handled.",
        },
        {
          q: "How do you generate binary numbers from 1 to n using a queue?",
          a: "Start with '1' in queue. Dequeue, append '0' and '1' to create next two numbers, enqueue both. Repeat n times.",
        },
        {
          q: "What is the difference between blocking and non-blocking queue?",
          a: "Blocking: operations wait if queue full (enqueue) or empty (dequeue). Non-blocking: operations fail immediately. Used in concurrent programming.",
        },
        {
          q: "How do you find the first non-repeating character in a stream?",
          a: "Use queue to maintain order and hash map for frequency. Remove repeating characters from queue front. Time: O(n)",
        },
      ],
    },
    sorting: {
      title: "Sorting Algorithms",
      questions: [
        {
          q: "What is sorting? Why is it important?",
          a: "Arranging elements in order (ascending/descending). Important for: efficient searching, data analysis, optimization problems, better visualization.",
        },
        {
          q: "What is the time and space complexity of Bubble Sort?",
          a: "Time: Best O(n), Average O(n²), Worst O(n²). Space: O(1). Stable sorting algorithm.",
        },
        {
          q: "Explain how Bubble Sort works.",
          a: "Repeatedly compares adjacent elements and swaps if in wrong order. Largest element 'bubbles' to end each pass. Optimized with flag for early termination.",
        },
        {
          q: "What is the time and space complexity of Selection Sort?",
          a: "Time: O(n²) for all cases. Space: O(1). Unstable sorting (can be made stable with modifications).",
        },
        {
          q: "Explain how Selection Sort works.",
          a: "Finds minimum element from unsorted portion and places at beginning. Maintains sorted and unsorted portions. Makes minimum number of swaps.",
        },
        {
          q: "What is the time and space complexity of Insertion Sort?",
          a: "Time: Best O(n), Average O(n²), Worst O(n²). Space: O(1). Stable sorting algorithm.",
        },
        {
          q: "Explain how Insertion Sort works.",
          a: "Builds sorted array one element at a time. Takes element and inserts into correct position in sorted portion. Efficient for small or nearly sorted data.",
        },
        {
          q: "What is the time and space complexity of Merge Sort?",
          a: "Time: O(n log n) for all cases. Space: O(n) for auxiliary array. Stable sorting, divide-and-conquer approach.",
        },
        {
          q: "Explain how Merge Sort works.",
          a: "Divides array in half recursively until single elements, then merges sorted subarrays. Merge operation compares and combines two sorted arrays.",
        },
        {
          q: "What is the time and space complexity of Quick Sort?",
          a: "Time: Best O(n log n), Average O(n log n), Worst O(n²). Space: O(log n) for recursion stack. Unstable, in-place sorting.",
        },
        {
          q: "Explain how Quick Sort works.",
          a: "Picks pivot, partitions array (smaller left, larger right), recursively sorts partitions. Performance depends on pivot selection.",
        },
        {
          q: "What is the partition algorithm in Quick Sort?",
          a: "Places pivot in correct position with smaller elements left and larger right. Common approaches: Lomuto (simpler) and Hoare (efficient).",
        },
        {
          q: "How can you optimize Quick Sort to avoid O(n²) worst case?",
          a: "Random pivot selection, median-of-three pivot, three-way partitioning for duplicates, switch to insertion sort for small subarrays.",
        },
        {
          q: "What is the time and space complexity of Heap Sort?",
          a: "Time: O(n log n) for all cases. Space: O(1) as in-place. Unstable sorting algorithm.",
        },
        {
          q: "Explain how Heap Sort works.",
          a: "Build max heap from array (O(n)), repeatedly extract maximum (root) and place at end, then heapify remaining elements. Combines heap and sorting.",
        },
        {
          q: "What is the time and space complexity of Counting Sort?",
          a: "Time: O(n + k) where k is range of input. Space: O(k). Stable, non-comparison sort. Works best when k is not much larger than n.",
        },
        {
          q: "Explain how Counting Sort works and when to use it.",
          a: "Counts occurrences of each value, calculates positions, places elements in output. Use when range of input is known and not too large.",
        },
        {
          q: "What is the time and space complexity of Radix Sort?",
          a: "Time: O(d × (n + k)) where d is digits, k is base. Space: O(n + k). Stable, non-comparison sort.",
        },
        {
          q: "Explain how Radix Sort works.",
          a: "Sorts by individual digits from least to most significant (or reverse). Uses stable sort (counting sort) for each digit position.",
        },
        {
          q: "What is the time and space complexity of Bucket Sort?",
          a: "Time: Average O(n + k), Worst O(n²). Space: O(n + k). Stable when using stable sorting in buckets.",
        },
        {
          q: "Explain how Bucket Sort works.",
          a: "Distributes elements into buckets based on range, sorts individual buckets (insertion sort), concatenates. Works well for uniformly distributed data.",
        },
        {
          q: "What is a stable sorting algorithm? Give examples.",
          a: "Maintains relative order of equal elements. Examples: Bubble Sort, Insertion Sort, Merge Sort, Counting Sort, Radix Sort.",
        },
        {
          q: "What is an unstable sorting algorithm? Give examples.",
          a: "May change relative order of equal elements. Examples: Quick Sort, Selection Sort, Heap Sort (standard implementations).",
        },
        {
          q: "What is an in-place sorting algorithm?",
          a: "Uses O(1) extra space (constant space). Examples: Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, Heap Sort.",
        },
        {
          q: "Compare comparison-based vs non-comparison-based sorting.",
          a: "Comparison: compares elements, O(n log n) lower bound. Non-comparison: uses value properties, can be O(n) (Counting, Radix, Bucket).",
        },
        {
          q: "What is the lower bound for comparison-based sorting and why?",
          a: "Ω(n log n) in worst case. Based on decision tree model - need at least log₂(n!) comparisons to distinguish all n! permutations.",
        },
        {
          q: "When would you use Insertion Sort over Quick Sort?",
          a: "Small datasets (< 10-20 elements), nearly sorted data, stable sort needed, online sorting (elements arrive one at a time).",
        },
        {
          q: "What is 3-way partitioning in Quick Sort?",
          a: "Divides into three parts: less than pivot, equal to pivot, greater than pivot. Efficient for arrays with many duplicate elements.",
        },
        {
          q: "How does Timsort work (Python's default sort)?",
          a: "Hybrid of Merge Sort and Insertion Sort. Identifies 'runs' (sorted sequences), merges them. Time: O(n log n), stable, optimized for real-world data.",
        },
        {
          q: "What is external sorting? When is it used?",
          a: "Sorting data too large for memory. Uses disk storage, typically K-way merge sort. Used for: database operations, big data processing.",
        },
      ],
    },
    tree: {
      title: "Trees",
      questions: [
        {
          q: "What is a tree? Define key tree terminology.",
          a: "Hierarchical data structure with root node and children. Terms: root, parent, child, leaf, height, depth, level, degree, subtree.",
        },
        {
          q: "What is a binary tree? How does it differ from a general tree?",
          a: "Tree where each node has at most 2 children (left and right). General tree can have any number of children per node.",
        },
        {
          q: "What is the maximum number of nodes at level L in a binary tree?",
          a: "2^L nodes (L starts from 0). Level 0 (root): 1 node, Level 1: 2 nodes, Level 2: 4 nodes, etc.",
        },
        {
          q: "What is the maximum number of nodes in a binary tree of height H?",
          a: "2^(H+1) - 1 nodes. This occurs in a perfect binary tree.",
        },
        {
          q: "What is a complete binary tree?",
          a: "All levels filled except possibly last, which is filled from left to right. Used in heaps. Height: O(log n)",
        },
        {
          q: "What is a full binary tree?",
          a: "Every node has either 0 or 2 children (no node has exactly 1 child). Also called strictly binary tree.",
        },
        {
          q: "What is a perfect binary tree?",
          a: "All internal nodes have 2 children and all leaves at same level. Has 2^h - 1 nodes for height h.",
        },
        {
          q: "What is a balanced binary tree?",
          a: "Height difference between left and right subtrees ≤ 1 for every node. Ensures O(log n) operations. Examples: AVL, Red-Black trees.",
        },
        {
          q: "Explain Inorder traversal of binary tree.",
          a: "Left -> Root -> Right (LNR). Gives sorted order for BST. Recursive: traverse left, visit root, traverse right. Iterative: use stack.",
        },
        {
          q: "Explain Preorder traversal of binary tree.",
          a: "Root -> Left -> Right (NLR). Used for: copying tree, prefix expressions. Recursive: visit root, traverse left, traverse right.",
        },
        {
          q: "Explain Postorder traversal of binary tree.",
          a: "Left -> Right -> Root (LRN). Used for: deleting tree, postfix expressions. Recursive: traverse left, traverse right, visit root.",
        },
        {
          q: "Explain Level Order traversal of binary tree.",
          a: "Visit nodes level by level, left to right. Use queue: enqueue root, dequeue and process node, enqueue children. Time: O(n)",
        },
        {
          q: "What is the time complexity of tree traversals?",
          a: "O(n) for all traversals (inorder, preorder, postorder, level order) as each node is visited exactly once.",
        },
        {
          q: "What is a Binary Search Tree (BST)? What is its property?",
          a: "Binary tree where for each node: left subtree values < node value < right subtree values. Enables efficient search, insert, delete.",
        },
        {
          q: "What is the time complexity of search, insert, delete in BST?",
          a: "Average: O(log n) for balanced BST. Worst: O(n) for skewed tree (degenerates to linked list). Best: O(log n) for balanced.",
        },
        {
          q: "How do you search for an element in BST?",
          a: "Compare with root: if equal return, if smaller go left, if larger go right. Repeat recursively. Returns null if not found.",
        },
        {
          q: "How do you insert an element in BST?",
          a: "Search for position (leaf), create new node there. Maintain BST property. Always insert as leaf node. Time: O(h) where h is height.",
        },
        {
          q: "How do you delete a node from BST?",
          a: "Three cases: 1) Leaf: just remove. 2) One child: replace with child. 3) Two children: replace with inorder successor/predecessor, delete successor/predecessor.",
        },
        {
          q: "What is an inorder successor? How to find it?",
          a: "Next node in inorder traversal. For node with right subtree: leftmost node in right subtree. Without: ancestor where node is in left subtree.",
        },
        {
          q: "What is an AVL tree? Why is it needed?",
          a: "Self-balancing BST where height difference (balance factor) between left and right subtrees ≤ 1. Guarantees O(log n) operations. Prevents skewing.",
        },
        {
          q: "What are the rotations in AVL tree?",
          a: "Four types: Left-Left (LL - right rotation), Right-Right (RR - left rotation), Left-Right (LR - left then right), Right-Left (RL - right then left). Used to maintain balance.",
        },
        {
          q: "What is a Red-Black Tree?",
          a: "Self-balancing BST with color property (red/black). Rules ensure height ≤ 2log(n+1). Faster insertions than AVL but slower searches.",
        },
        {
          q: "What is the lowest common ancestor (LCA) in a binary tree?",
          a: "Deepest node that has both given nodes as descendants. Can find in O(n) using recursion or O(log n) with preprocessing.",
        },
        {
          q: "How do you find the diameter of a binary tree?",
          a: "Longest path between any two nodes. At each node, consider diameter passing through it = left_height + right_height. Return max. Time: O(n)",
        },
        {
          q: "How do you check if a binary tree is balanced?",
          a: "Recursively check height difference ≤ 1 for all nodes. Can optimize to return both height and balance status. Time: O(n)",
        },
        {
          q: "How do you find the height/depth of a binary tree?",
          a: "Recursively: 1 + max(left_height, right_height). Base case: null node has height -1 or 0 (by convention). Time: O(n)",
        },
        {
          q: "What is a segment tree? What is it used for?",
          a: "Binary tree for range queries (sum, min, max) and updates. Build: O(n), Query: O(log n), Update: O(log n). Space: O(4n)",
        },
        {
          q: "What is a Fenwick Tree (Binary Indexed Tree)?",
          a: "Array-based structure for range sum queries and point updates. Space: O(n), Query: O(log n), Update: O(log n). More space efficient than segment tree.",
        },
        {
          q: "What is a Trie (Prefix Tree)?",
          a: "Tree for storing strings where each node represents a character. Used for: autocomplete, spell check, IP routing. Insert/Search: O(L) where L is string length.",
        },
        {
          q: "What is the difference between binary tree and binary heap?",
          a: "Binary tree: hierarchical structure, can be any shape. Binary heap: complete binary tree with heap property (parent ≥ children for max heap).",
        },
      ],
    },
    graph: {
      title: "Graphs",
      questions: [
        {
          q: "What is a graph? Define its components.",
          a: "Set of vertices (nodes) connected by edges. Components: vertices (V), edges (E), degree, path, cycle, connected/disconnected.",
        },
        {
          q: "What are the types of graphs?",
          a: "Directed/Undirected, Weighted/Unweighted, Cyclic/Acyclic, Connected/Disconnected, Dense/Sparse, Simple/Multigraph.",
        },
        {
          q: "What is the difference between directed and undirected graphs?",
          a: "Directed: edges have direction (u→v ≠ v→u). Undirected: edges are bidirectional (u-v = v-u). Examples: Twitter (directed), Facebook (undirected).",
        },
        {
          q: "What is a weighted graph? Give examples.",
          a: "Edges have associated weights/costs. Examples: road networks (distance), flight routes (cost), network latency.",
        },
        {
          q: "How do you represent a graph? Compare representations.",
          a: "1) Adjacency Matrix: O(V²) space, O(1) edge check. 2) Adjacency List: O(V+E) space, O(degree) edge check. List better for sparse graphs.",
        },
        {
          q: "What is the space complexity of adjacency matrix vs adjacency list?",
          a: "Matrix: O(V²) always. List: O(V+E). For sparse graphs (E << V²), list is more space efficient.",
        },
        {
          q: "What is BFS (Breadth-First Search)? How does it work?",
          a: "Level-wise traversal using queue. Visit node, enqueue all neighbors, repeat. Finds shortest path in unweighted graph. Time: O(V+E)",
        },
        {
          q: "What is DFS (Depth-First Search)? How does it work?",
          a: "Explores as far as possible before backtracking. Use stack (or recursion). Used for: cycle detection, topological sort, connected components. Time: O(V+E)",
        },
        {
          q: "Compare BFS and DFS. When to use which?",
          a: "BFS: shortest path, level-wise, uses queue, more memory. DFS: path finding, cycle detection, uses stack, less memory. BFS for unweighted shortest path.",
        },
        {
          q: "How do you detect a cycle in an undirected graph?",
          a: "Using DFS: if visiting a visited node (not parent), cycle exists. Or use Union-Find. Time: O(V+E)",
        },
        {
          q: "How do you detect a cycle in a directed graph?",
          a: "Using DFS with recursion stack: if node in current DFS path is revisited, cycle exists. Track visited and recursion stack separately. Time: O(V+E)",
        },
        {
          q: "What is topological sorting? When is it possible?",
          a: "Linear ordering of vertices where u comes before v if edge u→v exists. Only possible in DAG (Directed Acyclic Graph). Time: O(V+E)",
        },
        {
          q: "How do you perform topological sort?",
          a: "Two methods: 1) DFS-based: finish time order. 2) Kahn's algorithm: BFS with in-degree. Both O(V+E). Used in: task scheduling, prerequisite problems.",
        },
        {
          q: "What is Dijkstra's algorithm? What is its time complexity?",
          a: "Finds shortest path from source to all vertices in weighted graph (non-negative weights). Uses priority queue. Time: O((V+E) log V) with min-heap.",
        },
        {
          q: "What are the limitations of Dijkstra's algorithm?",
          a: "Doesn't work with negative edge weights. Can get stuck in infinite loops with negative cycles. Use Bellman-Ford for negative weights.",
        },
        {
          q: "What is Bellman-Ford algorithm? When to use it?",
          a: "Finds shortest path with negative edge weights. Can detect negative cycles. Relaxes all edges V-1 times. Time: O(VE). Slower than Dijkstra but handles negative weights.",
        },
        {
          q: "What is Floyd-Warshall algorithm?",
          a: "Finds shortest paths between all pairs of vertices. Works with negative weights (no negative cycles). Time: O(V³), Space: O(V²). Dynamic programming approach.",
        },
        {
          q: "What is Prim's algorithm for MST?",
          a: "Grows MST one vertex at a time. Start with any vertex, add minimum weight edge connecting to tree. Use priority queue. Time: O((V+E) log V)",
        },
        {
          q: "What is Kruskal's algorithm for MST?",
          a: "Sorts all edges, adds minimum weight edge that doesn't form cycle. Uses Union-Find. Time: O(E log E) for sorting. Works on disconnected graphs.",
        },
        {
          q: "What is a Minimum Spanning Tree (MST)?",
          a: "Subset of edges connecting all vertices with minimum total weight, no cycles. Has V-1 edges. Used in: network design, clustering.",
        },
        {
          q: "Compare Prim's and Kruskal's algorithms.",
          a: "Prim's: grows tree from vertex, better for dense graphs, needs connected graph. Kruskal's: edge-based, better for sparse graphs, works on disconnected.",
        },
        {
          q: "What is Union-Find (Disjoint Set Union)?",
          a: "Data structure for tracking disjoint sets. Operations: Find (which set), Union (merge sets). Used in: Kruskal's, cycle detection. Time: O(α(n)) with optimizations.",
        },
        {
          q: "What optimizations are used in Union-Find?",
          a: "1) Union by Rank: attach smaller tree to larger. 2) Path Compression: flatten tree during find. Together give O(α(n)) amortized time (nearly constant).",
        },
        {
          q: "What is a strongly connected component (SCC)?",
          a: "Maximal set of vertices where every vertex is reachable from every other. In directed graphs. Find using Kosaraju's or Tarjan's algorithm. Time: O(V+E)",
        },
        {
          q: "What is Kosaraju's algorithm for finding SCCs?",
          a: "Two DFS passes: 1) Find finish times. 2) DFS on transpose graph in reverse finish time order. Each DFS tree is an SCC. Time: O(V+E)",
        },
        {
          q: "What is a bipartite graph? How to check if graph is bipartite?",
          a: "Vertices can be divided into two sets with edges only between sets. Check using BFS/DFS with 2-coloring. If odd-length cycle exists, not bipartite.",
        },
        {
          q: "What is the Traveling Salesman Problem (TSP)?",
          a: "Find shortest route visiting all cities exactly once and returning to start. NP-hard problem. Brute force: O(n!), DP with bitmask: O(n²·2ⁿ)",
        },
        {
          q: "What is the difference between Eulerian and Hamiltonian path?",
          a: "Eulerian: uses every edge exactly once. Hamiltonian: visits every vertex exactly once. Eulerian is polynomial time, Hamiltonian is NP-complete.",
        },
        {
          q: "What is an Eulerian path/circuit? When does it exist?",
          a: "Path: uses every edge once. Circuit: path that returns to start. Exists if: graph connected and 0 or 2 odd-degree vertices (path) or all even (circuit).",
        },
        {
          q: "What is A* algorithm? How does it differ from Dijkstra?",
          a: "Informed search using heuristic h(n) + actual cost g(n). Dijkstra is special case with h(n)=0. Faster when good heuristic available. Used in: pathfinding, games.",
        },
        {
          q: "What is the Bridges and Articulation Points problem?",
          a: "Bridge: edge whose removal increases connected components. Articulation: vertex whose removal increases components. Find using DFS with low-link values. Time: O(V+E)",
        },
      ],
    },
    algorithms: {
      title: "Algorithm Paradigms",
      questions: [
        {
          q: "What is the Divide and Conquer paradigm? Give examples.",
          a: "Breaks problem into smaller subproblems, solves recursively, combines solutions. Examples: Merge Sort, Quick Sort, Binary Search, Strassen's Matrix Multiplication.",
        },
        {
          q: "What are the three steps of Divide and Conquer?",
          a: "1) Divide: break into subproblems. 2) Conquer: solve subproblems recursively. 3) Combine: merge solutions. Recurrence often: T(n) = aT(n/b) + f(n)",
        },
        {
          q: "What is the Greedy paradigm? Give examples.",
          a: "Makes locally optimal choice at each step hoping for global optimum. Examples: Dijkstra's, Prim's, Kruskal's, Huffman Coding, Activity Selection.",
        },
        {
          q: "When does greedy approach give optimal solution?",
          a: "When problem has optimal substructure and greedy choice property. Not always correct (e.g., 0/1 Knapsack fails). Must prove correctness.",
        },
        {
          q: "What is Dynamic Programming (DP)? When to use it?",
          a: "Breaks problem into overlapping subproblems, stores solutions (memoization/tabulation). Use when: optimal substructure + overlapping subproblems exist.",
        },
        {
          q: "What is the difference between memoization and tabulation?",
          a: "Memoization: top-down, recursive, computes on demand. Tabulation: bottom-up, iterative, fills table. Both O(n) space, tabulation often better for cache.",
        },
        {
          q: "What is the difference between Divide & Conquer and Dynamic Programming?",
          a: "D&C: independent subproblems, no overlap. DP: overlapping subproblems, stores solutions. D&C example: Merge Sort. DP example: Fibonacci with memoization.",
        },
        {
          q: "What is Backtracking? Give examples.",
          a: "Explores all possibilities by building solution incrementally, abandons (backtracks) when constraints violated. Examples: N-Queens, Sudoku, Rat in Maze, Subset Sum.",
        },
        {
          q: "How does Branch and Bound differ from Backtracking?",
          a: "Both explore tree. Backtracking: checks feasibility. Branch & Bound: uses bounds to prune, optimizes cost. B&B used for optimization problems (TSP, Knapsack).",
        },
        {
          q: "What is the Two Pointer technique? When is it useful?",
          a: "Uses two pointers moving through data structure. Useful for: sorted arrays, finding pairs, partitioning, palindromes. Often reduces O(n²) to O(n).",
        },
        {
          q: "What is the Sliding Window technique? Give examples.",
          a: "Maintains window of elements while sliding through array. Examples: max sum of k elements, longest substring without repeating, minimum window substring.",
        },
        {
          q: "What is Binary Search? What is its prerequisite?",
          a: "Divide search space in half each iteration. Requires sorted array. Time: O(log n). Can be applied to search spaces beyond arrays (answer spaces).",
        },
        {
          q: "How do you apply binary search on answer/search space?",
          a: "When answer lies in range and monotonic condition exists. Binary search on possible answers, check if feasible. Examples: square root, book allocation.",
        },
        {
          q: "What is the Meet in the Middle technique?",
          a: "Divides problem into two halves, solves each, combines results. Reduces O(2ⁿ) to O(2^(n/2)). Example: subset sum with smaller exponential complexity.",
        },
        {
          q: "What is Bit Manipulation? Give common tricks.",
          a: "Operations on bits. Tricks: x&1 (odd check), x&(x-1) (remove rightmost 1), x^x=0, x^0=x, -x=~x+1 (2's complement). Fast and space efficient.",
        },
        {
          q: "How do you check if a number is a power of 2?",
          a: "n > 0 && (n & (n-1)) == 0. Power of 2 has exactly one bit set. n&(n-1) removes rightmost bit.",
        },
        {
          q: "What is the Fast Power algorithm (Exponentiation by Squaring)?",
          a: "Computes x^n in O(log n). If n even: x^n = (x^(n/2))². If odd: x^n = x × (x^(n/2))². Uses divide and conquer.",
        },
        {
          q: "What is the Euclidean algorithm for GCD?",
          a: "GCD(a,b) = GCD(b, a mod b) until b=0. Time: O(log min(a,b)). Can extend to find coefficients in Bézout's identity.",
        },
        {
          q: "What is the Sieve of Eratosthenes?",
          a: "Finds all primes up to n. Mark multiples of each prime as composite. Time: O(n log log n), Space: O(n). Most efficient for finding many primes.",
        },
        {
          q: "What is the KMP (Knuth-Morris-Pratt) algorithm?",
          a: "Pattern matching algorithm. Uses LPS (Longest Proper Prefix Suffix) array to avoid re-checking matched characters. Time: O(n+m) vs O(nm) naive.",
        },
        {
          q: "What is the Rabin-Karp algorithm?",
          a: "Pattern matching using rolling hash. Computes hash of pattern and text windows. Time: O(n+m) average, O(nm) worst. Good for multiple pattern search.",
        },
        {
          q: "What is the Z-algorithm?",
          a: "Finds all occurrences of pattern in text. Creates Z-array where Z[i] is length of longest substring starting at i matching prefix. Time: O(n+m)",
        },
        {
          q: "What is the Boyer-Moore algorithm?",
          a: "Pattern matching with bad character and good suffix rules. Skips sections of text. Time: O(n/m) best case, O(nm) worst. Very fast in practice.",
        },
        {
          q: "What is Manacher's algorithm?",
          a: "Finds longest palindromic substring in O(n) time. Uses previously computed palindrome info to avoid recomputation. Better than O(n²) expand around center.",
        },
        {
          q: "What is the Flood Fill algorithm?",
          a: "Fills connected region in matrix. Used in: paint bucket, puzzle solving, island problems. Implementation: DFS or BFS. Time: O(rows × cols)",
        },
        {
          q: "What is the Catalan Number? Give applications.",
          a: "Cₙ = (2n)!/(n+1)!n! = C(2n,n)/(n+1). Applications: BST count, valid parentheses, ways to triangulate polygon, mountain ranges.",
        },
        {
          q: "What is the Pigeonhole Principle in algorithms?",
          a: "If n items in m containers and n > m, at least one container has >1 item. Used to prove: duplicates exist, birthday paradox, substring problems.",
        },
        {
          q: "What is amortized analysis? Give an example.",
          a: "Average time per operation over worst-case sequence. Example: Dynamic array doubling - individual insert can be O(n) but amortized O(1).",
        },
        {
          q: "What is the difference between online and offline algorithms?",
          a: "Online: processes input piece-by-piece without future knowledge. Offline: has all input beforehand. Example: online vs offline sorting, streaming algorithms.",
        },
        {
          q: "What are Las Vegas and Monte Carlo algorithms?",
          a: "Las Vegas: always correct, random runtime (QuickSort with random pivot). Monte Carlo: always fast, possibly incorrect (Miller-Rabin primality). Randomized algorithms.",
        },
      ],
    },
    dp: {
      title: "Dynamic Programming",
      questions: [
        {
          q: "What is Dynamic Programming? When should you use it?",
          a: "Optimization technique storing solutions to subproblems. Use when: 1) Optimal substructure 2) Overlapping subproblems exist. Converts exponential to polynomial time.",
        },
        {
          q: "What is the difference between top-down and bottom-up DP?",
          a: "Top-down (Memoization): recursive, computes on demand, uses recursion stack. Bottom-up (Tabulation): iterative, fills table systematically, better cache performance.",
        },
        {
          q: "What is the Fibonacci problem? Compare naive vs DP solutions.",
          a: "Fib(n) = Fib(n-1) + Fib(n-2). Naive recursion: O(2ⁿ) time. DP memoization: O(n) time, O(n) space. DP tabulation: O(n) time, O(1) space (only store last 2).",
        },
        {
          q: "Explain the 0/1 Knapsack problem and its DP solution.",
          a: "Given weights and values, maximize value within capacity. Can't break items. DP: dp[i][w] = max value with first i items and capacity w. Time: O(n×W), Space: O(n×W)",
        },
        {
          q: "Explain the Unbounded Knapsack problem. How does it differ from 0/1?",
          a: "Can take unlimited quantity of each item. DP: for each weight, try all items. Same formula but inner loop forward. Time: O(n×W)",
        },
        {
          q: "What is the Longest Common Subsequence (LCS) problem?",
          a: "Find longest subsequence common to two strings. DP: if chars match, 1+LCS(i-1,j-1), else max(LCS(i-1,j), LCS(i,j-1)). Time: O(m×n)",
        },
        {
          q: "What is the Longest Increasing Subsequence (LIS) problem?",
          a: "Find longest strictly increasing subsequence. DP: O(n²) or Binary Search: O(n log n). DP[i] = length of LIS ending at i.",
        },
        {
          q: "What is the Edit Distance (Levenshtein Distance) problem?",
          a: "Minimum operations (insert, delete, replace) to convert string1 to string2. DP: if chars match, dp[i-1][j-1], else 1+min of three operations. Time: O(m×n)",
        },
        {
          q: "What is the Coin Change problem? Explain both variations.",
          a: "Min coins: dp[i] = 1 + min(dp[i-coin]). Ways to make change: dp[i] += dp[i-coin]. Time: O(n×amount), Space: O(amount)",
        },
        {
          q: "What is the Rod Cutting problem?",
          a: "Cut rod of length n to maximize profit. Similar to unbounded knapsack. dp[i] = max(price[j] + dp[i-j-1]) for all j. Time: O(n²)",
        },
        {
          q: "What is the Matrix Chain Multiplication problem?",
          a: "Find optimal parenthesization to minimize scalar multiplications. dp[i][j] = min cost for multiplying matrices i to j. Time: O(n³), Space: O(n²)",
        },
        {
          q: "What is the Palindrome Partitioning problem?",
          a: "Partition string into minimum palindromic substrings. DP: dp[i] = min cuts for substring [0...i]. Check all palindrome endings at i. Time: O(n²)",
        },
        {
          q: "What is the Longest Palindromic Subsequence problem?",
          a: "Find longest palindromic subsequence. DP: dp[i][j] = LPS of substring i to j. If s[i]==s[j], 2+dp[i+1][j-1]. Time: O(n²)",
        },
        {
          q: "What is the Longest Palindromic Substring problem?",
          a: "Find longest contiguous palindromic substring. DP: dp[i][j] = true if substring is palindrome. Or expand around center O(n²). Manacher's: O(n)",
        },
        {
          q: "What is the Egg Dropping problem?",
          a: "Find minimum trials needed to find threshold floor. DP: dp[eggs][floors] = min over all floors of (1 + max(dp[eggs-1][floor-1], dp[eggs][totalFloors-floor])). Time: O(n×k²)",
        },
        {
          q: "What is the Partition Equal Subset Sum problem?",
          a: "Check if array can be partitioned into two equal sum subsets. DP: subset sum with target = totalSum/2. Time: O(n×sum), Space: O(sum)",
        },
        {
          q: "What is the Minimum Path Sum problem in a grid?",
          a: "Find path from top-left to bottom-right with minimum sum. DP: dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]). Time: O(m×n)",
        },
        {
          q: "What is the Unique Paths problem in a grid?",
          a: "Count paths from top-left to bottom-right moving only right/down. DP: dp[i][j] = dp[i-1][j] + dp[i][j-1]. Time: O(m×n) or O(m+n) with math.",
        },
        {
          q: "What is the House Robber problem?",
          a: "Rob houses to maximize money without robbing adjacent. DP: dp[i] = max(dp[i-1], nums[i] + dp[i-2]). Time: O(n), Space: O(1) optimized",
        },
        {
          q: "What is the Climbing Stairs problem?",
          a: "Ways to reach top taking 1 or 2 steps. DP: dp[i] = dp[i-1] + dp[i-2]. Same as Fibonacci. Time: O(n), Space: O(1)",
        },
        {
          q: "What is the Word Break problem?",
          a: "Check if string can be segmented into dictionary words. DP: dp[i] = true if substring [0...i] can be segmented. Time: O(n²×m) worst case",
        },
        {
          q: "What is the Decode Ways problem?",
          a: "Count ways to decode numeric string (A=1, B=2, ..., Z=26). DP: dp[i] depends on last 1 or 2 digits being valid. Time: O(n)",
        },
        {
          q: "What is the Regular Expression Matching problem?",
          a: "Match string against pattern with '.' and '*'. DP: dp[i][j] = match for text[0...i] and pattern[0...j]. Time: O(m×n)",
        },
        {
          q: "What is the Interleaving String problem?",
          a: "Check if s3 is interleaving of s1 and s2 maintaining order. DP: dp[i][j] = true if first i+j chars of s3 can be formed. Time: O(m×n)",
        },
        {
          q: "What is the Wildcard Matching problem?",
          a: "Match string against pattern with '?' (any char) and '*' (any sequence). DP similar to regex matching. Time: O(m×n)",
        },
        {
          q: "What is the Minimum Cost to Merge Stones?",
          a: "Merge piles of stones with minimum cost. Extension of matrix chain multiplication. DP: dp[i][j][p] = min cost to merge [i...j] into p piles. Time: O(n³)",
        },
        {
          q: "What is the Best Time to Buy and Sell Stock (various versions)?",
          a: "Multiple versions: single transaction (greedy), multiple transactions (DP), k transactions (DP with state), with cooldown (state machine DP). Time varies O(n) to O(n×k)",
        },
        {
          q: "What is the Maximal Square problem?",
          a: "Find largest square of 1s in binary matrix. DP: dp[i][j] = side of largest square with bottom-right at (i,j). Formula: 1 + min of three neighbors. Time: O(m×n)",
        },
        {
          q: "What is Kadane's Algorithm? Is it DP?",
          a: "Finds maximum subarray sum. Yes, it's DP: dp[i] = max(nums[i], dp[i-1] + nums[i]). Greedy-like but optimal substructure. Time: O(n), Space: O(1)",
        },
        {
          q: "What is the difference between DP and Greedy?",
          a: "Greedy: makes locally optimal choice each step, may not be globally optimal. DP: considers all choices, stores results, guarantees optimal. Greedy faster when it works.",
        },
      ],
    },
    greedy: {
      title: "Greedy Algorithms",
      questions: [
        {
          q: "What is a Greedy Algorithm? When does it work?",
          a: "Makes locally optimal choice at each step hoping for global optimum. Works when: 1) Greedy choice property 2) Optimal substructure exist. Must prove correctness.",
        },
        {
          q: "What is the difference between Greedy and Dynamic Programming?",
          a: "Greedy: makes one choice per step, no backtracking, may not always be optimal. DP: considers all choices, stores solutions, always optimal for solvable problems.",
        },
        {
          q: "What is the Activity Selection problem?",
          a: "Select maximum non-overlapping activities. Greedy: sort by end time, select if start ≥ previous end. Time: O(n log n) for sorting. Proof: earliest finish time is safe.",
        },
        {
          q: "What is the Fractional Knapsack problem?",
          a: "Can take fractions of items to maximize value. Greedy: sort by value/weight ratio, take highest ratio first. Time: O(n log n). Unlike 0/1 Knapsack, greedy works here.",
        },
        {
          q: "Why doesn't greedy work for 0/1 Knapsack?",
          a: "Taking highest value/weight ratio may not be optimal. Example: capacity=10, items: (7kg,$42, $6/kg) vs (3kg,$18, $6/kg)+(4kg,$28, $7/kg). Needs DP.",
        },
        {
          q: "What is Huffman Coding? How does the greedy algorithm work?",
          a: "Optimal prefix-free encoding. Build tree bottom-up: merge two smallest frequency nodes repeatedly. Frequent chars get shorter codes. Time: O(n log n) with priority queue.",
        },
        {
          q: "What is the Job Sequencing problem?",
          a: "Schedule jobs with deadlines and profits to maximize profit. Greedy: sort by profit descending, assign to latest available slot before deadline. Time: O(n²) or O(n log n) with efficient structures.",
        },
        {
          q: "What is the Minimum Platforms problem (train scheduling)?",
          a: "Find minimum platforms needed for trains with arrival/departure times. Greedy: sort arrivals and departures, track overlap. Time: O(n log n)",
        },
        {
          q: "What is the N meetings in one room problem?",
          a: "Maximum meetings in single room (same as Activity Selection). Greedy: sort by end time, select non-overlapping. Time: O(n log n)",
        },
        {
          q: "What is the Minimum Coins problem? When does greedy work?",
          a: "Make change with minimum coins. Greedy works for canonical coin systems (like USD: 1,5,10,25). May fail for arbitrary systems. DP needed for general case.",
        },
        {
          q: "What is the Water Connection problem?",
          a: "Connect houses with pipes to maximize minimum diameter. Greedy: sort pipes by diameter descending, use disjoint set union. Time: O(n log n)",
        },
        {
          q: "What is the Partition problem and why doesn't greedy work?",
          a: "Partition array into two equal sum subsets. Greedy (largest first) fails. Example: {3,3,3,3,2,2,2,2,2,2} can partition but greedy picks {3,3,3,3} leaving impossible remainder. Needs DP.",
        },
        {
          q: "What is the Jump Game problem? When can you use greedy?",
          a: "Check if can reach end of array. Greedy: track farthest reachable index. Time: O(n). Greedy works because if we can reach position i, we can reach all positions before i.",
        },
        {
          q: "What is the Gas Station (Circular Tour) problem?",
          a: "Find starting gas station to complete circuit. Greedy: if total gas ≥ total cost, solution exists. Start from first station where cumulative gas-cost becomes negative. Time: O(n)",
        },
        {
          q: "What is the Page Replacement (FIFO, LRU, Optimal)?",
          a: "FIFO: remove oldest (queue). LRU: remove least recently used (hash+doubly linked list). Optimal: remove page used farthest in future (greedy, not practical). Belady's anomaly.",
        },
        {
          q: "What is the Candy Distribution problem?",
          a: "Give candies to children based on ratings, neighbor with higher rating gets more. Greedy: two passes (left to right, right to left). Time: O(n), Space: O(n)",
        },
        {
          q: "What is the Assign Cookies problem?",
          a: "Maximize number of content children given cookies. Greedy: sort both arrays, assign smallest sufficient cookie to each child. Time: O(n log n)",
        },
        {
          q: "What is the Minimum Arrows to Burst Balloons?",
          a: "Balloons at intervals, find minimum arrows. Same as Activity Selection: sort by end, shoot when next balloon doesn't overlap. Time: O(n log n)",
        },
        {
          q: "What is the Non-overlapping Intervals problem?",
          a: "Remove minimum intervals to make rest non-overlapping. Greedy: Activity Selection - keep maximum non-overlapping. Answer = total - selected. Time: O(n log n)",
        },
        {
          q: "What is Prim's Algorithm? Is it greedy?",
          a: "Yes, greedy MST algorithm. Starts with vertex, repeatedly adds minimum weight edge connecting to tree. Uses priority queue. Time: O(E log V)",
        },
        {
          q: "What is Kruskal's Algorithm? Is it greedy?",
          a: "Yes, greedy MST algorithm. Sorts all edges, adds minimum weight edge that doesn't form cycle. Uses Union-Find. Time: O(E log E). Works on disconnected graphs.",
        },
        {
          q: "What is Dijkstra's Algorithm? Is it greedy?",
          a: "Yes, greedy shortest path algorithm. Always picks unvisited vertex with minimum distance. Uses priority queue. Time: O((V+E) log V). Doesn't work with negative weights.",
        },
        {
          q: "What is the Interval Scheduling Maximization?",
          a: "Maximize number of non-overlapping intervals. Greedy: sort by finish time, pick earliest finishing interval that doesn't overlap. Proof: earliest finish leaves most room. Time: O(n log n)",
        },
        {
          q: "What is the Minimum Spanning Tree problem?",
          a: "Connect all vertices with minimum total edge weight, no cycles. Greedy solutions: Prim's (vertex-based) or Kruskal's (edge-based). Both correct and optimal.",
        },
        {
          q: "What is the Interval Partitioning problem?",
          a: "Partition intervals into minimum number of groups where no two overlap in a group. Greedy: sort by start time, assign to earliest available group (depth = max overlap). Time: O(n log n)",
        },
        {
          q: "What is the Minimize Lateness problem?",
          a: "Schedule jobs to minimize maximum lateness. Greedy: Earliest Deadline First (EDF). Sort by deadline, schedule in order. Proof: swapping inverted pairs doesn't increase max lateness. Time: O(n log n)",
        },
        {
          q: "What is the Optimal Caching problem?",
          a: "Decide which item to evict from cache. Greedy: evict item needed farthest in future (Bélády's algorithm). Optimal but not practical (needs future knowledge). Online: use LRU.",
        },
        {
          q: "What is the Set Cover problem? Is greedy optimal?",
          a: "Cover all elements with minimum sets. NP-complete. Greedy: pick set covering most uncovered elements. Not optimal but good approximation (H_n = O(log n) factor).",
        },
        {
          q: "What is the Vertex Cover problem? Is greedy optimal?",
          a: "Select minimum vertices to cover all edges. NP-complete. Greedy gives 2-approximation: pick edge, add both endpoints, remove covered edges. Not optimal but bounded.",
        },
        {
          q: "What is the Task Scheduling with deadlines and profits?",
          a: "Maximize profit by completing tasks before deadlines. Greedy: sort by profit decreasing, schedule in latest possible slot. Use disjoint set for efficient slot finding. Time: O(n log n)",
        },
      ],
    },
  };

  const generatePDF = () => {
    let pdfContent = `DATA STRUCTURES AND ALGORITHMS - COMPREHENSIVE QUIZ
================================================================================================

`;

    Object.values(quizData).forEach((topic) => {
      pdfContent += `\n\n${"=".repeat(90)}\n`;
      pdfContent += `${topic.title.toUpperCase()}\n`;
      pdfContent += `${"=".repeat(90)}\n\n`;

      topic.questions.forEach((item, index) => {
        pdfContent += `Q${index + 1}. ${item.q}\n\n`;
        pdfContent += `Answer: ${item.a}\n\n`;
        pdfContent += `${"-".repeat(90)}\n\n`;
      });
    });

    // Create blob and download
    const blob = new Blob([pdfContent], { type: "text/plain" });
    const url = URL.createObjectURL(blob);
    const a = document.createElement("a");
    a.href = url;
    a.download = "DSA_Complete_Quiz.txt";
    document.body.appendChild(a);
    a.click();
    document.body.removeChild(a);
    URL.revokeObjectURL(url);
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-blue-50 to-indigo-100 p-8">
      <div className="max-w-6xl mx-auto">
        <div className="bg-white rounded-2xl shadow-2xl p-8 mb-8">
          <div className="flex items-center justify-between mb-6">
            <div className="flex items-center gap-3">
              <BookOpen className="w-10 h-10 text-indigo-600" />
              <h1 className="text-4xl font-bold text-gray-800">
                Complete DSA Quiz Collection
              </h1>
            </div>
            <button
              onClick={generatePDF}
              className="flex items-center gap-2 bg-indigo-600 text-white px-6 py-3 rounded-lg hover:bg-indigo-700 transition-colors shadow-lg"
            >
              <Download className="w-5 h-5" />
              Download as Text File
            </button>
          </div>

          <div className="bg-indigo-50 border-l-4 border-indigo-600 p-4 mb-6">
            <p className="text-indigo-900 font-medium">
              📚 Total Questions:{" "}
              <span className="font-bold">
                {Object.values(quizData).reduce(
                  (sum, topic) => sum + topic.questions.length,
                  0
                )}
              </span>
            </p>
            <p className="text-indigo-800 text-sm mt-2">
              Comprehensive coverage of Arrays, Linked Lists, Time Complexity,
              Stack, Queue, Sorting, Trees, Graphs, Algorithms, Dynamic
              Programming, and Greedy Algorithms
            </p>
          </div>
        </div>

        {Object.entries(quizData).map(([key, topic]) => (
          <div key={key} className="bg-white rounded-xl shadow-lg p-6 mb-6">
            <h2 className="text-2xl font-bold text-indigo-600 mb-4 flex items-center gap-2">
              <span className="bg-indigo-100 px-3 py-1 rounded-full text-lg">
                {topic.questions.length}
              </span>
              {topic.title}
            </h2>

            <div className="space-y-4">
              {topic.questions.map((item, index) => (
                <div
                  key={index}
                  className="border-l-4 border-indigo-300 bg-gray-50 p-4 rounded-r-lg hover:bg-indigo-50 transition-colors"
                >
                  <p className="font-semibold text-gray-800 mb-2">
                    <span className="text-indigo-600">Q{index + 1}.</span>{" "}
                    {item.q}
                  </p>
                  <p className="text-gray-700 pl-6">
                    <span className="font-semibold text-green-600">
                      Answer:
                    </span>{" "}
                    {item.a}
                  </p>
                </div>
              ))}
            </div>
          </div>
        ))}

        <div className="bg-gradient-to-r from-indigo-600 to-purple-600 text-white rounded-xl shadow-lg p-6 text-center">
          <h3 className="text-xl font-bold mb-2">
            Ready to Test Your Knowledge?
          </h3>
          <p className="text-indigo-100">
            Download this complete quiz collection and master Data Structures &
            Algorithms!
          </p>
        </div>
      </div>
    </div>
  );
};

export default DSAQuizPDF;
