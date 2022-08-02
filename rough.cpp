#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool isValid(vector<vector<char>> &B, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (B[i][col] == c)
                return false;

            if (B[row][i] == c)
                return false;

            if (B[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &B)
    {
        for (int i = 0; i < B.size(); i++)
        {
            for (int j = 0; j < B[0].size(); j++)
            {
                if (B[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(B, i, j, c))
                        {
                            B[i][j] = c;
                            if (solve(B))
                                return true;
                            // BackTrack
                            else
                                B[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
    void printSoduko(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution S;
    cout << endl
         << "Before Solving: " << endl;
    S.printSoduko(board);
    S.solveSudoku(board);
    cout << endl
         << endl
         << endl
         << "After solving: " << endl;
    S.printSoduko(board);
    return 0;
}