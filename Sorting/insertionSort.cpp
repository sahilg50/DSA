#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i--)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    int arr[] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(int);

    insertionSort(arr, size);

    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}