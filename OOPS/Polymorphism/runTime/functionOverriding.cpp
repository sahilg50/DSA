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

class Phone
{
private:
protected:
public:
    int number = 10;
    void info()
    {
        cout << "\nModel: Phone\nNumber: " << this->number << endl;
    }
};

class Android : public Phone
{
private:
protected:
public:
    int number = 12345;

    // Overriding the info() function.
    void info()
    {
        cout << "\nModel: Android\nAndroid number: " << this->number;
        cout << "\nBase number: " << this->Phone::number << endl;
    }
};

int main()
{
    Android device;
    device.info();
    cout << device.Phone::number << endl;
    return 0;
}