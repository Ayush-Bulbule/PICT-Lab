#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

#define SIZE 10

class Student {
  int rollno;
  char name[10];
  // 21467
public:
  Student() {
    rollno = 0;
    strcpy(name, "noname");
  }

  void getStudent() {
    cout << "Enter RollNo: ";
    cin >> rollno;
    cout << "Enter Name: ";
    cin >> name;
  }

  void display() {
    cout << "Student Name: " << name << endl;
    cout << "Roll No: " << rollno << endl;
  }

  friend class DFA;
};

class DFA {
  Student s;

public:
  void init() {
    ifstream file("datafil.dat", ios::binary);

    if (!file) {
      cout << "File does not exist. Creating a new file with dummy data."
           << endl;
      file.close();

      ofstream outfile("datafil.dat", ios::binary);
      for (int i = 0; i < SIZE; i++) {
        Student dummy;
        outfile.write((char *)&dummy, sizeof(Student));
      }
      outfile.close();
    } else {
      file.close();
    }
  }

  int getHash(int roll) { return roll % SIZE; }

  void save() {
    s.getStudent();

    int hash = getHash(s.rollno);

    fstream file("datafil.dat", ios::in | ios::out | ios::binary);

    file.seekp(hash * sizeof(Student), ios::beg);
    file.write((char *)&s, sizeof(s));

    file.close();
  }

  void deleteStudent() {
    int roll;
    cout << "Enter the roll to delete: " << endl;
    cin >> roll;
    int hash = getHash(roll);
    Student dummy;
    fstream file("datafil.dat", ios::in | ios::out | ios::binary);

    file.seekp(hash * sizeof(Student), ios::beg);

    file.write((char *)&dummy, sizeof(dummy));
    file.close();
  }

  void read() {
    int roll;
    cout << "Enter Roll no: ";
    cin >> roll;

    int hash = getHash(roll);
    ifstream file("datafil.dat", ios::binary);
    file.seekg(hash * sizeof(Student), ios::beg);
    file.read((char *)&s, sizeof(Student));

    if (s.rollno == roll) {
      s.display();
      return;
    }
    cout << "Student Not Found!!" << endl;

    file.close();
  }
};

int main() {

  // Object to do
  DFA d;
  d.init();

  // driver program
  bool flag = true;

  int ch;

  while (true) {
    cout << "\nDIRECT ACCESS FILE" << endl;
    cout << "1. Save Data" << endl;
    cout << "2. Read Data" << endl;
    cout << "3. Delete Data" << endl;
    cout << "4. Exit..." << endl;

    cout << "Enter Your choice: ";
    cin >> ch;

    switch (ch) {
    case 1:
      d.save();
      break;
    case 2:
      d.read();
      break;
    case 3:
      d.deleteStudent();
      break;
    case 4:
      cout << "Exiting..." << endl;
      flag = false;
      break;
    }
  }

  return 0;
}