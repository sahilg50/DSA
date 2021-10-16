#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()

{
    vector<vector<int>> v;
    v.push_back({1, 2, 3, 4, 5, 7, 8});
    v.push_back({1, 2, 3});
    v[1].push_back(4);
    v[4].push_back(10);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    // list<int> *l = new list<int>[2];

    // l[0].push_back(1);
    // l[0].push_back(1);
    // l[0].push_back(1);
    // l[0].push_back(1);

    // l[1].push_back(90);
    // l[1].push_back(90);

    // // l[2].push_back(80);
    // // l[2].push_back(80);

    // // l[3].push_back(40);
    // // l[3].push_back(40);

    // cout << endl;

    // for (int i = 0; i < 2; i++)
    // {

    //     list<int>::iterator it;
    //     for (it = l[i].begin(); it != l[i].end(); it++)
    //     {
    //         cout << *it << " ";
    //     }

    //     cout << endl;
    // }

    return 0;
}