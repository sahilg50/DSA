#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cout << "Enter the number of curries available: ";
    int n;
    cin >> n;
    vector<int> v;
    cout << "Enter the curries: ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    cout << "Enter the value for which currency is to be given: ";
    int value;
    cin >> value;

    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += value / v[i];
        value %= v[i];
    }

    cout << ans << endl;

    return 0;
}