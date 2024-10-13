### Fibonacci Series

Write a non-recursive and recursive program to calculate Fibonacci numbers and analyze their time and space complexity.

#### Non-Recursive Fibonacci (Iterative):
```cpp
#include <iostream>
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

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci number (Iterative): " << fibonacciIterative(n) << endl;
    return 0;
}
```
- **Time Complexity**: O(n)  
- **Space Complexity**: O(1)

#### Recursive Fibonacci:
```cpp
#include <iostream>
using namespace std;

int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci number (Recursive): " << fibonacciRecursive(n) << endl;
    return 0;
}
```
- **Time Complexity**: O(2^n)  
- **Space Complexity**: O(n) (due to recursion stack)

#### Analysis:
- **Iterative**: Efficient in both time (O(n)) and space (O(1)).
- **Recursive**: Exponential time complexity (O(2^n)) due to repeated calculations, with space complexity of O(n) due to recursive calls.