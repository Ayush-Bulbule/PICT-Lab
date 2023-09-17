//============================================================================
// Name        : Parenthesis Checker using Stack
// Author      : Ayush Shashikant Bulbule
// Version     :
// Copyright   : Your copyright notice
// Description :Queues are frequently used in computer programming, and a typical example is the creation
//              of a job queue by an operating system. If the operating system does not use priorities, then
//              the jobs are processed in the order they enter the system. Write C++ program for simulating
//              job queue. Write functions to add job, display job and delete job from queue. 
//============================================================================


#include<iostream>
#define SIZE 100
using namespace std;

class Queue{
    int* arr;
    int front, rear;
    public:
    Queue(){
        arr = new int[SIZE];
        front = -1;
        rear = -1;
    }

    void enqueue(int n){
        if(rear>=SIZE-1){
            cout<<"Queue is Full";
        }
        rear++;
        arr[rear] = n;

        if(front==-1){
            front++;
        }
    }

    void dequeue(){
        if(front==-1||front>rear){
            cout<<"Queue is empty"<<endl;
        }
        front++;
    }
    int peek(){
        if(front==-1||front>rear){
            cout<<"Queue is empty"<<endl;
        }
        return arr[front];
    }

    bool isFull(){
        if(front>=rear){
            cout<<"Queue is Full"<<endl;
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(front==-1||front>rear){
            cout<<"Queue is empty"<<endl;
            return true;
        }
        return false;
    }

    void display(){
        for(int i =front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n"<<endl;
    }
};



int main(){

    Queue q;
    int ch,jid;

   

    bool flag = true;

    while(flag){
        cout<<"\n###Job Management using queue"<<endl;
        cout<<"\n1. Insert Job"<<endl;
        cout<<"2. Display Jobs"<<endl;
        cout<<"3. Delete Jobs"<<endl;

        cout<<"Enter Your Choice";
        cin>>ch;

        switch (ch)
        {
        case 1:
            cout<<"Insert Job"<<endl;
            cout<<"Enter Job ID: ";
            cin>>jid;
            q.enqueue(jid);
            break;
        case 2:
            cout<<"Display Jobs"<<endl;
            q.display();
            break;
        case 3:
            cout<<"Delete Job"<<endl;
            q.dequeue();
            cout<<"Display"<<endl;
            q.display();
            break;
        default:
            break;
        }

    }

    return 0;
}