//Print the matrix in spiral order

#include <iostream>

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

    int arr[100][100];

    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "The matrix is: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int row_start = 0;
    int row_end = m - 1;
    int column_start = 0;
    int column_end = n - 1;

    while (row_start <= row_end && column_start <= column_end)
    {
        //for starting row
        for (int col = column_start; col <= column_end; col++)
        {
            cout << arr[row_start][col] << " ";
        }

        //for last column
        for (int row = row_start + 1; row <= row_end; row++)
        {
            cout << arr[row][column_end] << " ";
        }

        //for last row
        for (int col = column_end - 1; col >= column_start; col--)
        {
            cout << arr[row_end][col] << " ";
        }

        //for first col
        for (int row = row_end - 1; row > row_start; row--)
        {
            cout << arr[row][column_start] << " ";
        }

        row_start++;
        row_end--;
        column_start++;
        column_end--;
    }

    return 0;
}