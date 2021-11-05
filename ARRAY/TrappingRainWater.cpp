#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

int max_water(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    int maximum = INT16_MIN;
    while (left < right)
    {
        if (arr[left] <= arr[right])
        {
            maximum = max(maximum, arr[left] * (right - left));
            left++;
        }
        else
        {
            maximum = max(maximum, arr[right] * (right - left));
            right--;
        }
    }
    return maximum;
}

int main()
{

    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    int *arr = new int[n];
    cout << max_water(arr, n);
    return 0;
}