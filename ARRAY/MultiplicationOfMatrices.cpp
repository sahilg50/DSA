
//WAP to print the multiplication of two matrices.

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

    cout << "Enter the number of rows in matrix: ";
    int o;
    cin >> o;

    cout << endl
         << "Enter the number of columns in matrix: ";
    int p;
    cin >> p;

    int arr2[100][100];

    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < o; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cin >> arr2[i][j];
        }
    }

    //Printing the elements of the matrix.
    cout << endl;
    for (int i = 0; i < o; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    //Create a new matrix
    int arr3[100][100];

    int sum;
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < p; k++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += (arr1[i][j] * arr2[j][k]);
            }
            arr3[i][k] = sum;
        }
    }

    //Printing the elements of the matrix.
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}