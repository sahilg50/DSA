#include <iostream>
#include <vector>
using namespace std;

class Number
{
public:
    int a = 10, b = 20;
};

int main()
{
    Number N1;
    Number N2;
    N2 = N1;
    N2.a = 30;
    cout << &N1 << endl
         << &N2;
    return 0;
}