/*
CONSTRUCTOR:
    -> Whenever we create an object, a constructor is called by default. e.g. while creating object a, a.Hero() is called.
    -> Non parameterized constructor is the default constructor that is called by itself if not delcared.
    inside class.
    -> If we write any constructor inside class, then the default constructor are no longer valid. E.g. if we create a parameterized construtor, in that case the default non parameterized construtor gets deleted.
    -> this keyword is the pointer pointing to the current object.

DESTRUCTOR:
    -> Properties of Destructor:
        - Name is same as the class
        - No parameters
        - No return type
    -> For statically allocated objects, the destructor is called automatically.
    -> For dynamically allocated objects, the destructor has to be called manually. (e.g. in this case: 'B')
    -> Destructor is called only once
*/

#include <iostream>
using namespace std;

class Hero
{
private:
    char name = '+'; // + is the deault name of the Hero class
    int level, health;

public:
    // Non-parameterized constructor
    Hero()
    {
        cout << "Initialization constructor(non-paramterized) called." << endl;
    }
    // Parameterized constructor
    Hero(char name, int level, int health)
    {
        cout << "Initialization constructor(parameterized) called." << endl;
        this->name = name, this->level = level, this->health = health;
    }

    ~Hero()
    {
        cout << "Destructor called for " << this->name << endl;
    }
};

int main()
{
    // Statically allocated
    Hero S;

    // Dynamically allocated
    Hero *A = new Hero('A', 10, 100);
    delete A;
    return 0;
}