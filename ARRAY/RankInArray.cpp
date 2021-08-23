/* Replace the elements of the array by their rank in the array. The smallest element is given the rank zero*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myCompare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

int main()
{
    int arr[] = {1, 4, 2, 9, 0, 6, 10, 90};

    vector<pair<int, int>> v;

    int size = sizeof(arr) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        v.push_back(make_pair(arr[i], i));
    }

    sort(v.begin(), v.end(), myCompare);
    for (int i = 0; i < v.size(); i++)
    {
        arr[v[i].second] = i;
    }

    for (auto i : v)
    {
        cout << i.first << " ";
    }

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}