// Using Friend Class : If we want that class to be instantiated only by a friend class.
#include <iostream>
using namespace std;

// class A
class A
{
private:
    A()
    {
        cout << "Constructor of A\n";
    }
    friend class B; // Declaring class B as the friend of class A
};

// class B, friend of class A
class B
{
public:
    B()
    {
        A a1;
        cout << "constructor of B\n";
    }
};

int main()
{
    B b1;
    // B b1 = B();
    return 0;
}