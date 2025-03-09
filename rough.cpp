#include <iostream>
#include <map>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 5};
    map<int, int> M;
    for (auto num : nums)
        M[num]++;

    for (auto it : M)
    {
        cout << type_info(it);
    }

    for (auto it : M)
        cout << it.second << " ";
    return 0;
}