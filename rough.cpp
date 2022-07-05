#include <iostream>
#include <vector>
using namespace std;

int solve(int N, int a, vector<int> x)
{
    for (int i = 0; i < x.size(); i++)
    {
        x[i] = abs(a - x[i]);
    }

    int x1, x2;
    auto max_it = x.begin();
    int maxi = x[0];
    for (auto it = x.begin(); it != x.end(); it++)
    {
        if (*it > maxi)
        {
            max_it = it;
            maxi = *it;
        }
    }

    x1 = maxi;
    x.erase(max_it);

    max_it = x.begin();
    maxi = x[0];
    for (auto it = x.begin(); it != x.end(); it++)
    {
        if (*it > maxi)
        {
            max_it = it;
            maxi = *it;
        }
    }

    x2 = maxi;
    return x1 + x2;
}

int main()
{
    vector<int> X = {9, 9, 3, 1, 7, 9, 5, 6, 5, 4};
    cout << solve(X.size(), 7, X);
    return 0;
}