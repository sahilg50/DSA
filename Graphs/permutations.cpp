#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void permute(string s, int l, int r)
{

    //base case
    if (l == r)
    {
        cout << s << endl;
        return;
    }

    for (int i = l; i <= r; i++)
    {

        swap(s[i], s[l]);

        permute(s, l + 1, r);

        //backtrack
        swap(s[i], s[l]);
    }
}

int main()
{
    cout << "Enter the string: ";
    string str;
    getline(cin, str);

    permute(str, 0, str.size() - 1);
    return 0;
}

/*
It is a backtracing problem.
TC: O(n!) because the total number of permutations are n!
SC: O(r-l) where the r-l represents the size of the string 
*/