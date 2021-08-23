/*Write a program to cylindrically rotate the array by one*/

#include <iostream>
using namespace std;

void Rotate(int arr[], int m)
{
    int temp = arr[m];

    int i = m - 1;
    while (i > 0)
    {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[i] = temp;

    cout << "The array after rotation is: ";
    for (int i = 0; i < m; i++)
        cout
            << arr[i] << " ";

    cout << endl;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int m = sizeof(arr) / sizeof(int);
    Rotate(arr, m);
    return 0;
}