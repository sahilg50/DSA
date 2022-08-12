/*
AIRBNB:
For a given string s and an integer k, find the maximum number of palindrome substrings that can be formed such that no two substrings should overlap each other and the length of each substring should be greater than or equal to k.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
private:
    vector<int> dp;
    bool isPalindrome(int L, int H, string &str)
    {
        while (L < H)
        {
            if (str[L] != str[H])
                return false;
            L++, H--;
        }
        return true;
    }

    int util(int start, int k, string &str, int n)
    {
        if (start >= n)
            return 0;

        if (dp[start] != -1)
            return dp[start];

        int maxi = 0;
        for (int K = k; K < n; K++)
        {
            int currMax = 0;
            for (int i = start; i < n; i++)
            {
                if (isPalindrome(i, i + K - 1, str))
                    currMax = max(currMax, 1 + util(i + K, k, str, n));

                else
                    currMax = max(currMax, util(i + K, k, str, n));
            }
            maxi = max(maxi, currMax);
        }

        return dp[start] = maxi;
    }

public:
    int maxPaliSubStrings(string &str, int k)
    {
        int n = str.size();
        this->dp.resize(n, -1);
        return util(0, k, str, str.size());
    }
};

int main()
{
    string str = "ababaeocco";
    Solution S;
    cout << S.maxPaliSubStrings(str, 4);
    return 0;
}

/*
TC-> O(N*W), N is the size of the array and W=N-K+1
SC-> O(N)
*/