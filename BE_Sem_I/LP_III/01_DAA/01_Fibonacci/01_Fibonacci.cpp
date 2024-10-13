#include<bits/stdc++.h>

using namespace std;

int fibonacciIterative(int n) {
    if (n <= 1)
        return n;
    int a = 0, b = 1, fib = 0;
    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}


int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci number (Recursive): " << fibonacciRecursive(n) << endl;
    cout << "Fibonacci number (Iterative): " << fibonacciIterative(n) << endl;

}