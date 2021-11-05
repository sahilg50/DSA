/*This problem is solved using dynamic prgramming (DP)
The brute force solution would be to find all the substrings and then check for the palindromic substrings. In this approach the time complexity would be O(n^3).
The Optimal solution would be using the dynamic programming approach and in this case the time complexity would be O(n^2) where n is the size of the string. The space complexity is also O(n^2).
There is also a 3rd approach and that takes O(n^2) time complexity and and a constant space complexity.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void printSubStr(string str, int low, int high)
{
    for (int i = low; i < high; i++)
    {
        cout << str[i] << "";
    }
    cout << endl;
}

//Using DP
int longestSubString(string str)
{
    int n = str.size();
    //default elements of the table dp is -1
    // dp[i][j] will be 0 if substring str[i..j] is not palindrome.
    // Else dp[i][j] will be 1
    vector<vector<int>> dp(n, vector<int>(n, -1));

    //All the substrings of length 1 palindrome
    int maxlength = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            dp[i][i + 1] = 1;
            maxlength = 2;
            start = i;
        }
        else
        {
            dp[i][i + 1] = 0;
        }
    }

    // Check for lengths greater than 2.
    // k is length of substring
    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;

            if (dp[i + 1][j - 1] && str[i] == str[j])
            {
                dp[i][j] = 1;

                if (k > maxlength)
                {
                    start = i;
                    maxlength = k;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "Longest palindromw substring is: " << endl;
    printSubStr(str, start, start + maxlength);

    return maxlength;
}

int main()
{
    string str = "geeksababageeks";
    cout << longestSubString(str);
    return 0;
}

//3Rd Approach
string longestPalindrome(string s)
{
    if (s.length() < 1)
        return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = max(len1, len2);
        if (len > end - start)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end + 1);
}

int expandAroundCenter(string s, int left, int right)
{
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s.at(L) == s.at(R))
    {
        L--;
        R++;
    }
    return R - L - 1;
}