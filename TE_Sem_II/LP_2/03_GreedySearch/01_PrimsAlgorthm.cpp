/**
 * Problem Statement: mplement Greedy Search algorithm on some application for
 * 1. Minimum Spanning Tree OR
 * 2. Single—Source Shortest Path Problem
 *
 * Selected: Minimum spanning tree using prims algorithm
 */

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int nv;                          // Number of vertices
    vector<pair<int, int>> *adjList; // Adjacency list e.g. {vertex, weight}

public:
    Graph(int nv)
    {
        this->nv = nv;
        adjList = new vector<pair<int, int>>[nv];
    }

    void addEdge(int src, int des, int weight)
    {
        adjList[src].push_back({des, weight});
        adjList[des].push_back({src, weight}); // For undirected graph
    }

    void primsMST(int start)
    {
        vector<int> parent(nv, -1);     // To store the parent of each vertex
        vector<int> key(nv, INT_MAX);   // To store the weight of each vertex
        vector<bool> mstSet(nv, false); // To store the vertices that are already included in MST

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min heap to store the vertices

        key[start] = 0;      // Start with the first vertex
        pq.push({0, start}); // Push the first vertex to the priority queue

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            mstSet[u] = true;

            for (auto i : adjList[u])
            {
                int v = i.first;
                int weight = i.second;

                if (mstSet[v] == false && weight < key[v])
                {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }

        for (int i = 1; i < nv; i++)
        {
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
        }

        // total weight of MST
        int totalWeight = 0;
        for (int i = 1; i < nv; i++)
        {
            totalWeight += key[i];
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main()
{
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