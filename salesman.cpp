#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int deleteproducts(vector<int> ids, int m)
{
    unordered_map<int, int> map;

    for (int i : ids)
    {
        map[i]++;
    }

    vector<pair<int, int>> V;
    for (auto i : map)
    {
        V.push_back({i.first, i.second});
    }

    sort(V.begin(), V.end(), compare);

    auto it = V.begin();
    int res = V.size();
    while (it != V.end() && m > 0)
    {
        it->second--;
        if (it->second == 0)
        {
            it++;
            res--;
        }
        --m;
    }
    return res;
};

int main()
{
    vector<int> v{1, 1, 5, 5};
    cout << deleteproducts(v, 2);
    return 0;
}