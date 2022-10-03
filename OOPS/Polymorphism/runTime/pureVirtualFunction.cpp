/*
- A class having atleast one pure virtual function is known as an abstract class.

- When we declare a pure virtual function, in that case, all the derived classes will have to provide their own implementation of the pure virtual function.
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
    // i1->makeSound();

    Instrument *i2 = new Piano();
    // i2->makeSound();

    Instrument *instruments[2] = {i1, i2};
    for (int i = 0; i < 2; i++)
        instruments[i]->makeSound();
    return 0;
}