// Print all the subarrays of the array.

#include <iostream>
using namespace std;

//functino ot print the subarrays of the array
void SubArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SubArray(arr, n);

    return 0;
}