#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int memo[1000];

int getMinNumberOfSquares(unsigned int n)
{
    if ((sqrt(n) - floor(sqrt(n))) == 0)
    {
        memo[n] = 1;
        return 1;
    }

    else if (n <= 3)
    {
        memo[n] = n;
        return n;
    }

    else
    {
        int res = n;

        for (int x = 1; x * x <= n; x++)
        {
            int temp = x * x;

            if (memo[n] != -1)
            {
                return memo[n];
            }

            else
            {
                res = min(res, 1 + getMinNumberOfSquares(n - temp));
            }
        }
        memo[n] = res;
        return res;
    }
}

int main()
{
    fill_n(memo, 1000, -1);
    int n;
    cin >> n;
    cout << getMinNumberOfSquares(n);

    return 0;
}