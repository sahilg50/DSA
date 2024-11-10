/*
TOPIC: Pure Virtual Function (Virtual Abstract Method)
    -> A pure virtual function is declared by using the 'virtual' keyword in method definition and '= 0' syntax in its declaration.

    -> A class containing at least one pure virtual function is called an abstract class. Additionally, it can have a constructor, destructor, data members, and non-abstract methods.

    -> An object of the abstract class cannot be instantiated.

    -> Any derived class must provide its own implementation of the pure virtual function. If a derived class does not implement the pure virtual function, it also becomes an abstract class.
*/

#include <iostream>
using namespace std;

class Instrument
{
public:
    virtual void makeSound() = 0; // pure virtual function
};

class Guitar : public Instrument
{
public:
    void makeSound()
    {
        cout << "Guitar is playing...\n";
    }
};

class Piano : public Instrument
{
public:
    void makeSound()
    {
        cout << "Piano is playing...\n";
    }
};

int main()
{
    Instrument *i1 = new Guitar();
    i1->makeSound();
    cout << "\n\n";

    Instrument *i2 = new Piano();
    i2->makeSound();

    return 0;
}