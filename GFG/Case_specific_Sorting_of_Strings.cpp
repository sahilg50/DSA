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
public:
    // Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string L = "", U = ""; // Lower case and Upper case
        for (auto ch : str)
        {
            if (isupper(ch))
                U.push_back(ch);
            else
                L.push_back(ch);
        }
        sort(L.begin(), L.end());
        sort(U.begin(), U.end());

        string ans;
        for (auto ch : str)
        {
            if (isupper(ch))
            {
                ans.push_back(U[0]);
                U.erase(U.begin());
            }
            else
            {
                ans.push_back(L[0]);
                L.erase(L.begin());
            }
        }
        return ans;
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
        string str;
        cin >> str;
        Solution obj;
        cout << obj.caseSort(str, n) << endl;
    }
}