#include <iostream>
using namespace std;

class Base
{
public:
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
    return 0;
}