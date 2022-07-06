
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int mod = 1e9 + 7;

int main()
{
    string s;
    getline(cin, s);
    int n = s.size();
    long long ans = pow(2, n);
    ans -= n;
    cout << (int)(ans % mod);

    return 0;
}