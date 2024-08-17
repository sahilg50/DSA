#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    vector<int> dp = {1, 2, 2, 3, 4};
    dp = {0};
    for (auto num : dp)
    {
        num = 0;
        cout << num;
    }
    return 0;
}