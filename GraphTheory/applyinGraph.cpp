#include <bits/stdc++.h>
using namespace std;

//----------using adjacency matrix--------------

class Graph
{
private:
    int numOfVertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int VerticesNum)
    {
        this->numOfVertices = VerticesNum;
        // making necessary matrix
        adjMatrix.resize(numOfVertices, vector<int>(numOfVertices, 0));
    }

    void AddEdge(int source, int destination, int weight = 1)
    {
        adjMatrix[source][destination] = weight;
    }
    void GraphPrinter()
    {
        cout << "The graph given below";
        for (int i = 0; i < numOfVertices; i++)
        {
            for (int j = 0; j < numOfVertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << "Compilation ok!";
    Graph testGraph(4);
    testGraph.AddEdge(1, 2, 3);
    testGraph.AddEdge(2, 1, 6);
    testGraph.AddEdge(3, 2, 6);
    testGraph.AddEdge(3, 4, 4);
    testGraph.AddEdge(3, 1, 6);
    testGraph.AddEdge(4, 1, 9);
    testGraph.AddEdge(2, 4, 6);
    testGraph.GraphPrinter();
    return 0;
}