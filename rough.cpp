#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(70);

    v.push_back(8);

    cout << v.back() << endl;

    sort(v.begin(), v.end());

    for (int element : v)
    {
        cout << element << " ";
    }
    cout << endl;

    int h = 9;

    cout << h / 2;

    return 0;
}