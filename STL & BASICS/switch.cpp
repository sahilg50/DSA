#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    set<int> s;

    // taking input of the number of queries
    int Q;
    cin >> Q;
    while (Q--)
    {
        int code, num;
        cin >> code >> num;

        switch (code)
        {

        case 1:
        {
            s.insert(num);
            break;
        }
        case 2:
        {
            auto it = s.find(num);
            if (it != s.end())
                s.erase(it);
            break;
        }
        case 3:
        {
            auto itr = s.find(num);
            if (itr != s.end())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            break;
        }
        }
    }
    return 0;
}
