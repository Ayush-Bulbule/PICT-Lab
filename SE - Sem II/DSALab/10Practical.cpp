//============================================================================
// Name        : PracticalNo10.cpp
// Author      : Ayush Bulbule
// Titile      : Heap Sort
// Description : Read the marks obtained by students of second year in an online examination of
//               particular subject. Find out maximum and minimum marks obtained in that subject. Use
//               heap) data structure. Analvze the algorithm.
//============================================================================
#include <iostream>

using namespace std;

class Student
{
    string name;
    int marks;

public:
    Student()
    {
        name = "";
        marks = 0;
    }

    Student(string name, int marks)
    {
        this->name = name;
        this->marks = marks;
    }

    void setStudent()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    int getMarks() { return marks; }
    string getName() { return name; }

    void display() { cout << "Name: " << name << " Marks: " << marks << endl; }

    friend class MaxHeap;
};

class MaxHeap
{

    Student **heap;
    int capacity; // capacity of heap
    int size;     // current no of data

    int parent(int i)
    {
        return (i / 2);
    }
    int leftChild(int i)
    {
        return 2 * i + 1;
    }
    int rightChild(int i)
    {
        return 2 * i + 2;
    }

    void swap(Student *&a, Student *&b)
    {
        Student *temp = a;
        a = b;
        b = temp;
    }

    void maxHeapify(int i)
    {
        int left = leftChild(i);
        int right = rightChild(i);
        int largest = i;

        if (left < size && heap[left]->marks > heap[largest]->marks)
        {
            largest = left;
        }

        if (right < size && heap[right]->marks > heap[largest]->marks)
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

public:
    MaxHeap(int capacity)
    {
        this->capacity = capacity;
        heap = new Student *[capacity];
        size = 0;
    }

    void insert(Student *student)
    {
        if (size == capacity)
        {
            return;
        }
        size++;

        int currentIndex = size - 1;
        heap[currentIndex] = student;

        while (currentIndex > 0 && heap[currentIndex]->marks > heap[parent(currentIndex)]->marks)
        {
            swap(heap[currentIndex], heap[parent(currentIndex)]);
            currentIndex = parent(currentIndex);
        }
    }

    Student *extractMax()
    {
        if (size == 0)
            return nullptr;

        Student *maxStudent = heap[0];

        heap[0] = heap[size - 1]; // replace root with last element

        size--;
        maxHeapify(0); // again heapify

        return maxStudent;
    }
};
// void heapSort
void heapSort(Student *arr[], int n)
{
    MaxHeap maxHeap(n);

    for (int i = 0; i < n; i++)
    {
        maxHeap.insert(arr[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = maxHeap.extractMax();
    }
}

int main()
{

    int ch;
    int numStudents;

    cout << "Enter No. of Students: ";
    cin >> numStudents;
    bool flag = true;

    Student *students[numStudents];
    Student st;

    while (flag)
    {

        cout << "\n===== Heap Sort =====" << endl;
        cout << "1. Add Students" << endl;
        cout << "2. Sort Studnets" << endl;
        cout << "3 Print Max Marks" << endl;
        cout << "----------------------" << endl;
        cout << "\n Enter Your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:{
           
            for (int i = 0; i < numStudents; i++)
            {
               Student *new_student = new Student();
               new_student->setStudent();
                students[i] = new_student;
                // if(i>0){cout<<students[i-1]->getName();}
            }
            cout << "Students Added!" << endl;
            break;
        }
        case 2:{
            cout << "Sorted Students: " << endl;
            cout << "Sr.\tName\tMarks" << endl;
            heapSort(students,numStudents);
            for (int i = 0; i < numStudents; i++)
            {
                cout << i+1 << ". " << students[i]->getName() << " - " << students[i]->getMarks() << endl;
            }
            break;
        }
        case 3:{
            cout << "Student with Max Marks: " << endl;
            cout << "Name: " << students[numStudents - 1]->getName() << endl;
            cout << "Marks: " << students[numStudents - 1]->getMarks() << endl;
            break;
        }
        case 4:{
            cout << "Exiting... Thank You" << endl;
            flag = false;
            break;
        }
        default:{
            cout << "Invalid Input" << endl;
            break;
        }
        }
    }

    return 0;
}