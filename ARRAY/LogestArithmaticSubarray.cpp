/*An arithmetic array is an array that contains at least two integers and the differences between consecutive integers are equal. For example, [9, 10], [3, 3, 3], and [9, 7, 5, 3] are arithmetic arrays, while [1, 3, 3, 7], [2, 1, 2], and [1, 2, 4] are not arithmetic arrays.

Sarasvati has an array of N non-negative integers. The i-th integer of the array is Ai. She wants to choose a contiguous arithmetic subarray from her array that has the maximum length. Please help her to determine the length of the longest contiguous arithmetic subarray.*/

#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array!: ";
    cin >> n;
    int *arr = new int[n];

    cout << "Enter the elements of the array!" << endl;
    //input the array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //previous commmon difference
    int pd = arr[1] - arr[0];

    //current arithmetic subarray length;
    int curr = 2;

    //max arithmatic subarray length
    int ans = 2;

    for (int i = 2; i < n; i++)
    {
        if (pd == arr[i] - arr[i - 1])
        {
            curr++;
        }
        else
        {
            pd = arr[i] - arr[i - 1];
            curr = 2;
        }
        ans = max(ans, curr);
    }
    cout << endl
         << ans << endl;
    return 0;
}