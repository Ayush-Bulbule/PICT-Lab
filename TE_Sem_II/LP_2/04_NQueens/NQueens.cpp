/**
 * Problrm Statement:Implement a solution for a Constraint Satisfaction Problem using Branch and Bound;
 * and Backtracking for n-queens problem OR a graph coloring problem.
 *
 * Selected: N-Queens Problem
 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// Function to check if a queen can be placed at a given position
bool isSafe(vector<string> &board, int row, int col, int n)
{
    // Check for the column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check for the left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Check for the right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

// Function to print the N-Queens board
void printBoard(vector<string> &board)
{
    for (string row : board)
    {
        cout << row << endl;
    }
    cout << endl;
}

// Function to solve the N-Queens problem
void solveNQueens(vector<vector<string>> &res, vector<string> &board, int row, int n)
{
    // If all queens are placed, add the board to the result
    if (row == n)
    {
        res.push_back(board);
        return;
    }

    // Check for each column in the current row
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            // Place the queen then print each decision and a line after each wrong path
            board[row][col] = 'Q';
            printBoard(board);
            solveNQueens(res, board, row + 1, n);
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));

    solveNQueens(res, board, 0, n);

    for (vector<string> board : res)
    {
        printBoard(board);
    }

    return 0;
}
