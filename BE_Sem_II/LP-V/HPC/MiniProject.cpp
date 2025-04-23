#include <mpi.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Function to perform quicksort on a vector
void quicksort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    if (left < j) quicksort(arr, left, j);
    if (i < right) quicksort(arr, i, right);
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const int N = 1000000; // Total number of elements
    std::vector<int> data;
    int local_n = N / size;
    std::vector<int> local_data(local_n);

    if (rank == 0) {
        // Initialize the data with random integers
        data.resize(N);
        std::srand(static_cast<unsigned>(std::time(0)));
        for (int i = 0; i < N; ++i) {
            data[i] = std::rand();
        }
    }

    // Scatter the data to all processes
    MPI_Scatter(data.data(), local_n, MPI_INT,
                local_data.data(), local_n, MPI_INT,
                0, MPI_COMM_WORLD);

    // Each process sorts its local data
    quicksort(local_data, 0, local_n - 1);

    // Gather the sorted subarrays back to the root process
    MPI_Gather(local_data.data(), local_n, MPI_INT,
               data.data(), local_n, MPI_INT,
               0, MPI_COMM_WORLD);

    if (rank == 0) {
        // Final merge step (if necessary)
        // Since each subarray is sorted, we can perform a k-way merge
        // For simplicity, we'll use std::inplace_merge iteratively
        for (int i = 1; i < size; ++i) {
            std::inplace_merge(data.begin(), data.begin() + i * local_n, data.begin() + (i + 1) * local_n);
        }

        // Output the first 10 sorted elements as a sample
        std::cout << "First 10 sorted elements:\n";
        for (int i = 0; i < 10; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    MPI_Finalize();
    return 0;
}
