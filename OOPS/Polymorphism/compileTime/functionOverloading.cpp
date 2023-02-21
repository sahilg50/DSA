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

void print(int a, float b) { cout << a + b; }

void print(float a, int b) { cout << a + b; }

int area(int x) { return x * x; }

int area(int x, int y) { return x * y; }

float area(float r) { return 3.14 * r * r; }

int main()
{

    /*
    print(2,2);
    The above statement will throw error because the function call print(2, 2) can be internally promoted to (int(2), float(2)) or (float(2), int(2)). This causes ambiguity, therefore it will cause errors.


    print(2.0, 2.0);
    The above statement will throw error because the function call print(2.0, 2.0) can be internally promoted to (int(2.0), float(2.0)) or (float(2.0), int(2.0)). Again ambiguity !
    */

    print(2.0, 2);

    cout << "\nArea Of Square: " << area(5);
    cout << "\nArea Of Rect: " << area(5, 2);
    cout << "\nArea Of Circle: " << area(float(5));

    return 0;
}