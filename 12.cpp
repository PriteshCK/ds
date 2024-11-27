// 12 Write a C++ program to store a given graph in adjacency list and perform Depth-First-Search

#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

// Class to represent a graph using an adjacency list
class Graph {
    int V;  // Number of vertices
    vector<list<int>> adj;  // Adjacency list

public:
    // Constructor to initialize graph with V vertices
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);  // Add v to u's list
        adj[v].push_back(u);  // Since it's an undirected graph, add u to v's list
    }

    // Recursive DFS function
    void dfsRecursive(int v, vector<bool>& visited) {
        visited[v] = true;  // Mark the current node as visited
        cout << v << " ";  // Print the current node

        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited);
            }
        }
    }

    // Iterative DFS function using a stack
    void dfsIterative(int start) {
        vector<bool> visited(V, false);  // Mark all vertices as not visited
        stack<int> s;

        s.push(start);  // Push the start node onto the stack
        visited[start] = true;

        while (!s.empty()) {
            int node = s.top();
            s.pop();
            cout << node << " ";  // Print the current node

            // Push all unvisited neighbors of the current node onto the stack
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }
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

    // Input edges
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    // Perform DFS (Recursive)
    cout << "\nDFS Traversal (Recursive): ";
    vector<bool> visited(V, false);  // Create a visited array
    g.dfsRecursive(0, visited);  // Starting DFS from vertex 0
    cout << endl;

    // Perform DFS (Iterative)
    cout << "\nDFS Traversal (Iterative): ";
    g.dfsIterative(0);  // Starting DFS from vertex 0
    cout << endl;

    return 0;
}
