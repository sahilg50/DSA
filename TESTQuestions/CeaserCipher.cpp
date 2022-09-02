/*
BARCO: Decode the ceaser cipher
It is given in the question that cipher was formed by replacing the string alphabets by the 3rd alphabet to its left;
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

char *decrypt(char *input1)
{
    unordered_map<char, char> m;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        cout << ch;
        if (ch >= 'x')
        {
            if (ch == 'x')
                m[ch] = 'a';
            else if (ch == 'y')
                m[ch] = 'b';
            else if (ch == 'z')
                m[ch] = 'c';
        }
        else
            m[ch] = char(ch + 3);
    }
    char *t;
    for (t = input1; *t != '\0'; t++)
    {
        *t = m[*t];
    }
    return input1;
}
int main()
{
    char name[] = "nrfzh";
    decrypt(name);
    cout << endl
         << endl;
    for (int i = 0; i < sizeof(name); i++)
    {
        cout << name[i];
    }
    return 0;
}