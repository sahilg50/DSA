/*
Conversion Operator: We can also write conversion operators that can be used to convert one type to another type.
*/

#include <iostream>
using namespace std;

class Fraction
{
private:
    int num, den;

public:
    Fraction(int n, int d)
    {
        this->num = n;
        this->den = d;
    }

    // Conversion operator: return float value of fraction
    operator float() const
    {
        return float(num) / float(den);
    }
};

int main()
{
    Fraction f(2, 5);
    float val = f;
    cout << val << '\n';
    return 0;
}