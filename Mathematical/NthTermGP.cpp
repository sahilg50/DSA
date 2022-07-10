#include <iostream>
using namespace std;

long long power(int R, int N, int mod)
{
    if (N == 0)
        return 1;

    long long temp = power(R, N / 2, mod) % mod;

    if (N % 2 == 0)
        return (temp * temp) % mod;

    else
        return (((temp * temp) % mod) * R) % mod;
}

int nthTermOfGP(int N, int A, int R)
{

    int mod = 1000000007;
    long long ans = (A * power(R, N - 1, mod)) % mod;
    return (int)ans;
}

int main()
{
    cout << nthTermOfGP(3, 2, 2);
    return 0;
}

/*
    code studio solution
    Time complexity: O(logN)
    Space complexity: O(logN)

    Where N is the term of GP required.
*/
