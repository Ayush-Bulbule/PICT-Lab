//============================================================================
// Name        : BinaryTreeeIterative.cpp
// Author      : Ayush Bulbule
// Title       : Binary Tree Iterative
// Description : Insert and Traversal in Iterative Approach
//============================================================================

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

template<class T>
class Node {
	T data;
	Node *left;
	Node *right;
public:
	Node() {
		data = NULL;
		left = NULL;
		right = NULL;
	}
	Node(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
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

	Node<T>* getRoot() {
		return this->root;
	}
	//Iterative Methods
	void insert(T data) {     //
		if (root == NULL) {
			root = new Node<T>(data);
			cout << "Root Inserted!" << endl;
		} else {
			//if root is not NULL
			queue<Node<T>*> q;
			//push root to queue
			q.push(root);
			while (!q.empty()) {
				//pop on e from queue
				Node<T> *temp = q.front();
				q.pop();
				//add to left
				if (temp->left != NULL) {
					q.push(temp->left);
				} else {
					temp->left = new Node<T>(data);
					cout << "Left Child" << endl;
					return;
				}

				//add to right
				if (temp->right != NULL) {
					q.push(temp->right);
				} else {
					temp->right = new Node<T>(data);
					cout << "Right Child" << endl;
					return;
				}

			}
		}
	}

	void inorderIterative() {
		stack<Node<T>*> st;

		Node<T> *temp = root;

		while (!st.empty() || temp != NULL) {
			if (temp != NULL) {
				st.push(temp);
				temp = temp->left;
			} else {
				temp = st.top();
				st.pop();

				cout << temp->data << " ";
				temp = temp->right;
			}
		}
	}
	//Iterative Preorder

	void preorderIterative() {
		stack<Node<T>*> st;
		Node<T> *temp = root;
		st.push(temp);

		while (!st.empty()) {
			if (temp != NULL) {
				cout << temp->data << " ";
			}

			if (temp->right != NULL) {
				st.push(temp->right);
			}

			if (temp->left != NULL) {
				temp = temp->left;
			} else {
				temp = st.top();
				st.pop();
			}
		}

	}

	//Iterative Post Order Using 2 Stack
	void postorder() {
		stack<Node<T>*> st1;
		stack<Node<T>*> st2;

		Node<T> *temp = root;
		Node<T> *ptr = NULL;

		st1.push(temp);

		while (!st1.empty()) {
			if (temp != NULL) {
				temp = st1.top();
				st1.pop();
				st2.push(temp);
			}

			Node<T> *ptr = st2.top();
			if (ptr->left != NULL) {
				st1.push(ptr->left);

			}
			if (ptr->right != NULL) {
				st1.push(ptr->right);
			}
		}

		while (!st2.empty()) {
			cout << st2.top()->data << " ";
			st2.pop();
		}
		//Testing traversal
	}
	void inorder(Node<T> *node) {
		if (node != NULL) {
			//5 3 6 4 2 9
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
		}
	}

};

int main() {
	int ch = -1;
	BinaryTree<int> bt;

	int data;

	while (ch) {
		cout << "1. Insert" << endl;
		cout << "2. Traverse" << endl;
		cout << "3. Print" << endl;
		cout << "4. Predorder" << endl;
		cout << "5. Postorder" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter Your Choice: " << endl;
		cin >> ch;

		switch (ch) {
		case 1:
			cout << "Enter Data: ";
			cin >> data;
			bt.insert(data);
			break;
		case 2:
			cout << "Traversal Is: " << endl;
			bt.inorder(bt.getRoot());
			break;
		case 3:
			cout << "Iterative Inorder: " << endl;
			bt.inorderIterative();
			break;
		case 4:
			cout << "Iterative Inorder: " << endl;
			bt.preorderIterative();
			break;
		case 5:
			cout << "Iterative Postorder: " << endl;
			bt.postorder();
			cout<<endl;
			break;
		default:
			cout << "Invalid Choidce" << endl;
			break;

		}
	}
	return 0;
}
