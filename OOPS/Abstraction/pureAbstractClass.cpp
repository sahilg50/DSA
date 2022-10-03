/*
-> Pure Abstract Classes:
An abstract class is one in which there is a declaration but no definition for a member function. The way this concept is expressed in C++ is to have the member function declaration assigned to zero.

A pure Abstract class has only abstract member functions and no data or concrete member functions. In general, a pure abstract class is used to define an interface and is intended to be inherited by concrete classes. It's a way of forcing a contract between the class designer and the users of that class. The users of this class must declare a matching member function for the class to compile.
*/

#include <iostream>
using namespace std;

class SmartPhone
{
public:
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