/*
    https://www.scaler.com/topics/difference-between-function-overloading-and-overriding-in-cpp/

TOPIC: What is function overloading ?
    -> Function overloading or method overloading is the ability to create multiple functions of the same name with different implementations.

TOPIC: How to distinguish functions from each other ?
    -> The number of parameters
    -> The data type of parameters

    -> Functions cannot be distinguished from each other based upon the return type of the function.

TOPIC: Function Overloading and Type Casting
    -> One subtle problem with distinguishing functions based on data type of parameters of function is type casting (i.e. say a char type can be promoted to int or float or double).


    The C++ compiler follows a series of priorities when matching the function application:
    -> It first tries to match exact type (int to int / float to float)
    -> If no match is found, it promotes the data type and retries (conversion between int to char and char to int or float to double and double to float).
    -> If still no match is found, C++ compiler throws an error.
*/

#include <iostream>
using namespace std;

void print(int a)
{
    cout << "\nprint(int a) called!\n";
    cout << a << endl;
}

void print(int a, int b)
{
    cout << "\nprint(int a, int b) called!\n";
    cout << a << " " << b << endl;
}

void print(double a, double b)
{
    cout << "\nprint(double a, double b) called!\n";
    cout << a << " " << b << endl;
}

void print(float a, float b)
{
    cout << "\nprint(float a, float b) called!\n";
    cout << a << " " << b << endl;
}

void print(double a, int b)
{
    cout << "\nprint(double a, int b) called!\n";
    cout << a << " " << b << endl;
}

int main()
{
    // print(5) will not throw an error, because print(int a) function will be called as '5' is int.
    print(5);

    /*
    print(6.5) will not throw an error but will generate a "warning: implicit conversion from 'double' to 'int' changes value from 6.5 to 6"
    The compiler will perform implicit typecasting to covert 'double' to 'int' and then will call the function print(int a).
    */
    print(6.5);

    // print(5, 6) will not throw an error, because print(int a, int b) function will be called as both '5' and '6' are int.
    print(5, 6);

    // print(2.9, 1.3) will not throw an error, because print(double a, double b) function will be called as both '2.9' and '1.3' are double.
    print(2.9, 1.3);

    // print(4.1, 2) will not throw an error, because print(double a, int b) function will be called as '4.1' is double and '2' is int.
    print(4.1, 2);

    /*
    print (2, 4.1) will throw an error because there is no function like 'print(int a, double b)'. Therefore, the compiler will look at other instances of print function which involve the minimum number of typecasting.
    All the print function instances are:
        -> void print(int a, int b)
        -> void print(double a, double b)
        -> void print(float a, float b)
        -> void print(double a, int b)

    But the 'print' function(s) that involves minimum number of typecasting are:
        -> void print(int a, int b)
        -> void print(double a, double b)

    Still, there are two instances of the 'print' function that are applicable. Therefore, the compiler will now throw an error: "call to 'print' is ambiguous."

    NOTE: If there had been only one candidate function, the compiler would have performed the typecasting and called the function.
    */
    print(2, 4.1);

    return 0;
}