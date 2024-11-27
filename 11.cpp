// 11 Write a C++ program to store a given graph in adjacency matrix and perform Breadth-First- Search
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
    int V;  // Number of vertices
    vector<vector<int>> adjMatrix;  // Adjacency matrix

public:
    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0));  // Resize matrix to VxV with 0s
    }

    // Function to add an edge in the graph
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;  // Add edge from u to v
        adjMatrix[v][u] = 1;  // Since it's an undirected graph, also add edge from v to u
    }

    // BFS Traversal using a queue
    void bfs(int start) {
        vector<bool> visited(V, false);  // Track visited nodes
        queue<int> q;  // Queue for BFS

        visited[start] = true;  // Mark the start node as visited
        q.push(start);  // Enqueue the start node

        cout << "BFS Traversal starting from node " << start << ": ";

        while (!q.empty()) {
            int node = q.front();  // Get the front node from the queue
            q.pop();  // Dequeue the front node
            cout << node << " ";  // Print the visited node

            // Visit all adjacent unvisited nodes
            for (int i = 0; i < V; i++) {
                if (adjMatrix[node][i] == 1 && !visited[i]) {  // If there's an edge and the node is not visited
                    visited[i] = true;  // Mark it visited
                    q.push(i);  // Enqueue the node
                }
            }
        }

        cout << endl;
    }
};

int main() {
    int V, E, u, v;

    // Input number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);

    // Input the edges
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        g.addEdge(u, v);  // Add the edge to the graph
    }

    // Perform BFS
    int start;
    cout << "Enter the starting node for BFS: ";
    cin >> start;
    g.bfs(start);  // Perform BFS starting from the given node

    return 0;
}

