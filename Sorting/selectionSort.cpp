#include <iostream>
#include <algorithm>

using namespace std;

void selectionSort(int arr[], int n)
{
    int min_idx;

    for (int i = 0; i < n - 1; i++)
    {

        min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        swap(arr[i], arr[min_idx]);
    }
};

int main()
{

    int arr[] = {19, 3, 5, 3, 5, 9, 0, 10, 6};
    int size = sizeof(arr) / sizeof(int);

    selectionSort(arr, size);

    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}