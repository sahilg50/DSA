#include <iostream>
using namespace std;

int memo[100][100];

int CoinChange(int S[], int m, int val)
{
    if (val == 0)
        return 1;

    if (val < 0)
        return 0;

    if (m <= 0 && val > 0)
        return 0;

    if (memo[m][val] != -1)
        return memo[m][val];

    memo[m][val] = CoinChange(S, m - 1, val) + CoinChange(S, m, val - S[m - 1]);

    return memo[m][val];
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            memo[i][j] = -1;
        }
    }

    int S[] = {1, 2, 3};
    int m = sizeof(S) / sizeof(int);

    int val;
    cin >> val;

    cout << CoinChange(S, m, val);
    return 0;
}