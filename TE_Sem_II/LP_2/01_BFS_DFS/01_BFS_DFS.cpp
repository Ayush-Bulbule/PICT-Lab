// BFS and DFS in cpp

#include <bits/stdc++.h>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

   public:
    Graph(int V) {
        this->V = V;
        adj = vector<vector<int>>(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int s) {
        vector<bool> visited(V, false);  // Track visited
        queue<int> q;

        q.push(s);
        visited[s] = true;

        while (!q.empty()) {
            int u = q.front();
            cout << u << " ";
            q.pop();

            for (int i = 0; i < adj[u].size(); i++) {
                if (!visited[adj[u][i]]) {
                    visited[adj[u][i]] = true;
                    q.push(adj[u][i]);
                }
            }
        }
    }

    void DFS(int s) {
        vector<bool> visited(V, false);
        stack<int> st;
        st.push(s);
        visited[s] = true;

        while (!st.empty()) {
            int u = st.top();
            cout << u << " ";
            st.pop();

            for (int i = 0; i < adj[u].size(); i++) {
                if (!visited[adj[u][i]]) {
                    visited[adj[u][i]] = true;
                    st.push(adj[u][i]);
                }
            }
        }
    }

    // DFS Recursive
    void DFSUtil(int s, vector<bool> &visited) {
        visited[s] = true;
        cout << s << " ";

        for (int i = 0; i < adj[s].size(); i++) {
            if (!visited[adj[s][i]]) {
                DFSUtil(adj[s][i], visited);
            }
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS: ";
    g.BFS(2);
    cout << endl;

    cout << "DFS: ";
    g.DFS(2);
    cout << endl;

    cout << "DFS Recursive: ";
    vector<bool> visited(4, false);
    g.DFSUtil(2, visited);
    cout << endl;

    return 0;
}