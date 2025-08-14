### DSA Lab – Linked List Tasks

---

#### **Task 1: Basic Linked List Operations**

1. Write a C/C++/Java/Python program to create a singly linked list.
2. Implement functions to insert elements (alphabetic, numeric, alphanumeric, strings) at:

   * The beginning
   * The end
   * A specific position in the list
3. Create a function to delete an element from the list based on its value.
4. Display the contents of the linked list.
5. Implement a function to find the length of the linked list.

---

#### **Task 2: Handling Elements of a Linked List**

1. **Remove Duplicates**
   Given a singly linked list consisting of `N` nodes, remove duplicates (nodes with duplicate values) without sorting the list.

   **Example 1**
   Input: `2 -> 2 -> 4 -> 5`
   Output: `2 -> 4 -> 5`

   **Example 2**
   Input: `2 -> 2 -> 2 -> 2`
   Output: `2`

2. **Swap Adjacent Nodes**
   Given a linked list, swap every two adjacent nodes and return its head. Do not modify the values in the nodes.

   **Example**
   Input: `999 -> 888 -> 777 -> 666 -> 555 -> 444 -> 333 -> 222`
   Output: `888 -> 999 -> 666 -> 777 -> 444 -> 555 -> 222 -> 333`

3. **Reorder List**
   Given a singly linked list:
   `A0 -> A1 -> ... -> An-2 -> An-1`
   Reorder it to:
   `A0 -> An-1 -> A1 -> An-2 -> A2 -> An-3 -> ...`

   **Example**
   Input: `999 -> 888 -> 777 -> 666 -> 555 -> 444 -> 333 -> 222 -> 111`
   Output: `999 -> 111 -> 888 -> 222 -> 777 -> 333 -> 666 -> 444 -> 555`
