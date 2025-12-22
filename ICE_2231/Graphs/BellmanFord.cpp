#include <iostream>
#include <climits>
using namespace std;

#define V 5

void bellmanFord(int graph[V][V], int src)
{
    int dist[V];

    // Step 1: Initialize distances
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Step 2: Relax all edges V-1 times
    for (int k = 1; k <= V - 1; k++)
    {
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < V; v++)
            {
                if (graph[u][v] != 0 &&
                    dist[u] != INT_MAX &&
                    dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Step 3: Check for negative weight cycle
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                cout << "Graph contains a negative weight cycle\n";
                return;
            }
        }
    }

    // Print result
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << endl;
}

int main()
{
    int graph[V][V] = {
        {0, 4, 1, 0, 0},
        {0, 0, -2, 5, 0},
        {0, 0, 0, 8, 10},
        {0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0}};

    bellmanFord(graph, 0);
    return 0;
}
