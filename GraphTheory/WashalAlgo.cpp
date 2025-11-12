#include <bits/stdc++.h>
using namespace std;

void warshallAlgorithm(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> path = graph;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
            }
        }
    }

    cout << "Path Matrix (Transitive Closure):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 4;
    vector<vector<int>> graph = {
        {0, 0, 0, 1},
        {1, 0, 1, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 0}};

    warshallAlgorithm(graph);
    return 0;
}