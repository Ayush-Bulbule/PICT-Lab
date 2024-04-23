#include <iostream>
#include <vector>
#include <queue>
#include <utility> // For std::pair

using namespace std;

// Define the structure for edges
struct Edge {
    int to, weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

// Compare function for priority queue
struct CompareEdge {
    bool operator()(Edge& a, Edge& b) {
        return a.weight > b.weight; // Min-Heap based on weight
    }
};

// Function to add edge
void addEdge(vector<vector<Edge>>& graph, int from, int to, int weight) {
    graph[from].push_back(Edge(to, weight));
}

// Greedy Search using Priority Queue
void greedySearch(vector<vector<Edge>>& graph, int start, int n) {
    // Vector to store minimum weights to each node
    vector<int> minWeight(n, INT_MAX);
    minWeight[start] = 0;

    // Priority queue to pick the edge with the smallest weight
    priority_queue<Edge, vector<Edge>, CompareEdge> pq;
    pq.push(Edge(start, 0));

    while (!pq.empty()) {
        Edge current = pq.top();
        pq.pop();

        int vertex = current.to;
        int weight = current.weight;

        // Iterate through all edges connected to the current vertex
        for (Edge& edge : graph[vertex]) {
            if (minWeight[edge.to] > weight + edge.weight) {
                minWeight[edge.to] = weight + edge.weight;
                pq.push(Edge(edge.to, minWeight[edge.to]));
            }
        }
    }

    // Print minimum weights to each vertex from start
    for (int i = 0; i < n; ++i) {
        cout << "Shortest path to vertex " << i << " is " << minWeight[i] << endl;
    }
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<Edge>> graph(n);

    // Adding edges
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 3, 4, 2);

    // Start Greedy Search from vertex 0
    greedySearch(graph, 0, n);

    return 0;
}
