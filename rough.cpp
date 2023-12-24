#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    int *ptr1 = &a;
    int *ptr2 = &b;

    // swap(ptr1, ptr2);
    cout << *ptr1 << " " << *ptr2;
    return 0;
}
