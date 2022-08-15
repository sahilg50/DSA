// This problem is the variation of activity selection problem.
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <sstream>
using namespace std;

struct val
{
    int first;
    int second;
};

class Solution
{
private:
    static bool cmp(struct val a, struct val b)
    {
        return a.second < b.second;
    }

public:
    int maxChainLen(struct val p[], int n)
    {

        sort(p, p + n, cmp);

        int maxLen = 1;
        int end = p[0].second;
        for (int i = 1; i < n; i++)
        {
            if (end < p[i].first)
            {
                maxLen++;
                end = p[i].second;
            }
        }
        return maxLen;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        struct val *p = new struct val[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }
        Solution ob;
        cout << ob.maxChainLen(p, n) << endl;
    }
    return 0;
}

/*
    TC-> Sorting: O(NlogN) + Iterating: O(N), N is the size of the array
    SC-> O(1)
*/