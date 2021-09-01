#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    string str = "Apnikaksha";
    getline(cin, str);
    cout << str << endl;

    string s1 = "fam";
    string s2 = "ily";
    string abc = "osnfj pwojf0w f08";

    //compare two strings
    cout << s1.compare(s2) << endl;

    //Append the strings.
    s1.append(s2);
    cout << s1 << endl;
    cout << s1[3] << endl;

    //This funcrtino is used to clear the string.
    abc.clear();
    cout << abc;

    if (abc.empty())
    {
        cout << "The string abc is empty!" << endl;
    }

    //Deleteing from a particular indexes.
    s1.erase(2, 2);
    cout << s1 << endl;

    //finding substring and returning starting index
    cout << s1.find("ly") << endl;

    //INserting at particular index
    s1.insert(2, "lol");
    cout << s1 << endl;

    //Finding the length of the string.
    cout << s1.size() << endl;

    //Getting a substring from the string
    string s4 = s1.substr(2, 4);
    cout << s4 << endl;

    //String to integer
    string s5 = "768";
    int x = stoi(s5);
    cout << x << endl;

    //INteger to string
    int y = 90;
    cout << to_string(y) + "2" << endl;

    //Sorting a string
    string s10 = "lsdhf dofj";
    sort(s10.begin(), s10.end());
    cout << s10 << endl;
    return 0;
}