#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    /*
    Note that calculation is always done in higher datatype
    Increasing order: char < int < long int < long long int < float < double

    Rough ranges:
        10^-9 <= int <= 10^9
        10^-12 <= long int <= 10^12
        10^-18 <= long long int <= 10^18

     */
    cout << endl
         << 7 / 2;
    cout << endl
         << 7 / 2.0;
    cout << endl
         << (int)'c';

    cout << endl
         << 'c' + 1;

    float a = 2 / 2;
    cout << endl
         << "a = " << a;

    double b = 1e10;
    cout << endl
         << fixed
         << setprecision(0) << "b = " << b;
    /* Here the fixed key word is used to not print the number in scientific form.
    setprecision is used to define the number of precision points in double of float and the library used is iomanip.
    */

    // Note that double datatype is capable of storing large values but at the cost of accuracy, example is given below.
    cout << endl
         << (double)1e24;

    // An example of printing the value in long long int
    int p = 1e9;
    int q = 1e9;
    cout << endl
         << "Without overflow control: "
         << p * q;
    cout << endl
         << "With overflow control: "
         << p * 1LL * q;
    return 0;
}