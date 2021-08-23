/* Find the Kth maximum and minimum array in an array*/

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j < r; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
        }
        i++;
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int KthSmallest(int arr[], int l, int r, int k)
{
    if (l == r)
    {
        return arr[l];
    }

    int pos = partition(arr, l, r);

    if (pos - l == k - 1)
    {
        return arr[pos];
    }

    else if (pos - l > k - 1)
    {
        return KthSmallest(arr, l, pos - 1, k);
    }

    return KthSmallest(arr, pos + 1, r, k - pos + l - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n = sizeof(arr) / sizeof(int);

    int k;
    cout << "Enter the value of K: ";
    cin >> k;

    int answer = KthSmallest(arr, 0, n, k);
    cout << answer;
}