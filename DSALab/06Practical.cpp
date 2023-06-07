#include <iostream>
using namespace std;
#define size 100

template <class T>
class Stack
{
    T arr[size];
    int top;

public:
    Stack() { top = -1; }
    bool isFull() { return (top > size - 1); }
    bool isEmpty() { return (top == -1); }
    void push(T data)
    {
        if (isFull())
        {
            cout << "Stack is Full" << endl;
            return;
        }
        arr[++top] = data;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack Empty" << endl;
            exit(EXIT_FAILURE);
        }
        return arr[top--];
    }
};

// Queue ----------------------------------------------
template <class T>
class Queue
{
    T arr[size];
    int front = -1;
    int rear = -1;

public:
    bool isEmpty() { return front == -1 || front >= rear; }
    bool isFull() { return front > rear; }
    void enqueue(T data)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
            arr[front] = data;
            rear = 1;
            return;
        }

        arr[rear] = data;

        rear = rear + 1;

        return;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "The Queue is Empty!!" << endl;
            exit(EXIT_FAILURE);
        }

        T temp = arr[front];
        front += 1;
        return temp;
    }
};

class Node
{
    int dest;
    Node *next;

public:
    Node()
    {
        dest = 0;
        next = NULL;
    }
    Node(int dest)
    {
        this->dest = dest;
        next = NULL;
    }
    friend class Graph;
};

class Graph
{
    string *places; // to store places
    Node **adjList;
    int nv;

public:
    Graph()
    {
        places = NULL;
        adjList = NULL;
        nv = 0;
    }
    Graph(int n)
    {
        nv = n;
        adjList = new Node *[n];

        for (int i = 0; i < nv; i++)
        {
            adjList[i] = nullptr;
        }
        places = new string[nv];
    }

    // get Index of a place
    int getIndex(string place)
    {
        for (int i = 0; i < nv; i++)
        {
            if (places[i] == place)
            {
                return i;
            }
        }
        return -1;
    }

    void addEdge(int s, int d)
    {
        Node *new_node = new Node(d);
        // point node to src
        new_node->next = adjList[s];
        adjList[s] = new_node;

        // uncomment below if undirected graph
        //  new_node = new Node(s);
        //  new_node->next = adjList[d];
        //  adjList[d] = new_node;
    }

    void initGraph()
    {
        for (int i = 0; i < nv; i++)
        {
            cout << "Enter Place [" << i << "] : ";
            cin >> places[i];
        }
        string des;

        for (int i = 0; i < nv; i++)
        {
            for (int j = 0; j < nv - 1; j++)
            {

                cout << "Add Places connected to " << places[i] << " : ";
                cin >> des;
                int srcId = getIndex(places[i]);
                int desId = getIndex(des);

                if (srcId == -1 || desId == -1)
                {
                    break;
                }

                // finally addEdge
                addEdge(srcId, desId);
            }
        }
    }

    void displayGraph()
    {
        for (int i = 0; i < nv; i++)
        {
            Node *temp = adjList[i];
            cout << places[i] << " -> ";
            while (temp)
            {
                cout << places[temp->dest] << " ";
                temp = temp->next;
            }
            cout << " \n";
        }
    }

    void bfs(int src)
    {
        bool visited[nv];

        for (int i = 0; i < nv; i++)
        {
            visited[i] = false;
        }

        Queue<int> que;
        que.enqueue(src);

        visited[src] = true;
        while (!que.isEmpty())
        {
            int curr = que.dequeue();
            cout << places[curr] << " ";

            Node *temp = adjList[curr];

            while (temp)
            {
                int neighbour = temp->dest;
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    que.enqueue(neighbour);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
    void dfs(int src)
    {
        // create a array of visited
        bool visited[nv];

        for (int i = 0; i < nv; i++)
        {
            visited[i] = false;
        }

        Stack<int> st;

        st.push(src);

        visited[src] = true;

        while (!st.isEmpty())
        {
            int curr = st.pop();
            cout << places[curr] << " ";

            Node *temp = adjList[curr];
            while (temp)
            {
                int neighbour = temp->dest;
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    st.push(neighbour);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main()
{
    cout << "Graph Trersal BFS - DFS\n"
         << endl;
    int nv;
    cout << "Enter the no of places: ";
    cin >> nv;

    Graph *g = new Graph(nv);

    bool flag = true;
    string src;
    int srcId;
    bool def;

    while (flag)
    {
        int ch;

        cout << "\n1.Add Nodes\n2.Print Graph\n3.BFS Traversal\n4.DFS "
                "Traversal\n5.Exit..."
             << endl;
        cout << "Enter Your Choice: " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:

            g->initGraph();

            //

            break;
        case 2:
            cout << "Graph - " << endl;

            g->displayGraph();
            break;
        case 3:
            cout << "BFS Traversal" << endl;
            cout << "Enter source: " << endl;
            cin >> src;
            srcId = g->getIndex(src);
            g->bfs(srcId);

            // g->bfs(data);
            break;
        case 4:
            cout << "DFS Traversal" << endl;
            cout << "Enter source: " << endl;
            cin >> src;

            srcId = g->getIndex(src);
            g->dfs(srcId);
            break;
        case 5:
            cout << "Exiting....." << endl;
            flag = false;
            break;
        default:
            cout << "Wrong Input!" << endl;
            break;
        }
    }

    // g->print();

    // cout << "BFS Traversal: " << endl;
    // g->bfs(0);

    // cout << "DFS Traversal: " << endl;
    // g->dfs(0);

    return 0;
}