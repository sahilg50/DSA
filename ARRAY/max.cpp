#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int mx = arr[0];
    for (int j = 0; j < n; j++)
    {
        mx = max(mx, arr[j]);
    }

    return 0;
}