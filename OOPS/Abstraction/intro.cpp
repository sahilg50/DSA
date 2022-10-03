/*
Abstraction means displaying only essential information and hiding the unimportant and complex details. Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation.
*/

#include <iostream>
using namespace std;

class NUM
{
private:
    int a, b;

public:
    // method to set values of
    // private members
    void set(int x, int y)
    {
        a = x;
        b = y;
    }

    void display()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};

int main()
{
    NUM obj;
    obj.set(10, 20);
    obj.display();
    return 0;
}