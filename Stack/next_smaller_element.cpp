#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> NSE(int *arr, int n)
{
    // storing the next smaller values in nse
    vector<int> nse(n, 0);
    stack<int> S;
    int i = 0;
    while (i < n)
    {
        if ((!S.empty()) && (arr[S.top()] > arr[i]))
        {
            nse[S.top()] = arr[i];
            S.pop();
        }
        else
        {
            S.push(i++);
        }
    }
    return nse;
}

int main()
{
    // array containing only positive elements
    int arr[] = {2, 90, 3, 4, 3, 1};
    int n = sizeof(arr) / sizeof(int);

    vector<int> nse = NSE(arr, n);

    cout << "\nNSE: ";
    for (auto i : nse)
    {
        cout << i << " ";
    }

    return 0;
}
