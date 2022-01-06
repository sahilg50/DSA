#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    vector<int> arr(2);
    unordered_map<int, arr> map;
    vector<int> vec;

    vec.push_back(6);
    vec.push_back(-17);
    vec.push_back(12);

    cout << "Vector Size: " << vec.size() << endl;

    vec.erase(next(vec.begin()));
    cout << "Vector Size: " << vec.size() << endl;
    return 0;
}
