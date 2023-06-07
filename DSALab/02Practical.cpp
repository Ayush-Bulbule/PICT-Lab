//============================================================================
// Name        : p_02btree.cpp
// Author      : Ayush Bulbule
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * Beginning with an empty binary tree, Construct binary tree by inserting
 the values in the order given. After constructing a binary tree perform
 following operations on it-
  Perform in order / pre order and post order traversal
  Change a tree so that the roles of the left and right pointers are
 swapped at every node
  Find the height of tree
  Copy this tree to another [operator=]
   Count number of leaves, number of internal nodes.
  Erase all nodes in a binary tree.
 (implement both recursive and non-recursive methods)
 */

// Binary Tree Operations
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template<class T>
class Node {
	T data;
	Node *left, *right;

public:
	Node() {
		data = NULL;
		left = right = NULL;
	}
	Node(T data) {
		this->data = data;
		left = right = NULL;
	}
	void print() {
		cout << data;
	}

	template<class S> friend class BinaryTree;
};

template<class T>
class BinaryTree {
	Node<T> *root;

public:
	BinaryTree() {
		root = NULL;
	}

	// setRoot
	void setRoot(Node<T> *node) {
		root = node;
	}

	// getRoot
	Node<T>* getRoot() {
		return root;
	}

	// Recursive Functions
	Node<T>* create() {
		T data;
		cout << "Enter Data (-1 - stop): ";
		cin >> data;

		if (data == -1) {
			return NULL;
		} else {
			// check if root is present
			Node<T> *new_node = new Node<T>(data);
			int leaf;
			cout << "Is " << data << " is a leaf node?(0-no)";
			cin >> leaf;

			if (leaf) {
				return new_node;
			} else {
				cout << "Left child of " << data << " : ";
				new_node->left = create();

				cout << "Right child of " << data << " : ";
				new_node->right = create();
			}
			return new_node;
		}
	}
	// Traversal
	// Inorder
	void inorderRecursive(Node<T> *node) {
		if (node != NULL) {
			inorderRecursive(node->left);
			node->print();
			inorderRecursive(node->right);
		}
	}
	// preorder
	void preorderRecursive(Node<T> *node) {
		if (node != NULL) {
			node->print();
			preorderRecursive(node->left);
			preorderRecursive(node->right);
		}
	}
	// postorder
	void postorderRecursive(Node<T> *node) {
		if (node != NULL) {
			postorderRecursive(node->left);
			postorderRecursive(node->right);
			node->print();
		}
	}

	// mirror
	void mirror(Node<T> *node) {
		if (node != NULL) {
			// swap childrens
			Node<T> *temp = node->left;
			node->left = node->right;
			node->right = temp;

			// call recursively
			this->mirror(node->left);
			this->mirror(node->right);
		}
	}

	// height
	int heightRecursive(Node<T> *node) {
		if (node == NULL) {
			return -1;
		}

		int leftHeight = heightRecursive(node->left);
		int rightHeight = heightRecursive(node->right);

		return (max(leftHeight, rightHeight) + 1);
	}

	// coopy
	Node<T>* copyTree(Node<T> *node) {
		Node<T> *copyNode;

		if (node == NULL) {
			return NULL;
		} else {
			copyNode = new Node<T>(node->data);
			copyNode->left = copyTree(node->left);
			copyNode->right = copyTree(node->right);
		}
		return copyNode;
	}

	// overload operator
	void operator=(BinaryTree<T> bt) {
		this->root = bt.copyTree(bt.getRoot());
	}

	// eraseTree
	void eraseTree(Node<T> *node) {
		if (node != NULL) {
			eraseTree(node->left);
			eraseTree(node->right);

			delete node;
			node = NULL;
		}
		return;
	}

	// calculate leaf
	void countNodes(Node<T> *node, int &total, int &leaf) {
		if (node != NULL) {
			total++;

			if (node->left == NULL && node->right) {
				leaf++;
				return;
			} else {
				this->countNodes(node->left, total, leaf);
				this->countNodes(node->right, total, leaf);
			}
		}
	}

	// Iterative Functions -
};

int main() {

	bool flag = true;
	int ch;

	BinaryTree<int> bt;

	while (flag) {

		cout << "======== Binary Tree ========" << endl;
		cout << "1. Create Tree(Recursive)" << endl;
		cout << "2. Traversal (Recursive)" << endl;
		cout << "3. Mirror Tree" << endl;
		cout << "4. Height of Tree" << endl;
		cout << "5. Copy Tree" << endl;
		cout << "6. Erase Tree" << endl;
		cout << "7. Count Nodes" << endl;


		cout << "\nEnter Your choice : ";
		cin >> ch;
		cout << "-----------------------------" << endl;

		switch (ch) {
		case 1: {
			cout << "Creating Tree" << endl;
			Node<int> *t = bt.create();
			bt.setRoot(t);
			cout << "Tree Created!!" << endl;
			break;
		}
		case 2: {
			cout << "1. Inorder Traversal" << endl;
			cout << "2. Preorder Traversal" << endl;
			cout << "3. Postorder Traversal" << endl;
			cout << "Enter Your choice: " << endl;
			int ch2;
			cin >> ch2;
			switch (ch2) {
			case 1:
				cout << "Inorder Traversal: " << endl;
				bt.inorderRecursive(bt.getRoot());
				break;
			case 2:
				cout << "Preodrder Traversal: " << endl;
				bt.preorderRecursive(bt.getRoot());
				break;
			case 3:
				cout << "Post Order: " << endl;
				bt.postorderRecursive(bt.getRoot());
				break;
			default:
				cout << "Wrong Input!\nPreorder: ";
				bt.preorderRecursive(bt.getRoot());
				break;
			}
			break;
		}
		case 3: {
			cout<<"Mirror Tree"<<endl;
			bt.mirror(bt.getRoot());
			cout<<"Tree Mirrored!"<<endl;
			cout<<"Inorder Traversal!"<<endl;
			bt.inorderRecursive(bt.getRoot());
			break;
		}
		case 4: {
			cout << "Height of tree is: " << endl;
			cout << bt.heightRecursive(bt.getRoot());
			break;
		}

		case 5:{
			cout<<"Copy Tree !"<<endl;
			BinaryTree<int> new_bt;
			new_bt = bt;

			new_bt.inorderRecursive(new_bt.getRoot());
			break;
		}

		case 6:{
			bt.eraseTree(bt.getRoot());
			cout<<"Tree Erased!"<<endl;
			break;
		}

		case 7:{
			int total = 0;
			int leaf = 0;
			bt.countNodes(bt.getRoot(), total, leaf);
			int internal = total-leaf;
			cout<<"Total Nodes: "<<total<<endl;
			cout<<"Internal Nodes:"<<internal<<endl;
			cout<<"Leaf Node: "<<leaf<<endl;
			break;
		}
			//yet to come
		default:
			cout << "Invalid Input" << endl;
			break;

		}
	}

	return 0;
}
