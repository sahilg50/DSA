/*
TOpic: What are static members?
The variables declared as static are initialized only once as they are allocated space in separate static storage so, the static variables in a class are shared by the objects. There can not be multiple copies of same static variables for different objects. Also because of this reason static variables can not be initialized using constructors.

TOPIC: Properties of Static Members:
    -> The values of static members are carried through the function calls.
    -> A static member is shared by all objects of the class.
    -> Static members can be private as well as public.
    -> C++ forbids in-class initialization of non-const static member.

STATIC KEYWORD:
    TOPIC: Data Member
        - Data member declared using static keyword belongs to the class and we do not need to create an object to access it.
        - Firstly, the static data members should be explicitly assigned values by the user by only using scope resolution operator outside the class (int Box::objectCount = 0) and only then ew can modify it:
        - Ways to Modify the value:
            -> The value can also be modified from inside the static or non-static method.
            -> If an object of that class exists then it can also be modified using the '.' operator.

    TOPIC: Member Functions-
        - Methods declared using static keyword belongs to the class and we do not need to create an object to access it.
        - Static methods can only access static data members.
        - Static methods do no have 'this' keyword. This is because 'this' keyword belongs to the object and not the class.

IMP : A static member can be called/accessed even if no objects of the class exist and in that case the static members are called/accessed using only the class name and the scope resolution operator '::'.

TOPIC: Use Case
Suppose you're initializing a private data member as static. In that case, you won't be able to initialize its value by using the '::' operator outside the class because now it's private and can only be accessed from inside the class. So the other way is to make it constant and initialize its value (const static int objectCount = 0), but in this case, you won't be able to change the value.
*/

#include <iostream>
using namespace std;

class Box
{
private:
    double l, b, h;
    const static int type = 1;

public:
    static int objectCount; // Static data member

    // Constructor definition
    Box(double l = 2.0, double b = 2.0, double h = 2.0)
    {
        cout << "\nConstructor called.";
        this->l = l;
        this->b = b;
        this->h = h;

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
    static void getType()
    {
        cout << "\nThe type of boxes is: " << type;
    }
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void)
{
    // Print total number of objects before creating object.
    cout << "\nInital Stage Count: " << Box::getCount();

    Box Box1(3.3, 1.2, 1.5); // Declare box1
    Box Box2(8.5, 6.0, 2.0); // Declare box2
    Box1.objectCount++;

    // Print total number of objects after creating object.
    cout << "\nFinal Stage Count: " << Box2.getCount();
    // cout << "Final Stage Count: " << Box::getCount() << endl;

    Box::getType();

    return 0;
}