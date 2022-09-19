/*

https://www.scaler.com/topics/difference-between-function-overloading-and-overriding-in-cpp/

Function overriding is a runtime polymorphism where more than one methods with same signature(same name, number of parameters and the type of the parameters) perform different tasks.

We know that child classes inherit all public data and methods from the parent class. So the Square class also inherits the area function. However, we redefine the area function to be side * side. This redefinition of the area function is an example of function overriding. Basically, C++ knows that you specifically redefined the area function for the Square class. This overriding of function is a type of runtime polymorphism.

-> KEY POINTS:
    - Function overriding is applicable exclusively to an inherited class (or in other words a subclass).
    - Function overriding is resolved at run time.
    - Overridden functions are in different scopes.
    - Overridden functions have same function signatures.
    - Function overriding is used when we want to add some additional functionality on top of base class implementation.

-> Q: WHy function/method overriding is runtime polymorphism?
   Ans: C++ distinguishes the function call at runtime instead of knowing it during compilation because the function signature is similar at compile time.
*/

#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length, breadth;

public:
    Rectangle() : length(0), breadth(0){};
    Rectangle(int l, int b) : length(l), breadth(b){};

    void area()
    {
        cout << "The area of rectangle is: " << length * breadth << endl;
    }

    void sayHello()
    {
        cout << "Hello from Rectangle! " << endl;
    }
};

class Square : public Rectangle
{
private:
    int side;

public:
    Square() : side(0){};
    Square(int s) : side(s){};

    void area()
    {
        cout << "The area of sqaure is: " << side * side << endl;
    }
};

int main()
{

    Rectangle r(2, 4);
    r.area();
    r.sayHello();

    Square s(3);
    s.area();
    s.sayHello();
    return 0;
}