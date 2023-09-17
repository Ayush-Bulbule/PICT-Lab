//============================================================================
// Name        : Parenthesis Checker using Stack
// Author      : Ayush Shashikant Bulbule
// Version     :
// Copyright   : Your copyright notice
// Description :In any language program mostly syntax error occurs due to unbalancing delimiter such as
//              (),{},[]. Write C++ program using stack to check whether given expression is well
//              parenthesized or not.
//============================================================================

#include <iostream>
#define SIZE 100

using namespace std;

class Stack
{
    char *arr;
    int top;

public:
    Stack()
    {
        arr = new char[SIZE];
        top = -1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (top >= SIZE - 1)
        {
            return true;
        }
        return false;
    }

    void push(char c)
    {
        if (isFull())
        {
            cout << "Stack Overflow!" << endl;
        }
        top++;
        arr[top] = c;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
        }
        top--;
    }

    char Top()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
        }
        return arr[top];
    }
};

bool parenthesisCheck(string exp)
{

    Stack st;

    for (int i = 0; i < exp.length(); i++)
    {
        if((exp[i]>='a'&& exp[i]<='z')||(exp[i] >= 'A' && exp[i] < 'Z')||(exp[i]>='1'&&exp[i]<=9)||(exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*'||exp[i]=='^')){
            continue;
        }
        else if (st.isEmpty())
        {
            st.push(exp[i]);
        }
        else if ((st.Top() == '(' && exp[i] == ')') ||
                 (st.Top() == '{' && exp[i] == '}') ||
                 (st.Top() == '[' && exp[i]))
        {
            st.pop();
        }
        else
        {
            st.push(exp[i]);
        }
    }

    if (st.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    cout << "###### Parenthesis Checker using Stack #######" << endl;
    string expr;
    cout << "Enter an Expression:";
    cin >> expr;

    if (parenthesisCheck(expr))
    {
        cout << "The Given Expression is Well Parenthesized!!" << endl;
    }
    else
    {
        cout << "The Given Expressionis Not Well Parenthesized!!" << endl;
    }

    return 0;
}