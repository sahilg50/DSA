/*
Convert a string to both upper case and lower case.
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{

    string str = "Ridhu";
    cout << 'a' - 'A' << endl;

    //Converting to upper case
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
    cout << str << endl;

    //Convert to lower case
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
    cout << str << endl;

    //Case convertion using inbuilt function
    transform(str.begin(), str.end(), str.begin(), ::toupper);

    cout << str;

    return 0;
}