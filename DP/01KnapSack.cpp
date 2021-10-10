#include <iostream>
#include <algorithm>
using namespace std;

int val[100], wt[100];

int memo[100][100];

int knapSack(int n, int w)
{

    if (w <= 0)
        return 0;

    else if (n <= 0)
        return 0;

    else if (memo[n][w] != -1)
        return memo[n][w];

    else if (wt[n - 1] > w)
        memo[n][w] = knapSack(n - 1, w);

    else
        memo[n][w] = max(knapSack(n - 1, w), knapSack(n - 1, w - wt[n - 1]) + val[n - 1]);
    return memo[n][w];
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            memo[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    for (int i = 0; i < n; i++)
        cin >> val[i];

    int max_weight;
    cin >> max_weight;

    cout << knapSack(n, max_weight);

    return 0;
}