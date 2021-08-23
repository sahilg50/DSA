#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(int);

    bubbleSort(arr, size);

    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}