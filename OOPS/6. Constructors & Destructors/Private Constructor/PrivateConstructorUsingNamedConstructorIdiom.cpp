/*
TOPIC: Named Constructor Idiom
    -> Since the constructor has the same name as of class, different constructors are differentiated by their parameter list, but if the number of constructors is more, implementation can become error-prone.

    -> With the Named Constructor Idiom, you declare all the class’s constructors in the private or protected sections, and then for accessing objects of the class, you create public static functions whose return type is that class.

TOPIC: Note
    -> In this example we're able to return constructor from a static method because the constructor that we're returning belongs to the class and not to the oject.
*/
#include <iostream>
#include <cmath>
using namespace std;
class Point
{
private:
    // c1 = coordinate 1,   c2 = coordinate 2
    float c1, c2;
    Point(float c1, float c2)
    {
        c1 = c1;
        c2 = c2;
    };

public:
    // polar(radius, theta)
    static Point Polar(float, float);

    // rectangular(x, y)
    static Point Rectangular(float, float);

    void display()
    {
        cout << "(" << this->c1 << ", " << this->c2 << ")";
    }
};

// Returns polar coordinates
Point Point ::Polar(float r, float theta)
{
    return Point(r, theta);
}

// Returns rectangular coordinates
Point Point ::Rectangular(float r, float theta)
{
    return Point(r * cos(theta), r * sin(theta));
}

int main()
{
    // Polar coordinates
    Point pp = Point::Polar(5.7, 1.2);
    cout << "\nPolar coordinates (r, theta): ";
    pp.display();

    // Rectangular coordinates
    Point pr = pr.Rectangular(5.7, 1.2);
    cout << "\nRectangular coordinates (x, y): ";
    pr.display();

    return 0;
}