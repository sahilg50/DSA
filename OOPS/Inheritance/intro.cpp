/*
https://www.codingninjas.com/codestudio/library/inheritance-in-c

- Inheritance is a mechanism of reusing and extending existing classes without modifying them, thus producing hierarchical relationships between them.
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

// deriving class B from class A
class B : public A
{
public:
    void print_message()
    {
        cout << "Method of class B\n";
    }
};

// deriving class C from class A
class C
{
public:
    void print_statement()
    {
        cout << "Method of class C\n";
    }
};

// deriving class D from B and C
class D : public B, public C
{
public:
    void print_function()
    {
        cout << "Method of class D\n";
    }
};

// driver function
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