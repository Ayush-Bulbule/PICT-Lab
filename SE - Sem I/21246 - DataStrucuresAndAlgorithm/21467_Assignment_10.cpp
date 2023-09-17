//============================================================================
// Name        : Postfix conversion & Evaluation Checker using Stack
// Author      : Ayush Shashikant Bulbule
// Version     :
// Copyright   : Your copyright notice
// Description :Implement C++ program for expression conversion as infix to postfix and its evaluation
//              using stack based on given conditions:
//              1. Operands and operator, both must be single character.
//              2. Input Postfix expression must be in a desired format.
//              3. Only '+', '-', '*' and '/ ' operators are expected.
//============================================================================

#include <iostream>
#define SIZE 100
using namespace std;

template <class T>
class Stack
{
    T *arr;
    int top;

public:
    Stack()
    {
        arr = new T(SIZE);
        top = -1;
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        if (top >= SIZE - 1)
            return true;
        return false;
    }
    void push(T data)
    {
        if (isFull())
        {
            cout << "Stack is Full" << endl;
            return;
        }

        top++;
        arr[top] = data;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        T t = arr[top];
        top--;
        return t;
    }

    T Top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        return arr[top];
    }
};

//----------- PRECEDENCE CHECKER  ------------
int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

//-----------  INFIX TO POSTFIX  ----------------
string infixToPostfix(string s)
{

    string res = "";
    Stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        cout << "Top" << st.Top() << endl;
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            res += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (st.Top() != '(')
            {
                res += st.Top();
                st.pop();
            }
            st.pop();
        }
        // Operator encountered
        else
        {
            while (!st.isEmpty() && prec(c) <= prec(st.Top()))
            {
                res += st.Top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty())
    {
        res += st.Top();
        st.pop();
    }
    cout << "res" << res << endl;
    return res;
}

//------  EVALUATE POSTFIX  --------------------
int evalPostfix(string s)
{
    Stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue;
        else if (isdigit(s[i]))
        {
            int num = 0;
            while (isdigit(s[i]))
            {
                num = num * 10 + (int)(s[i] - '0');
                i++;
            }
            i--;
            st.push(num);
        }
        else
        {
            int val1 = st.pop();
            int val2 = st.pop();
            cout << "Val1: " << val1 << " aval2 " << val2 << endl;

            switch (s[i])
            {
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            }
        }
    }
    return st.Top();
}

int main()
{

    int choice;
    string infix,postfix;
    int result;
    
    bool flag = true;

    while (flag)
    {
        cout << "\n #### Infix-Postfix Stack ####" << endl
             << "1. Infix to Postfix" << endl
             << "2. Evaluat Postfix" << endl
             << "3.Exit" << endl
             << "Enter Your Choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter Infix Expression: ";
            cin>>infix;
            postfix = infixToPostfix(infix);
            cout<<"Postfix: "<<postfix<<endl;
            break;
        case 2:
            cout<<"Enter Postfix Expression(Seperated By ' '(space)): ";
            cin>>postfix;
            result = evalPostfix(postfix);
            cout<<"Postfix: "<<result<<endl;
            break;
        case 3:
            flag = false;
        default:
            break;
        }
    }

    return 0;
}
