// https : // www.youtube.com/watch?v=i_5pvt7ag7E&t=494s
// https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1381799
#include <iostream>
using namespace std;

/*
 */

class Hero
{

public:
    // properties
    char *name;
    int level;
    int health;
    static int timeToComplete;

    // Non-Parameterized constructor
    Hero()
    {
        cout << "Simple construtor is called " << endl;
    }
    // Parameterized constructor
    Hero(char name, int level, int health)
    {
        cout << "Construtor called.\n";
        this->name = new char[1];
        this->name[0] = name;
        this->level = level;
        this->health = health;
    }
    // Copy Constructor
    Hero(Hero &temp)
    {
        cout << "Copy constructor called" << endl;
        this->name = temp.name;
        this->level = temp.level;
        this->health = temp.health;
    }
    // Method to print all the properties
    void print()
    {
        cout << "[ Name: " << this->name[0] << ", ";
        cout << "Level: " << this->level << ", ";
        cout << "Health: " << this->health << ", ";
        cout << "Time To Complete: " << timeToComplete << " ]";
    }

    // Static member function
    static int gotHit()
    {
        timeToComplete /= 2;
    }
    ~Hero()
    {
        cout << "Destructor called for: " << this->name[0] << endl;
    }
};

// Assigning value to the static variable
int Hero::timeToComplete = 100;

int main()
{
    // Statically allocated
    Hero A('A', 1, 20);
    cout << "Size of the class Hero: " << sizeof(A) << endl;
    A.print();
    cout << "\n\n";

    // Dynamically allocated
    Hero *B = new Hero('B', 2, 40);
    // (*B).print();
    B->print();
    cout << endl;
    delete B;
    cout << "\n\n";

    // Create C as a shallow copy of A
    Hero C(A);
    C.print();
    cout << "\n\n";

    // When copying the data of object at the time of initialization then copy is made through COPY CONSTRUCTOR
    Hero D = A;
    D.timeToComplete = 300; // Updating the value of the static variable
    D.print();
    cout << "\n\n";

    // When copying the data of object after initialization then the copy is done through DEFAULT ASSIGNMENT OPERATOR
    Hero E;
    E = A;
    E.gotHit(); // Static method to change the value of the static variable
    E.print();
    cout << "\n\n";
    // In all the above examples, a shallow copy is being created since some of the data members have been dynammically allocated.
    return 0;
}