### Fractional Knapsack Problem (C++)

Write a program to solve a fractional Knapsack problem using a greedy method.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item with value and weight
struct Item {
    int value, weight;
    
    // Constructor
    Item(int value, int weight) {
        this->value = value;
        this->weight = weight;
    }
};

// Comparison function to sort items based on value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;  // Sort by decreasing ratio
}

// Function to calculate maximum value for fractional knapsack
double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;  // Total value accumulated
    int curWeight = 0;        // Current weight in the knapsack

    for (auto item : items) {
        if (curWeight + item.weight <= W) {
            // Add the entire item to the knapsack
            curWeight += item.weight;
            totalValue += item.value;
        } else {
            // Add fractional part of the item
            int remain = W - curWeight;
            totalValue += item.value * ((double)remain / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int W = 50;  // Knapsack capacity

    // List of items: {value, weight}
    vector<Item> items = { {60, 10}, {100, 20}, {120, 30} };

    // Calculate maximum value
    double maxValue = fractionalKnapsack(W, items);

    cout << "Maximum value in Knapsack: " << maxValue << endl;

    return 0;
}
```

#### How Fractional Knapsack Works:
1. **Value-to-Weight Ratio**: Items are sorted in descending order based on their value-to-weight ratio.
2. **Greedy Selection**: Items are added to the knapsack starting with the highest ratio. If an item cannot fit entirely, we take the fractional part of it.
3. **Stopping Condition**: The process stops when the knapsack is full.

#### Example Input:
Items: `{ {60, 10}, {100, 20}, {120, 30} }`  
Capacity: `W = 50`

#### Example Output:
```
Maximum value in Knapsack: 240
```

#### Time Complexity:
- **Sorting**: O(n log n) (for sorting items based on their value/weight ratio)
- **Greedy Selection**: O(n)

**Overall Time Complexity**: O(n log n)

#### Space Complexity:
- **Space**: O(1) (excluding the input array)