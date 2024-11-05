/**
 * Problem Statement: Write a program non-recursive and recursive program to calculate Fibonacci
 * numbers andanalyze their time and space complexity
*/

#include<bits/stdc++.h>
using namespace std;

// Recursive Fibonacci
int fibonacci_recurtsive(int n){
    if(n<=1) return n;
    return fibonacci_recurtsive(n - 1) + fibonacci_recurtsive(n - 2);
}

// Iterative Fibonacci
int fibonacci_iterative(int n){
    if(n<=1) return n;

    int a = 0, b = 1,fib;

    for(int i = 2;i<=n;i++){
        fib = a+b;
        a = b;
        b = fib;
    }
    return fib;
}


int main(){
    int n;

    cout<<"Enter a Number: ";
    cin>>n;

    cout<<"Fibonacci Recursive: "<<fibonacci_recurtsive(n)<<endl;
    cout<<"Fibonacci Iterative: "<<fibonacci_iterative(n)<<endl;

    return 0;
}

