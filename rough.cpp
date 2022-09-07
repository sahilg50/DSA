#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void mostWanted(vector<vector<int>> &crimes)
{
    map<int, int> m;

    for (int i = 0; i < crimes.size(); i++)
    {
        sort(crimes[i].begin(), crimes[i].end());
        for (int j = 0; j < crimes[i].size(); j++)
        {
            if (j == 0 || crimes[i][j] != crimes[i][j - 1])
                m[crimes[i][j]]++;
        }
    }
    for (auto id : m)
    {
        if (id.second >= 2)
        {
            cout << id.first << " ";
        }
    }
}
int main()
{
    vector<int> t;
    for (int i = 0; i < 3; i++)
    {
        int temp;
        cin >> temp;
        t.push_back(temp);
    }

    vector<vector<int>> crimes(3);
    for (int i = 0; i < 3; i++)
    {
        vector<int> cases;
        for (int j = 0; j < t[i]; j++)
        {
            int temp;
            cin >> temp;
            cases.push_back(temp);
        }
        crimes.push_back(cases);
    }

    mostWanted(crimes);

    return 0;
}