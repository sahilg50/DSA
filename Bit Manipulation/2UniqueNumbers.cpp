/* write a program to find 2 u nique numbers in the array where all the number except two are present twice*/

#include <iostream>
using namespace std;

//Function to find the unique number
int unique(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    return xorsum;
}

int main()
{
    //Enter the size of the array
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    //Input the elements of the array
    int *arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //Calling the unique function
    cout << unique(arr, n);

    return 0;
}