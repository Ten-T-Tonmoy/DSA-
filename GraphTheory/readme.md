# Graph Theory and Implementation in C++

## Table of Contents

- [Introduction to Graphs](#introduction-to-graphs)
- [Graph Representation](#graph-representation)
  - [Adjacency Matrix](#adjacency-matrix)
  - [Adjacency List](#adjacency-list)
  - [Edge List](#edge-list)
- [Graph Types](#graph-types)
  - [Directed vs Undirected](#directed-vs-undirected)
  - [Weighted vs Unweighted](#weighted-vs-unweighted)
  - [Special Graph Types](#special-graph-types)
- [Basic Graph Operations](#basic-graph-operations)
- [Graph Traversal Algorithms](#graph-traversal-algorithms)
  - [Depth-First Search (DFS)](#depth-first-search-dfs)
  - [Breadth-First Search (BFS)](#breadth-first-search-bfs)
- [Path Finding Algorithms](#path-finding-algorithms)
  - [Dijkstra's Algorithm](#dijkstras-algorithm)
  - [Bellman-Ford Algorithm](#bellman-ford-algorithm)
  - [Floyd-Warshall Algorithm](#floyd-warshall-algorithm)
  - [A\* Search Algorithm](#a-search-algorithm)
- [Minimum Spanning Tree](#minimum-spanning-tree)
  - [Kruskal's Algorithm](#kruskals-algorithm)
  - [Prim's Algorithm](#prims-algorithm)
- [Network Flow](#network-flow)
  - [Ford-Fulkerson Algorithm](#ford-fulkerson-algorithm)
  - [Edmonds-Karp Algorithm](#edmonds-karp-algorithm)
- [Graph Connectivity](#graph-connectivity)
  - [Connected Components](#connected-components)
  - [Strongly Connected Components](#strongly-connected-components)
  - [Biconnected Components](#biconnected-components)
- [Topological Sorting](#topological-sorting)
- [Cycle Detection](#cycle-detection)
- [Common Graph Problems](#common-graph-problems)
- [Advanced Topics](#advanced-topics)
- [C++ Implementation](#c-implementation)
- [Resources](#resources)

## Introduction to Graphs

A graph is a non-linear data structure consisting of nodes (vertices) and edges that connect these nodes. Graphs are used to represent relationships between various entities.

Formally, a graph G is defined as an ordered pair G = (V, E) where:

- V is a set of vertices
- E is a set of edges connecting these vertices

### Basic Terminology

- **Vertex (Node)**: A fundamental unit in a graph
- **Edge**: Connects two vertices
- **Adjacent Vertices**: Vertices connected by an edge
- **Path**: Sequence of vertices where each adjacent pair is connected by an edge
- **Cycle**: Path that starts and ends at the same vertex
- **Degree**: Number of edges connected to a vertex
  - In-degree: Number of incoming edges
  - Out-degree: Number of outgoing edges

## Graph Representation

### Adjacency Matrix

An adjacency matrix is a 2D array of size V×V where V is the number of vertices. If there is an edge between vertex i and vertex j, the value at matrix[i][j] is 1 (or the weight of the edge for weighted graphs), otherwise 0.

#### C++ Implementation

```cpp
class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int src, int dest, int weight = 1) {
        adjMatrix[src][dest] = weight;
        // For undirected graph: adjMatrix[dest][src] = weight;
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};
```

#### Pros and Cons

**Pros:**

- Simple implementation
- Edge lookup is O(1)
- Easy to implement for weighted graphs

**Cons:**

- Space complexity is O(V²), inefficient for sparse graphs
- Adding/removing vertices requires recreating the matrix

### Adjacency List

An adjacency list uses an array of lists, where each element in the array represents a vertex and the corresponding list contains all adjacent vertices.

#### C++ Implementation

```cpp
class Graph {
private:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adjList; // Vertex, Weight pairs

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int src, int dest, int weight = 1) {
        adjList[src].push_back({dest, weight});
        // For undirected graph: adjList[dest].push_back({src, weight});
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> ";
            for (auto& edge : adjList[i]) {
                cout << edge.first << "(" << edge.second << ") ";
            }
            cout << endl;
        }
    }
};
```

#### Pros and Cons

**Pros:**

- Space-efficient for sparse graphs, O(V+E)
- Adding a vertex is easy

**Cons:**

- Edge lookup is O(E) in worst case
- Slightly more complex implementation

### Edge List

An edge list is a simple representation that stores all edges in a list.

#### C++ Implementation

```cpp
struct Edge {
    int src, dest, weight;

    Edge(int s, int d, int w = 1) : src(s), dest(d), weight(w) {}

    // For sorting edges
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
private:
    int V; // Number of vertices
    vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest, int weight = 1) {
        edges.push_back(Edge(src, dest, weight));
    }

    void printGraph() {
        for (const auto& edge : edges) {
            cout << edge.src << " -> " << edge.dest
                 << " (" << edge.weight << ")" << endl;
        }
    }
};
```

#### Pros and Cons

**Pros:**

- Simple and ideal for algorithms like Kruskal's
- Space-efficient for sparse graphs

**Cons:**

- Edge lookup is O(E)
- Finding all edges connected to a specific vertex is inefficient

## Graph Types

### Directed vs Undirected

- **Directed Graph (Digraph)**: Edges have a direction
- **Undirected Graph**: Edges have no direction (bidirectional)

### Weighted vs Unweighted

- **Weighted Graph**: Edges have weights or costs
- **Unweighted Graph**: Edges have no weights (or all weights are equal)

### Special Graph Types

- **Complete Graph**: Every vertex is connected to every other vertex
- **Bipartite Graph**: Vertices can be divided into two disjoint sets such that no vertices within the same set are adjacent
- **Tree**: Connected acyclic undirected graph
- **DAG (Directed Acyclic Graph)**: Directed graph with no cycles
- **Planar Graph**: Can be drawn on a plane without edges crossing
- **Sparse Graph**: |E| is much less than |V|²
- **Dense Graph**: |E| is close to |V|²

## Basic Graph Operations

- Adding vertices
- Adding edges
- Removing vertices
- Removing edges
- Finding adjacent vertices
- Checking if two vertices are adjacent

### C++ Implementation

```cpp
class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addVertex() {
        adjList.push_back(vector<pair<int, int>>());
        V++;
    }

    void addEdge(int src, int dest, int weight = 1) {
        if (src >= V || dest >= V) return;
        adjList[src].push_back({dest, weight});
    }

    void removeEdge(int src, int dest) {
        if (src >= V) return;
        auto& neighbors = adjList[src];
        neighbors.erase(
            remove_if(neighbors.begin(), neighbors.end(),
                [dest](const pair<int, int>& p) { return p.first == dest; }),
            neighbors.end()
        );
    }

    bool areAdjacent(int src, int dest) {
        if (src >= V) return false;
        for (const auto& edge : adjList[src]) {
            if (edge.first == dest) return true;
        }
        return false;
    }

    vector<int> getAdjacentVertices(int vertex) {
        vector<int> neighbors;
        if (vertex >= V) return neighbors;

        for (const auto& edge : adjList[vertex]) {
            neighbors.push_back(edge.first);
        }
        return neighbors;
    }
};
```

## Graph Traversal Algorithms

### Depth-First Search (DFS)

DFS explores as far as possible along each branch before backtracking. It uses a stack (implicit via recursion or explicit) to keep track of nodes to visit.

#### C++ Implementation

```cpp
class Graph {
    // ... previous code ...

    void DFS(int startVertex) {
        vector<bool> visited(V, false);
        DFSUtil(startVertex, visited);
    }

private:
    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (const auto& edge : adjList[vertex]) {
            int neighbor = edge.first;
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
};
```

#### Time and Space Complexity

- Time Complexity: O(V+E)
- Space Complexity: O(V)

### Breadth-First Search (BFS)

BFS explores all vertices at the present depth before moving to vertices at the next depth level. It uses a queue to keep track of nodes to visit.

#### C++ Implementation

```cpp
class Graph {
    // ... previous code ...

    void BFS(int startVertex) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (const auto& edge : adjList[vertex]) {
                int neighbor = edge.first;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};
```

#### Time and Space Complexity

- Time Complexity: O(V+E)
- Space Complexity: O(V)

#### Applications of Graph Traversal

- Finding connected components
- Pathfinding
- Cycle detection
- Topological sorting
- Solving puzzles and mazes

## Path Finding Algorithms

### Dijkstra's Algorithm

Dijkstra's algorithm finds the shortest path from a source vertex to all other vertices in a weighted graph with non-negative edge weights.

#### C++ Implementation

```cpp
class Graph {
    // ... previous code ...

    vector<int> dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};
```

#### Time and Space Complexity

- Time Complexity: O((V+E)log V)
- Space Complexity: O(V)

### Bellman-Ford Algorithm

Bellman-Ford algorithm finds the shortest paths from a source vertex to all other vertices, and it works with negative edge weights. It can also detect negative cycles.

#### C++ Implementation

```cpp
class Graph {
    // ... previous code ...

    pair<vector<int>, bool> bellmanFord(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        bool hasNegativeCycle = false;

        // Relax all edges V-1 times
        for (int i = 1; i < V; i++) {
            for (int u = 0; u < V; u++) {
                for (const auto& edge : adjList[u]) {
                    int v = edge.first;
                    int weight = edge.second;

                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        // Check for negative cycles
        for (int u = 0; u < V; u++) {
            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    hasNegativeCycle = true;
                    break;
                }
            }
        }

        return {dist, hasNegativeCycle};
    }
};
```

#### Time and Space Complexity

- Time Complexity: O(V\*E)
- Space Complexity: O(V)

### Floyd-Warshall Algorithm

Floyd-Warshall algorithm finds the shortest paths between all pairs of vertices in a weighted graph. It works with negative edge weights but not with negative cycles.

#### C++ Implementation

```cpp
class Graph {
    // ... previous code ...

    vector<vector<int>> floydWarshall() {
        vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

        // Initialize distances
        for (int i = 0; i < V; i++) {
            dist[i][i] = 0;
            for (const auto& edge : adjList[i]) {
                dist[i][edge.first] = edge.second;
            }
        }

        // Update distances
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        return dist;
    }
};
```

#### Time and Space Complexity

- Time Complexity: O(V³)
- Space Complexity: O(V²)

### A\* Search Algorithm

A\* is an informed search algorithm that finds the shortest path between nodes, using a heuristic to guide the search.

#### C++ Implementation

```cpp
struct Node {
    int vertex;
    int cost;
    int heuristic;

    Node(int v, int c, int h) : vertex(v), cost(c), heuristic(h) {}

    bool operator>(const Node& other) const {
        return (cost + heuristic) > (other.cost + other.heuristic);
    }
};

class Graph {
    // ... previous code ...

    vector<int> aStar(int start, int goal, function<int(int, int)> heuristic) {
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);
        dist[start] = 0;

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push(Node(start, 0, heuristic(start, goal)));

        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();

            if (current.vertex == goal) break;

            if (current.cost > dist[current.vertex]) continue;

            for (const auto& edge : adjList[current.vertex]) {
                int neighbor = edge.first;
                int weight = edge.second;

                int newCost = dist[current.vertex] + weight;
                if (newCost < dist[neighbor]) {
                    dist[neighbor] = newCost;
                    parent[neighbor] = current.vertex;
                    pq.push(Node(neighbor, newCost, heuristic(neighbor, goal)));
                }
            }
        }

        // Reconstruct path
        vector<int> path;
        for (int at = goal; at != -1; at = parent[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        return path;
    }
};
```

## Minimum Spanning Tree

A minimum spanning tree (MST) is a subset of the edges that connects all vertices with the minimum total edge weight.

### Kruskal's Algorithm

Kruskal's algorithm finds an MST by sorting all edges by weight and adding them to the tree if they don't create a cycle.

#### C++ Implementation

```cpp
class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
        }
    }
};

class Graph {
    // ... previous code ...

    vector<Edge> kruskalMST() {
        vector<Edge> mst;
        vector<Edge> allEdges;

        // Collect all edges
        for (int u = 0; u < V; u++) {
            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                allEdges.push_back(Edge(u, v, weight));
            }
        }

        // Sort edges by weight
        sort(allEdges.begin(), allEdges.end());

        UnionFind uf(V);

        for (const auto& edge : allEdges) {
            if (uf.find(edge.src) != uf.find(edge.dest)) {
                mst.push_back(edge);
                uf.unite(edge.src, edge.dest);
            }
        }

        return mst;
    }
};
```

#### Time and Space Complexity

- Time Complexity: O(E log E)
- Space Complexity: O(V + E)

### Prim's Algorithm

Prim's algorithm builds an MST by starting from a vertex and always adding the lowest-weight edge that connects a vertex in the tree to a vertex outside the tree.

#### C++ Implementation

```cpp
class Graph {
    // ... previous code ...

    vector<Edge> primMST() {
        vector<Edge> mst;
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);

        // Start with vertex 0
        key[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // {key, vertex}

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            if (parent[u] != -1) {
                mst.push_back(Edge(parent[u], u, key[u]));
            }

            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (!inMST[v] && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }

        return mst;
    }
};
```

#### Time and Space Complexity

- Time Complexity: O(E log V)
- Space Complexity: O(V)

## Network Flow

### Ford-Fulkerson Algorithm

Ford-Fulkerson algorithm computes the maximum flow in a flow network. It works by finding augmenting paths in the residual graph and augmenting the flow along these paths.

#### C++ Implementation

```cpp
class Graph {
    // ... previous code ...

    int fordFulkerson(int source, int sink) {
        vector<vector<int>> residualGraph(V, vector<int>(V, 0));

        // Initialize residual graph
        for (int u = 0; u < V; u++) {
            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int capacity = edge.second;
                residualGraph[u][v] = capacity;
            }
        }

        vector<int> parent(V, -1);
        int maxFlow = 0;

        // Augment flow while there is a path from source to sink
        while (bfs(residualGraph, source, sink, parent)) {
            int pathFlow = INT_MAX;

            // Find minimum residual capacity in the augmenting path
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                pathFlow = min(pathFlow, residualGraph[u][v]);
            }

            // Update residual capacities
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                residualGraph[u][v] -= pathFlow;
                residualGraph[v][u] += pathFlow;
            }

            maxFlow += pathFlow;
        }

        return maxFlow;
    }

private:
    bool bfs(const vector<vector<int>>& residualGraph, int source, int sink, vector<int>& parent) {
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;
        parent[source] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < V; v++) {
                if (!visited[v] && residualGraph[u][v] > 0) {
                    parent[v] = u;
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return visited[sink];
    }
};
```

#### Time and Space Complexity

- Time Complexity: O(E × max_flow)
- Space Complexity: O(V²)

### Edmonds-Karp Algorithm

Edmonds-Karp algorithm is an implementation of the Ford-Fulkerson method that uses BFS to find augmenting paths.

#### C++ Implementation

```cpp
class Graph {
    // ... previous code ...

    int edmondsKarp(int source, int sink) {
        // Same implementation as fordFulkerson, but BFS is already used
        return fordFulkerson(source, sink);
    }
};
```

#### Time and Space Complexity

- Time Complexity: O(V × E²)
- Space Complexity: O(V²)

## Graph Connectivity

### Connected Components

A connected component is a subgraph in which there is a path between every pair of vertices.

#### C++ Implementation

```cpp
class Graph {
    // ... previous code ...

    vector<vector<int>> findConnectedComponents() {
        vector<bool> visited(V, false);
        vector<vector<int>> components;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfsForComponents(i, visited, component);
                components.push_back(component);
            }
        }

        return components;
    }

private:
    void dfsForComponents(int vertex, vector<bool>& visited, vector<int>& component) {
        visited[vertex] = true;
        component.push_back(vertex);

        for (const auto& edge : adjList[vertex]) {
            int neighbor = edge.first;
            if (!visited[neighbor]) {
                dfsForComponents(neighbor, visited, component);
            }
        }
    }
};
```

### Strongly Connected Components

A strongly connected component (SCC) is a subgraph in which there is a directed path between every pair of vertices.

#### Kosaraju's Algorithm

Kosaraju's algorithm finds all SCCs in a directed graph.

```cpp
class Graph {
    // ... previous code ...

    vector<vector<int>> findStronglyConnectedComponents() {
        vector<bool> visited(V, false);
        vector<int> finishOrder;

        // Step 1: DFS to fill stack
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                fillOrder(i, visited, finishOrder);
            }
        }

        // Step 2: Create transpose graph
        Graph transposed(V);
        for (int i = 0; i < V; i++) {
            for (const auto& edge : adjList[i]) {
                transposed.addEdge(edge.first, i, edge.second);
            }
        }

        // Step 3: DFS on transpose graph
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> sccs;

        for (int i = finishOrder.size() - 1; i >= 0; i--) {
            int vertex = finishOrder[i];
            if (!visited[vertex]) {
                vector<int> scc;
                transposed.dfsForComponents(vertex, visited, scc);
                sccs.push_back(scc);
            }
        }

        return sccs;
    }

private:
    void fillOrder(int vertex, vector<bool>& visited, vector<int>& order) {
        visited[vertex] = true;

        for (const auto& edge : adjList[vertex]) {
            int neighbor = edge.first;
            if (!visited[neighbor]) {
                fillOrder(neighbor, visited, order);
            }
        }

        order.push_back(vertex);
    }
};
```

### Biconnected Components

A biconnected component is a connected subgraph with no articulation points (vertices whose removal would disconnect the graph).

## Topological Sorting

Topological sorting is a linear ordering of vertices in a DAG such that for every directed edge (u, v), vertex u comes before v in the ordering.

#### C++ Implementation

```cpp
class Graph {
    // ... previous code ...

    vector<int> topologicalSort() {
        vector<bool> visited(V, false);
        vector<int> order;

        function<void(int)> dfs = [&](int vertex) {
            visited[vertex] = true;

            for (const auto& edge : adjList[vertex]) {
                int neighbor = edge.first;
                if (!visited[neighbor]) {
                    dfs(neighbor);
                }
            }

            order.push_back(vertex);
        };

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};
```

## Cycle Detection

### Cycle Detection in Undirected Graphs

```cpp
class Graph {
    // ... previous code ...

    bool hasCycle() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (hasCycleUtil(i, visited, -1)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool hasCycleUtil(int vertex, vector<bool>& visited, int parent) {
        visited[vertex] = true;

        for (const auto& edge : adjList[vertex]) {
            int neighbor = edge.first;

            if (!visited[neighbor]) {
                if (hasCycleUtil(neighbor, visited, vertex)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true;
            }
        }

        return false;
    }
};
```

### Cycle Detection in Directed Graphs

```cpp
class Graph {
    // ... previous code ...

    bool hasCycleDirected() {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++) {
            if (hasCycleDirectedUtil(i, visited, recStack)) {
                return true;
            }
        }

        return false;
    }

private:
    bool hasCycleDirectedUtil(int vertex, vector<bool>& visited, vector<bool>& recStack) {
        if (!visited[vertex]) {
            visited[vertex] = true;
            recStack[vertex] = true;

            for (const auto& edge : adjList[vertex]) {
                int neighbor = edge.first;

                if (!visited[neighbor] && hasCycleDirectedUtil(neighbor, visited, recStack)) {
                    return true;
                } else if (recStack[neighbor]) {
                    return true;
                }
            }
        }

        recStack[vertex] = false;
        return false;
    }
};
```

## Common Graph Problems

- **Traveling Salesman Problem**: Find the shortest possible route that visits every city exactly once and returns to the starting city
- **Graph Coloring**: Assign colors to vertices such that no adjacent vertices have the same color
- **Hamiltonian Path/Cycle**: Find a path/cycle that visits every vertex exactly once
- **Eulerian Path/Circuit**: Find a path/circuit that visits every edge exactly once
- **Maximum Independent Set**: Find the largest set of vertices such that no two vertices are adjacent
- **Minimum Vertex Cover**: Find the smallest set of vertices such that each edge has at least one endpoint in the set
- **Maximum Clique**: Find the largest complete subgraph
- **Graph Isomorphism**: Determine if two graphs are isomorphic

## Advanced Topics

- **Spectral Graph Theory**: Study of the eigenvalues and eigenvectors of matrices associate
