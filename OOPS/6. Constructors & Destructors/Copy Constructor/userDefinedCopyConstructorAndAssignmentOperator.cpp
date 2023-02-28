/*
TOPIC: User Defined Copy Constructor
    -> It is called when a new object is created from an existing object, as a copy of the existing object.

    -> It creates a separate memory block for the new object.

    -> It is an overloaded constructor.

    -> C++ compiler implicitly provides a copy constructor, if no copy constructor is defined in the class.

    -> The copy constructor has to be passed by reference otherwise if we pass by value then it will get caught in the infinite loop of creating and copying the constructor.

TOPIC: User Defined Assignment Operator
    -> This operator is called when an already initialized object is assigned a new value from another existing object.

    -> It does not create a separate memory block or new memory space.

    -> It is a bitwise operator.

    -> A bitwise copy gets created, if the Assignment operator is not overloaded.
*/

#include <iostream>
using namespace std;

class Hero
{
private:
    char name;
    int level, health;

public:
    Hero() { cout << "\nDefault constructor called."; }

    Hero(char name, int level, int health)
    {
        cout << "\nParameterized constructor called.";
        this->name = name, this->level = level, this->health = health;
    }

    Hero(const Hero &temp)
    {
        cout << "\nCopy constructor called.";
        this->name = temp.name;
        this->level = temp.level;
        this->health = temp.health;
    }

    void operator=(const Hero &temp)
    {
        cout << "\nAssignment operator called.";
        this->name = temp.name;
        this->level = temp.level;
        this->health = temp.health;
    }

    void print()
    {
        cout << "\n[ " << this->name << ", " << this->health << ", " << this->level << " ]\n\n";
    }
};

int main()
{
    Hero S('S', 10, 100);
    S.print();

    // When copying the data after initialization then the copy is done through DEFAULT ASSIGNMENT OPERATOR
    Hero A;
    A = S;
    A.print();

    // When copying the data at the time of initialization then copy is made through COPY CONSTRUCTOR
    Hero C = S;
    // Hero C(S);
    C.print();
    return 0;
}