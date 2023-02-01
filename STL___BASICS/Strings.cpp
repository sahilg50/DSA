#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{

    /*
    Topic: difference between getline and cin.
    -> If we enter the string: "    Hello     World" using cin, only "hello" is stored and the remaining string is taken as input in the next input command, in case 1: getline() and in case 2: cin.

    -> cin ignores the spaces in front of first input character and (everything after the last character or from the first space that occurs after the first character input)

    IMP-> If you want that your getline should not pickup any space left by cin, then you can use cin.ignore() after calling cin.

    */

    // Test Case : "   Hello        World" cout << "\nCASE 1: ";
    string str1;
    cout << "CASE 1: Using getline()\nEnter the string: ";
    cin >> str1;
    cout << str1;
    getline(cin, str1);
    cout << "Output: " << str1 << endl;

    cout << "\nCASE 2: Using cin\nEnter the string: ";
    cin >> str1;
    cout << "Output: " << str1 << endl;

    // Comparison of two strings
    string s1 = "aa";
    string s2 = "aafz";
    /*
    Topic : Compares the strings s1 and s2 lexicographically.
    If s1 > s2, return 1
    If s1 == s2, return 0
    If s1 < s2 , return -1

    If the s1 = "aa" and s2="aazfh", then it return -3, because the s1 is subset of s2 and it return the difference in the lengths of the strings. Its also true vise versa.
    */
    cout << s1.compare(s2) << endl;

    // This function is used to clear the string.
    string abc = "YELLO";
    abc.clear();
    cout << abc;

    if (abc.empty())
    {
        cout << "The string abc is empty!" << endl;
    }

    // Delete from idx and at-most n elements-> s.erase(idx, n)
    s1.erase(2, 2); // will delete 2 elements starting from 2nd index
    cout << s1 << endl;

    // finding substring and returning starting index
    cout << s1.find("ly") << endl; // ! TC -> O(N^2), N is size(s1) + size(s2)

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
    string s10 = "Sahil Gupta";
    sort(s10.begin(), s10.end());
    cout << s10 << endl;

    // str.change() -> changes the last character of the string str
    string STR1 = "Sahil";
    STR1.back() = 'C';
    cout << STR1 << endl;

    /*
    TOPIC: Character and String Concatenation
    https://www.codingninjas.com/codestudio/library/cpp-string-concatenation
    */

    string A = "HELL", B;
    A.push_back('O');
    /*
    TC-> O(1), SC-> O(1)
    -> Appends only a single character at the end of the string.
    -> Throws length_error if the resulting size exceeds the maximum number of characters.
    */

    A = "HELLO";
    B = "WORLD";
    A.append(B, 2, 1); // Appends 5 characters from the 2nd index of S1.
    cout << endl
         << A;
    /*
    TC-> O(B), SC-> O(N), N = sum of lengths of both strings(A + B)
    -> Adds characters of the second string to the first string one by one in each iteration.
    -> .append(B, start_idx, number_of_chars), it tries to add the defined number of characters from the defined starting index of string B. If the defined number of characters is -ve then it will add all the remaining characters. But is is important to define a valid start index otherwise it will throw an error.
    -> Unlike the '+' operator, the append function does not create a new string every time.
    -> Throws length_error if the resulting size exceeds the maximum number of characters.
    */

    A = "HELL";
    B = "CAT";
    A = A + B;
    /*
    TC-> O(N^2), SC-> O(N), N = sum of lengths of both strings(A + B)
    -> While performing this operation, in each iteration, a new string is created, and the previous string + new character is copied to it.
        So the sequence will be as follows:
        iteration1 + iteration2 + iteration3 + .... so on. And the number of characters added in each iteration will be: 1 + 2 + 3 + 4 + .... + N
        So TC = N*(N+1) / 2 ->O(N^2)
    */

    // TOPIC: const keyword
    const string C = "Sahil";
    // ! C.push_back('G');  This method is not allowed because of the const keyword.

    return 0;
}