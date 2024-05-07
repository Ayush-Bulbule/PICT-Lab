## 03 Greedy Search

Greedy Search is a search algorirhtm that selects the best choice at each step. It is a simple and fast algorithm, but it is not guaranteed to find the optimal solution. Greedy Search is used in many optimization problems, such as the Knapsack Problem, the Travelling Salesman Problem, and Huffman Coding.

### Greedy Search Algorithm

1. Create an empty set to store the solution.
2. While the solution is not complete:
    1. Select the best choice.
    2. Add the best choice to the solution.
    3. Update the problem state.

### Problem Statements

1. Part I
    a. Minimum Spanning Tree
        OR
    b. Single—Source Shortest Path Problem

2. Part II
    a. Job Scheduling Problem
        OR
    b. Prim's Minimal Spanning Tree algorithm
3. Part III
    a. Kruskal's Minimum Spanning Tree algorithm
        OR
    b. Dijkstra's Minimum Spanning Tree algorithm

### Implementations

1. Minimum Spanning Tree (Prims Algorithm)
    Algorithm for finding the minimum spanning tree of a graph using prims.

    ```
        1. Create a set mstSet that keeps track of vertices already included in MST.

        2. Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign key value as 0 for the first vertex so that it is picked first.

        3. While mstSet doesn’t include all vertices:
            a. Pick a vertex u which is not there in mstSet and has minimum key value.
            b. Include u to mstSet.
            c. Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent vertices. For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v, update the key value as weight of u-v.

        4. Print the edges of Minimum Spanning Tree. 
    ```

2. Dijkshtra's Algorithm
    Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph. It is a greedy algorithm that finds the shortest path from a source node to all other nodes in the graph.

    ```algorithm
        1. Create a priority queue to store vertices that are being preprocessed.
        
        2. Create a vector dist[] of size V to store the shortest distance from source to i.
        
        3. Initialize all distances as infinite (INF).
        
        4. Insert source vertex into priority queue and make its distance as 0.
        
        5. While priority queue is not empty, do the following:
            a. Extract the vertex with minimum distance value node from priority queue.
            b. For every adjacent vertex v of the extracted vertex, do the following:
            
                i. If dist[v] > dist[u] + weight(u, v) then update dist[v] = dist[u] + weight(u, v)
                
                ii. Insert v into the priority queue if it is not already present.
                
        6. Print the shortest path from source to all vertices.
    ```
