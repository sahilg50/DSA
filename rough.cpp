#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec = {1, 0, 0, 9, 9, 3, 0, 1, 0, 0, -1, 10, 9, 4, 5, 6, 6, 0, 0, 0, 0, -10};
    int mask = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] != 0)
            mask |= (1 << i);
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (mask & (1 << i))
            cout << vec[i] << " ";
    }

    return 0;
}