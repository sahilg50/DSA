// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k)
    {
        // Find the number of elements smaller than k
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
            {
                num++;
            }
        }

        /* Create a window with size = 'num' and slide this through entire array to find
        out the minimum number of elements that are greater than k. */

        int i = 0, j = num - 1, curr_swap = 0, min_swap = INT_MAX;

        for (int x = i; x <= j; x++)
            if (arr[x] > k)
                curr_swap++;

        min_swap = min(min_swap, curr_swap);

        i++, j++;
        while (j != n)
        {

            if (arr[i - 1] > k)
                curr_swap--;
            if (arr[j] > k)
                curr_swap++;

            min_swap = min(min_swap, curr_swap);
            i++, j++;
        }
        return min_swap;
    }

    /*
    TC: O(N)
    SC: O(1)
    */
};

// { Driver Code Starts.

// Driver code
int main()
{

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends