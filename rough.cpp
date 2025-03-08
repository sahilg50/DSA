#include <iostream>
#include <string>
using namespace std;

string compressedString(string &S)
{

    int n = S.size();
    S.push_back('.');

    string compressed = "";

    char ch;
    int count = 0;
    for (int ind = 0; ind < n; ind++)
    {
        ch = S[ind];
        count++;
        if (ch != S[ind + 1])
        {
            compressed.append(to_string(count));
            compressed.push_back(ch);
            count = 0;
        }
    }

    return compressed;
}

int main()
{
    string sample = "1";
    cout << compressedString(sample);
    return 0;
}