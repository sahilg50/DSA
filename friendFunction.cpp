#include <iostream>
using namespace std;

/*
-> A class can have multiple friend functions
-> Just declare the functions inside inside the class along with the friend keyword.
-> A class can have friend classes

-> Arguments are passed by value, unless the function signature specifies otherwise:

    - in void foo(type arg), arg is passed by value regardless of whether type is a simple type, a pointer type or a class type,
    - in void foo(type& arg), arg is passed by reference.
*/
class EquilateralTriangle
{
    float a, circumference, area;

public:
    void setA(float length)
    {
        a = length;
        circumference = 3 * a;
        area = (1.73 * a * a) / 4;
    }

    // friend void PrintResults(EquilateralTriangle);

    friend class HomeWork;
};

// void PrintResults(EquilateralTriangle et)
// {
//     cout << "Circumference= " << et.circumference << endl;
// }

class HomeWork
{
public:
    void PrintResults(EquilateralTriangle &et)
    {
        cout << "Circumference = " << et.circumference << endl;
        et.setA(10);
    }
};

int main()
{
    EquilateralTriangle et;
    et.setA(3);
    // PrintResults(et);
    HomeWork h;
    h.PrintResults(et);
    h.PrintResults(et);

    return 0;
}