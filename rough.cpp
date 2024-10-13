#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    vector<int> dp = {1, 2, 3, 4, 4};
    dp = {0};
    for (auto num : dp)
        cout << num << " ";
    return 0;
}