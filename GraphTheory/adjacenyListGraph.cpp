#include <bits/stdc++.h>
using namespace std;

/**
 * pairs iter
 * either   //using ref dont make copies so fast af
 *  size_t &edge :adjList[i]
 *      edge.first, edge.second
 *
 * or
 *  adjList[i][j].first/seconnd manual iteration
 *
 */

class Graph
{
private:
    int V;
    vector<vector<pair<int, int>>> adjacencyList;

public:
    Graph(int vertices)
    {
        this->V = vertices;
        adjacencyList.resize(V);
    }

    void AddEdge(int source, int destination, int weight = 1)
    {
        adjacencyList[source].push_back({destination, weight});
    }

    void GraphPrinter()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << " -> ";
            for (auto &vertex : adjacencyList[i])
            {
                cout << vertex.first << "(" << vertex.second << ") ";
            }
            cout << endl;
        }
    }

    //--------------------adding vertex---------------------------
    void AddVertex()
    {
        //<>() gives default shit
        adjacencyList.push_back(vector<pair<int, int>>());
        V++;
    }

    //-----------------removeEdge------------------------------------
    void RemoveEdge(int source, int destination)
    {
        if (source > V || destination > V)
            return;

        auto &neighbours = adjacencyList[source];
        // kinda array conversion usin ref for mutation
        for (size_t i = 0; i < neighbours.size(); i++)
        {
            if (neighbours[i].first == destination)
            {

                neighbours.erase(neighbours.begin() + i);
                break;
            }
        }
    }

    //----------------------------are adjacent---------------------------------
    bool areAdjacent(int src, int dest)
    {
        if (src > V)
            return false;

        for (const auto &edge : adjacencyList[src])
        {
            if (edge.first == dest)
                return true;
        }
        return false;
    }

    //--------------------------getAdjacents------------------------------------
    void GetAdjacentVertices(int vertex)
    {
        vector<int> neighbors;
        if (vertex >= V)
            return;

        for (const auto &edge : adjacencyList[vertex])
        {
            neighbors.push_back({edge.first});
        }
        // return neighbors;
        cout << "Adjacent vertices of vertex :" << vertex << " are => ";
        for (auto &el : neighbors)
            cout << el << " -> ";
        cout << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph testGraph(5);
    testGraph.AddEdge(1, 2, 3);
    testGraph.AddEdge(2, 1, 6);
    testGraph.AddEdge(3, 2, 6);
    testGraph.AddEdge(3, 4, 4);
    testGraph.AddEdge(3, 1, 6);
    testGraph.AddEdge(4, 1, 9);
    testGraph.AddEdge(2, 4, 6);
    testGraph.AddVertex();
    // testGraph.RemoveEdge(3, 2);
    testGraph.GraphPrinter();
    testGraph.GetAdjacentVertices(3);

    // cout << "2 points towards 4 :" << testGraph.areAdjacent(2, 4);
    return 0;
}