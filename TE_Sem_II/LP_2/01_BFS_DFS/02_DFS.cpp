#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

// Function to perform Depth-First Search
void DFS(const vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> stk;

    // Push the starting node onto the stack and mark it as visited
    stk.push(start);
    visited[start] = true;

    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();
        cout << current << " ";

        // Push adjacent nodes onto the stack if they are not visited yet
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                stk.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},     // Node 0 is connected to nodes 1 and 2
        {0, 3, 4},  // Node 1 is connected to nodes 0, 3, and 4
        {0, 5},     // Node 2 is connected to nodes 0 and 5
        {1},        // Node 3 is connected to node 1
        {1},        // Node 4 is connected to node 1
        {2}         // Node 5 is connected to node 2
    };

    cout << "DFS traversal starting from node 0: ";
    DFS(graph, 0);

    return 0;
}
