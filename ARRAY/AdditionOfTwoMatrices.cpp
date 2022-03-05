#include <iostream>
using namespace std;

#define m 3
#define n 3

int main()
{
    int A1[m][n];
    // Storing the elements in the array
    cout << "\nEnter the elements in the 1st matrix: ";
    int val;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> val;
            A1[i][j] = val;
        }
    }

    int A2[m][n];
    // Storing the elements in the array
    cout << "\nEnter the elements in the 2nd matrix: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> val;
            A2[i][j] = val;
        }
    }

    // Adding the two matrices by storing the elements in the third array
    int A3[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A3[i][j] = A1[i][j] + A2[i][j];
        }
    }

    // Print the elements of the final summed up array
    cout << "Final summed up array: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A3[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}