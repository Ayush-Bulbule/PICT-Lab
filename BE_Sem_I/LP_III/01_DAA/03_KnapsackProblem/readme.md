### Fractional Knapsack Problem (C++)

Write a program to solve a fractional Knapsack problem using a greedy method.

```cpp

#include <bits/stdc++.h>
using namespace std;

int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n) {
    
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0)); // table

    // Build the DP table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n = 4;
    int capacity = 9;
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};

    int max_value = knapsack(capacity, weights, values, n);

    cout << "The maximum value that can be obtained is: " << max_value << endl;

    return 0;
}
```
This code solves the **0-1 Knapsack Problem** using **dynamic programming**. Let's break down each part of the code.

### Problem Recap

In the **0-1 Knapsack Problem**, you have:
- `n` items, each with a specific `weight` and `value`.
- A knapsack with a fixed `capacity`.
  
The goal is to maximize the **total value** of items in the knapsack without exceeding its capacity. Each item can either be included (1) or excluded (0), hence "0-1".

### Code Breakdown

```cpp
#include <bits/stdc++.h>
using namespace std;
```
- Includes the necessary libraries. `#include <bits/stdc++.h>` is a common shortcut in competitive programming that includes almost all standard headers.

```cpp
int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0)); // table
```
- The `knapsack` function takes in:
  - `capacity`: the maximum weight the knapsack can hold.
  - `weights`: a vector containing the weight of each item.
  - `values`: a vector containing the value of each item.
  - `n`: the number of items.
  
- It initializes a **2D DP table** `dp` of dimensions `(n+1) x (capacity+1)`, filled with `0`s. `dp[i][w]` will store the **maximum value** attainable using the first `i` items with knapsack capacity `w`.

### Building the DP Table (Bottom-Up)

```cpp
    // Build the DP table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
```

1. **Loop through each item** \(i = 1\) to \(n\) and each capacity \(w = 1\) to \(W\):
   - If the weight of the current item `weights[i-1]` is less than or equal to `w`, we have two options:
     - **Exclude the item**: Take the maximum value achievable without this item, which is `dp[i-1][w]`.
     - **Include the item**: Add the current item's value `values[i-1]` and take the best achievable value for the remaining capacity, which is `dp[i-1][w - weights[i-1]]`.
   - The formula for this decision is:
     \[
     dp[i][w] = \max(dp[i-1][w], \text{values}[i-1] + dp[i-1][w - \text{weights}[i-1]])
     \]

2. **Else (If item doesn't fit)**:
   - Simply carry over the best solution for this capacity without the item: `dp[i][w] = dp[i-1][w]`.

### Returning the Result

```cpp
    return dp[n][capacity];
}
```
- The maximum value that can be obtained with all items and the full capacity is stored in `dp[n][capacity]`.

### Main Function

```cpp
int main() {
    int n = 4;
    int capacity = 9;
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};

    int max_value = knapsack(capacity, weights, values, n);

    cout << "The maximum value that can be obtained is: " << max_value << endl;

    return 0;
}
```
- Initializes a test case with:
  - 4 items, a knapsack capacity of 9.
  - Each item has corresponding weights `{2, 3, 4, 5}` and values `{3, 4, 5, 6}`.
  
- Calls `knapsack()` and stores the result in `max_value`.
  
- Prints the maximum value that can be achieved with the given items and knapsack capacity.

### Example Calculation (Dry Run)

For this input:
- Items are chosen to maximize value without exceeding the weight 9.
- The DP table would compute optimal values for all capacities up to 9, building on previous results for each item.
  
### Complexity Analysis

- **Time Complexity**: \(O(n \times W)\), as it fills up an `(n+1) x (capacity+1)` table.
- **Space Complexity**: \(O(n \times W)\), due to the storage requirement for the DP table.