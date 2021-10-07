/*
Check if a given number is the power of 2
*/

#include <iostream>
using namespace std;

bool isPowerOf_2(int n)
{

    return n && !(n & n - 1);
}

int main()
{
    cout << isPowerOf_2(14) << endl;
    cout << isPowerOf_2(16);

    return 0;
}