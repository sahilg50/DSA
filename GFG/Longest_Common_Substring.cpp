#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    // Approach 1-> Tabulation
    int lcsTabulation(string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
    /*
    TC-> O(n*m)
    SC-> DP Array: O(n*m)
    */

    // Approach 2-> Recursion
    int lcsRecur(int i, int j, string S1, string S2, int count)
    {
        if (i == 0 || j == 0)
            return count;

        int match = 0, notMatch = 0;
        if (S1[i - 1] == S2[j - 1])
        {
            count = lcsRecur(i - 1, j - 1, S1, S2, count + 1);
        }
        count = max(count, max(lcsRecur(i, j - 1, S1, S2, 0), lcsRecur(i - 1, j, S1, S2, 0)));

        return count;
    }
    /*
    TC-> O(2^n * 2^m)
    SC-> O(max(n,m))
    */
};

int main()
{
    string S1 = "Maninin";
    string S2 = "Manan";
    int n = S1.size();
    int m = S2.size();
    Solution s;
    cout << endl
         << s.lcsTabulation(S1, S2, n, m);
    cout << endl
         << s.lcsRecur(n, m, S1, S2, 0);
    return 0;
}
