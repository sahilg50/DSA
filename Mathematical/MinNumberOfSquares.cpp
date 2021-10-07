#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int getMinNumberOfSquares(unsigned int n)
{
    if ((sqrt(n) - floor(sqrt(n))) == 0)
        return 1;

    else if (n <= 3)
        return n;

    else
    {
        int res = n;

        for (int x = 1; x * x <= n; x++)
        {

            res = min(res, 1 + getMinNumberOfSquares(n - (x * x)));
        }
        return res;
    }
}
int main()
{
    cout << getMinNumberOfSquares(60);

    return 0;
}