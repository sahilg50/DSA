/*Write a program to cylindrically rotate the array by k times*/

#include <iostream>
using namespace std;

/*This is a recursive function that is used to rotate the array.*/
int RotateByK(int arr[], int m, int K, int count)
{

    if (count == K)
        return 0;

    int temp = arr[m - 1];

    int i = m - 1;
    while (i > 0)
    {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[i] = temp;

    return RotateByK(arr, m, K, count += 1);
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int m = sizeof(arr) / sizeof(int);

    int K;
    cout << "Enter the number of times you want to rotate the array: ";
    cin >> K;

    RotateByK(arr, m, K, 0);

    cout << "The array after rotation is: ";
    for (int i = 0; i < m; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}