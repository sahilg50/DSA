#include <iostream>
#include <cmath>
using namespace std;
class Point
{
private:
    float x1, y1;
    Point(float x, float y)
    {
        x1 = x;
        y1 = y;
    };

public:
    // polar(radius, angle)
    static Point Polar(float, float);

    // rectangular(x, y)
    static Point Rectangular(float, float);

    void display();
};

// utility function for displaying of coordinates
void Point ::display()
{
    cout << "x :: " << this->x1 << endl;
    cout << "y :: " << this->y1 << endl;
}

// return polar coordinates
Point Point ::Polar(float x, float y)
{
    return Point(x * cos(y), x * sin(y));
}

// return rectangular coordinates
Point Point ::Rectangular(float x, float y)
{
    return Point(x, y);
}

int main()
{
    // Polar coordinates
    Point pp = Point::Polar(5.7, 1.2);
    cout << "polar coordinates \n";
    pp.display();

    // rectangular coordinates
    Point pr = Point::Rectangular(5.7, 1.2);
    cout << "rectangular coordinates \n";
    pr.display();

    return 0;
}