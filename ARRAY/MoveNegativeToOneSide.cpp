/*Move all negative numbers to beginning and positive to end with constant extra space*/

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shifting(int arr[], int n)
{

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(&arr[i], &arr[j]);
            j++;
        }
    }
}

int main()
{
    int arr[] = {-9, 4, -8, 3, -20, 5, 32, 5, 2, 5};

    int length = sizeof(arr) / sizeof(int);

    shifting(arr, length);

    cout << "The sorted array is: ";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}