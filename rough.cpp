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
    Box1.objectCount++;

    // Print total number of objects after creating object.
    cout << "Final Stage Count: " << Box::getCount() << endl;
    // cout << "Final Stage Count: " << Box2.getCount() << endl;

    return 0;
}