#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string LPS(string s)
{
    string s1 = s, s2 = s;
    reverse(s2.begin(), s2.end());
    cout << s1 << endl
         << s2 << endl;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int maxLen = dp[n][n];
    string ans = "";
    for (int i = 0; i < maxLen; i++)
        ans.push_back('$');
    int index = maxLen - 1;
    int i = n, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans[index] = s1[i - 1];
            index--;
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    return ans;
}

int main()
{
    string s = "abab";
    cout << LPS(s);
    return 0;
}
/*
TC->O(N*N)
SC->O(N*N)
*/