#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int count = 0;
void formString(int minLen, int maxLen, int one_group, int zero_group, string str, int size, string &one, string &zero)
{
    if (size > maxLen)
        return;
    if (size + one_group <= maxLen)
    {
        if (size + one_group >= minLen)
            ::count++;
        formString(minLen, maxLen, one_group, zero_group, str + one, size + one_group, one, zero);
    }

    if (size + zero_group <= maxLen)
    {
        if (size + zero_group >= minLen)
            ::count++;
        formString(minLen, maxLen, one_group, zero_group, str + zero, size + zero_group, one, zero);
    }

    return;
}

int main()
{
    int minLen = 2, maxLen = 3;
    int one_group = 2, zero_group = 1;
    string one, zero;
    for (int j = 0; j < one_group; j++)
        one.push_back('1');
    for (int j = 0; j < zero_group; j++)
        zero.push_back('0');

    string str = "";
    formString(minLen, maxLen, one_group, zero_group, str, 0, one, zero);
    cout << ::count;
    return 0;
}