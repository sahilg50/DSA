/*
TOPIC: Abstract Class:
    -> A class that has at least one pure virtual function is called an abstract class. It can have a data member, abstract method, method body (non-abstract method), and a constructor.

    -> An abstract class is one in which there is a declaration but no definition for a member function.

    -> This concept is implemented in C++ by declaring a member function as virtual and assigning it to zero.

TOPIC: Pure Abstract Class
    -> A pure Abstract class has only abstract member functions and no data or concrete member functions.

    -> A pure abstract class can't be used to create objects so it doesn't have a constructor.

    -> A pure abstract class is used to define an interface and is intended to be inherited by concrete classes. It's a way of forcing a contract between the class designer and the users of that class. The users of this class must declare a matching member function for the class to compile.

TOPIC: Points To Note
    -> If we do not override the pure virtual function in derived class, then derived class also becomes abstract class.

TOPIC: Use Case
    -> Sometimes implementation of all functions cannot be provided in a base class because we don’t know the implementation. Such a class is called an abstract class. For example, let Shape be a base class. We cannot provide the implementation of function area() in Shape, but we know every derived class must have the implementation of area()

*/

#include <iostream>
using namespace std;

// This is pure abstract class
class SmartPhone
{
public:
    // Pure Virtual Function
    virtual void makeCall() = 0;
    virtual void takeSelfie() = 0;
};

class Android : public SmartPhone
{
public:
    void makeCall() { cout << "Android Calling...\n"; }
    void takeSelfie() { cout << "Android Selfie\n"; }
};

class IPhone : public SmartPhone
{
public:
    void makeCall() { cout << "IPhone calling...\n"; }
    void takeSelfie() { cout << "IPhone Selfie\n"; }
};

int main()
{
    SmartPhone *a = new Android;
    a->makeCall();
    a->takeSelfie();

    SmartPhone *i = new IPhone;
    i->makeCall();
    i->takeSelfie();
    return 0;
}