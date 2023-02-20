/*
TOPIC: Using scope resolution '::' to avoid ambiguous situations of data member in derived class.
    -> This program uses explicit scope resolution to select i.
*/

#include <iostream>
using namespace std;

class base
{
public:
    int i;
};

// derived1 inherits base.
class derived1 : public base
{
public:
    int j;
};

// derived2 inherits base.
class derived2 : public base
{
public:
    int k;
};

// derived2 inherits derived1 and derived2
class derived3 : public derived1, public derived2
{
public:
    int sum;
};

int main()
{
    derived3 ob;
    ob.derived1::i = 10;
    /*
    Use scope resolution operator '::' to manually use derived1's i
    */

    ob.j = 20, ob.k = 30;
    ob.sum = ob.derived1::i + ob.j + ob.k;
    cout << ob.sum;

    /*
    cout << ob.i;
    The above statement will give an error that i is ambiguous because i is derived from both derived1 and derived2. Therefore to resolve this issue use scope resolution.
    */
    return 0;
}