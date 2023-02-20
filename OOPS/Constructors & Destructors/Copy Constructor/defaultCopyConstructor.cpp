/*
TOPIC: Default Copy Constructor:
    -> It is an overloaded constructor.

    -> The copy constructor is invoked when the new object is initialized with the existing object.

    -> The compiler automatically generates the implicit default copy constructor if a programmer does not define a custom copy constructor.

    -> The object to be copied is passed as an argument to the function.

    -> The default version of the copy constructor (created by the compiler) always makes a shallow copy. It means that the object is copied exactly as it is. Each data member value is copied exactly over to the corresponding data member location in the new object.

        -> Suppose one of the data members is a pointer to an array. When we create a copy of this object, the address stored in this pointer will be copied to the other pointer(data member of the new object). Now, when we make any change in the array using any object, it will be reflected in both objects because both pointers are pointing to the same array.

        -> Suppose one of the data member is an integer variable. When we create a copy of this object, the value stored in that integer variable will be copied to the other integer variable(data member of the new object). Now, if we change value of this data member of the new object then the change won't be reflected in the other object because both the data members hold their separate copies of the integer.

    -> Both the existing object and new object shares the different memory locations but the data members may share same memory location depending upon the type of copy(Shallow copy or deep copy) as we've seen above.
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