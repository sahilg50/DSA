#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4};
    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it;
    }
    return 0;
}