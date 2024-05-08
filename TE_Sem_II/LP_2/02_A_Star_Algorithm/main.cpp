/**
 * Problem Statement: Implement Astar algorith for any of the game search problem.
 * Game Selected: 8Puzzle Problem
 *
 * 1 2 3
 * 0 4 6
 * 7 5 8
 *
 * Output:
 * 1 2 3
 * 4 5 6
 * 7
 */

#include <bits/stdc++.h>
using namespace std;
#define N 3

// for the movement positions
int drow[] = {1, 0, -1, 0};
int dcol[] = {0, -1, 0, 1};
struct Node {
    Node *parent;   // pointer to parent
    int mat[N][N];  // current matrix
    int g;
    int h;     // heuristic value (no of misplaced positions)
    int x, y;  // blank pos coordinates
};

// Function to print the matrix
void printMatrix(int mat[N][N], int g, int h) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << "g: " << g << " "
         << "h: " << h << " "
         << "f: " << g + h << endl;
}

// Function to initiate a new node
Node *newNode(int mat[N][N], int x, int y, int nx, int ny, int g,
              Node *parent) {
    Node *node = new Node;
    node->parent = parent;  // set this ad parent
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            node->mat[i][j] = mat[i][j];
        }
    }

    // swap the blank with new positions
    swap(node->mat[x][y], node->mat[nx][ny]);

    // set cost of this node f(n) = g(n) + h(n)
    node->h = INT_MAX;
    node->g = g;
    // Update the position of the blank tile
    node->x = nx;
    node->y = ny;

    return node;
}

// Function to calculate the heuristic value (count of misplaced pos compared to goals)
int heuristic(int initial[N][N], int final[N][N]) {
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (initial[i][j] && initial[i][j] != final[i][j])
                count++;
    return count;
}

// Check if the calculated pos is out of the board or not
bool isSafe(int x, int y) { return (x >= 0 && x < N && y >= 0 && y < N); }

// To print path till the successfull state
void printPath(Node *root) {
    if (root == NULL)
        return;
    printPath(root->parent);
    printMatrix(root->mat, root->g, root->h);

    cout << endl;
}

// custom compare function required to compare the nodes (req. in queue)
struct comp {
    bool operator()(const Node *lhs, const Node *rhs) const {
        return (lhs->h + lhs->g) > (rhs->h + rhs->g);
    }
};

// Funtion which implements astar algorithm for solving the problem
void solve(int start[N][N], int x, int y, int goal[N][N]) {
    int cnt = 0;                                      // maintain the count required steps
    priority_queue<Node *, vector<Node *>, comp> pq;  // queue to maintain the nodes

    Node *root = newNode(start, x, y, x, y, 0, NULL);  // create a new root node first
    root->h = heuristic(start, goal);                  // calculate heuristic value

    pq.push(root);

    while (!pq.empty()) {
        Node *m = pq.top();
        pq.pop();

        // if we reach to goal state
        if (m->h == 0) {
            cout << "\n\nThis puzzle is solved in " << cnt << " moves \n";
            printPath(m);
            return;
        }

        // now go in four directions
        cnt++;
        for (int i = 0; i < 4; i++) {
            // find all possible 4 pos movements
            int dx = m->x + drow[i];
            int dy = m->y + dcol[i];

            // if possible to move create node add to queue
            if (isSafe(dx, dy)) {
                Node *child = newNode(m->mat, m->x, m->y, dx, dy, m->g + 1, m);
                child->h = heuristic(child->mat, goal);
                pq.push(child);
            }
        }
    }
}

int main() {
    // declare matrix for start and goal state
    int start[N][N];
    int goal[N][N];

    int x = -1;
    int y = -1;

    cout << "Enter the start state: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> start[i][j];
            if (start[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }
    cout << endl;
    cout << "Enter the goal state: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> goal[i][j];
        }
    }

    solve(start, x, y, goal);
    return 0;
}
