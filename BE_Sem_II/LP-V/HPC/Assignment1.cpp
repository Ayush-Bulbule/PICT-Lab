#include <bits/stdc++.h>
using namespace std;

void ParallelDFSUtil(int node, vector<int> &visited, vector<vector<int>> &adjList)
{
    visited[node] = 1;
    cout << node << " ";
#pragma omp parallel for
    for (int i = 0; i < adjList[node].size(); i++)
    {
        int it = adjList[node][i];
        if (!visited[it])
        {
#pragma omp task
            ParallelDFSUtil(it, visited, adjList);
        }
    }
}

void ParallelDFS(int startNode, vector<vector<int>> &adjList)
{
    int n = adjList.size();
    vector<int> visited(n, 0);
#pragma omp parallel
    {
#pragma omp single
        ParallelDFSUtil(startNode, visited, adjList);
    }
    cout << endl;
}

void ParallelBFS(int startNode, vector<vector<int>> &adjList)
{
    int n = adjList.size();
    vector<int> visited(n, 0);
    queue<int> q;
    visited[startNode] = 1;
    q.push(startNode);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
#pragma omp parallel for
        for (int i = 0; i < adjList[node].size(); i++)
        {
            int it = adjList[node][i];
            if (!visited[it])
            {
#pragma omp critical
                {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> adjList = {
        {1, 2},    // Neighbors of node 0
        {0, 3, 4}, // Neighbors of node 1
        {0, 5},    // Neighbors of node 2
        {1},       // Neighbors of node 3
        {1},       // Neighbors of node 4
        {2}        // Neighbors of node 5
    };
    int startNode = 0;
    cout << "Parallel DFS starting from node " << startNode << ": ";
    ParallelDFS(startNode, adjList);
    cout << "Parallel BFS starting from node " << startNode << ": ";
    ParallelBFS(startNode, adjList);
    cout << endl;
    return 0;
}