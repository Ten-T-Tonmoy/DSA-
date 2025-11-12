#include <bits/stdc++.h>
// queue, vector ,
using namespace std;

void graphPrinter(const vector<vector<pair<int, int>>> &graph)
{
    cout << "Graph Representation (Adjacency List):\n";
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (auto &edge : graph[i])
        {
            cout << "(" << edge.first << ", w=" << edge.second << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

//-------------------------Dijkstra-------------------------------------

//  current  node -> u
// neighbour node-> v

void dijkstra(int start, const vector<vector<pair<int, int>>> &graph)
{

    int n = graph.size();
    vector<int> distances(n, INT_MAX);
    distances[start] = 0;

    // heap part
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>> // for minHeap
        >
        pq;

    pq.push({0, start});

    // the main loop shi

    while (!pq.empty())
    {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDistance > distances[currentNode])
        {
            continue;
        }

        for (auto &edge : graph[currentNode])
        {
            int neighborTag = edge.first;
            int edgeWeight = edge.second;

            int newDistance = distances[currentNode] + edgeWeight;

            if (newDistance < distances[neighborTag])
            {
                distances[neighborTag] = newDistance;
                pq.push({newDistance, neighborTag});
            }
        }
    }

    cout << "Shortest distances from source vertex " << start << ":\n";
    for (int vertex = 0; vertex < n; vertex++)
    {
        cout << "To " << vertex << " -> ";
        if (distances[vertex] == INT_MAX)
            cout << "INF";
        else
            cout << distances[vertex];
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*
        Graph Representation (Adjacency List):
        0 -> (1, w=4) (2, w=2)
        1 -> (2, w=5) (3, w=10)
        2 -> (4, w=3)
        3 -> (5, w=11)
        4 -> (3, w=4)
5 ->
    */

    int numOfVertices = 6;
    vector<vector<pair<int, int>>> adjacencyList(numOfVertices);

    // populating
    adjacencyList[0].push_back({1, 4});
    adjacencyList[0].push_back({2, 2});
    adjacencyList[1].push_back({2, 5});
    adjacencyList[1].push_back({3, 10});
    adjacencyList[2].push_back({4, 3});
    adjacencyList[4].push_back({3, 4});
    adjacencyList[3].push_back({5, 11});

    graphPrinter(adjacencyList);
    dijkstra(1, adjacencyList);

    return 0;
}