//============================================================================
// Name        : PracticalNo02.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Practical No: 2 Beginning with an empty binary tree, Construct binary tree by inserting
// the values in the order given. After constructing a binary tree perform
// following operations on it-
// - Perform in order / pre order and post order traversal
// - Change a tree so that the roles of the left and right pointers are swapped at every node
// - Find the height of tree
// - Copy this tree to another [operator=]
// - Count number of leaves, number of internal nodes.
// - Erase all nodes in a binary tree.
// (implement both recursive and non-recursive methods)
//============================================================================

#include <iostream>
using namespace std;

#define MAX 100
// Stack
template <class T>
class Stack
{
    T arr[MAX];

    int top;

public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return top >= (MAX - 1);
    }

    void push(T data)
    {
        top++;
        arr[top] = data;
    }

    T pop()
    {
        T data = arr[top];

        top--;

        return data;
    }
};

// Queue - ------------------------------------------------
template <class T>
class Queue
{
    T arr[MAX];
    int front, rear = -1;

public:
    Queue()
    {
        rear = 1;
        front = -1;
    }
    bool isFull()
    {
        return front > rear;
    }

    bool isEmpty()
    {
        return front >= rear || front == -1;
    }

    void enqueue(T data)
    {
        cout << data << endl;
        if (isFull())
        {
            cout << "Queue is full";
            return;
        }

        if (front == -1)
        {
            front = 0;
            rear = 1;
            arr[front] = data;
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
            cout << "Queue is empty" << endl;
            exit(EXIT_FAILURE);
        }

        T data = arr[front];
        front = front + 1;
        return data;
    }
};

// Queue

template <class T>
class Node
{
    T data;
    Node<T> *left, *right;

public:
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    template <class S>
    friend class BinaryTree;
};

// BT

template <class T>
class BinaryTree
{
    Node<T> *root;

public:
    BinaryTree()
    {
        root = NULL;
    }
    BinaryTree(T data)
    {
        root = new Node<T>(data);
    }

    // Setter
    void setRoot(Node<T> *root)
    {
        this->root = root;
    }

    // Getter
    Node<T> *getRoot()
    {
        return this->root;
    }

    // Recursive Operations
    Node<T> *create()
    {
        T data;
        cout << "Enter data (-1 for no data): ";

        cin >> data;

        if (data == -1)
        {
            return NULL;
        }
        else
        {

            Node<T> *p = new Node<T>(data);

            bool conti;
            cout << "Do you want to continue adding ?(1-yes/0-No)  ";
            cin >> conti;

            if (conti)
            {

                cout << "Enter for left of " << data << endl;
                p->left = create();
                cout << "Enter right of  " << data << endl;
                p->right = create();
            }
            return p;
        }
    }

    // Recursive Traversal -------------------------------------------------
    // Inorder
    void recInorder(Node<T> *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        recInorder(temp->left);
        cout << temp->data;
        recInorder(temp->right);
    }

    // Preorder
    void recPreorder(Node<T> *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        cout << temp->data;
        recPreorder(temp->left);
        recPreorder(temp->right);
    }

    // Postorder
    void recPostorder(Node<T> *node)
    {
        if (node == NULL)
        {
            return;
        }
        recPostorder(node->left);
        recPostorder(node->right);
        cout << node->data;
    }

    // Mirror Tree
    void recMirror(Node<T> *node)
    {
        if (node == NULL)
        {
            return;
        }
        else
        {
            Node<T> *temp;
            // recursive call
            mirror(node->left);
            mirror(node->right);

            // Swap
            temp = new Node<T>(node->left);
            node->left = node->right;
            node->right = temp;
        }
    }

    // Copy Tree
    Node<T> *copyTree(Node<T> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        Node<T> *new_node = new Node<T>(node->data);

        new_node->left = copy(node->left);
        new_node->right = copy(node->right);

        return new_node;
    }

    // Erase Tree
    void eraseTree(Node<T> *temp)
    {
        if (temp != NULL)
        {
            eraseTree(temp->left);
            eraseTree(temp->right);

            delete temp;
        }

        else
        {
            return;
        }
    }

    // calculate height
    int recHeight(Node<T> *node)
    {
        if (node == NULL)
        {
            return -1;
        }

        int leftHeight = recHeight(node->left);
        int rightHeight = recHeight(node->right);

        return (max(leftHeight, rightHeight));
    }

    // Overload Operator  = to copy tree
    //	Node<T>*

    // claculate leaf node and internal nodes

    // Iterative Approach
};

int main()
{
    cout << "Practical No 2: Binary Tree" << endl;
    //
    BinaryTree<int> *bt = new BinaryTree<int>();

    Node<int> *node = bt->create();
    bt->setRoot(node);

    // Traversal
    cout << "Inorder: " << endl;
    bt->recInorder(bt->getRoot());

    // Preorder
    cout << "Inorder: " << endl;
    bt->recPostorder(bt->getRoot());

    // Postorder
    cout << "Inorder: " << endl;
    bt->recPreorder(bt->getRoot());

    return 0;
}
