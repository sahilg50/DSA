#include <iostream>
using namespace std;

int DP[200] = {0};

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (DP[n] != 0)
    {
        return DP[n];
    }

    DP[n] = fib(n - 1) + fib(n - 2);
    return DP[n];
}
int main()
{

    int n;
    cin >> n;

    cout << fib(n - 1);
    return 0;
}