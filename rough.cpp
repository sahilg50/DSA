#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    char ch = 'z';
    ch = char((int('z') + 1) % int('z'));
    cout << "Hello";
    cout << ch;
    cout << "Hello";
    return 0;
}
