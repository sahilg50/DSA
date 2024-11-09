/*
TOPIC: Using scope resolution operator '::' to access/update ambiguous data members and member functions in the derived class.

Diamond inheritance structure:
                Shape
            (dim1, dim2)
            /           \
        Square      Rectangle
            \           /
               Hybrid
*/

#include <iostream>
using namespace std;

class Shape
{
private:
protected:
public:
    Shape()
    {
        cout << "\nClass 'Shape' constructor called.";
    }

    int dim1;
    int dim2;
};

class Square : public Shape
{
private:
protected:
public:
    void infoSquare()
    {
        cout << "\nHey, I'm square!";
    }
    void area()
    {
        cout << "\nArea of square: " << dim1 * dim2;
    }
};

class Rectangle : public Shape
{
private:
protected:
public:
    void infoRectangle()
    {
        cout << "\nHey, I'm rectangle!";
    }
    void area()
    {
        cout << "\nArea of rectangle: " << dim1 * dim2;
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

        // NOTE: We cannot use 'dim1' and 'dim2' directly in method declaration, because it's ambiguous.
    }
};

int main()
{
    Hybrid h;
    h.infoHybrid();
    cout << "\n\n";

    /*
    We'll set the data members of the "Hybrid" class object 'h' as follows:
    When acting as square: dim1 = 5, dim2 = 5
    When acting as rectangle: dim1 = 3, dim3 = 10

    If we try to set 'dim1' and 'dim2' using the following statement:
    h.dim1 = 3, h.dim2 = 10;
    then it will throw an error because the data members('dim1' and 'dim2') are derived from both the class "Shape" and class "Rectangle" and it will be ambiguous for the compiler. The compiler will not understand if we're trying access/update the data members('dim1' and 'dim2') derived from class "Shape" or class "Rectangle".

    To solve the problem, we'll use the scope resolution operator '::' to access and update the following data members:
        1. dim1 and dim2 derived from class "Square"
        2. dim1 and dim2 derived from class "Rectangle".

    NOTE: The 'Shape' class constructor will be called twice.
    */
    h.Square::dim1 = 5;
    h.Square::dim2 = 5;

    h.Rectangle::dim1 = 3;
    h.Rectangle::dim2 = 10;

    /*
    We'll use the scope resolution operator '::' to call the following methods:
        1. area() derived from class "Square"
        2. area() derived from class "Rectangle"
    */
    // Let the "Hybrid" class act as square.
    h.infoSquare();
    h.Square::area();
    cout << "\n\n";

    // Let the "Hybrid" class act as rectangle.
    h.infoRectangle();
    h.Rectangle::area();
    cout << "\n\n";

    h.printDimensions();
    cout << "\n\n";

    return 0;
}