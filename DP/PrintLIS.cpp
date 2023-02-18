// https://takeuforward.org/data-structure/printing-longest-increasing-subsequence-dp-42/
// very important problem

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void printLIS(vector<int> &nums)
{
    int n = nums.size(), LIS = 1, lastInd = 0;
    vector<int> dp(n, 1), hash(n);

    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        for (int prevInd = 0; prevInd < ind; prevInd++)
        {
            if (nums[ind] > nums[prevInd] && 1 + dp[prevInd] > dp[ind])
            {
                dp[ind] = 1 + dp[prevInd];
                hash[ind] = prevInd;
            }
        }
        if (dp[ind] > LIS)
        {
            LIS = dp[ind];
            lastInd = ind;
        }
    }
    cout << "The length of LIS is: " << LIS << endl;

    // Printing the Longest increasing subsequence
    vector<int> ans;
    ans.push_back(nums[lastInd]);
    while (hash[lastInd] != lastInd)
    {
        lastInd = hash[lastInd];
        ans.push_back(nums[lastInd]);
    }
    reverse(ans.begin(), ans.end());
    cout << "The LIS is: ";
    for (auto &num : ans)
        cout << num << " ";
    cout << endl;
}
/*
    If N is the size of nums array then:
    TC-> O(N*N), because of 2 nested loops
    SC-> Dp Array: O(N) + Hash: O(N)
*/
int main()
{
    vector<int> nums = {0, 10, 20, 30, 3, 4, 5, 6, 7};
    printLIS(nums);
    return 0;
}