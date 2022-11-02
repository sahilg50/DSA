#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> v;
    v["Sahil"] = 1;
    cout << v["sahi"];
    return 0;
}