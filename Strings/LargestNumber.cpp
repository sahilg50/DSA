//Make the lergest number from the given number

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{

    string s = "89034";
    sort(s.begin(), s.end(), greater<int>());

    cout << s << endl;

    return 0;
}