#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
using namespace std;

char find_solo_performer(string d)
{

    vector<char> M(26, 0);
    for (char ch : d)
        M[ch - 'a']++;

    vector<char> solo, group;
    vector<int> vis(26, 0);

    for (unsigned int i = 0; i < d.size(); i++)
    {
        if (vis[d[i] - 'a'] == 0)
        {
            if (M[d[i] - 'a'] == 1)
                solo.push_back(d[i]);
            else
                group.push_back(d[i]);
            vis[d[i] - 'a'] = 1;
        }
    }

    int n = solo.size();
    if (n == 0)
        return group[0];

    if (n >= 3)
        return solo[n - 3];
    if (n >= 2)
        return solo[n - 2];
    if (n >= 1)
        return solo[n - 1];

    return d[0];
}

int main()
{
    string str = "abawpqquuo";
    cout << find_solo_performer(str);

    return 0;
}