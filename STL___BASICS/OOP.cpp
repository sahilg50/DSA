#include <iostream>
using namespace std;

/*
Primitive Datatypes:
    -> int a;
    -> char ch;
    -> float f;

Class(Hero) is a user defined data type:
    -> Hero Jack;

Note:
    -> Size of the class depends upon the size of it's properties. (in bytes).
    -> Empty class has size of 1 byte to keep it's track.

    -> Properties can be accessed using '.' operator.

    -> Types of access modifiers:
        - Public
        - Private
        - Protected
    -> Default access modifier is private.
    -> Private data members and functions can be accessed only inside the class.
    -> Public data member and functions can be accessed both inside and outside the class.
    -> By default, data members hold the garbage value(i.e. in case we do not assign the value to them).
    -> In case we make the properties private, we can decalre public get() and set() methods to get and set values of private data members.

    -> Padding: Ii is the concept that adds one or more empty bytes between the memory addresses to align the data in memory such that CPU cycles should not be wasted. This is because processor doesn't read 1 byte at a time. 32-bit processor reads 4 bytes a time and 64-bit processor reads 8 bytes at a time. Class with a single data member does not use padding.
    https://www.youtube.com/watch?v=aROgtACPjjg


*/

class Hero
{

public:
    // properties
    char level;
    char name;
    int health;
};

int main()
{
    Hero h1;
    cout << "Size of the class Hero: " << sizeof(h1) << endl;
    cout << "Health: " << h1.health << endl;
    cout << "Level: " << h1.level << endl;
    return 0;
}