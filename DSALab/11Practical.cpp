#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

class Student
{
    int roll;
    char name[20];

public:
    Student()
    {
        roll = 0;
        strcpy(name, "");
    }

    void getStudentData()
    {
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter Name: ";
        // cin.ignore();
        cin.getline(name, 19);
        cin >> name;
    }

    void displayStudentData()
    {
        cout << "Roll No : " << roll << endl;
        cout << "Name    : " << name << endl;
        cout << "------------------------------------------" << endl;
    }
    friend class StudentDB;
};

class StudentDB
{
    Student s;

public:
    // store data in file
    int saveStudent()
    {
        s.getStudentData();
        if (s.roll == 0 && strcmp(s.name, ""))
        {
            cout << "Please Add data to save!" << endl;
            return 0;
        }
        else
        {
            ofstream fout;
            fout.open("datafile.dat", ios::app | ios::binary);
            // write that object to file
            fout.write((char *)&s, sizeof(s));
            fout.close();
        }
        return 1;
    }

    // read data
    void readStudent()
    {
        ifstream fin;
        Student s;
        fin.open("datafile.dat", ios::in | ios::binary);

        if (!fin)
        {
            cout << "File Not Found!!" << endl;
        }
        else
        {
            fin.read((char *)&s, sizeof(s));
            while (!fin.eof())
            {
                s.displayStudentData();
                fin.read((char *)&s, sizeof(s));
            }
        }
    }
    void searchStudent(string name)
    {
        ifstream fin;
        Student s;
        fin.open("datafile.dat", ios::in | ios::binary);

        if (!fin)
        {
            cout << "File Not Found!!" << endl;
        }
        else
        {
            fin.read((char *)&s, sizeof(s));
            while (!fin.eof())
            {
                if (s.name == name)
                {
                    s.displayStudentData();
                    return;
                }
                fin.read((char *)&s, sizeof(s));
            }
        }
    }

    void deleteStudent(string name)
    {
        // yet to impliment
        ifstream fin;
        ofstream fout;

        fin.open("datafile.dat", ios::in | ios::binary);
        fout.open("tempfile.dat", ios::app | ios::binary);

        if (!fin)
        {
            cout << "File Not Found!";
            return;
        }
        else
        {

            fin.read((char *)&s, sizeof(s));

            while (!fin.eof())
            {
                if (s.name == name)
                {
                    s.displayStudentData();
                }
                else
                {
                    fout.write((char *)&s, sizeof(s));
                }
                fin.read((char *)&s, sizeof(s));
            }
        }

        remove("datafile.dat");
        rename("tempfile.dat", "datafile.dat");
    }
};
int main()
{
    cout << "Sequential Files in CPP" << endl; // prints Hashing

    StudentDB s1;

    bool flag = true;
    string data;

    while (flag)
    {
        cout << "1. Add new Student (save)" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Exit..." << endl;
        int ch;
        cout << "\nEnter Your Choise: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            s1.saveStudent();
            break;
        case 2:
            s1.readStudent();
            break;

        case 3:
            cout << "Enter Name to search: ";
            cin >> data;
            s1.searchStudent(data);
            break;
        case 4:
            cout << "Enter Name to delete: ";
            cin >> data;
            s1.deleteStudent(data);
            break;
        case 5:
            cout << "Exiting...";
            flag = false;
            break;
        default:
            cout << "Invalid Entry" << endl;
            break;
        }
    }
    return 0;
}
