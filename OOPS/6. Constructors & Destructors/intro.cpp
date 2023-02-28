/*
TOPIC: CONSTRUCTOR
    -> Properties of Destructor:
        - Name is same as the class
        - Can be parameterized and non-parameterized.
        - No return type (does not return anything)

    -> 'this' keyword is the pointer pointing to the current object.

    -> we cannot have a virtual constructor.

    TYPES OF CONSTRUCTOR:
        TOPIC: Default Constructor
            -> A constructor either has no parameters or all the parameters with default values.

            -> If no user-defined constructor exists for a class, then the compiler implicitly declares a default parameterless constructor.

            -> Whenever we create an object, the default constructor is called automatically.

        TOPIC: Parameterized Constructor
            -> A constructor with one or more parameters with no default value.

            -> It is an overloaded constructor

        TOPIC: Copy Constructor
            -> Creates an object by initializing it with an object of the same class, which has been created previously.

            -> It is an overloaded constructor



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