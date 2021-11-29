#include <iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n)
{
    //You can check for the column
    for (int row = 0; row < i; row++)
    {
        if (board[row][j] == 1)
            return false;
    }

    // You can check for left diagonal
    int x = i, y = j;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        else
            x--, y--;
    }

    //You can check for the right diagonal
    x = i, y = j;
    while (x >= 0 && y < n)
    {
        if (board[x][y] == 1)
            return false;
        else
            x--, y++;
    }
    return true;
}

bool solveNQueen(int board[][10], int i, int n)
{
    //base case
    if (i == n)
    {
        //You have successfully paced the queens in n rows(0...n-1)
        //Print the board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl
             << endl;
        return true; //change this to false if you want all the configurations
    }

    //recurcive call
    //Try ot place the queen in the current row and call on the remaining part which will be solved by recursion.
    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, i, j, n))
        {
            //place the queen assuming i, j is the right position
            board[i][j] = 1;

            bool nextQueenRakhPaye = solveNQueen(board, i + 1, n);
            if (nextQueenRakhPaye)
            {
                return true;
            }
            else
                board[i][j] = 0; //backtrack
        }
    }
    // You have checked for all the rows but you could not place the queen anywhere
    return false;
};

int main()
{
    int n;
    int board[10][10] = {0};
    solveNQueen(board, 0, 4);
    return 0;
}