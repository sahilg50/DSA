#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    // vector<int> *v = new vector<int>();
    // v->push_back(10);
    // v->push_back(20);
    // cout << v->at(0) << endl;
    // cout << *v->rbegin();

    vector<int> v = {1, 8, 2, 3, 4};
    auto it = v.end();
    it -= 3;
    it += 1;
    cout << *it;
    return 0;
}