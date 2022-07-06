#include <iostream>
using namespace std;

/*
- Nullptr is a keyword that represents zero as an address (its type is considered a pointer-type), while NULL is the value zero as an int . If you're writing something where you're referring to the zero address, rather than the value zero, you should use nullptr .

- The nullptr keyword represents a null pointer value. Use a null pointer value to indicate that an object handle, interior pointer, or native pointer type does not point to an object.
*/

int main()
{
    int *ptr = nullptr;
    cout << *ptr;

    int *ptr2 = NULL;
    cout << *ptr2;

    return 0;
}