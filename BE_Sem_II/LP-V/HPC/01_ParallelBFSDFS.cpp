/*
 * Assignment No:     01
 * Author:            Ayush-Bulbule
 * Problem Statement: Design and implement Parallel Breadth First Search and Depth First Search based on existing algorithms using OpenMP. Use a Tree or an undirected graph for BFS and DFS . ˀMeasure the performance of sequential and parallel algorithms.
 */

#include <omp.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {

    private:
        int vertices;
        vector<vector<int>> adjList;  

    public:
        Graph(int vertices){
            this->vertices = vertices;
            adjList.resize(vertices);
        }

        void addEdge(int u, int v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        void printGraph(){
            for(auto ai:adjList){
                for(auto x:ai){
                    cout<<x<<"  ";
                }
                cout<<endl;
            }
        }

        // BFS Parallel
        void BFS(int start){
            vector<bool> visited(vertices, false);
            queue<int> queue;
            queue.push(start);

            visited[start] = true;

            while(!queue.empty()){
                int current;

                #pragma omp parallel shared(queue, visited)
                {
                    #pragma omp single
                    {
                        current = queue.front();
                        queue.pop();
                        cout<<"Theread "<<omp_get_thread_num()<<" visited "<<current<<endl;
                    }

                    #pragma omp for 
                    for(int i = 0;i<adjList[current].size(); i++){
                        if(!visited[adjList[current][i]]){
                            #pragma omp critical
                            {
                                queue.push(adjList[current][i]);
                                visited[adjList[current][i]] = true;
                            }
                        }
                    }
                }
            }
        }

        // DFS Parallel
        void DFS(int start){
            vector<bool> visited(vertices, false);
            
            DFSUntil(start, visited);
        }

        void DFSUntil(int v, vector<bool> &visited){
            #pragma omp critical
            {
                visited[v] = true;
                cout<<"Thread "<<omp_get_thread_num()<<" visited "<<v<<endl;
            }

            #pragma omp parallel for
            for(int i = 0; i< adjList[v].size();i++){
                int u = adjList[v][i];
                if(!visited[u]){
                    DFSUntil(u, visited);
                }
            }
        }

};

int main() {

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 4);


    g.printGraph();

    cout << endl;
    cout << "BFS traversal starting from vertex 0: " << endl;
    g.BFS(0);
    cout << endl;

    cout << "DFS traversal starting from vertex 0: " << endl;
    g.DFS(0);
    cout << endl;

  return 0;
}