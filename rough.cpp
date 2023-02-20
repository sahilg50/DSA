#include <iostream>
using namespace std;

int init(int num)
{
    cout << "\nFunc. to init the variable called!\n";
    return num;
}

int main()
{
    int a(init(10));
    cout << a;

    int b = 20;
    cout << b;
    return 0;
}