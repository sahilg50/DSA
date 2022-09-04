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

    IMP-> If you want that your getline should not pickup any space left by cin, then you can use cin.ignore() after calling cin.
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

    // Comparison of two strings
    string s1 = "aa";
    string s2 = "aafz";
    /*
    Compares the strings s1 and s2 lexicographically.
    If s1 > s2, return 1
    If s1 == s2, return 0
    If s1 < s2 , return -1

    If the s1 = "aa" and s2="aazfh", then it return -3, because the s1 is subset of s2 and it return the difference in the lengths of the strings. Its also true vise versa.
    */
    cout << s1.compare(s2) << endl;

    // Append the strings.
    s1.append(s2);
    cout << s1 << endl;
    cout << "helloi " << s1[3] << endl;

    // This funcrtino is used to clear the string.
    string abc = "YELLO";
    abc.clear();
    cout << abc;

    if (abc.empty())
    {
        cout << "The string abc is empty!" << endl;
    }

    // Delete from idx and atmost n elements-> s.erase(idx, n)
    s1.erase(2, 2); // will delete 2 elements starting from 2nd index
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

    // Integer to string
    int y = 90;
    cout << to_string(y) + "2" << endl;

    // Sorting a string
    string s10 = "lsdhf dofj";
    sort(s10.begin(), s10.end());
    cout << s10 << endl;

    /*
    If you weant to append a character at the end of the string, then always go for s.push_back('a') instead of s = s + 'a', this is because in this method it first creates a copy of original string s (TC->O(s.size())), then add 'a' to it and then finally store it in s.
    */
    string s = "hello";
    s.push_back('a');

    // Appends 5 characters from 0th index of
    // str2 to str1
    str1 = "React", str2 = "Native";
    str1.append(str2, 0, 5);

    // str.change() -> changes the last character of the string str
    string STR1 = "Sahil";
    STR1.back() = 'C';
    cout << STR1 << endl;
    return 0;
}