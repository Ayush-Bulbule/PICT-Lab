/**
 * Problem Statement: Write a program to solve a 0-1 Knapsack problem using dynamic programming 
 * or branch andbound strategy.
 */

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