/*
TOPIC: Virtual Base Class
    -> When multiple classes ('A1' and 'B1'), inherit from a common base class 'Base', and another class 'C2' derives from those multiple classes ('A1' and 'B1'), there is a risk of multiple copies of the base class 'Base' being included in the object of derived class 'C2'. This can lead to ambiguity.

    -> To prevent this, virtual inheritance is used. By declaring the base class 'Base' as 'virtual' during inheritance (inheriting class 'A1' and class 'B1' from class 'Base'), you ensure that object of base class 'Base' is only constructed once, and that object is shared in the inheritance hierarchy.
    This eliminates ambiguity and avoids multiple copies of the base class 'Base'.

    -> NOTE: The 'Base' class constructor will only be called once per object('Base' or 'A1' or 'B1' or 'C2') creation.

TOPIC: In this example
    1. 'A1' and 'B1' inherit from 'Base' using virtual inheritance.

    2. 'C2' inherits from both 'A1' and 'B1' using normal inheritance.

    3. Since 'Base' is inherited virtually by 'A1' and 'B1', therefore 'C2' contains only one copy of 'Base'.
*/

#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "\n'Base' class constructor called.";
    }
    int i;
};

// 'A1' inherits 'Base' as virtual.
class A1 : virtual public Base
{
public:
    int j;
};

// 'B1' inherits 'Base' as virtual.
class B1 : virtual public Base
{
public:
    int k;
};

// 'C2' inherits 'A1' and 'B1' normally
class C2 : public A1, public B1
{
public:
    void print()
    {
        cout << "\ni: " << i;
    }
};

int main()
{
    C2 obj;
    cout << "\n\n";

    // Trying to access the data member 'i' derived from class 'A1' and 'B2' without using the scope resolution operator '::' will not throw an error because class 'A' and class 'B' virtually inherited from base class 'Base'. Therefore only one object of base class 'Base' is present in the entire inheritance tree.
    obj.i = 10;
    obj.print();
    cout << "\n\n";

    obj.A1::i = 20;
    obj.print();
    cout << "\n\n";

    obj.B1::i = 30;
    obj.print();
    cout << "\n\n";

    return 0;
}
