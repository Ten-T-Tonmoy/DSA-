#include <iostream>
using namespace std;

#define V 5

int minKey(int key[], bool mstSet[])
{
    int min = 1e9, min_index;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    return min_index;
}

void primMST(int graph[V][V])
{
    int parent[V];  // store MST
    int key[V];     // min edge weight to connect to MST
    bool mstSet[V]; // true if vertex included in MST

    // Initialize keys and mstSet
    for (int i = 0; i < V; i++)
    {
        key[i] = 1e9;
        mstSet[i] = false;
    }

    key[0] = 0; // start from vertex 0
    parent[0] = -1;

    // MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet); // pick min key vertex
        mstSet[u] = true;

        // update key value and parent index of adjacent vertices
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    // print MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
}

int main()
{
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    primMST(graph);
    return 0;
}
