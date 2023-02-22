/*
https://www.codingninjas.com/codestudio/library/inheritance-in-c

TOPIC: What is Inheritance?
    -> Inheritance is a mechanism of reusing and extending existing classes without modifying them, thus producing hierarchical relationships between them.

TOPIC: Types of Access Specifiers
    -> Public
    -> Protected
    -> Private

TOPIC: Types of Inheritance
    -> Single Inheritance
    -> Multiple Inheritance
    -> Hierarchical Inheritance
    -> MultiLevel Inheritance
    -> Hybrid Inheritance

TOPIC: NOTE
    -> Protected and Private members cannot be accessed in the driver function(main function) directly.

    -> Private members are never inherited.

    -> If publicly inherited, public members will be public and protected members will be protected.

    -> If we inherit under a protected specifier, public and protected members become protected.
*/

// Example of hybrid inheritance.
#include <iostream>
using namespace std;

// defining base class A
class A
{
private:
    int data;

public:
    // a function to set the value of data
    void set_data(int new_data)
    {
        data = new_data;
    }

    // a function to get the value of data
    int get_data()
    {
        return data;
    }
};

// Deriving class B from class A
class B : public A
{
public:
    void print_message()
    {
        cout << "Method of class B\n";
    }
};

// Deriving class C from class A
class C
{
public:
    void print_statement()
    {
        cout << "Method of class C\n";
    }
};

// Deriving class D from B and C
class D : public B, public C
{
public:
    void print_function()
    {
        cout << "Method of class D\n";
    }
};

// Driver function
int main()
{

    D obj;

    // accessing functions of class A
    obj.set_data(55);
    cout << obj.get_data() << endl;

    obj.print_message();
    obj.print_statement();
    obj.print_function();

    return 0;
}