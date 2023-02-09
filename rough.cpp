#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int doesSatisfy(int val)
{
    return val == 30;
}
int main()
{
    vector<int> vec = {10, 20, 30, 40, 30, 60, 70, 30, 100};
    // auto it = remove_if(vec.begin(), vec.end(), doesSatisfy);
    // vec.erase(it, vec.end());
    vec.pop_back();
    for (auto num : vec)
        cout << num << " ";

    return 0;
}