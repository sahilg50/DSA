/*
Diamond inheritance structure (problem):
                Shape
            (dim1, dim2)
            /           \
        Square          Rectangle
        (dim1, dim2)  (dim1, dim2)
                \       /
                 Hybrid

In this diamond problem, 'Hybrid' class object 'h' contains 4 sets of data members ('dim1' and 'dim2') due to the following inheritance structure:
    -> 2 sets of data members ('dim1' and 'dim2') of base class 'Shape' are inherited when class 'Square' and class 'Rectangle' inherits from class 'Shape'.
    -> 1 set of data members ('dim1' and 'dim2') of class 'Square' is inherited when class 'Hybrid' inherits from class 'Square'.
    -> 1 set of data members ('dim1' and 'dim2') of class 'Rectangle' is inherited when class 'Hybrid' inherits from class 'Rectangle'.


Looking at the heirarchy tree inheritance structure from 'Hybrid' class object 'h' point of view, the following observations were made:
    -> No error occurs when compiler tries to access data members ('dim1' and 'dim2') of class 'Square' from inside class 'Hybrid'.

    -> No error occurs when compiler tries to access data members ('dim1' and 'dim2') of class 'Rectangle' from inside class 'Hybrid'.

    -> Error occurs when compiler tries to access data members ('dim1' and 'dim2') of base class 'Shape' from inside class 'Hybrid'. This is because 2 copies of data members ('dim1' and 'dim2') of base class 'Shape' are present inside the inheritance hierarchy. As a result, the compiler cannot determine which set of data members ('dim1' and 'dim2') to use, leading to an ambiguous situation, thereby throwing an error.

    -> Solution: To prevent this, virtual inheritance is used. By declaring the base class 'Shape' as 'virtual' during inheritance (inheriting class 'Square' and class 'Rectangle' from class 'Shape'), you ensure that object of base class 'Shape' is only constructed once, and that object is shared in the inheritance hierarchy.
    This eliminates ambiguity and avoids multiple copies of the base class 'Shape'.

    Diamond inheritance structure (solution):
                Shape
            (dim1, dim2)
            /           \
        virtual         virtual
        Square          Rectangle
        (dim1, dim2)  (dim1, dim2)
                \       /
                 Hybrid

    -> NOTE: The 'Base' class constructor will only be called once per object('Base' or 'A1' or 'B1' or 'C2') creation.
*/
#include <iostream>
using namespace std;

class Shape
{
private:
protected:
public:
    int dim1 = -1;
    int dim2 = -1;
};

class Square : virtual public Shape
{
private:
protected:
public:
    int dim1 = 5;
    int dim2 = 5;
    void infoSquare()
    {
        cout << "\nHey, I'm square!";
    }
};

class Rectangle : virtual public Shape
{
private:
protected:
public:
    int dim1 = 3;
    int dim2 = 10;
    void infoRectangle()
    {
        cout << "\nHey, I'm rectangle!";
    }
};

class Hybrid : public Square, public Rectangle
{
private:
protected:
public:
    void infoHybrid()
    {
        cout << "\nHey, I'm hybrid!";
    }

    void printDimensions()
    {
        cout << "\nDimensions derived from class Square: " << Square::dim1 << " " << Square::dim2;

        cout << "\nDimensions derived from class Rectangle: " << Rectangle::dim1 << " " << Rectangle::dim2;

        cout << "\nDimensions derived from class Shape: " << Square::Shape::dim1 << " " << Square::Shape::dim2;
    }
};

int main()
{
    Hybrid h;
    h.printDimensions();
    cout << "\n\n";
    return 0;
}