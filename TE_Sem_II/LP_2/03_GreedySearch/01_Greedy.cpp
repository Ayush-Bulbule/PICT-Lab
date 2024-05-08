/**
 * Problem Statement: Prim's Alogrithm
 */

#include <iostream>
#define INF 1e9

using namespace std;

class Graph {
    int **adjMatrix;
    string *cities;
    int nv;

   public:
    Graph(int nv) {
        this->nv = nv;
        adjMatrix = new int *[nv];
        cities = new string[nv];

        for (int i = 0; i < nv; i++) {
            adjMatrix[i] = new int[nv];

            for (int j = 0; j < nv; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    int getIndex(string city) {
        for (int i = 0; i < nv; i++) {
            if (cities[i] == city) {
                return i;
            }
        }
        return -1;
    }
    void addEdge(int src, int des, int weight) {
        adjMatrix[src][des] = weight;
        adjMatrix[des][src] = weight;
    }
    void initGraph() {
        string des, src;
        int weight;
        int desId, srcId;
        // take all cities
        for (int i = 0; i < nv; i++) {
            cout << "Enter city [" << i << "] : ";
            cin >> cities[i];
        }

        for (int i = 0; i < nv; i++) {
            for (int j = 0; j < nv - 1; j++) {
                cout << "Add city connected to " << cities[i] << " : ";
                cin >> des;
                cout << "Enter the cost of connection : ";
                cin >> weight;

                srcId = getIndex(cities[i]);
                desId = getIndex(des);

                if (srcId == -1 || desId == -1) {
                    break;
                }
                // add edge
                addEdge(srcId, desId, weight);
            }
        }
    }

    void displayGraph() {
        for (int i = 0; i < nv; i++) {
            cout << cities[i] << " : ";
            for (int j = 0; j < nv; j++) {
                cout << " ( " << cities[j] << "," << adjMatrix[i][j] << ")"
                     << " ";
            }
            cout << endl;
        }
    }

    int minKey(int key[], bool mstSet[]) {
        int min = INF, min_index;

        for (int i = 0; i < nv; i++) {
            if (mstSet[i] == false && key[i] < min) {
                min = key[i];
                min_index = i;
            }
        }
        return min_index;
    }

    void primsAlgo() {
        // declare arrays for state of mst
        int parent[nv];
        int key[nv];
        bool mstSet[nv];

        for (int i = 0; i < nv; i++) {
            key[i] = INF;
            mstSet[i] = false;
        }

        // select first key
        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < nv - 1; count++) {
            int u = this->minKey(key, mstSet);

            mstSet[u] = true;
            for (int i = 0; i < nv; i++) {
                if (adjMatrix[u][i] && mstSet[i] == false && adjMatrix[u][i] < key[i]) {
                    parent[i] = u;
                    key[i] = adjMatrix[u][i];
                }
            }
        }
        printMST(parent);
    }

    void printMST(int parent[]) {
        cout << "Minimum cost for connection is: " << endl;
        cout << "Edges\t\tWeight" << endl;
        int cost = 0;
        for (int i = 1; i < nv; i++) {
            cost += adjMatrix[i][parent[i]];
            cout << cities[parent[i]] << " - " << cities[i] << "\t " << adjMatrix[i][parent[i]] << endl;
        }
        cout << "Total Cost is :  " << cost << endl;
    }
};
int main() {
    int nv;
    cout << "Enter the number of cities: ";
    cin >> nv;

    Graph g(nv);

    bool flag = true;
    int ch;

    while (flag) {
        cout << "1. Initlize Graph" << endl;
        cout << "2. Add Connections " << endl;
        cout << "3. Prims Min Cost " << endl;
        cout << "5. Exit...." << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                g.initGraph();
                break;
            case 2:
                g.displayGraph();
                break;
            case 3:
                g.primsAlgo();
            case 4:
                flag = false;
                cout << "Exiting...." << endl;
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
        }
    }
}