#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
private:
    long long mod = 1e9 + 7;

    /*
    f(n) = number of ways, people can ermain single or pair up
    For the n-th person there are 2 choices:
    1-> remain single and recur for f(n-1)
    2-> pair up with remaining n-1 persons. we get (n-1)*f(n-2)
    */
    long long util(int n, vector<long long> &dp)
    {
        if (n <= 0)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = (util(n - 1, dp) + (n - 1) * util(n - 2, dp)) % mod;
    }
    // we can also write tabulation for this

public:
    int countFriendsPairings(int n)
    {
        vector<long long> dp(n + 1, -1);
        return util(n, dp);
    }
    /*
    TC-> O(N)
    SC-> Recursion stack:O(N)ASC + DP:O(N)
    */
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}
