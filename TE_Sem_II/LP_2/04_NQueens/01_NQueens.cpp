#include <iostream>
using namespace std;

int cnt = 1;

void display(bool board[][12], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

int queenB(bool board[][12], int row, int n)
{
    // base case
    if (row == n)
    {
        display(board, n);
        cout << endl;
        return 1;
    }

    // conditional cases
    int count = 0;

    for (int col = 0; col < n; col++) // bekkar main loop
    {
        bool safe = true;

        // check vertical safe
        for (int i = 0; i < row; i++)
        {
            if (board[i][col])
            {
                safe = false;
                break;
            }
        }

        // check letf horizontal safe
        int leftShift = min(row, col);
        for (int i = 1; i <= leftShift; i++)
        {
            if (board[row - i][col - i])
            {
                safe = false;
                break;
            }
        }

        // check right horizontal safe
        int rightShift = min(row, n - col - 1);
        for (int i = 1; i <= rightShift; i++)
        {
            if (board[row - i][col + i])
            {
                safe = false;
                break;
            }
        }

        if (safe)
        {
            board[row][col] = true;
            display(board, n);
            count += queenB(board, row + 1, n);
            board[row][col] = false;
        }
    }

    return count;
}

void backTrackQueen(int n)
{
    bool board[12][12] = {{false}};
    int noOfPossibleSol = queenB(board, 0, n);
    cout << "Possible solutions = " << noOfPossibleSol << endl;
}

void queensBNB(bool board[][12], int row, bool colAttacked[], bool leftDiagonalAttacked[], bool rightDiagonalAttacked[], int n)
{
    // base case
    if (row == n)
    {
        cout << "Final: " << cnt << endl;
        cnt += 1;
        display(board, n);
        return;
    }

    // conditions

    for (int col = 0; col < n; col++)
    {
        if (!colAttacked[col] && !leftDiagonalAttacked[row + col] && !rightDiagonalAttacked[row - col + n - 1])
        {
            board[row][col] = true;
            colAttacked[col] = true;
            leftDiagonalAttacked[row + col] = true;
            rightDiagonalAttacked[row - col + n - 1] = true;

            queensBNB(board, row + 1, colAttacked, leftDiagonalAttacked, rightDiagonalAttacked, n);

            board[row][col] = false;
            colAttacked[col] = false;
            leftDiagonalAttacked[row + col] = false;
            rightDiagonalAttacked[row - col + n - 1] = false;
        }
    }
}

void branchAndBound(int n)
{
    bool board[12][12] = {{false}};
    bool colAttacked[12] = {false};
    bool leftDiagonalAttacked[2 * 12 - 1] = {false};
    bool rightDiagonalAttacked[2 * 12 - 1] = {false};
    queensBNB(board, 0, colAttacked, leftDiagonalAttacked, rightDiagonalAttacked, n);
}

int main()
{
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    if (n < 4)
    {
        cout << "No possible solutions" << endl;
        return 0;
    }

    bool flag = true;

    while (flag)
    {
        cout << "\n1. Back-Track\n";
        cout << "2. Branch and Bound\n";
        cout << "3. Exit\n";

        int ch;
        cout << "\nEnter Your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            backTrackQueen(n);
            break;

        case 2:
            branchAndBound(n);
            break;

        case 3:
            flag = false;
            break;

        default:
            flag = false;
            break;
        }
    }

    return 0;
}