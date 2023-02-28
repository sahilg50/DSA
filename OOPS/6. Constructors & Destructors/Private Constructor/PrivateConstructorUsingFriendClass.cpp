/*
TOPIC: Accessing Private Constructor Using Friend Class
    -> Private or Protected constructors cannot be accessed from outside the class therefore the object creation in the main function becomes impossible.

    -> To tackle this, we declare class 'B' as friend of class 'A'.

    -> Now, class 'B' has access to all the private, protected and public members of the class 'A'. Therefore, we'll define a method inside class 'B' that will create an object of class 'A' by calling the constructor of class 'A' and then return that object to the main function.

TOPIC: NOTE
    -> Private or Protected constructor can also be accessed using friend function.
*/

#include <iostream>
using namespace std;

// Class A
class A
{
private:
    A() { cout << "\nConstructor of A called!"; }
    friend class B; // Declaring class B as the friend of class A

public:
    void hello() { cout << "\nHello from class A!"; }
};

// Class B, friend of class A
class B
{
public:
    B() { cout << "\nConstructor of class B called!"; }

    A createObjectOfClassA()
    {
        cout << "\nCreating object of class A!";
        A a;
        return a;
    }
};

int main()
{
    B b1;
    // B b1 = B();

    A a1 = b1.createObjectOfClassA();
    a1.hello();

    return 0;
}