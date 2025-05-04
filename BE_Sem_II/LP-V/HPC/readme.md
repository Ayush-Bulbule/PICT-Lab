# High Performance Computing (HPC) Assignments

High Performance Computing (HPC) is the use of parallel processing techniques for running advanced application programs efficiently, reliably, and quickly. It involves leveraging the power of multiple processors or computing resources simultaneously to solve complex computational problems.


## 🛠️ Environment Setup

### OpenMP

OpenMP is an API that supports multi-platform shared-memory multiprocessing programming in C, C++, and Fortran. It enables the development of parallel applications by using simple compiler directives.

#### 🔧 Steps to Setup OpenMP

1. Install GCC with OpenMP support:
   ```bash
   brew install gcc
   ```
2. Compile your code with OpenMP support:
   ```bash
    g++-14 -fopenmp -o my_program my_program.c
    ```
3. Run your program:
   ```bash
   ./my_program
   ```


### CUDA (Compute Unified Device Architecture)
CUDA is a parallel computing platform and application programming interface (API) model created by NVIDIA. It allows developers to use a CUDA-enabled graphics processing unit (GPU) for general-purpose processing.

To enable GPPU runtime in Google colab -

1. Sign in with a Google account and open Colab
2. Runtime > Change Runtime Type > T4 GPU


```python
!apt-get install -y nvidia-cuda-toolkit
```

## 📋 Assignments List

| Sr. No | Assignment Title            | Description |
|--------|-----------------------------|-------------|
| 1      | **Parallel DFS & BFS**      | Design and implement Parallel Breadth First Search and Depth First Search using OpenMP. Use a Tree or an undirected graph. Measure the performance of sequential and parallel algorithms. |
| 2      | **Parallel Sorting**        | Implement Parallel Bubble Sort and Merge Sort using OpenMP. Measure and compare the performance of sequential and parallel implementations. |
| 3      | **Parallel Reduction**      | Implement Min, Max, Sum, and Average operations using Parallel Reduction. Measure and compare performance with sequential equivalents. |
| 4      | **CUDA Programming**        | Write CUDA programs for: 1) Addition of two large vectors, 2) Matrix Multiplication using CUDA C. Compare performance of sequential and parallel implementations. |
