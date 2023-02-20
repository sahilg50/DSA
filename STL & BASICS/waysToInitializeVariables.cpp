/*
TOPIC: Different Ways to Initialize Variables
    -> As AndersK suggested, the best way to initialize variables in C++ is using {}. Because it ensures type safety, let's talk more about it.

    -> Type Safety: Every object in C++ is used according to its type and an object needs to be initialized before its use.


    TOPIC: Safe Initialization: '{}' or 'auto'
    The compiler protects from information loss during type conversion.

    -> int a{7};        The initialization is OK
    -> int a = {10};    The initialization is OK
    -> int b{7.5};      Compiler shows ERROR because of information loss.

    -> auto c = 7.5;    The initialization is OK
    -> auto c(7.5);     The initialization is OK
    -> auto c{7.5};     The initialization is OK


    TOPIC: Unsafe Initialization: '=' or '()'
    The compiler doesn't protect from information loss during type conversion.

    -> int a = 7;       The initialization is OK
    -> int a = 7.5;     The initialization is OK, but information loss occurs. The actual value of a will become 7.0

    -> int c(7);        The initialization is OK
    -> int c(7.5);      The initialization is OK, but information loss occurs. The actual value of a will become 7.0
*/

#include <iostream>
#include <typeinfo>
using namespace std;

// Custom function initialize integer
int init(int num)
{
    cout << "\n\nInit Func. called!";
    return num;
}

int main()
{
    int a(30.4);
    cout << "\na : " << a << ", Type: " << typeid(a).name();

    int b(init(20.10));
    cout << "\nb : " << b << ", Type: " << typeid(b).name();

    auto c{40.90};
    cout << "\n\nc-: " << c << ", Type: " << typeid(c).name();
    return 0;
}
