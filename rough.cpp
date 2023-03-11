#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2};
    cout << *max_element(v.begin() + 0, v.begin() + 2);
    return 0;
}