#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {2, 3, 4, 5, 6, 7};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    // Initializing the iterator
    vector<int>::iterator it = v.begin();
    for (it = v.begin(); it != v.end(); ++it)
    {
        cout << (*it) << " ";
    }

    // Using iterators on nested vectors
    vector<pair<int, int>> v_p = {{1, 2}, {3, 4}, {5, 6}};
    vector<pair<int, int>>::iterator it1;
    for (it1 = v_p.begin(); it1 != v_p.end(); it1++)
    {
        cout << (*it1).first << " " << (*it1).second << endl;
        cout << (it1->first) << " " << (it1->second) << endl;
    }
    // NOTE: (*it).first <==> (it->first)

    // In C++11 owards
    cout << endl
         << endl
         << "RANGE BASED LOOPS" << endl;
    // value is a copy
    for (int value : v)
    {
        cout << value << " ";
    }
    cout << endl;

    // Using references
    for (int &value : v)
    {
        value++;
    }
    for (int value : v)
    {
        cout << value << " ";
    }
    cout << endl;

    // Understanding auto keyword
    cout << endl
         << endl
         << "UNDERSTANDING AUTO KEYWORD" << endl;
    for (auto it3 = v.begin(); it3 != v.end(); it3++)
    {
        cout << *it3 << " ";
    }
    cout << endl;
    // Note: Auto keyword automatically detects the datatype of the assigned value.

    for (auto &num : v)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}