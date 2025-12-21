#include <bits/stdc++.h>
using namespace std;

void printGraph(int graph[][10], int n, char names[])
{
    cout << "    ";
    for (int i = 0; i < n; i++)
    {
        cout << names[i] << "   ";
    }
    cout << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << names[i] << " [ ";
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << "   ";
        }
        cout << "]\n";
    }
}

void printPath(int prev[], int end, char names[])
{
    if (prev[end] == -1)
    {
        cout << names[end];
        return;
    }
    printPath(prev, prev[end], names);
    cout << " -> " << names[end];
}

void shortestPath(int graph[][10], int n, int start, int end, char names[])
{
    int dist[10];
    bool visited[10];
    int prev[10];

    for (int i = 0; i < n; i++)
    {
        dist[i] = 999999;
        visited[i] = false;
        prev[i] = -1;
    }

    dist[start] = 0;

    for (int count = 0; count < n; count++)
    {
        int minDist = 999999;
        int curr = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                curr = i;
            }
        }

        if (curr == -1)
            break;

        visited[curr] = true;

        for (int next = 0; next < n; next++)
        {
            if (!visited[next] && graph[curr][next] != 0)
            {
                int newDist = dist[curr] + graph[curr][next];
                if (newDist < dist[next])
                {
                    dist[next] = newDist;
                    prev[next] = curr;
                }
            }
        }
    }

    cout << "\n  Shortest path from " << names[start] << " to " << names[end] << " is: ";
    printPath(prev, end, names);
    cout << "\n  Total distance: " << dist[end] << "\n";
}

int main()
{
    int n = 5;
    char names[] = {'A', 'B', 'C', 'D', 'E'};

    int graph[10][10] = {
        {0, 4, 0, 0, 0},
        {0, 0, 3, 3, 0},
        {2, 0, 0, 0, 2},
        {0, 0, 0, 0, 0},
        {0, 5, 0, 2, 0}};

    cout << "Weight Matrix:\n";
    printGraph(graph, n, names);

    int start = 0;
    int end = 3;

    shortestPath(graph, n, start, end, names);

    return 0;
}