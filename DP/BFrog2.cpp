#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(int ind, vector<int> &heights, int K, vector<int> &dp)
{

    // base case
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int minSteps = INT_MAX;
    for (int i = 1; i <= K; i++)
    {
        if (ind - i >= 0)
        {
            int jump = solve(ind - i, heights, K, dp) + abs(heights[ind] - heights[ind - i]);
            minSteps = min(minSteps, jump);
        }
    }
    return dp[ind] = minSteps;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> heights(N);
    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }
    vector<int> dp(N, -1);
    cout << solve(N - 1, heights, K, dp);
}