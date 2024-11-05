/**
 * Problem Statement: Design n-Queens matrix having first Queen placed. Use backtracking to placeremainingQueens to generate the final n-queen
 */

#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n ){

    // check for column
    for(int i = 0;i<row;i++)
        if(board[i][col]=='Q')
            return false;
    
    // check for left diagonal
    for(int i = row, j= col; i>=0 && j>=0;i--, j--){
        if(board[i][j]=='Q')
            return false;
    }

    // cehck for the right 
    for(int i = row, j = col; i>=0 && j < n; i--, j++){
        if(board[i][j]=='Q')
            return false;
    }

    return true;
}
void printBoard(vector<string> board){
   for(string row:board){
    cout<<row<<endl;
   }
   cout<<endl;
}
void solveNQueens(vector<vector<string>> &res, vector<string> &board, int row,  int n){

    // If all queens are placed, add board to result
    if(row == n){
        res.push_back(board);
        return;
    }

    // check for each column in current row
    for(int col = 0;col<n; col++){
        if(isSafe(board, row, col, n)){
            board[row][col]='Q';
            // printBoard(board); // uncomment this to test
            solveNQueens(res, board, row+1, n);
            board[row][col] = '.';
        }
    }
}

int main(){


    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));

    solveNQueens(res, board, 0, n);

    for(vector<string> board: res){
        printBoard(board);
    }

    return 0;
}