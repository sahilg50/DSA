#include <iostream>
using namespace std;

int fisrtMissingPositiveInteger(int arr[], int n)
{
    // Step 1. Mark Element which are out of range and manage the presence of one
    bool one = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            one = true;
        else if (arr[i] < 1 || arr[i] > n)
            arr[i] = 1;
    }
    if (one == false)
        return 1;

    // Step 2. Map the elements with index
    for (int i = 0; i < n; i++)
    {
        int ind = abs(arr[i]);
        arr[ind - 1] = -1 * abs(arr[ind - 1]);
    }

    // Step 3. Find out the missing integer
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            return i + 1;
    }
    return n + 1;
}

int main()
{
    int arr[] = {1, 2, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    cout << fisrtMissingPositiveInteger(arr, n);
    return 0;
}