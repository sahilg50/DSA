#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void printZigZagConcat(string str, int n)
{

    /*str is the string to be printed in zigzag manner
    n is the number of rows*/

    /*
    The time complexity in this case is O(len(str)) and the space compexity O(len(str))
    */

    if (n == 1)
    {
        cout << str;
        return;
    }

    int length = str.length();

    string *arr = new string[n];

    int row = 0;
    bool down = true;

    for (int i = 0; i < length; i++)
    {
        arr[row].push_back(str[i]);

        if (row == n - 1)
            down = false;

        if (row == 0)
            down = true;

        down ? (row++) : (row--);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "";
    }

    return;
};

int main()
{
    string str = "PAYPALISHIRING";
    printZigZagConcat(str, 3);

    return 0;
}