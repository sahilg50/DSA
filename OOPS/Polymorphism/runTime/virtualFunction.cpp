/*
-> Definition: A virtual function is a member function which is declared within a base class and is re-defined (overridden) by a derived class. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the function.

-> NOTE
    - They are mainly used to achieve Runtime polymorphism
    - Functions are declared with a virtual keyword in base class.
    - The resolving of function call is done at runtime.

-> Rules for Virtual Functions
    - Virtual functions cannot be static.
    - A virtual function can be a friend function of another class.
    - Virtual functions should be accessed using pointer or reference of base class type to achieve runtime polymorphism.
    - The prototype of virtual functions should be the same in the base as well as derived class.
    - They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.
    - A class may have virtual destructor but it cannot have a virtual constructor.

-> Q. Why do we declare functions are virtual functions while function overriding?
    Ans: Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for function call.

-> Virtual functions should have an overrider in the derived class.
*/

#include <iostream>
using namespace std;

class Instrument
{
public:
    virtual void makeSound()
    {
        cout << "Intrument is playing.....\n";
    }
};

class Guitar : public Instrument
{
public:
    void makeSound()
    {
        cout << "Guitar is playing...\n";
    }
};

int main()
{
    Instrument *ptr = new Guitar();
    ptr->makeSound();
    return 0;
}