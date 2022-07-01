#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    /*
    Note the differece between getline and cin.
    If we enter the string: "    Hello     World" using cin, only "hello" is stored and the remaining string is taken as input in the next input command, in case 1: getline() and in case 2: cin.

    cin ingnores the spaces in front of first input character and (everything after the last character or from the first space that occurs after the first character input)
    */

    // Test Case : "   Hello        World" cout << "\nCASE 1: ";
    string str1,
        str2;
    cout << "\nEnter the string: ";
    cin >> str1;
    cout << str1;
    getline(cin, str1);
    cout << str1;

    cout << "\n\n\nCASE 2: ";
    cout << "\nEnter the string: ";
    cin >> str1;
    cout << str1;
    cin >> str1;
    cout << str1;

    string s1 = "aa";
    string s2 = "aafz";
    string abc = "osnfj pwojf0w f08";

    /*
    Compares the strings s1 and s2 lexicographically.
    If s1 > s2, return 1
    If s1 == s2, return 0
    If s1 < s2 , return -1v

    If the s1 = "aa" and s2="aazfh", then it return -3, because the s1 is subset of s2 and it return the difference in the lengths of the strings. Its also true vise versa.
    */
    cout << s1.compare(s2) << endl;

    // Append the strings.
    s1.append(s2);
    cout << s1 << endl;
    cout << "helloi " << s1[3] << endl;

    // This funcrtino is used to clear the string.
    abc.clear();
    cout << abc;

    if (abc.empty())
    {
        cout << "The string abc is empty!" << endl;
    }

    // Deleteing from a particular indexes.
    s1.erase(2, 2);
    cout << s1 << endl;

    // finding substring and returning starting index
    cout << s1.find("ly") << endl;

    // INserting at particular index
    s1.insert(2, "lol");
    cout << s1 << endl;

    // Finding the length of the string.
    cout << s1.size() << endl;

    // Getting a substring from the string
    string s4 = s1.substr(2, 4);
    cout << s4 << endl;

    // String to integer
    string s5 = "768";
    int x = stoi(s5);
    cout << x << endl;

    // INteger to string
    int y = 90;
    cout << to_string(y) + "2" << endl;

    // Sorting a string
    string s10 = "lsdhf dofj";
    sort(s10.begin(), s10.end());
    cout << s10 << endl;
    return 0;
}