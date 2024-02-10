#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, string> M;

    string value = "Hello";
    M.insert({1, value});
    cout << M[1] << endl;

    value = "Sahil";
    cout << M[1];

    return 0;
}