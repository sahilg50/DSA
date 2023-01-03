#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    string str = "gaga";
    map<char, int> M;
    for (char ch = 'a'; ch != 'z'; ch++)
        M[ch] = 0;

    for (auto &it : M)
        cout << it.first << " " << it.second << endl;
    return 0;
}