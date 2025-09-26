#include <bits/stdc++.h>
using namespace std;
/**
 * any order any node at first
 * .. step 1 start for any nore
 *  step 2 explore all of its node in any order
 *  step 3 in any order explore all its child
 *          beaware of interconnection dotted edges
 *  then form a tree and do the level order
 *
 * cross edges
 * bfs spanning tree is made
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

    //------------------DFS-------------------------------------

    void DFS_helper(int currentVertex, vector<bool> &isVisited)
    {
        isVisited[currentVertex] = true;
        cout << currentVertex << " ";

        for (const auto &edge : adjacencyList[currentVertex])
        {
            // 0 zerocheck beaware
            if (isVisited[edge.first] == 0 && edge.first != 0)
            {
                DFS_helper(edge.first, isVisited);
            }
        }
    }

    void DFS(int startIndex)
    {
        // will take starting vertex
        // shis same as preOrder of bin tree
        //!!!!!!!!!!!!!recursive fn auto uses stack!!!!!!!!!!!!!!!!!!!!!!1
        vector<bool> isVisited(V, false);
        cout << "DFS sequence : ";
        DFS_helper(startIndex, isVisited);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph testGraph(11);
    testGraph.AddEdge(2, 4, 6);
    testGraph.AddEdge(4, 5, 1);
    testGraph.AddEdge(0, 5, 2);
    testGraph.AddEdge(5, 6, 1);
    testGraph.AddEdge(6, 7, 7);
    testGraph.AddEdge(7, 8, 3);
    testGraph.AddEdge(8, 9, 5);
    testGraph.AddEdge(9, 10, 4);
    testGraph.AddEdge(1, 2, 3);
    testGraph.AddEdge(2, 1, 6);
    testGraph.AddEdge(3, 2, 6);
    testGraph.AddEdge(3, 4, 4);
    testGraph.AddEdge(3, 1, 6);
    testGraph.AddEdge(4, 1, 9);

    testGraph.DFS(1);
    return 0;
}