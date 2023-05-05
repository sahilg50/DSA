#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

// Using tabulation method to form the dp table and then using it to print the lcs string.
string lcs(const string &s, const string &t)
{
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {

            if (i >= n || j >= m)
                dp[i][j] = 0;

            else if (s[i] == t[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];

            else
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    // cout << dp[0][0];

    string ans = "";
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            ans.push_back(s[i]);
            i++, j++;
        }
        else if (dp[i][j + 1] > dp[i + 1][j])
            j++;
        else
            i++;
    }
    return ans;
}

int main()
{
    cout << lcs("sahil", "shl");
    return 0;
}