/**
 * Problem Statement: Implement N-Queens problem using backtracking and branch and bound.
 */

#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to check if a queen can be placed at a given position
bool isSafe(vector<string> &board, int row, int col, int n) {
    // Check for the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check for the left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    // Check for the right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

// Function to print the N-Queens board
void printBoard(vector<string> &board) {
    for (string row : board) {
        cout << row << endl;
    }
    cout << endl;
}

// Function to solve the N-Queens problem
void solveNQueens(vector<vector<string>> &res, vector<string> &board, int row, int n) {
    // If all queens are placed, add the board to the result
    if (row == n) {
        res.push_back(board);
        printBoard(board);
        return;
    }

    // Check for each column in the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            // Place the queen then print each decision and a line after each wrong path
            board[row][col] = 'Q';
            printBoard(board);
            solveNQueens(res, board, row + 1, n);
            board[row][col] = '.';
        }
    }
}

// Optimal Solution for N-Queens Problem (Added Branch and Bound)
void solveNQueensOptimal(vector<vector<string>> &res, vector<string> &board, int row, int n, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal) {
    if (row == n) {
        res.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (leftRow[col] == 0 && upperDiagonal[row + col] == 0 && lowerDiagonal[n - 1 + col - row] == 0) {
            board[row][col] = 'Q';
            leftRow[col] = 1;
            upperDiagonal[row + col] = 1;
            lowerDiagonal[n - 1 + col - row] = 1;

            solveNQueensOptimal(res, board, row + 1, n, leftRow, upperDiagonal, lowerDiagonal);

            board[row][col] = '.';
            leftRow[col] = 0;
            upperDiagonal[row + col] = 0;
            lowerDiagonal[n - 1 + col - row] = 0;
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));

    // For Optimal Solution
    vector<int> leftRow(n, 0);
    vector<int> upperDiagonal(2 * n - 1, 0);
    vector<int> lowerDiagonal(2 * n - 1, 0);

    solveNQueens(res, board, 0, n);

    cout << "All possible solutions for N-Queens problem are: " << endl;

    for (vector<string> board : res) {
        printBoard(board);
    }

    res.clear();
    // Optimal Solution
    solveNQueensOptimal(res, board, 0, n, leftRow, upperDiagonal, lowerDiagonal);

    cout << "All possible solutions for N-Queens problem are: " << endl;

    for (vector<string> board : res) {
        printBoard(board);
    }

    return 0;
}