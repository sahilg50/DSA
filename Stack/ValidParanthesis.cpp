// 20. Valid Paranthesis Leetode
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string validP(string s)
{
    stack<char> S;
    for (auto &c : s)
    {
        switch (c)
        {
        case '{':
            S.push('}');
            break;
        case '[':
            S.push(']');
            break;
        case '(':
            S.push(')');
            break;
        default:
            if (S.size() == 0 || c != S.top())
                return "No";
            else
                S.pop();
        }
    }
    if (S.size() == 0)
        return "Yes";
    return "No";
}

int main()
{
    cout << endl
         << "Input the string: ";
    string s;
    cin >> s;
    cout << "Is the string valid? " << validP(s);
    return 0;
}