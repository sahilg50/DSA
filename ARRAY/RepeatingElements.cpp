/*
Given an array arr[] of size n, find the first repeating element. The element should occurs more than once and the index of its first occurrence should be the smallest.

Expected Time Complexity: O(nlogn)
Expected Auxilliary Space: O(n)

 

Constraints:
1 <= n <= 106
0 <= Ai<= 106
*/
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];
    int minIdx = INT_MAX;

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    const int N = 1e6 + 2;
    int *idx = new int[N];

    for (int i = 0; i < N; i++)
        idx[i] = -1;

    for (int i = 0; i < n; i++)
    {
        if (idx[arr[i]] == -1)
        {

            idx[arr[i]] = i;
        }

        else
        {
            minIdx = min(minIdx, idx[arr[i]]);
        }
    }

    cout << minIdx;
    return 0;
}