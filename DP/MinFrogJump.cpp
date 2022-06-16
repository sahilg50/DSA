#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int solve(int ind, vector<int> &Heights, vector<int> &dp)
{

    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int jump1 = solve(ind - 1, Heights, dp) + abs(Heights[ind] - Heights[ind - 1]);

    int jump2 = INT_MAX;
    if (ind > 1)
    {
        jump2 = solve(ind - 2, Heights, dp) + abs(Heights[ind] - Heights[ind - 2]);
    }
    return dp[ind] = min(jump1, jump2);
};

int main()
{
    vector<int> Heights{30, 10, 60, 10, 60, 50};
    int n = Heights.size();
    vector<int> dp(n, -1);

    cout << solve(n - 1, Heights, dp);
}