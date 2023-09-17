//============================================================================
// Name        : PracticePPract8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Write C++ program for storing appointment schedule for day. Appointments are booked
//				randomly using linked list. Set start and end time and min and max duration for visit slot.
//				Write functions for-
//				a) Display free slots b) Book appointment c) Cancel appointment (
//				check validity, time bounds, availability) d) Sort list based on time e) Sort list based on time
//				using pointer manipulation
//============================================================================

#include <iostream>
using namespace std;

class Node {
	int id;
	int start;
	int end;
	int min_duration;
	int max_duration;
	bool status;
	Node *next;

public:
	Node() {
		id = 0;
		start = 0;
		min_duration = 0;
		max_duration = 0;
		status = false;
		end = 0;
		next = NULL;
	}
	friend class Appointment;

};
class Appointment {
	Node *head;
	static int count;
public:
	Appointment() {
		head = NULL;
	}
	void insertNode();
	void display();
	void bookSlot(int id);
	void cancelSlot(int id);

};
int Appointment::count = 0;
//to insert a node
void Appointment::insertNode() {

	//Creating new node
	Node *new_node = new Node();
	new_node->id = count + 1;
	new_node->status = false;
	new_node->next = NULL;
	cout << "Enter start time:";
	cin >> new_node->start;
	cout << "Enter End Time:";
	cin >> new_node->end;
	cout << "Enter Max Time: ";
	cin >> new_node->max_duration;
	cout << "Enter Min Time: ";
	cin >> new_node->min_duration;

//	Adding Node to list

	if (head == NULL) {
		head = new_node;
		cout << "1st";
		count++;
		return;
	}

	Node *temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
		cout << "2nd;0";
	}
	count++;

	temp->next = new_node;

}

void Appointment::display() {

	Node *temp = head;

	if (head == NULL) {
		cout << "No Appointments are created!!!!" << endl;
		return;
	}

	cout << "Sr.\tStart\tEnd\tMax\tMin\tStatus" << endl;
	while (temp != NULL) {
		cout << temp->id << "\t" << temp->start << "\t  " << temp->end << "\t"
				<< temp->max_duration << "\t  " << temp->min_duration << "\t";
		if (temp->status) {
			cout << " Booked" << endl;
		} else {
			cout << " Free" << endl;
		}
		temp = temp->next;

	}

}

void Appointment::bookSlot(int id) {
	Node *temp = head;

	while (temp != NULL) {
		if (temp->id == id) {
			temp->status = true;
			cout << "Appointment booked for id:" << id << endl;
			return;

		}
		temp = temp->next;
	}
	cout << "No such id!!" << endl;

}
void Appointment::cancelSlot(int id) {
	Node *temp = head;

	while (temp != NULL) {
		if (temp->id == id) {
			if (temp->id) {
				temp->status = false;
				cout << "Appointment canceled for id:" << id << endl;
				return;
			}
			cout << "Appointment not booked yet!" << endl;

		}
		temp = temp->next;
	}
	cout << "No such id!!" << endl;

}

int main() {

	cout << "!!!Appointment Booking System!!!" << endl; // prints !!!Hello World!!!

	bool flag = true;
	int choice, time, slots;

	Appointment obj;

	while (flag) {
		cout << "\n\t\t Appointment Booking System\n" << endl;

		cout
				<< "1.Create a Schedule\n2.Show Available Slots\n3.Book a Slot\n4.Cancel Appointment\n5.Sort Appointments\n"
				<< endl;
		cout << "Enter Your Choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Creating Appointment schedule" << endl;
			cout << "Enter the No of slots for today:";
			cin >> slots;

			for (int i = 0; i < slots; i++) {
				obj.insertNode();
			}
			break;
		case 2:
			cout << "Available Slots are: " << endl;

			obj.display();
			break;

		case 3:
			cout << "\nBook Slot Facility" << endl;
			cout << "Enter Id to Book Slot: ";
			cin >> time;
			obj.bookSlot(time);
			break;
		case 4:
			cout << "\nCancel Slot Facility" << endl;
			cout << "Enter Id to Cancel Slot: ";
			cin >> time;
			obj.cancelSlot(time);
			break;
		case 5:
			cout << "Sort Appointment" << endl;
			break;
		default:
			cout << "Wrong Input" << endl;

		}
	}

	return 0;
}

