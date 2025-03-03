#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "sahil";
    string a = s;
    a.push_back('d');
    cout<<s<<endl;
    cout<<a;

    return 0;
}