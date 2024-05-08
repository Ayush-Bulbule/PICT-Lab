/**
 * Problem Statement: mplement Greedy Search algorithm on some application for
 * 1. Minimum Spanning Tree OR
 * 2. Single—Source Shortest Path Problem
 *
 * Selected: Minimum spanning tree using prims algorithm
 */
#include <bits/stdc++.h>

using namespace std;

class Graph {
    int nv;
    vector<pair<int, int>> *adjList;

   public:
    Graph(int nv) {
        this->nv = nv;
        adjList = new vector<pair<int, int>>[nv];
    }

    // add the eedge
    void addEdge(int src, int des, int weight) {
        adjList[src].push_back({des, weight});
        adjList[des].push_back({src, weight});
    }

    // prims
    void primsMST(int start) {
        // Create an priority queue for head
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // create a vector to store the distance of each vertex from the source
        vector<int> key(nv, INT_MAX);
        vector<int> parent(nv, -1);
        vector<bool> mstSet(nv, false);

        key[start] = 0;  // initially zero weight
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            mstSet[u] = true;

            for (auto i : adjList[u]) {
                int v = i.first;

                int weight = i.second;

                // if the vertex is not included in the mst and the weight is less than the key of the vertex
                if (mstSet[v] == false && weight < key[v]) {
                    //
                    parent[v] = u;
                    key[v] = weight;

                    pq.push({key[v], v});
                }
            }
        }

        // print
        int sum = 0;
        for (int i = 1; i < nv; i++) {
            cout << parent[i] << "  -  " << i << "  " << key[i] << endl;
            sum += key[i];
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primsMST(0);

    return 0;
}