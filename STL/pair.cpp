#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    pair<int, string> p;
    // p = make_pair(24, "sahil");
    p = {24, "sahil"};
    cout << p.first << " " << p.second << endl;

    // When we make a copy of p, no change is made if me make changes in p1
    pair<int, string> p1 = p;
    p1.first = 3;
    cout << p.first << " " << p.second << endl;

    // When we make p2, the refernce of p, then all the changes will reflect in p if we make changes in p2.
    pair<int, string> &p2 = p;
    p2.first = 3;
    cout << p.first << " " << p.second << endl;

    // Note: pairs are used to maintain relations
    pair<int, int> p_array[3];
    p_array[0] = {1, 2};
    p_array[1] = {3, 4};
    p_array[2] = {5, 6};

    for (int i = 0; i < 3; i++)
    {
        cout << p_array[i].first << " " << p_array[i].second << endl;
    }
    cout << "After swapping" << endl;
    swap(p_array[0], p_array[2]);
    for (int i = 0; i < 3; i++)
    {
        cout << p_array[i].first << " " << p_array[i].second << endl;
    }
    // So basically, the entire pair is swapped.

    return 0;
}