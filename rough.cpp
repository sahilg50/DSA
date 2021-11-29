#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> map;

int main()
{
    map[10].push_back(1);
    map[19].push_back(20);
    map[10].push_back(8);
    map[10].push_back(90);
    for (auto i : map)
        cout << i.first << " ";
    return 0;
}