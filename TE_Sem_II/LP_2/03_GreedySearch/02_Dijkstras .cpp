/**
 * Problem Statement: Implement djikshtras algorithm.
 * We have implemented the greedy search using the min heap
 */

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int nv;                           // Number of vertices
    vector<pair<int, int>> *adjList;  // Adjacency list e.g. {vertex, weight}

   public:
    Graph(int nv) {
        this->nv = nv;
        adjList = new vector<pair<int, int>>[nv];
    }

    void addEdge(int src, int des, int weight) {
        adjList[src].push_back({des, weight});
        adjList[des].push_back({src, weight});  // For undirected graph
    }

    void djikshtras(int src) {
        // create a priority queue for storing the nodes as pair {distance, vertex}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // create a vector to store the distance of each vertex from the source
        // INF is used to represent that the vertex is not visited yet
        // this contains the source distance from the node
        vector<int> dist(nv, INT_MAX);
        // initilize the dist vector with INF and source with 0
        dist[src] = 0;

        pq.push({0, src});

        // now, pop the minimum distance node from the min-heap
        // and update the distance of its adjacent nodes
        while (!pq.empty()) {
            int u = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            // check for all the adjacent nodes (v) of the current node
            for (auto i : adjList[u]) {
                int v = i.first;
                int weight = i.second;

                if (dist[v] > dist[u] + weight)  // if the distance of v is less push to heap
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // print the shortest path from source to all vertices
        for (int i = 0; i < nv; i++) {
            cout << "Shortest path from " << src << " to " << i << " is " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.djikshtras(0);
    return 0;
}
