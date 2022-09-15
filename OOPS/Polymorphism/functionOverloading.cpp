/*
    Apart from distinguishing based on the number of arguments, C++ can also distinguish the function calls based on the data type of the arguments passed to the function. Now, the supervisor is impressed and also wants you to code for the condition of the circle if the user provided a floating value input. So if I were to pass a float value you would return the area of circle (3.14 * r * r) and if I were to pass int value you would return x * x as before. I can define a third function which distinguishes based on data type passed.

    Side Note: One subtle problem with distinguishing based on data type of function is type casting (i.e. say a char type can be promoted to int or float or double). The C++ compiler follows a series of priorities when matching the function application:
        - It first tries to match exact type (int to int / float to float)
        - If no match is found, it promotes the data type and retries (conversion between int to char and char to int or float to double and double to float)
        - If still no match is found, C++ compiler throws an error.
*/

#include <iostream>
using namespace std;

int area(int x)
{
    return x * x;
}

int area(int x, int y)
{
    return x * y;
}

float area(float r)
{
    return 3.14 * r * r;
}
int main()
{

    int areaOfSquare = area(5);
    int areaOfRect = area(5, 2);
    float areaOfCircle = area(float(5));

    cout << "Area of square with side length 5 is " << areaOfSquare << endl;
    cout << "Area of rectangle with length 5 and breadth 2 is " << areaOfRect << endl;
    cout << "Area of circle with radius 5.0 is " << areaOfCircle << endl;

    return 0;
}