#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, vector<int>> map;
unordered_set<int> set;

int main()
{
    map[10].push_back(1);
    map[19].push_back(20);
    map[10].push_back(8);
    map[10].push_back(90);
    for (auto i : map[10])
        set.insert(i);

    for (auto i : map[19])
        set.insert(i);

    for (auto i : map)
        set.insert(i.first);

    cout << set.size();

    return 0;
}