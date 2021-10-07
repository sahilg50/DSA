// Write a program to merge two sorted arrays.
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{

    int arr1[] = {1, 3, 5, 7, 9};
    int m = sizeof(arr1) / sizeof(int);

    int arr2[] = {2, 4, 6, 8};
    int n = sizeof(arr2) / sizeof(int);

    int *merge_arr = new int[m + n];

    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            merge_arr[k++] = arr1[i++];
        }
        else if (arr1[i] > arr2[j])
        {
            merge_arr[k++] = arr2[j++];
        }
    }

    while (i < m)
    {
        merge_arr[k++] = arr1[i++];
    }
    while (j < n)
    {
        merge_arr[k++] = arr2[j++];
    }

    for (int i = 0; i < m + n; i++)
    {
        cout << merge_arr[i] << " ";
    }

    return 0;
}