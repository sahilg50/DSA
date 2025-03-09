#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    vector<vector<int>> S;

    for (int i = 1; i < 10; i++)
    {
        vec.push_back(i);
        S.push_back(vec);
    }

    for (auto s : S)
    {
        copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
    }
    return 0;
}