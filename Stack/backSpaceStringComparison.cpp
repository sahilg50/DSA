// 844. BackSpace String Compare
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string isSame(string str1, string str2)
{
    // Forming stack S1 for string str1
    stack<int> S1;
    for (int i = 0; i < str1.size(); i++)
    {
        if ((str1[i] == '#') && (!S1.empty()))
            S1.pop();
        else
            S1.push(str1[i]);
    }

    // Forming stack S2 for string str2
    stack<int> S2;
    for (int i = 0; i < str2.size(); i++)
    {
        if ((str2[i] == '#') && (!S2.empty()))
            S2.pop();
        else
            S2.push(str2[i]);
    }

    // Popping all the elements of the stack and comparing
    if (S1.size() != S2.size())
        return "NO";

    for (int i = 0; i < S1.size(); i++)
    {
        if (S1.top() == S2.top())
        {
            S1.pop();
            S2.pop();
        }
        else
        {
            return "NO";
        }
    }
    return "YES";
}

int main()
{

    string s1 = "sahii#ll#";
    string s2 = "##########sahil";

    cout << endl
         << isSame(s1, s2);
    return 0;
}

/*
TC-> O(n + m)
SC-> O(n + m), where n and m is the size of the input strings
*/