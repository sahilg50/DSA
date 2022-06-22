#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {3, 1, 7, 9, 4, 5, 10, 6};
    int n = sizeof(arr) / sizeof(int);

    /*
    INTRO SORT
    In the sorting function, we define the starting index and the ending index + 1.
    */
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}