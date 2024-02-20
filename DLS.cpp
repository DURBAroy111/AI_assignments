
#include <bits/stdc++.h>

using namespace std;

// This function performs Depth-Limited Search starting from the given vertex
// and with a specified depth limit
void dls(int vertex, int depth, const vector<list<int>>& graph, vector<bool>& visited)
 {
    cout << vertex << " ";
    visited[vertex] = true;

    if (depth <= 0) // If depth limit reached, return
        return;

    // Traverse all adjacent vertices of vertex
    for (auto i = graph[vertex].begin();
     i != graph[vertex].end(); ++i)
      {
        if (!visited[*i]) {
            dls(*i, depth - 1, graph, visited);
        }
    }
}

// Depth-Limited Search function
void depthLimitedSearch(int startVertex, int depth, const vector<list<int>>& graph)
 {
    vector<bool> visited(graph.size(), false); // Initialize all vertices as not visited

    // Call the recursive helper function to perform DLS
    dls(startVertex, depth, graph, visited);
}

int main() {
    // Example graph representation using adjacency list
    int numVertices = 7;
    vector<list<int>> graph(numVertices);

    // Adding edges
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(5);
    graph[2].push_back(6);

    int startVertex = 0;
    int depthLimit = 2;

    cout << "Depth-Limited Search starting from vertex " << startVertex << " with depth limit " << depthLimit << ":\n";
    depthLimitedSearch(startVertex, depthLimit, graph);

    return 0;
}
