#include <bits/stdc++.h>
using namespace std;

void graphPrinter(const vector<vector<pair<int, int>>> &graph)
{
    cout << "Graph Representation (Adjacency List):\n";
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";

        for (auto &edge : graph[i])
        {
            // edge.first edge.second

            cout << "( e=" << edge.first << ", w=" << edge.second << ") -> ";
        }
        cout << endl;
    }
}

//-------------------------------dijkstra----------------------------------
void dijkstra(int src, const vector<vector<pair<int, int>>> &graph)
{
    int vertices = graph.size();
    vector<int> dist(vertices, INT_MAX);
    set<pair<int, int>> s;
    vector<vector<int>> parent(vertices);

    dist[src] = 0;
    s.insert({0, src});

    while (!s.empty())
    {
        auto it = s.begin();
        int node = it->second;
        int distanceSoFar = it->first;
        s.erase(it);

        for (auto &edge : graph[node])
        {

            int currentEdge = edge.first;
            int distanceToEdge = edge.second;

            if (dist[currentEdge] > distanceSoFar + distanceToEdge)
            {

                auto found = s.find({dist[currentEdge], currentEdge});
                if (found != s.end())
                {
                    s.erase(found);
                }

                dist[currentEdge] = distanceSoFar + distanceToEdge;
                s.insert({dist[currentEdge], currentEdge});
                parent[currentEdge].clear();
                parent[currentEdge].push_back();
            }
        }
    }

    cout << "Shortest distances from node " << src << " is :\n";
    for (int i = 0; i < vertices; i++)
    {
        cout << "node : " << i << " distance: " << dist[i] << endl;
    }
}

//-------------------------main func--------------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int vertices = 5;
    vector<vector<pair<int, int>>> adjList(vertices);

    // populating; node,dist
    adjList[0].push_back({2, 1});
    adjList[4].push_back({2, 2});
    adjList[4].push_back({3, 4});
    adjList[3].push_back({1, 1});
    adjList[2].push_back({3, 1});
    adjList[2].push_back({4, 2});
    adjList[2].push_back({1, 3});
    adjList[1].push_back({0, 2});
    adjList[1].push_back({3, 1});

    // graphPrinter(adjList);
    dijkstra(1, adjList);

    return 0;
}