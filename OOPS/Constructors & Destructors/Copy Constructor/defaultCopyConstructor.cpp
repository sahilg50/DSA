/*
TOPIC: Default Copy Constructor:
    -> It is an overloaded constructor.

    -> The copy constructor is invoked when the new object is initialized with the existing object.

    -> The compiler automatically generates the implicit default copy constructor if a programmer does not define a custom copy constructor.

    -> The object to be copied is passed as an argument to the function.

    -> The default version of the copy constructor (created by the compiler) always makes a shallow copy. It means that the object is copied exactly as it is. Each data member value is copied exactly over to the corresponding data member location in the new object.

    -> Both the existing object and new object shares the different memory locations but the data members may share same memory location depending upon the type of copy(Shallow copy or deep copy) as we've seen shallow copy and deep copy.
*/

#include <iostream>
using namespace std;

class Point
{
public:
    int *x, y;
    Point(int i, int j)
    {
        cout << "Initialization constructor called." << endl;
        *x = 10;
        y = 20;
    }
    void info()
    {
        cout << *this->x << " " << this->y << endl;
    }
};

int main()
{
    Point p1(10, 20);
    Point p2(p1);
    *(p2.x) = 100;
    p2.y = 200;
    p1.info();

    return 0;
}