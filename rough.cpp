#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<vector<int>> v;
    v.push_back({1, 2});
    v.push_back({3, 4});
    cout << v[0][0] << endl;
    cout << v[0][1];

    return 0;
}