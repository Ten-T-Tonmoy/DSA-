#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{

    // 2 5 6 7 8 4 4 7
    vector<int> heap;
    void heapifyUp(int i)
    {
        while (i > 0 && heap[(i - 1) / 2] < heap[i])
        {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
            //
        }
    }

    void heapifyDown(int i)
    {
        int n = size();
        int largest = i; // will get idx 0
        int left = 2 * i + 1, right = 2 * i + 2;

        if (left < n && heap[left] > heap[right])
            largest = left;
        if (right < n && heap[right] > heap[left])
            largest = right;

        if (largest != i)
        {

            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
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
            return heap[0];
        throw runtime_error("Heap is empty!");
    }

    bool isEmpty()
    {
        return this->heap.empty();
    }
    int size()
    {
        return this->heap.size();
    }

    void dumpedshowAsTree()
    {
        // bruh missed whole calc
        int tracker = 1;
        int nextBreak = 1;
        for (int i = 0; i < heap.size(); i++)
        {
            cout << " " << heap[i] << " ";

            if (i + 1 == tracker)
            {
                cout << endl;
                tracker = tracker * 2;
            }
        }
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

    /**
     * 0
     * 1
     *
     */
    MaxHeap mh;
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