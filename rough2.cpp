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

class Square : public Shape
{
private:
protected:
public:
    int dim1 = 3;
    int dim2 = 3;
};

class Rectangle : public Shape
{
private:
protected:
public:
    int dim1 = 5;
    int dim2 = 10;
};

int main()
{
    Square sq;
    cout << sq.Shape::dim1 << " " << sq.Shape::dim2;

    Rectangle return 0;
}