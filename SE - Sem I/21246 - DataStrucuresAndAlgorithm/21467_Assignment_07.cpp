//============================================================================
// Name        : 04_CircularDoublelyLinkedList.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : The ticket booking system of Cinemax theater has to be implemented using C++ program.
//				 There are 10 rows and 7 seats in each row. Doubly circular linked list has to be
//				 maintained to keep track of free seats at rows. Assume some random booking to start with.
//				 Use array to store pointers (Head pointer) to each row. On demand
//				 a) The list of available seats is to be displayed
//				 b) The seats are to be booked
//				 c) The booking can be cancelled.
//============================================================================

/*		Node:
 *     ------------------
 *     | &23 | 4 | &234;|
 *     ------------------
 */

#include <iostream>
using namespace std;

int ROW = 10;

class Node {
private:
	bool status;
	Node *prev;
	Node *next;

public:
	Node() {
		status = 0;
		prev = NULL;
		next = NULL;
	}
	Node(int status) {
		this->status = status;
		this->prev = NULL;
		this->next = NULL;
	}
	friend class CDL;
};

// CDL
class CDL {
private:
	Node *head;
public:
	CDL() {
		head = NULL;
	}
	void insertNode(int status) {
		Node *new_node = new Node(status);
		//If Empty
		if (head == NULL) {

			new_node->next = new_node->prev = new_node;
			head = new_node;
			return;
		}
		// If Not Empty
		// find last element
		Node *last = head->prev;

		last->next = new_node;
		new_node->next = head;
		new_node->prev = last;
		head->prev = new_node;

	}

	void printAll() {
		Node *temp = head;
		while (temp->next != head) {
			cout << temp->status << "\t";
			temp = temp->next;
		}
		cout << temp->status << "" << endl;
	}

	void printAllRev() {
		Node *temp = head->prev;
		while (temp->prev != head) {
			cout << temp->status << " ->";
			temp = temp->prev;
		}
		cout << temp->status << " ->";
	}

	//To alter list pos
	bool alterPos(int pos) {
		Node *temp = head;
		for (int i = 1; i < pos; i++) {
			temp = temp->next;
		}
		if (temp->status) {
			return false;
		}
		temp->status = !temp->status;
		return true;
	}

	bool resetPos(int pos) {
		Node *temp = head;
		for (int i = 1; i < pos; i++) {
			temp = temp->next;
		}
		if (temp->status == 1) {
			temp->status = 0;
			return true;
		} else {
			return false;

		}

	}
};

int main() {
	cout << "!!!Cinemax!!!" << endl; // prints !!!Hello World!!!

	bool flag = true;

	CDL cnmx[ROW];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 7; j++) {
			cnmx[i].insertNode(0);
		}
	}

	while (flag) {
		cout << "\t\t#### CINEMAX ####" << endl;
		cout << "1. Show Available Bookings" << endl;
		cout << "2. Book a Ticket" << endl;
		cout << "3. Cancel Booking" << endl;

		int choice;

		cout << "Enter your choice: ";
		cin >> choice;
		int row;
		int col;

		switch (choice) {
		case 1:
			cout << "The Available Seats are: " << endl;
			cout<<"0 - Available\t1 - Booked\n"<<endl;
			for (int i = 0; i < 10; i++) {
				cnmx[i].printAll();
			}
			break;
		case 2:
			cout << " Enter the row in which you want to book seat: " << endl;
			cin >> row;
			cout << "Enter seat no: ";
			cin >> col;
			if (!cnmx[row - 1].alterPos(col)) {
				cout << "Seat is already booked!" << endl;
				break;
			}

			break;
		case 3:
			cout << "Cancel Ticket" << endl;
			cout << " Enter the row in which you want to book seat: " << endl;
			cin >> row;
			cout << "Enter seat no: ";
			cin >> col;
			if (!cnmx[row - 1].resetPos(col)) {
				cout << "Seat is not booked yet!" << endl;
				break;
			}
			break;

		}
	}

	return 0;
}

