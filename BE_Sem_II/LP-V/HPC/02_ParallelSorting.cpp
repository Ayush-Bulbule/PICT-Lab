/*
 * Assignment No:     02
 * Author:            Ayush-Bulbule
 * Problem Statement: Implement Parallel Bubble Sort and Merge Sort using OpenMP. Measure and compare the performance of sequential and parallel implementations.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <omp.h>

using namespace std;

// Utility to generate random array
void generateArray(vector<int>& arr, int size) {
    arr.resize(size);
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 10000;
}

// Sequential Bubble Sort
void bubbleSortSequential(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

// Parallel Bubble Sort (odd-even transposition sort)
void bubbleSortParallel(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        #pragma omp parallel for
        for (int j = (i % 2); j < n - 1; j += 2) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

// Merge function
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid+1, k = 0;

    while (i <= mid && j <= right)
        temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int i = 0; i < k; i++)
        arr[left + i] = temp[i];
}

// Sequential Merge Sort
void mergeSortSequential(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right)/2;
        mergeSortSequential(arr, left, mid);
        mergeSortSequential(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

// Parallel Merge Sort
void mergeSortParallel(vector<int>& arr, int left, int right, int depth = 0) {
    if (left < right) {
        int mid = (left + right)/2;

        if (depth < 4) { // avoid oversubscription
            #pragma omp parallel sections
            {
                #pragma omp section
                mergeSortParallel(arr, left, mid, depth+1);
                #pragma omp section
                mergeSortParallel(arr, mid+1, right, depth+1);
            }
        } else {
            mergeSortSequential(arr, left, mid);
            mergeSortSequential(arr, mid+1, right);
        }

        merge(arr, left, mid, right);
    }
}

int main() {
    const int SIZE = 5000;
    vector<int> original;
    generateArray(original, SIZE);

    vector<int> a1 = original, a2 = original;
    vector<int> a3 = original, a4 = original;

    double t1, t2;

    
    t1 = omp_get_wtime();
    bubbleSortSequential(a1);
    t2 = omp_get_wtime();
    cout << "Sequential Bubble Sort Time: " << t2 - t1 << "s\n";

    
    t1 = omp_get_wtime();
    bubbleSortParallel(a2);
    t2 = omp_get_wtime();
    cout << "Parallel Bubble Sort Time: " << t2 - t1 << "s\n";

    
    t1 = omp_get_wtime();
    mergeSortSequential(a3, 0, SIZE-1);
    t2 = omp_get_wtime();
    cout << "Sequential Merge Sort Time: " << t2 - t1 << "s\n";

   
    t1 = omp_get_wtime();
    mergeSortParallel(a4, 0, SIZE-1);
    t2 = omp_get_wtime();
    cout << "Parallel Merge Sort Time: " << t2 - t1 << "s\n";

    return 0;
}
