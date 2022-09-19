/*
The variables declared as static are initialized only once as they are allocated space in separate static storage so, the static variables in a class are shared by the objects. There can not be multiple copies of same static variables for different objects. Also because of this reason static variables can not be initialized using constructors.

The values of static members are carried through the function calls.

STATIC KEYWORD:
    -> Data Member
        - Data member declared using static keyword belongs to the class and we do not need to create an object to access it.
        - Firstly, static data member has to be assigned value using scope '::' operator and only then we can modify it using '.' operator by an object.
        - The static data members should be explicitly assigned values by the user by only using scope resolution operator outside the class (int Box::objectCount = 0) or the value can also be assinged from inside the static method.
        - A static member is shared by all objects of the class.

    -> Member Functions-
        - Member functions declared using static keyword belongs to the class and we do not need to create an object to access it.
        - Static member function can only access static data members.
        - Static member functions do no have 'this' keyword. This is because 'this' keyword belongs to the object and not the class.

IMP : A static member can be called/accessed even if no objects of the class exist and in that case the static members are called/accessed using only the class name and the scope resolution operator '::'.

*/

#include <iostream>
using namespace std;

class Box
{
private:
    double l, b, h;

public:
    static int objectCount; // Static data member

    // Constructor definition
    Box(double l = 2.0, double b = 2.0, double h = 2.0)
    {
        cout << "Constructor called." << endl;
        l = l;
        b = b;
        h = h;

        // Increase every time object is created
        objectCount++;
    }
    double Volume()
    {
        return l * b * h;
    }
    static int getCount()
    {
        // objectCount = 0;
        return objectCount;
    }
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void)
{
    // Print total number of objects before creating object.
    cout << "Inital Stage Count: " << Box::getCount() << endl;

    Box Box1(3.3, 1.2, 1.5); // Declare box1
    Box Box2(8.5, 6.0, 2.0); // Declare box2

    // Print total number of objects after creating object.
    cout << "Final Stage Count: " << Box::getCount() << endl;
    // cout << "Final Stage Count: " << Box2.getCount() << endl;

    return 0;
}