#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
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

    cout << char('0' + 9) << endl;

    /*
    C++ Algorithm remove() function is used to eliminate all the elements that are equal to val from a given range [first, last) without disturbing the order of the remaining elements. This function cannot alter the size of the container. It returns an iterator to the new end of the range.
    Now while removing spaces from the string, the remove() will return the iterator to the new end of the string and therefore we'll call the erase() method on top on the remove fuction to drop all the elements from the new end uptil the old end.
    */
    string s = "Hello W O r lddd s";
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    cout << s;

    /*
    ASCII VALUES
    'A' -> 65, 'Z' -> 90
    'a' -> 97, 'z' -> 122
    */

    return 0;
}