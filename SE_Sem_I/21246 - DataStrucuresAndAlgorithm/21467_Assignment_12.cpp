// Write program to implement a priority queue in C++ using an order list/array to store the
// items in the queue. Create a class that includes the data items (which should be template)
// and the priority (which should be int). The order list/array should contain these objects, with
// operator <= overloaded so that the items with highest priority appear at the beginning of the
// list/array (which will make it relatively easy to retrieve the highest item.)

#include <iostream>
#define SIZE 10
using namespace std;

template <class T>
class data
{
    T info;
    int priority;

public:
    data()
    {
        info = 0;
        priority = 0;
    }
    data(T info, int p)
    {
        this->info = info;

        this->priority = priority;
    }

    void getData(T info, int p)
    {
        this->info = info;
        this->priority = p;
    }
    bool operator<=(data<T> d2);

    template <class S>
    friend class priority_queue;
};

template <class T>
bool data<T>::operator<=(data<T> d2)
{
    if (this->priority <= d2.priority)
    {
        return true;
    }
    return false;
}

template <class T>
class priority_queue
{
    data<T> *elements;
    int front;
    int rear;
    int capacity;

public:
    priority_queue()
    {
        capacity = SIZE;
        elements = new data<T>(SIZE);
        front = -1;
        rear = -1;
    }

    priority_queue(int size)
    {
        capacity = SIZE;
        elements = new data<T>[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1 || front == rear + 1)
        {
            return true;
        }
        return false;
    }

    void insert(data<T> d)
    {
        if (rear == capacity - 1)
        {
            cout << "Overflow!!" << endl;
        }

        if (front == -1)
        {
            rear = 0;
            front = 0;
            elements[front] = d;
            cout << "Data Added!!" << endl;
            return;
        }

        // Insertion Sort
        int j = 0;
        rear++;
        j = rear - 1;

        while (this->elements[j] <= d && j >= 0)
        {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = d;
        cout << "Data Added!" << endl;
    }

    void remove()
    {
        if (this->isEmpty())
        {
            cout << "UnderFlow!!" << endl;
            return;
        }
        front++;
    }
    T Front()
    {
        if (this->isEmpty())
        {
            cout << "Undderflow!" << endl;
            return 0;
        }
        return this->elements[front].info;
    }

    void display()
    {

        // while (!this->isEmpty())
        // {
        //     cout << this->elements[front].info << " ";
        //     this->remove();
        // }
        if (!this->isEmpty())
        {
            for (int i = front; i <= rear; i++)
            {
                cout << this->elements[i].info << " ";
            }
        }

        cout << endl;
    }
};

int main()
{

    priority_queue<int> q(10);

    data<int> d;

    bool flag = true;
    int choice;
    int temp;
    int data, priority;

    while (flag)
    {

        cout << "\n##### Priority Queue #####" << endl
             << "1. Insert Data " << endl
             << "2. Remove Data" << endl
             << "3. Display All Data"<<endl
             << "4. Exit (Clean)" << endl
             << "--------------------------" << endl
             << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Data = ";
            cin >> data;
            cout << "Enter Priority: ";
            cin >> priority;

            d.getData(data, priority);
            q.insert(d);
            break;
        case 2:
            temp = q.Front();
            if (q.isEmpty())
            {
                cout << "Queue is Empty!!" << endl;
                break;
            }
            q.remove();
            cout << "Removed Data: " << temp << endl;
            break;

        case 3:
            cout << "Data in Queue: ";
            q.display();
            break;
        case 4:
            while (!q.isEmpty())
            {
                q.remove();
            }
            cout << "All Data REmoved!!" << endl;

            flag = false;
            break;
        default:
            cout << "Wrong choice!!" << endl;
            break;
        }
    }

    return 0;
}