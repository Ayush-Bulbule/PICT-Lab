### NQueens 
Design n-Queens matrix having the first Queen placed. Use backtracking to place remaining Queens and generate the final n-Queen matrix.


#### Working of the Code

1. **isSafe Function**: 
   - Checks if a queen can be placed in a given cell `(row, col)` without being attacked by other queens. It checks the column, left diagonal, and right diagonal.

2. **printBoard Function**: 
   - Prints the current state of the board, where `'Q'` represents a queen and `'.'` represents an empty cell.

3. **solveNQueens Function**:
   - This is the standard backtracking method for placing queens.
   - It recursively attempts to place queens in each row and checks for valid placements.
   - If a valid placement is found, it updates the board and calls itself for the next row.

4. **solveNQueensOptimal Function**:
   - This function implements the branch-and-bound approach.
   - It uses three additional arrays: `leftRow`, `upperDiagonal`, and `lowerDiagonal` to track which columns and diagonals are already occupied by queens.
   - This reduces the search space significantly and speeds up the process.

5. **main Function**:
   - Reads the size of the board (`n`).
   - Initializes the board and calls both the backtracking and the optimal functions to find and print all possible solutions.

#### Example Input and Output

**Example Input**:
```
Enter the value of n: 4
```

**Example Output**:
```
All possible solutions for N-Queens problem are: 

. . Q .
Q . . .
. . . Q
. Q . .

All possible solutions for N-Queens problem are: 
. . Q .
Q . . .
. . . Q
. Q . .
```

#### Time Complexity

1. **Backtracking Method**:
   - In the worst case, the time complexity is **O(n!)** because we try to place queens in every row and the placement in each column might lead to a valid configuration.
   - Each configuration could potentially require checking up to \(n\) rows and \(n\) columns.

2. **Branch and Bound Method**:
   - The time complexity is improved to approximately **O(n!)**, but the exact complexity depends on the number of valid placements available at each step, which can reduce the effective branching factor.

#### Space Complexity

1. **Both Methods**:
   - The space complexity is **O(n)** for the board, where `n` is the size of the board (number of rows or columns).
   - In the optimal method, additional arrays (`leftRow`, `upperDiagonal`, and `lowerDiagonal`) of size \(n\) and \(2n - 1\) are used, leading to a total space complexity of **O(n)**.

#### Conclusion
This implementation of the N-Queens problem efficiently explores the solution space using backtracking and an optimal approach with branch and bound. The choice of approach affects the performance, especially for larger values of `n`. The basic backtracking method provides a straightforward solution, while the branch-and-bound technique enhances efficiency significantly.