// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {

        /*
        The steps to solve the problem are as follows:
        - It's like a sliding window problem but inly after sorting.
        - Step 1: Sort the array
        - Step 2: The size of the window is equal to the number of students.
        - Step 3: Slide the window through the array and find the min difference between the
                  firt and the last element of the window.
        - Maintain a global min and indices and keep updating them.
        */

        //Sorting the vector
        sort(a.begin(), a.end());

        long long int currDiff, minDiff = INT_MAX;
        long long int start, end;

        long long int i = 0, j = m - 1; //Sliding window
        while (j != n)
        {
            currDiff = a[j] - a[i];
            minDiff = min(currDiff, minDiff);
            j++;
            i++;
        }
        return minDiff;
    }
};

// { Driver Code Starts.
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a;
        long long x;
        for (long long i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        long long m;
        cin >> m;
        Solution ob;
        cout << ob.findMinDiff(a, n, m) << endl;
    }
    return 0;
} // } Driver Code Ends