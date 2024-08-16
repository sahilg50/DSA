#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    vector<pair<char, int>> temp = {{'A', 10}, {'B', 20}, {'C', 30}};
    for (auto it = temp.rbegin(); it != temp.rend(); it++)
        cout << (*it).first * 2;
    return 0;
}