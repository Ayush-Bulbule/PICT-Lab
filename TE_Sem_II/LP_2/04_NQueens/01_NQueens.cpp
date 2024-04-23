#include<bits/stdc++.h>

using namespace std;

class N_Queens
{
    int **matrix;
    int size;
    public:
   
    N_Queens(int n)
    {
        size = n;
        matrix = new int*[size];
        for(int i=0;i<size;i++)
        {
            matrix[i] = new int[size];
        }
        init();
    }

    void init()
    {
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    void print()
    {
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(matrix[i][j])
                {
                    cout<<"Q"<<" ";
                }
                else
                {
                    cout<<"."<<" ";
                }
            }
            cout<<endl;
        }
    }

    bool isSafe(int row,int col)
    {
        int i,j;
        for(int i=0;i<col;i++)
        {
            if(matrix[row][i])
            {
                return false;
            }
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        {
            if(matrix[i][j])
            {
                return false;
            }
        }
        for(int i=row,j=col; j>=0 && i<size;i++,j--)
        {
            if(matrix[i][j])
            {
                return false;
            }
        }

        return true;

    }

    bool solve(int col)
    {
        // base case: If all queens are placed
        // then return true
        if(col >= size)
        {
            return true;
        }

        for(int i=0;i<size;i++)
        {
            //Check if the queen can be placed on board[i][col]
            if(isSafe(i,col))
            {
                // Place this queen in board[i][col]
                matrix[i][col] = 1;

                // recur to place rest of the queens
                if(solve(col+1))
                {
                    return true;
                }
                // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
                matrix[i][col] = 0;
            }
           
        }
        // If the queen cannot be placed in any row in this column col  then return false
        return false;

    }


};


int main()
{
    int n;
    cout<<"Enter N : ";
    cin>>n;
    N_Queens obj(n);
    bool ans = obj.solve(0);
   
   obj.print();
   


    return 0;
}        