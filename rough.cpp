#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<char, int> M;
    M['a'] = 1;
    if (M['b'] > 20)
        cout << "hello World";

    for (auto &it : M)
        cout << it.first << " " << it.second << endl;

    return 0;
}