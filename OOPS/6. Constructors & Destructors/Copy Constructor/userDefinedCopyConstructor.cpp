/*
TOPIC: User Defined Copy Constructor
    -> The copy constructor has to be passed by reference otherwise if we pass by value then it will get caught in the infinite loop of creating and copying the constructor.
*/

#include <iostream>
using namespace std;

class Hero
{
private:
    char name;
    int level, health;

public:
    Hero() { cout << "\nInitialization constructor called."; }
    Hero(char name, int level, int health)
    {
        cout << "\nInitialization constructor called.";
        this->name = name, this->level = level, this->health = health;
    }
    Hero(const Hero &temp)
    {
        cout << "\nCopy constructor called.";
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
    // Hero C(S);
    Hero C = S;
    C.print();
    return 0;
}