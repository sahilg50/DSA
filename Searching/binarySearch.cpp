#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n)
{
    int temp[n];

    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            temp[j++] = arr[i];
        }
    }

    temp[j++] = arr[n - 1];

    for (int i = 0; i < j; i++)
        arr[i] = temp[i];

    return j;
}

int main()
{
    int num[] = {1, 1, 2, 2, 5, 6};
    int size = 6;

    int newsize = removeDuplicates(num, size);

    for (int i = 0; i < newsize; i++)
    {
        cout << num[i] << " ";
    }

    return 0;
}