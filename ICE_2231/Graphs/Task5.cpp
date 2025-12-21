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

int findMin(int dist[], bool done[], int n)
{
    int small = 999999;
    int pos = -1;

    for (int i = 0; i < n; i++)
    {
        if (!done[i] && dist[i] < small)
        {
            small = dist[i];
            pos = i;
        }
    }

    return pos;
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

void findShortestPath(int graph[][10], int n, int start, int end, char names[])
{
    int dist[10];
    bool done[10];
    int prev[10];

    for (int i = 0; i < n; i++)
    {
        dist[i] = 999999;
        done[i] = false;
        prev[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int curr = findMin(dist, done, n);

        if (curr == -1)
            break;

        done[curr] = true;

        for (int j = 0; j < n; j++)
        {
            if (!done[j] && graph[curr][j] != 0 &&
                dist[curr] + graph[curr][j] < dist[j])
            {
                dist[j] = dist[curr] + graph[curr][j];
                prev[j] = curr;
            }
        }
    }

    cout << "\n shortest path from " << names[start] << " to " << names[end] << " is: ";
    printPath(prev, end, names);
    cout << "\n total distance: " << dist[end] << "\n";
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

    cout << "weight matrix:\n";
    printGraph(graph, n, names);

    int start = 0;
    int end = 3;

    findShortestPath(graph, n, start, end, names);

    return 0;
}