
#include <iostream>
using namespace std;

//FUnciton to find the bit the bit at particular location.
int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

//Funciotn to set the bit, this means to place 1 at that location
int setBit(int n, int pos)
{
    return n | (1 << pos);
}

//Function to clear a bit a particular position
int clearBit(int n, int pos)
{
    return ((n & ~(1 << pos)));
}

//Update the bit a particular position with the given value
int updateBit(int n, int pos, int value)
{
    n = clearBit(n, pos);
    if (value == 1)
    {
        return setBit(n, pos);
    }
    return n;
}

int main()
{
    cout << getBit(5, 2) << endl;

    cout << setBit(5, 1) << endl;

    cout << clearBit(5, 2) << endl;

    cout << updateBit(1, 2, 1);
    return 0;
}