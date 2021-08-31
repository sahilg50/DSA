/*
Given a nxm matrix.
Write an algorithm to find that the given value exists in the matrix or not.
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Constraints
1 <= N,M <= 1,000

Sample Test Case:
Consider the following matrix:
[
[1, 4, 7, 11, 15],
[2, 5, 8, 12, 19],
[3, 6, 9, 16, 22],
[10, 13, 14, 17, 24],
[18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Enter the number of rows in matrix: ";
    int m;
    cin >> m;

    cout << endl
         << "Enter the number of columns in matrix: ";
    int n;
    cin >> n;

    int arr1[100][100];

    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr1[i][j];
        }
    }

    //Printing the elements of the matrix.
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    int key;
    cout << "Enter the key to be searched: ";
    cin >> key;

    // Starting from top right
    int c = n - 1;
    int r = 0;
    while (0 <= r < m && 0 <= c < n)
    {
        if (arr1[r][c] == key)
        {
            cout << "Target Found!" << endl;
            break;
        }
        else if (key > arr1[r][c])
        {
            r++;
        }
        else if (key < arr1[r][c])
        {
            c--;
        }
        else
        {
            cout << "Target Not Found!";
        }
    }

    return 0;
}