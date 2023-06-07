//============================================================================
// Name        : 03Practical.cpp
// Author      : Ayush Bulbule
// Version     :
// Title       : Threaded BST
// Description : Create an inordered threaded binary search tree. Perform inorder,
//               preorder traversals without recursion and deletion of a node. Analyze
//               time and space complexity of the algorithm.
//============================================================================

#include <iostream>
using namespace std;

// 0->Thread 1->Link

class Node
{
    int data;
    Node *left;
    Node *right;

    bool lbit;
    bool rbit;

public:
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
        lbit = 0;
        rbit = 0;
    }
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        lbit = 0;
        rbit = 0;
    }
    friend class TBST;
};

class TBST
{
    Node *head, *root;

public:
    TBST()
    {
        head = root = NULL;
    }

    Node *getRoot()
    {
        return root;
    }

    // insert:
    void insert(int key)
    {
        // if Tree is Empty
        if (root == NULL)
        {
            head = new Node(-9999);
            head->right = head;

            // create root
            root = new Node(key);
            // attach root to header
            head->left = root;
            head->lbit = 1;
            root->left = head;
            root->right = head;
            return;
        }
        // Tree is Not Empty
        else
        {
            Node *parent = root;
            Node *new_node = new Node(key);

            while (true)
            {
                if (key == parent->data)
                {
                    delete new_node;
                    return; // duplicate key
                }

                else if (key < parent->data)
                {
                    // explore left subtree
                    if (parent->lbit == 1)
                    {
                        parent = parent->left;
                    }
                    // add new node to end
                    else
                    {
                        new_node->left = parent->left;
                        new_node->right = parent;
                        parent->left = new_node;
                        parent->lbit = 1;
                        return;
                    }
                }
                else
                {
                    // when key > parent->data
                    if (parent->rbit == 1)
                    {
                        parent = parent->right;
                    }
                    else
                    {
                        // right
                        new_node->right = parent->right;
                        new_node->left = parent;
                        parent->right = new_node;
                        parent->rbit = 1;
                        return;
                    }
                }
            }
        }
    }

    // Inorder Traversal
    void inorder()
    {
        Node *temp = root;

        // finding extreme left of root
        while (temp->lbit == 1)
        {
            temp = temp->left;
        }

        while (temp != head)
        {
            // print node
            cout << temp->data << " ";

            // It has right child
            if (temp->rbit == 1)
            {
                temp = temp->right;
                // again leftmost node
                while (temp->lbit == 1)
                {
                    temp = temp->left;
                }
            }
            else
            {
                temp = temp->right;
            }
        }
        cout<<endl;
    }

    void preorder()
    {
        bool flag = 0;

        Node *temp = root;

        while (temp != head)
        {
            if (flag == 0)
            {
                cout << temp->data << " ";
            }

            if (flag == 0 && temp->lbit == 1)
            {
                temp = temp->left;
            }
            else
            {
                flag = (temp->rbit == 1) ? (0) : (1);
                temp = temp->right;
            }
        }
        cout<<endl;
    }

    // search
    bool search(int key, Node *&current, Node *&parent)
    {
        while (current != head)
        {
            if (current->data == key)
            {
                 return true;
            }
            else
            {
                parent = current;
                if (key < current->data)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
        }
        return false;
    }
    void deleteNode(Node *&p, Node *&t)
    {
       //2 Links
        if (t->lbit == 1 && t->rbit == 1)
        {
            Node *cs = t->right;
            p = t;
            while (cs->lbit == 1)
            {
                p = cs;
                cs = cs->left;
            }
            t->data = cs->data;
            t = cs;
            cout<<"Deleting Node Having 2 links"<<endl;
        }

        // leaf node 
        if (t->lbit == 0 && t->rbit == 0)
        {
            if (p->left == t)
            {
                cout<<"Deleting Leaf (Left)"<<endl;
                p->left = t->left;
                p->lbit = 0;
            }
            else
            {
                cout<<"Deleting Leaf (Right)"<<endl;
                p->right = t->right;
                p->rbit = 0;
            }
            delete t;
        }

        // left Link, right thread
        if (t->lbit == 1 && t->rbit == 0)
        {
            Node *temp = t->left;
            if (p->left == t)
            {
                p->left = temp;
            }

            else
            {
                p->right = temp;
            }

            while (temp->rbit == 1)
            {
                temp = temp->right;
            }
            temp->right = t->right;
            cout<<"Deleting Node with left link"<<endl;
            delete t;
        }

        // right link, left thread
        if (t->lbit == 0 && t->rbit == 1)
        {
            Node *temp = t->right;
            if (p->left == t)
            {
                p->left = temp;
            }
            else
            {
                p->right = temp;
            }

            while (temp->lbit == 1)
            {
                temp = temp->left;
            }
            temp->left = t->left;
            cout<<"Deleting Node with right link"<<endl;
            delete t;
        }
    }
};

int main()
{

    TBST tbst;

    int choice = -1;
    int temp;

    bool flag = true;

    while (flag)
    {
        cout << "===== Threaded BST =====" << endl;
        cout << "1. Insert a Node" << endl;
        cout << "2. In-Order Traversal" << endl;
        cout << "3. Pre-Order Traversal" << endl;
        cout << "4. Delete Node" << endl;
        cout << "5. Exit.." << endl;
        cout << "-------------------------" << endl;
        cout << "\nEnter Your choice: ";
        cin >> choice;

        int value;

        switch (choice)
        {
        case 1:
        { // Inser Node
            cout << "Enter no. of nodes:" << endl;
            cin >> temp;
            while (temp-- > 0)
            {
                cout << "Enter node: ";
                cin >> value;
                tbst.insert(value);
            }
            cout << "Nodes Inserted!" << endl;
            break;
        }
        case 2:
        { // Inorder Traversal
            cout << "Inorder Taversal : " << endl;
            tbst.inorder();
            break;
        }
        case 3:
        {
            cout << "Preorder Traversal: " << endl;
            tbst.preorder();
            break;
        }
        case 4:
        {
            cout << "Enter node to delete: " << endl;
            cin >> temp;

            Node *parent = NULL;
            Node *current = tbst.getRoot();

            if (tbst.search(temp, current, parent))
            {
                tbst.deleteNode(parent, current);
                cout << temp << "deleted!" << endl;
            }
            else
            {
                cout << temp << " not present!" << endl;
            }
        }
        break;
        case 5:
        {
            cout << "Exiting....ThankYou:)" << endl;
            flag = false;
            break;
        }
        default:
        {
            cout << "Invalid Input" << endl;
            break;
        }
        }
    }

    return 0;
}
