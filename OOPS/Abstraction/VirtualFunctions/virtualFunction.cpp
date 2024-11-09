/*
https://www.youtube.com/watch?v=BuWehV6sD1c

Both virtual functions and pure virtual functions are used in C++ to achieve runtime polymorphism, but they differ in functionality and purpose.

TOPIC: Virtual Function

    -> A virtual function is a member function in a base class that can be overridden in derived classes. It provides a mechanism for dynamic dispatch, meaning the function to be called is determined at runtime based on the type of the object.

    -> A virtual function can have a body in the base class.

    -> Derived classes may or may not override the virtual function.

    -> If not overridden, the base class function is called.

    -> Base class object can be created.


TOPIC: Inheritance Heirarchy

                        Base
                (virtual display())
                /       |          \
            Square    Circle    Rectangle
(display() override)            (display() override)

*/
#include <iostream>
using namespace std;

class Shape
{
public:
    // Constructor
    Shape()
    {
        cout << "\nShape constructor called!";
    }

    // Destructor
    ~Shape()
    {
        cout << "\nShape destructor called!";
    }

    // Member function (display())
    virtual void display()
    {
        cout << "\nShape member function called!";
    }
};

class Square : public Shape
{
public:
    // Constructor
    Square()
    {
        cout << "\nSquare constructor called!";
    }

    // Destructor
    ~Square()
    {
        cout << "\nSquare destructor called!";
    }

    // Overrides the base class 'Base' member function (display())
    void display() override
    {
        cout << "\nSquare member function called!";
    }
};

class Rectangle : public Shape
{
public:
    // Constructor
    Rectangle()
    {
        cout << "\nRectangle constructor called!";
    }

    // Destructor
    ~Rectangle()
    {
        cout << "\nRectangle destructor called!";
    }

    // Overrides the base class 'Base' member function (display())
    void display() override
    {
        cout << "\nRectangle member function called!";
    }
};

class Circle : public Shape
{
public:
    // Constructor
    Circle()
    {
        cout << "\nCircle constructor called!";
    }

    // Destructor
    ~Circle()
    {
        cout << "\nCircle destructor called!";
    }
};

int main()
{
    Shape *shape = new Shape;
    shape->display();
    shape->Shape::display();
    /************************************************************************************/

    Shape *square = new Square;
    /*
    The display() method of the derived class 'Square' is called because it overrides the virtual display() method from the base class 'Shape'.
    */
    square->display();
    /*
    To call the virtual display() method from the base class 'Shape', the scope resolution operator '::' must be used.
    */
    square->Shape::display();
    cout << "\n\n";
    /************************************************************************************/

    Shape *rectangle = new Rectangle;
    /*
    The display() method of the derived class 'Rectangle' is called because it overrides the virtual display() method from the base class 'Shape'.
    */
    rectangle->display();
    /*
    To call the virtual display() method from the base class 'Shape', the scope resolution operator '::' must be used.
    */
    rectangle->Shape::display();
    cout << "\n\n";
    /***************************************************************************************/

    Shape *circle = new Circle;
    /*
    The display() method of the base class 'Shape' is called because the derived class 'Circle' does not override the virtual display() method from 'Shape'.
    */
    circle->display();
    circle->Shape::display();

    return 0;
}