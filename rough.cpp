#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    string s = "sahil";
    s[0] = toupper(s[0]);
    cout << s.back();
    return 0;
}