// C++ program to demonstrate use of stringstream to count frequencies of words.

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

void printFrequency(string st)
{
    unordered_map<string, int> M;

    // Used for breaking words
    stringstream ss(st);

    // To store individual words
    string Word;

    while (ss >> Word)
        M[Word]++;

    for (auto &it : M)
        cout << it.first << ": " << it.second << endl;
}

int main()
{
    string s = "Geeks For Geeks Ide";
    printFrequency(s);
    return 0;
}