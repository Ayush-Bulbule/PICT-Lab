// Postfix Evaluation

#include <iostream>
using namespace std;
#define size 100
class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[size];
        top = -1;
    }
    void push(int c)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow";
        }
        top++;
        arr[top] = c;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Undeflow" << endl;
        }
        int t = arr[top];
        top--;
        return t;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Stack Empty";
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int postFixEvaluation(string expr)
{
    Stack st;
    for (int i = 0; i < expr.length(); i++)
    {
        // if char is blank sapace the just avoid it
        if (expr[i] == ' ')
            continue;
        else if (isdigit(expr[i]))
        {
            int num = 0;
            while (isdigit(expr[i]))
            {
                num = num * 10 + (int)(expr[i] - '0');
                i++;
            }
            i--;
            st.push(num);
        }
        else
        {
            int val1 = st.pop();
            int val2 = st.pop();

            switch (expr[i])
            {
            case '+':
                st.push(val1 + val2);
                break;
            case '-':
                st.push(val1 - val2);
                break;
            case '/':
                st.push(val1 / val2);
                break;
            case '*':
                st.push(val1 * val2);
                break;
            }

        }
    }
    return st.Top();
}

int main()
{

    int res = postFixEvaluation("2 31 *  9 +");
    cout << "Res: " << res << endl;

    return 0;
}