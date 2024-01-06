#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    reverse(arr.begin() + 1, arr.end());
    for (auto num : arr)
        cout << num << " ";
    return 0;
}
