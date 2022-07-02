#include <iostream>
using namespace std;

template <typename T>
void Swap(T &a, T &b) // Passing the variables as references
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{

    int a, b;
    cin >> a >> b;
    cout << endl
         << a << " " << b;
    Swap<int>(a, b);
    cout << endl
         << a << " " << b << endl
         << endl;

    char c, d;
    cin >> c >> d;
    cout << endl
         << c << " " << d;
    Swap<char>(c, d);
    cout << endl
         << c << " " << d;
    return 0;
}