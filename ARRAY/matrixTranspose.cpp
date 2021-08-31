//Write a function to return the transpose of the matrix

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Enter the number of rows and columns of the square matrix: ";
    int m;
    cin >> m;

    int arr[100][100];

    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    //Printing the elements of the matrix.
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //Taking the transpose.
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {

            swap(arr[i][j], arr[j][i]);
        }
    }

    //Printing the elements of the matrix.
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}