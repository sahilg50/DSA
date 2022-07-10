#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // if(0) evaluates to False and everything else to True;
    if (0)
        cout << "if(0)";
    if (-1)
        cout << "if(-1)" << endl;
    if (1)
        cout << "if(1)" << endl;

    // sqrt() is a function of cmath library
    cout << sqrt(10) << endl;

    // pow(x,y) = x^y
    cout << pow(2, 3) << endl;

    // We can also use 1LL (or 1ll). LL is the suffix for long long, which is 64-bit on most C/C++
    cout << 1ll << endl;
    int x = 1000000;
    int y = 1000000;
    long long int z = 1LL * x * y;
    cout << z << endl;

    return 0;
}