/*
TOPIC: Different Ways to Initialize Variables
    -> As AndersK suggested, the best way to initialize variables in C++ is using {}. Because it ensures type safety, let's talk more about it.

    -> Type Safety: Every object in C++ is used according to its type and an object needs to be initialized before its use.


    TOPIC: Safe Initialization: '{}' or 'auto'
    The compiler protects from information loss during type conversion.

    -> int a{7}; The initialization is OK
    -> int b{7.5}; Compiler shows ERROR because of information loss.

    -> auto c = 7.5; The initialization is OK
    -> auto c(7.5);


    TOPIC: Unsafe Initialization: '=' or '()'
    The compiler doesn't protect from information loss during type conversion.

    -> int a = 7; The initialization is OK
    -> int a = 7.5; The initialization is OK, but information loss occurs. The actual value of a will become 7.0

    -> int c(7); The initialization is OK
    -> int c(7.5); The initialization is OK, but information loss occurs. The actual value of a will become 7.0
*/

#include <iostream>
#include <typeinfo>
using namespace std;

int init(int num)
{
    cout << "\nFunc. to init the variable called!\n";
    return num;
}

int main()
{

    int a = 10;
    cout << typeid(a).name() << endl;

    int b(init(20));
    cout << typeid(b).name() << endl;
    return 0;
}
