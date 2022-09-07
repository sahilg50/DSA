// Program to remove space from string using stringstream

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void removeSpaces(string &str)
{
    stringstream ss;
    ss << str;
    str = "";
    string temp;
    while (!ss.eof())
    {
        ss >> temp;
        str.append(temp);
    }
}

int main()
{
    string str = "H H H H      H";
    removeSpaces(str);
    cout << str;
    return 0;
}