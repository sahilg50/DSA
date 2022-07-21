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
    void solve(int ind, vector<int> &arr, vector<int> &ans, int sum)
    {

        // Base case
        if (ind == arr.size())
        {
            ans.push_back(sum);
            return;
        }

        // Pick
        solve(ind + 1, arr, ans, sum + arr[ind]);

        // Not Pick
        solve(ind + 1, arr, ans, sum);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(0, arr, ans, 0);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans)
        {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}