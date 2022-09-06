// Program to parse a string "1,#,2,3,4,#,6";
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin). To use stringstream, we need to include sstream header file. The stringstream class is extremely useful in parsing input.

Basic methods are:
-> Clear()- To clear the stream.
-> str()- To get and set string object whose content is present in the stream.
-> operator <<- Add a string to the stringstream object.
-> operator >>- Read something from the stringstream object.
*/

void parseString(string str)
{
    // s is the stringstream Object
    stringstream s(str);
    string ch = "";
    while (getline(s, ch, ','))
    {
        cout << ch << " ";
    }
}

int main()
{
    string str = "1,#,2,3,4,#,6";
    parseString(str);
    return 0;
}