#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string &a, string &b)
{
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

bool isChain(string &a, string &b)
{
    if (a.size() + 1 != b.size())
        return false;

    int k = 1, i = 0, j = 0;
    while (i < a.size())
    {
        if (a[i] == b[j])
            i++, j++;
        else
        {
            if (k)
                j++, k--;
            else
                return false;
        }
    }

    return true;
}
int main()
{
    // vector<string> words = {"sahil", "zb", "a", "sa"};
    // sort(words.begin(), words.end(), cmp);
    // for (auto &word : words)
    //     cout << word << " ";

    string a = "ab", b = "abc";
    cout << boolalpha << isChain(a, b);
    return 0;
}