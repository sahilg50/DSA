/*
write a program to count the number of ones in binary representation of a number
*/

#include <iostream>

using namespace std;

int countOnes(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n & n - 1;
        count++;
    }
    return count;
}

int main()
{
    cout << countOnes(4);
    return 0;
}