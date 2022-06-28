#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void PSE(int *arr, int n)
{
    vector<int> pse(n, 0);
    stack<int> S;
    int i = 0;
    while (i < n)
    {

        if ((!S.empty()) && (arr[S.top()] < arr[i]))
        {
            pse[i] = arr[S.top()];
            S.push(i++);
        }
        else if (S.empty())
        {
            S.push(i++);
        }
        else
        {
            S.pop();
        }
    }
    cout << endl
         << "Previous smaller element: ";
    for (int i : pse)
    {
        cout << i << " ";
    }
}

int main()
{
    int arr[] = {1, 3, 5, 2, 6, 4, 3};
    int n = sizeof(arr) / sizeof(int);
    PSE(arr, n);
    return 0;
}