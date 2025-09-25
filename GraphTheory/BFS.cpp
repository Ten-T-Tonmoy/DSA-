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

    //------------------BFS-------------------------------------

    void BFS(int i)
    {
        // will take starting vertex
        vector<int> visited(numOfVertices, 0);
        queue<int> q;

        while(){
            u
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}