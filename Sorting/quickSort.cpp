#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{

    int arr[] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, size - 1);

    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}

/*
The time coplexity fo this approach is O(nlogn)
*/