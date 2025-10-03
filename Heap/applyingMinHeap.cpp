#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
private:
    /* data */
    vector<int> heap;

    //------------insertion helper-------------------------
    void heapifyUp(int i)
    {
        while (i > 0 && heap[i] < heap[(i - 1) / 2])
        {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    //-----------------------deletion helper-------------------------

    void heapifyDown(int i)
    {
        int n = size();
        int smallest = i;
        int left = 2 * i + 1, right = 2 * i + 2;

        if (left < n && heap[left] < heap[smallest])
            smallest = left;
        if (left < n && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i)
        {
            swap(heap[smallest], heap[i]);
            heapifyDown(smallest);
        }
    }

public:
    //-------------------insertion-----------------------
    void insert(int val)
    {
        heap.push_back(val);
        this->heapifyUp(heap.size() - 1);
    }
    //--------------------deletion---------------------------

    void pop()
    {
        if (heap.empty())
            return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    int top()
    {
        if (!heap.empty())
        {
            return heap[0];
        }
        throw runtime_error("Heap is empty!");
    }
    //-----------------utilities--------------------------------

    bool isEmpty()
    {
        return this->heap.empty();
    }
    int size()
    {
        return this->heap.size();
    }
    void showTree()
    {
        showAsTree(heap);
    }

    // tree rep off for now
    void showAsTree(const vector<int> &heapNec)
    {
        int n = size();
        int levels = log2(n) + 1;

        int idx = 0;
        int level = 0;
        // x<<n == x*(2^n) 2^level

        while (idx < n)
        {
            int currentLevelEl = 1 << level;
            for (int i = 0; i < currentLevelEl; i++)
            {
                if (idx == n)
                    break;
                cout << heapNec[idx++] << " ";
            }
            cout << endl;
            level++;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MinHeap mh;
    mh.insert(20);
    mh.insert(23);
    mh.insert(50);
    mh.insert(60);
    mh.insert(10);
    mh.insert(100);
    mh.insert(40);
    mh.showTree();
    cout << "Before heapify down " << mh.top() << endl;
    mh.pop();
    cout << "after heapify down " << mh.top() << endl;

    return 0;
}