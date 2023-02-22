/*
TOPIC: Static Variables Inside Functions
    -> The static variables are only declared once and their value is  carried through the function calls.

    -> In the code, the variable 'count' is declared as static. The variable 'count' is not getting initialized for every time the function is called.
*/

#include <iostream>
#include <string>
using namespace std;

void demo()
{
    static int count = 0;
    cout << count << " ";

    count++;
}

int main()
{
    for (int i = 0; i < 5; i++)
        demo();
    return 0;
}