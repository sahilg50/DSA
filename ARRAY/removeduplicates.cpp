#include <iostream>

using namespace std;

int removesduplicates(int num[], int n)
{
    int *temp = new int[n];
    int j = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (num[i] != num[i + 1])
        {
            temp[j++] = num[i];
        }
    }

    temp[j++] = num[n - 1];

    for (int i = 0; i < j; i++)
    {
        num[i] = temp[i];
    }

    return j;
}

int main()
{
    int arr[] = {1, 1, 1, 2, 3, 3, 3, 4, 5, 5, 6, 7};
    const int n = 12;
    int j = removesduplicates(arr, n);

    for (int i = 0; i < j; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}