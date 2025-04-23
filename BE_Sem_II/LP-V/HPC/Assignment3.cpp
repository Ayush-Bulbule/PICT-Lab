#include <bits/stdc++.h>
#include <omp.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int minval_sequential(const vector<int> &arr)
{
    int minval = arr[0];
    for (int val : arr)
    {
        if (val < minval)
            minval = val;
    }
    return minval;
}

int maxval_sequential(const vector<int> &arr)
{
    int maxval = arr[0];
    for (int val : arr)
    {
        if (val > maxval)
            maxval = val;
    }
    return maxval;
}

int sum_sequential(const vector<int> &arr)
{
    int sum = 0;
    for (int val : arr)
    {
        sum += val;
    }
    return sum;
}

double average_sequential(const vector<int> &arr)
{
    return static_cast<double>(sum_sequential(arr)) / arr.size();
}

int minval_parallel(const vector<int> &arr)
{
    int minval;
#pragma omp parallel for reduction(min : minval)
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0 || arr[i] < minval)
            minval = arr[i]; // ensures proper init
    }
    return minval;
}

int maxval_parallel(const vector<int> &arr)
{
    int maxval;
#pragma omp parallel for reduction(max : maxval)
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0 || arr[i] > maxval)
            maxval = arr[i];
    }
    return maxval;
}

int sum_parallel(const vector<int> &arr)
{
    int sum = 0;
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum;
}

double average_parallel(const vector<int> &arr)
{
    return static_cast<double>(sum_parallel(arr)) / arr.size();
}

int main()
{
    int n = 10000;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    auto start = high_resolution_clock::now();
    cout << "\nThe minimum value (sequential) is: " << minval_sequential(arr) << '\n';
    auto stop = high_resolution_clock::now();
    cout << "Time taken by sequential minval: "
         << duration_cast<microseconds>(stop - start).count() << " microseconds\n";

    start = high_resolution_clock::now();
    cout << "\nThe maximum value (sequential) is: " << maxval_sequential(arr) << '\n';
    stop = high_resolution_clock::now();
    cout << "Time taken by sequential maxval: "
         << duration_cast<microseconds>(stop - start).count() << " microseconds\n";

    start = high_resolution_clock::now();
    cout << "\nThe summation (sequential) is: " << sum_sequential(arr) << '\n';
    stop = high_resolution_clock::now();
    cout << "Time taken by sequential sum: "
         << duration_cast<microseconds>(stop - start).count() << " microseconds\n";

    start = high_resolution_clock::now();
    cout << "\nThe average (sequential) is: " << average_sequential(arr) << '\n';
    stop = high_resolution_clock::now();
    cout << "Time taken by sequential average: "
         << duration_cast<microseconds>(stop - start).count() << " microseconds\n";

    start = high_resolution_clock::now();
    cout << "\nThe minimum value (parallel) is: " << minval_parallel(arr) << '\n';
    stop = high_resolution_clock::now();
    cout << "Time taken by parallel minval: "
         << duration_cast<microseconds>(stop - start).count() << " microseconds\n";

    start = high_resolution_clock::now();
    cout << "\nThe maximum value (parallel) is: " << maxval_parallel(arr) << '\n';
    stop = high_resolution_clock::now();
    cout << "Time taken by parallel maxval: "
         << duration_cast<microseconds>(stop - start).count() << " microseconds\n";

    start = high_resolution_clock::now();
    cout << "\nThe summation (parallel) is: " << sum_parallel(arr) << '\n';
    stop = high_resolution_clock::now();
    cout << "Time taken by parallel sum: "
         << duration_cast<microseconds>(stop - start).count() << " microseconds\n";

    start = high_resolution_clock::now();
    cout << "\nThe average (parallel) is: " << average_parallel(arr) << '\n';
    stop = high_resolution_clock::now();
    cout << "Time taken by parallel average: "
         << duration_cast<microseconds>(stop - start).count() << " microseconds\n";

    return 0;
}
