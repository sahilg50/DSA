/*
-> Preprocessing performs (usually simple) operations on the source file(s) prior to compilation.

-> Typical preprocessing operations include:
    • Expanding macros (shorthand notations for longer constructs).
    For example, in C, #define abc(x,y) (3*x+y*(2+x))
    In program n = abc(a,b) becomes n = (3*a+b*(2+a))

    • Inserting named files.
    For example, in C++, # include <iostream> is replaced by the contents of the file iostream.h
*/
#include <iostream>
using namespace std;

#define N(a) (10 * a); // N(a) expands to (10 * a) during preprocessing.

int main()
{
    cout << N(5);
    return 0;
}