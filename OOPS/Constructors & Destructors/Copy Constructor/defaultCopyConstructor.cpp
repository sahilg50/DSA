/*
NOTE:
    - It is an overloaded constructor.
    - It initializes the new object with the existing object.
        - The copy constructor is invoked when the new object is initialized with the existing object.
        - The object is passed as an argument to the function.
        - It returns the object.
    - Both the existing object and new object shares the different memory locations but the data members may share same memory location depending upon the type of copy(Shallow copy or deep copy).

    DEFAULT COPY CONSTRUCTOR:
        - If a programmer does not define the copy constructor, the compiler will automatically generate the implicit default copy constructor.
        - The default copy constructor in C++ can only create a shallow copy of an object.
        - The programmer does not need to write the definition of the default copy constructor in C++.
        - The default version of the copy constructor (created by the compiler) makes what is known as a shallow copy. This simply means that the object is copied exactly as it is -- each member data value is copied exactly over to the corresponding member data location in the new object.
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
    p1.info();
    *(p1.x) = 100;
    p2.info();

    return 0;
}