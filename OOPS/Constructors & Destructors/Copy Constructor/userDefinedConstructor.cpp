/*
NOTE:
    -The copy constructor has to pass by reference otherwise if we pass by value then it will get caught in the infinite loop of creating and copying the constructor.
    - When copying the data of object at the time of initialization then copy is made through COPY CONSTRUCTOR Hero D = A;
    - When copying the data of object after initialization then the copy is done through DEFAULT ASSIGNMENT OPERATOR
*/

#include <iostream>
using namespace std;

class Hero
{
private:
    char name;
    int level, health;

public:
    Hero() { cout << "Initialization constructor called." << endl; }
    Hero(char name, int level, int health)
    {
        cout << "Initialization constructor called." << endl;
        this->name = name, this->level = level, this->health = health;
    }
    Hero(const Hero &temp)
    {
        cout << "Copy constructor called." << endl;
        this->name = temp.name;
        this->level = temp.level;
        this->health = temp.health;
    }
    void print()
    {
        cout << "[ " << this->name << ", " << this->health << ", " << this->level << " ]"
             << "\n\n";
    }
};

int main()
{
    Hero S('S', 10, 100);
    S.print();

    // When copying the data of object after initialization then the copy is done through DEFAULT ASSIGNMENT OPERATOR
    Hero A;
    A = S;
    A.print();

    // When copying the data of object at the time of initialization then copy is made through COPY CONSTRUCTOR Hero D = A;
    Hero C = S;
    C.print();
    return 0;
}