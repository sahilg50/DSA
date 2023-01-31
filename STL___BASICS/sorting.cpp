#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <random>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    /*
    Compares the first element of the pair, if it is same then it compares the second element of the pair.
    */
    return a < b;
}

int main()
{
    /*
    INTRO SORT is used by c++ STL
    In the sorting function, we define the starting index and the ending index + 1.
    */
    cout << "\nSorting the array using sort()" << endl;
    int arr[] = {3, 1, 7, 9, 4, 5, 10, 6};
    int n = sizeof(arr) / sizeof(int);
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    /*
    Now let's look at comparator function and we'll sort a vector of pairs using selection sort and custom comparator function(cmp)
    */
    vector<pair<int, int>> V = {{1, 2}, {3, 4}, {9, 0}, {-1, -1}, {-1, -10}};
    n = V.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (cmp(V[i], V[j]))
            {
                swap(V[i], V[j]);
            }
        }
    }

    cout << "\n\nPrinting the sorted vector<pair>: ";
    for (auto &pv : V)
    {
        cout << endl
             << pv.first << " " << pv.second;
    }

    /*
    Now let's sort the vector using inbuilt sort and the comparator function.
    */
    V = {{1, 2}, {3, 4}, {9, 0}, {-1, -1}, {-1, -10}};
    sort(V.begin(), V.end(), cmp);
    cout << "\n\nPrinting the sorted vector<pair> using custom cmp inside sort(): ";
    for (auto &pv : V)
    {
        cout << endl
             << pv.first << " " << pv.second;
    }

    // Inbuilt comparators
    sort(V.begin(), V.end(), greater<pair<int, int>>());
    cout << "\n\nPrinting using inbuilt cmp inside sort(): ";
    for (auto &pv : V)
    {
        cout << endl
             << pv.first << " " << pv.second;
    }
    return 0;
}