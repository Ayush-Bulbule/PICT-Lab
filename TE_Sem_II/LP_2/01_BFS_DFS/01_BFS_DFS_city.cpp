/**
 * Problem Statement: Implement depth first search (DFS) algorithm and breadth first search (BFS) algorithm.
 * Use an application for undirected graph and develop a recursive algorithm for searching all the vertices
 * of a graph or tree data structure. Also print the levels as it traverses for both algorithms.
 * Implement in CPP both ways Iterative and Recursive without using any inbuild stl function or classes
 */

// Application: Map of cities
#include <bits/stdc++.h>

using namespace std;

// Node of the Graph
class Node {
  int dest;
  Node* next;

 public:
  Node() {
    dest = 0;
    next = NULL;
  }
  Node(int data) {
    this->dest = data;
    next = NULL;
  }

  friend class Graph;
};

class Graph {
  string* cities;
  Node** adjList;
  int nv;

 public:
  Graph() {
    cities = NULL;
    adjList = NULL;
    nv = 0;
  }

  Graph(int n) {
    this->nv = n;
    adjList = new Node*[n];

    cities = new string[nv];  // to store the names of the cities

    for (int i = 0; i < nv; i++) {
      adjList[i] = nullptr;  // assign null just to avoid err
    }
  }
  // get Id(index of the city)
  int getIndex(string city) {
    for (int i = 0; i < nv; i++) {
      if (cities[i] == city)
        return i;
    }
    return -1;
  }

  // add an edge (link between city)
  void addEdge(int s, int d) {
    //
    Node* newNode = new Node(d);
    newNode->next = adjList[s];
    adjList[s] = newNode;
    newNode = new Node(s);
    newNode->next = adjList[d];
    adjList[d] = newNode;
  }

  // Display Graph
  void dislayGraph() {
    for (int i = 0; nv; i++) {
      Node* temp = adjList[i];
      while (temp) {
        cout << temp->dest;
        temp = temp->next;
      }
      cout << endl;
    }
  }

  // Initialize Map / Network
  void initMap() {
    for (int i = 0; i < nv; i++) {
      cout << "Enter the city no : " << i + 1 << " ";
      cin >> cities[i];
    }

    string des;

    for (int i = 0; i < nv; i++) {
      for (int j = 0; j < nv - 1; j++) {
        cout << "Add Cities connected to " << cities[i] << " : ";
        cin >> des;
        int srcId = getIndex(cities[i]);
        int desId = getIndex(des);

        if (srcId == -1 || desId == -1) {
          cout << "Unknown City!" << endl;
          break;
        }

        // finally addEdge
        addEdge(srcId, desId);
      }
    }
  }

  // 1. BFS - (queue)
  void BFS(int src) {
    vector<bool> visited(nv, false);

    queue<int> q;

    // Push src to queue
    q.push(src);

    // mark src visited
    visited[src] = true;

    int level = 0;
    while (!q.empty()) {
      int size = q.size();
      int curr = q.front();
      q.pop();
      Node* temp = adjList[curr];
      cout<<cities[curr]<<" ";

      while (temp) {
        int neighbour = temp->dest;
        if (!visited[neighbour]) {
          visited[neighbour] = true;
          q.push(neighbour);
        }
        temp = temp->next;
      }
    }
    cout << endl;
  }

  // DFS - Depth First Search
  void DFS(int src) {
    // visited arr
    vector<bool> visited(nv, false);

    stack<int> st;

    // push to stack
    st.push(src);

    visited[src] = true;

    while (!st.empty()) {
      int curr = st.top();
      st.pop();

      cout<<cities[curr]<<" ";

      Node* temp = adjList[curr];
      while (temp) {
        int neighbour = temp->dest;
        if (!visited[neighbour]) {
          visited[neighbour] = true;
          st.push(neighbour);
        }
        temp = temp->next;
      }
    }

    cout << endl;
  }
};


int main(){
    cout<<"BFS - DFS "<<endl;

    int nv;
    cout<<"Enter total no of cities: "<<endl;
    cin>>nv;


    Graph *g = new Graph(nv);

    bool loop =true;
    int op, srcId;
    string src;
    while(loop){
        int ch;

        cout << "\n1.Add Nodes\n2.Print Graph\n3.BFS Traversal\n4.DFS "
                "Traversal\n5.Exit..."
             << endl;
        cout << "Enter Your Choice: " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            g->initMap();
            break;
        case 2:
            cout << "Graph - " << endl;
            g->dislayGraph();
            break;
        case 3:
            cout << "BFS Traversal" << endl;
            cout << "Enter source: " << endl;
            cin >> src;
            srcId = g->getIndex(src);
            g->BFS(srcId);

            // g->bfs(data);
            break;
        case 4:
            cout << "DFS Traversal" << endl;
            cout << "Enter source: " << endl;
            cin >> src;

            srcId = g->getIndex(src);
            g->DFS(srcId);
            break;
        case 5:
            cout << "Exiting....." << endl;
            loop = false;
            break;
        default:
            cout << "Wrong Input!" << endl;
            break;
        }
    }

    return 0;
}