#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &a, vector<int> &b)
{
    double vw1 = (double)a[0] / a[1];
    double vw2 = (double)b[0] / b[1];
    return vw1 > vw2;
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        int value, weight;
        cin >> value >> weight;
        v.push_back({value, weight});
    }
    int w;
    cin >> w;
    sort(v.begin(), v.end(), compare);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (w >= v[i][1])
        {
            ans += v[i][0];
            w -= v[i][1];
            continue;
        }
        double vw = (double)v[i][0] / v[i][1];
        ans += vw * w;
        w = 0;
        break;
    }
    return 0;
}