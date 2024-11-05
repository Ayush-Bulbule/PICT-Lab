#include <bits/stdc++.h>
using namespace std;

// Function to partition the array around a pivot (Deterministic Quick Sort)
int partitionDeterministic(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Deterministic pivot (last element)
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to partition the array around a pivot (Randomized Quick Sort)
int partitionRandomized(vector<int>& arr, int low, int high) {
    int randomPivotIndex = low + rand() % (high - low + 1);  // Random pivot
    swap(arr[randomPivotIndex], arr[high]);  // Move random pivot to end
    return partitionDeterministic(arr, low, high);  // Reuse deterministic partition
}

// Deterministic Quick Sort
void quickSortDeterministic(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionDeterministic(arr, low, high);
        quickSortDeterministic(arr, low, pi - 1);
        quickSortDeterministic(arr, pi + 1, high);
    }
}

// Randomized Quick Sort
void quickSortRandomized(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionRandomized(arr, low, high);
        quickSortRandomized(arr, low, pi - 1);
        quickSortRandomized(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    // Testing Deterministic Quick Sort
    vector<int> arrDeterministic = arr;
    quickSortDeterministic(arrDeterministic, 0, arrDeterministic.size() - 1);
    cout << "Deterministic Quick Sort Result: ";
    for (int x : arrDeterministic) cout << x << " ";
    cout << endl;

    // Testing Randomized Quick Sort
    vector<int> arrRandomized = arr;
    srand(time(0));  // Seed for randomness
    quickSortRandomized(arrRandomized, 0, arrRandomized.size() - 1);
    cout << "Randomized Quick Sort Result: ";
    for (int x : arrRandomized) cout << x << " ";
    cout << endl;

    return 0;
}
