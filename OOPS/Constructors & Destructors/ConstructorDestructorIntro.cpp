/*
TOPIC: CONSTRUCTOR
    -> Properties of Destructor:
        - Name is same as the class
        - Can be parameterized and non-parameterized.
        - No return type (does not return anything)
    -> Whenever we create an object, a constructor is called by default. e.g. while creating object 'a' from class 'HERO', a.Hero() is called.
    -> Non parameterized constructor is the default constructor that is called by itself if no constructor is declared inside class.
    -> If we create any custom parameterized or non-parameterized constructor, in that case the default non parameterized constructor gets deleted.
    -> 'this' keyword is the pointer pointing to the current object.

TOPIC: DESTRUCTOR
    -> Properties of Destructor:
        - Name is same as the class
        - No parameters
        - No return type (does not return anything)
    -> For statically allocated objects, the destructor is called automatically.
    -> For dynamically allocated objects, the destructor has to be called manually. (e.g. in this case: 'B')
    -> Destructor is called only once for an object.
    -> Destructor cannot be overloaded.
    -> By default, the destructors are called in the reverse order in which objects are created.
*/

#include <iostream>
using namespace std;

class Hero
{
private:
    char name = '+'; // + is the default name of the Hero class
    int level, health;

public:
    // Non-parameterized constructor
    Hero()
    {
        cout << "Initialization constructor(non-parameterized) called.\n";
    }
    // Parameterized constructor
    Hero(char name, int level, int health)
    {
        cout << "Initialization constructor(parameterized) called.\n";
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
    Hero R('R', 20, 100);
    Hero S('S', 20, 100);
    Hero P('P', 20, 100);

    // Dynamically allocated
    Hero *A = new Hero('A', 10, 100);
    delete A;
    return 0;
}