#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> memo(1000, vector<int>(1000, -1));

//Using Tabular form
int LCS_Tabular(string a, string b)
{
    int m = a.length();
    int n = b.length();

    int longest_subSequence = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a.at(i) == b.at(j))
            {
                longest_subSequence++;
                break;
            }
        }
    }
    return longest_subSequence;
}

//Using Recursion
int LCS_Recursion(string &s1, string &s2, int m, int n)
{

    if (m == 0 || n == 0)
        return 0;

    else if (s1[m - 1] == s2[n - 1])
        return 1 + LCS_Recursion(s1, s2, m - 1, n - 1);

    else
    {
        return max(LCS_Recursion(s1, s2, m - 1, n), LCS_Recursion(s1, s2, m, n - 1));
    }
}

int main()
{
    string a = "Sahil";
    string b = "SaRahil";
    ;
    cout << LCS_Tabular(a, b) << endl;
    cout << LCS_Recursion(a, b, a.length(), b.length());
    return 0;
}