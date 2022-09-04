#include <iostream>
#include <stack>
using namespace std;

string removeKdigits(char *num, int k)
{
    stack<char> mystack;

    char *t;
    for (t = num; *t != '\0'; t++)
    {
        while (!mystack.empty() && k > 0 && mystack.top() > *t)
        {
            mystack.pop();
            k -= 1;
        }

        if (!mystack.empty() || *t != '0')
            mystack.push(*t);
    }

    while (!mystack.empty() && k--)
        mystack.pop();
    if (mystack.empty())
        return "0";

    while (!mystack.empty())
    {
        num[n - 1] = mystack.top();
        mystack.pop();
        n -= 1;
    }
    for (t = num + n; *t != '\0'; t++)
}

int main()
{
    char *num = "765028321";
    int k = 5;
    cout << removeKdigits(num, k);
    return 0;
}