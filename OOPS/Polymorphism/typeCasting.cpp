/*

https://www.scaler.com/topics/difference-between-function-overloading-and-overriding-in-cpp/

-> One subtle problem with distinguishing based on data type of function is type casting (i.e. say a char type can be promoted to int or float or double). The C++ compiler follows a series of priorities when matching the function application:

    - It first tries to match exact type (int to int / float to float)
    - If no match is found, it promotes the data type and retries (conversion between int to char and char to int or float to double and double to float)
    - If still no match is found, C++ compiler throws an error.
*/

#include <iostream>
using namespace std;

void print(int a, float b)
{
    cout << a + b;
}
void print(float a, int b)
{
    cout << a + b;
}

int main()
{
    print(2, 2);
    /*
    Here, rpint(2,2) is throwing error because the function call print(2,2) can be internally promoted to (int(2), float(2)) or (float(2), int(2)). This causes ambiqguity, therefore it causes errors.
    */

    print(2.0, 2); // THis function call will not throw an error because there is no ambiguity.

    return 0;
}