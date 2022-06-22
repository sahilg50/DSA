/*
Next Greater Element

https://www.hackerrank.com/contests/second/challenges/next-greater-element/problem
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> NGE(vector<int> &v)
{
    int n = v.size();
    vector<int> nge(n, -1);
    stack<int> s;
    int i = 0;
    while (i < n)
    {
        if ((!s.empty()) && (v[s.top()] < v[i]))
        {
            cout << s.top();
            nge[s.top()] = v[i];
            s.pop();
        }
        else
        {
            s.push(i++);
        }
    }
    return nge;
}

int main()
{
    cout << endl
         << "Enter the size of the array: ";
    int n;
    cin >> n;
    vector<int> v(n);
    cout << endl
         << "Enter all the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    vector<int> nge = NGE(v);
    for (int val : nge)
    {
        cout << endl
             << val << " ";
    }

    return 0;
}