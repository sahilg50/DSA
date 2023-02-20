// https : // www.youtube.com/watch?v=i_5pvt7ag7E&t=494s
// https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1381799

/*
TOPIC: SHALLOW COPY AND DEEP COPY
    -> Depending upon the resources like dynamic memory held by the object, either we need to perform Shallow Copy or Deep Copy in order to create a replica of the object. In general, if the variables of an object have been dynamically allocated, then it is required to do a Deep Copy in order to create a copy of the object.

    -> Suppose one of the data members is a pointer to an array. When we create a copy of this object, the address stored in this pointer will be copied to the other pointer(data member of the new object). Now, when we make any change in the array using any object, it will be reflected in both objects because both pointers are pointing to the same array.

    -> Suppose one of the data member is an integer variable. When we create a copy of this object, the value stored in that integer variable will be copied to the other integer variable(data member of the new object). Now, if we change value of this data member of the new object then the change won't be reflected in the other object because both the data members hold their separate copies of the integer.

    https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/
*/

#include <iostream>
using namespace std;

class Hero
{
public:
    // properties
    char *name;
    int level;
    int health;

    // Non-Parameterized constructor
    Hero()
    {
        cout << "Initialization constructor is called " << endl;
    }
    // Parameterized constructor
    Hero(char name, int level, int health)
    {
        cout << "Constructor called.\n";
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
        cout << "Health: " << this->health << " ]";
    }

    ~Hero()
    {
        cout << "\nDestructor called for: " << this->name[0];
    }
};

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
    delete B;
    cout << "\n\n";

    // Create C as a shallow copy of A
    Hero C(A);
    C.print();
    C.name[0] = 'C'; // if we change name of obj C, the name of obj A is also changed.
    cout << "\nChanges made in obj C will reflect in obj A (Changed name of obj C)" << endl;
    A.print();
    cout << "\n\n";

    return 0;
}