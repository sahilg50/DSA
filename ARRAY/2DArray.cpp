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

    int x;
    cout << "Enter the key to searched: ";
    cin >> x;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == x)
            {
                cout << "Found! ";
                break;
            }
        }
    }

    return 0;
}