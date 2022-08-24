#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Using Recursion
int LCS_Recursion(string &s1, string &s2, int m, int n)
{

    if (m == 0 || n == 0)
        return 0;

    else if (s1[m - 1] == s2[n - 1])
        return 1 + LCS_Recursion(s1, s2, m - 1, n - 1);

    else
    {
        return max(LCS_Recursion(s1, s2, m - 1, n), LCS_Recursion(s1, s2, m, n - 1));
    }
}
/*
TC-> O(2^n * 2^m)
SC-> Recursion stack: O(n+m)
*/

// Using Tabular form
int LCS_Tabular(string s1, string s2)
{

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }
    return dp[n][m];
}
/*
TC-> O(n*m)
SC-> DP array: O(n*m)
*/

// Tabulation with Space Optimization
int LCS_Tabular_Space_Optimization(string s1, string s2)
{

    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Base Case is covered as we have initialized the prev and cur to 0.

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1];
            else
                cur[ind2] = 0 + max(prev[ind2], cur[ind2 - 1]);
        }
        prev = cur;
    }

    return prev[m];
}
/*
TC-> O(n*m)
SC-> prev: O(m) + curr: O(m)
*/

// Using Tabular form to print the LCS string
string LCS_Tabular_string(string s1, string s2)
{

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    int len = dp[n][m];
    int i = n;
    int j = m;

    int index = len - 1;
    string str = "";
    for (int k = 1; k <= len; k++)
    {
        str += "$"; // dummy string
    }

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            str[index] = s1[i - 1];
            index--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }

        else
            j--;
    }
    return str;
}
/*
TC-> O(n*m)
SC-> DP array: O(n*m)
*/

int main()
{
    string a = "Yahil";
    string b = "YaRahil";

    cout << LCS_Recursion(a, b, a.length(), b.length()) << endl;
    cout << LCS_Tabular(a, b) << endl;
    cout << LCS_Tabular_Space_Optimization(a, b) << endl;
    cout << LCS_Tabular_string(a, b) << endl;
    return 0;
}