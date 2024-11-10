#include <iostream>
using namespace std;

class Base
{
public:
    int a;
    // Constructor
    Base()
    {
        cout << "\nBase constructor called!";
    }

    // Destructor
    ~Base()
    {
        cout << "\nBase destructor called!";
    }

    // Member function
    void memberFunction()
    {
        cout << "\nBase member function called!";
    }

     void memberFunction2() = 0;
};

class Derived : public Base
{
public:
    // Constructor
    Derived()
    {
        cout << "\nDerived constructor called!";
    }

    // Destructor
    ~Derived()
    {
        cout << "\nDerived destructor called!";
    }

    // Member function
    void memberFunction()
    {
        cout << "\nDerived member function called!";
    }
};

int main()
{
    Base base;
    base.memberFunction2();
    return 0;
}