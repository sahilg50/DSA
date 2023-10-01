#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Approach 1: Using Stack (Left -> Right traversal)
vector<int> nextSmallerElement(int *arr, int n)
{
    // storing the next smaller values in nse
    vector<int> NSE(n, -1);
    stack<int> S;
    int i = 0;
    while (i < n)
    {
        if ((!S.empty()) && (arr[S.top()] > arr[i]))
        {
            NSE[S.top()] = arr[i];
            S.pop();
        }
        else
        {
            S.push(i++);
        }
    }
    return NSE;
}
/*
TC-> O(2*N), because at any time you'll push and pop each element
SC-> Stack: O(N) + NSE: O(N)ASC
*/

// Approach 2: Using Stack (Right -> Left Traversal)
vector<int> nextSmallerElement2(int *arr, int n)
{

    // Storing the next smaller values in nse
    vector<int> NSE(n, -1);
    stack<int> S;
    int i = n - 1;
    while (i >= 0)
    {
        if (!S.empty() && S.top() < arr[i])
        {
            NSE[i] = S.top();
            S.push(arr[i]);
            i--;
        }
        else if (S.empty())
        {
            S.push(arr[i]);
            i--;
        }
        else
        {
            S.pop();
        }
    }
    return NSE;
}

int main()
{
    // array containing only positive elements
    int arr[] = {2, 0, 90, 80, 3, 2, 4, 3, 1};
    int n = sizeof(arr) / sizeof(int);

    vector<int> nse = nextSmallerElement2(arr, n);

    cout << "\nNSE: ";
    for (auto i : nse)
    {
        cout << i << " ";
    }

    return 0;
}
