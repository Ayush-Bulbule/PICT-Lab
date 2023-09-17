// A double-ended queue (deque) is a linear list in which additions and deletions may be made
// at either end. Obtain a data representation mapping a deque into a one dimensional array.
// Write C++ program to simulate deque with functions to add and delete elements from either
// end of the deque.

#include <iostream>
using namespace std;
#define SIZE 100
class Deque
{

    int front;
    int rear;
    int *arr;
    int size;

public:
    Deque(int size)
    {
        front = -1;
        rear = 0;
        arr = new int[SIZE];
        this->size = size;
    }
    bool isFull()
    {
        return ((front == 0 && rear == size - 1));
    }
    bool isEmpty()
    {
        return (front == -1);
    }

    void insertfront(int key)
    {
        if (isFull())
        {
            cout << "Overflow\n"
                 << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }

        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front = front - 1;
        }

        arr[front] = key;
    }

    void insertrear(int key)
    {
        if (isFull())
        {
            cout << "Overflow!!" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }

        arr[rear] = key;
    }

    void deletefront()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }
    }

    void deleterear()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!!" << endl;
            return;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear = rear - 1;
        }
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty() || rear < 0)
        {
            cout << "Queue is Empty!!" << endl;
            return -1;
        }
        cout<<"Rear: "<<rear;
        return arr[rear];
    }

    void display()
    {
        cout<<"Front: "<<front<<" Rear: "<<rear<<endl;
        if (isEmpty())
        {
            cout << "Queue is Empty!!" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Deque dq(5);

    int flag = true;
    int choice;
    int temp;

    while (flag)
    {
        cout << "\n #### Dequeue ####" << endl
             << "1. Insert Rear: " << endl
             << "2. Insert Front" << endl
             << "3. Delete Front" << endl
             << "4. Delete rear" << endl
             << "5. Display" << endl
             << "Enter Your choice: ";

        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter Data: ";
            cin >> temp;
            dq.insertrear(temp);
            break;
        case 2:
            cout << "Enter Data: ";
            cin >> temp;
            dq.insertfront(temp);
            break;
        case 3:
            cout << dq.getFront() << endl;
            cout << "Romove Front";
            dq.deletefront();
            break;
        case 4:
            cout << dq.getRear() << endl;
            cout << "Delete Rear" << endl;
            dq.deleterear();
            break;
        case 5:
            cout << "Queue: " << endl;
            dq.display();
            break;
        case 6:
            flag = false;
            break;
        default:
            cout << "Wrong Choice" << endl;
            break;
        }
    }

    return 0;
}
