/*
EXPEDIA

Count the number of strings that can be formed using the given rules:
1. minLen <= Length of string <= maxLen
2. if 1 occurs, then it should occur in the groups of size one_group
3. If 0 occurs, then it should occur in the groups of size zero_group

Return the total number of string that follows the above rule.
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int count = 0;
void formString(int minLen, int maxLen, int one_group, int zero_group, string str, int size, string &one, string &zero)
{
    cout << str << " ";
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
    int minLen = 1, maxLen = 3;
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