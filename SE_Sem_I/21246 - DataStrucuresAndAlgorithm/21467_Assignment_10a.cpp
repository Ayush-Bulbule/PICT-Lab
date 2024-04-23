// Infix to Post Fix:

// Infix to Postfix conversion
#include <iostream>
using namespace std;
#define size 100

class Stack
{
    char *arr;
    int top;

public:
    Stack()
    {
        arr = new char[size];
        top =-1;
    }
    void push(char c)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow";
            return;
        }
        arr[++top] = c;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    char Top()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        return top == -1;
    }
};

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
        return 1;
    else
        return -1;
}
void infixtoPostfix(string expr)
{
    string res = "";

    Stack st;

    for(int i=0;i<expr.length();i++){
        char c = expr[i];
        if((c>='a'&&c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9')){
            res+=c;
        }else if(c=='('){
            st.push(c);
        }else if(c==')'){
            while(st.Top()!='('){
                res+=st.Top();
                st.pop();
            }
            st.pop();
        }
        //operator is scanned
        else{
            while(!st.isEmpty() && prec(c)<=prec(st.Top())){
                res+=st.Top();
                st.pop();
            }
            st.push(c);
        }

    }

    while(!st.isEmpty()){
        res+=st.Top();
        st.pop();
    }

    cout<<res<<endl;
}
int main()
{
    infixtoPostfix("(a+b/c)*(b/a+c)");

    return 0;
}