#### Quick Sort Implementation in C++

Write a program for analysis of quick sort by using deterministic and randomized variants.

```cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to perform the partitioning for deterministic Quick Sort
int deterministicPartition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // Swap if element is smaller than pivot
        }
    }
    swap(arr[i + 1], arr[high]); // Place the pivot in the correct position
    return i + 1; // Return the partition index
}

// Deterministic Quick Sort function
void deterministicQuickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = deterministicPartition(arr, low, high); // Partitioning index
        deterministicQuickSort(arr, low, pi - 1); // Recursively sort left sub-array
        deterministicQuickSort(arr, pi + 1, high); // Recursively sort right sub-array
    }
}

// Function to perform the partitioning for randomized Quick Sort
int randomizedPartition(vector<int> &arr, int low, int high) {
    int randomIndex = low + rand() % (high - low); // Random index for pivot
    swap(arr[randomIndex], arr[high]); // Move pivot to the end
    return deterministicPartition(arr, low, high); // Use deterministic partitioning
}

// Randomized Quick Sort function
void randomizedQuickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high); // Partitioning index
        randomizedQuickSort(arr, low, pi - 1); // Recursively sort left sub-array
        randomizedQuickSort(arr, pi + 1, high); // Recursively sort right sub-array
    }
}

// Function to print the array
void printArray(const vector<int> &arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    vector<int> arr1 = {10, 7, 8, 9, 1, 5};
    vector<int> arr2 = arr1; // Copying the original array for randomized sort

    cout << "Original array: ";
    printArray(arr1);

    // Deterministic Quick Sort
    deterministicQuickSort(arr1, 0, arr1.size() - 1);
    cout << "Sorted array using Deterministic Quick Sort: ";
    printArray(arr1);

    // Randomized Quick Sort
    randomizedQuickSort(arr2, 0, arr2.size() - 1);
    cout << "Sorted array using Randomized Quick Sort: ";
    printArray(arr2);

    return 0;
}
```

#### Explanation of the Code:

1. **Deterministic Quick Sort**:
   - The `deterministicPartition` function selects the last element as the pivot and partitions the array around it.
   - The `deterministicQuickSort` function recursively sorts the left and right partitions.

2. **Randomized Quick Sort**:
   - The `randomizedPartition` function selects a random pivot from the current sub-array and uses the deterministic partitioning method to sort the array.
   - The `randomizedQuickSort` function recursively sorts the array in a similar manner.

3. **Main Function**:
   - The original array is defined, and a copy of it is created for the randomized sort.
   - Both sorting methods are executed, and the sorted arrays are printed.

#### Example Input/Output

**Example Output**:
```
Original array: 10 7 8 9 1 5 
Sorted array using Deterministic Quick Sort: 1 5 7 8 9 10 
Sorted array using Randomized Quick Sort: 1 5 7 8 9 10 
```

#### Complexity Analysis

- **Time Complexity**:
  - **Deterministic Quick Sort**: 
    - Average Case: O(n log n)
    - Worst Case: O(n²) (occurs when the smallest or largest element is consistently chosen as the pivot)
  - **Randomized Quick Sort**: 
    - Average Case: O(n log n)
    - Worst Case: O(n²) (but with a very low probability, as the pivot is chosen randomly)

- **Space Complexity**: O(log n) for the recursion stack in both implementations.

#### Conclusion
This program showcases both the deterministic and randomized variants of Quick Sort, highlighting the difference in how the pivot selection impacts performance and efficiency.