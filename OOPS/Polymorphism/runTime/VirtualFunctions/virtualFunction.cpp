/*
https://www.youtube.com/watch?v=BuWehV6sD1c

TOPIC: Virtual Function

    -> A virtual function is a member function which is declared and defined within a base class and is overridden (re-defined and re-declared) by a derived class.

    -> It provides a mechanism for dynamic dispatch, meaning the function to be called is determined at runtime based on the type of the object. It is mainly used to achieve runtime polymorphism.

    -> Derived classes may or may not override the virtual function. If not overridden, the base class function is called.

    -> When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the function.

    -> A virtual function can be a friend function of another class.

    -> A class may have virtual destructor but it cannot have a virtual constructor.

    -> Virtual functions cannot be static.

NOTE: We cannot create an object of the abstract class.
    -> An abstract class contains at least one pure virtual function(abstract method). It can include data members, non-abstract methods (virtual or non-virtual functions, but with a method body), and even a constructor.

-> Q. Why do we declare functions are virtual functions while function overriding?
    Ans: Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for function call.


TOPIC: Inheritance Heirarchy

                      Shape
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