#include <iostream>
using namespace std;

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