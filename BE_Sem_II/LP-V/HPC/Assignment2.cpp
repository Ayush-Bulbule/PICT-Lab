#include <bits/stdc++.h>
#include <omp.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Parallel Bubble Sort using Odd-Even Transposition Sort
void parallelBubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
#pragma omp parallel for
        for (int j = (i % 2); j < n - 1; j += 2)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Standard Bubble Sort
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void merge(vector<int> arr, int l, int m, int r)
{
    // Merge function for merge sort
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    // Merge sort function
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void parallelMergeSort(vector<int> &arr, int l, int r)
{
    // Parallel merge sort function
    if (l < r)
    {
        int m = l + (r - l) / 2;
#pragma omp parallel sections
        {
#pragma omp section
            mergeSort(arr, l, m);
#pragma omp section
            mergeSort(arr, m + 1, r);
        }
        merge(arr, l, m, r);
    }
}

int main()
{
    const int size = 10000; // Size of the array
    vector<int> arr(size), arr_copy(size);

    // Initialize array with random values
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 1000;
        arr_copy[i] = arr[i];
    }

    // Sequential bubble sort
    auto start = high_resolution_clock::now();
    bubbleSort(arr);
    auto stop = high_resolution_clock::now();
    auto seq_time = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by sequential bubble sort: " << seq_time.count() << " ms" << endl;

    // Parallel bubble sort
    start = high_resolution_clock::now();
    parallelBubbleSort(arr_copy);
    stop = high_resolution_clock::now();
    auto par_time = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by parallel bubble sort: " << par_time.count() << " ms" << endl;

    start = high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
    stop = high_resolution_clock::now();
    auto seq_time_merge = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by sequential merge sort: " << seq_time_merge.count() << " ms" << endl;

    start = high_resolution_clock::now();
    parallelMergeSort(arr_copy, 0, size - 1);
    stop = high_resolution_clock::now();
    auto par_time_merge = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by parallel merge sort: " << par_time_merge.count() << " ms" << endl;

    return 0;
}
