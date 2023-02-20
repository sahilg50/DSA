#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
using namespace std;

int main()
{
    map<pair<string, string>, vector<int>> m;

    /*
    Now the use case of this nested stl is that, let's suppose in a class, we want to store the name of the students along with the marks of the student and make sure that the entries on the bases of the name of student. Therefore we've declared a pair of string as the key and a vector a value.
    */

    // Total number of entries
    cout << endl
         << "Enter the total number of entries you wanna make: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "Enter the first name, last name and the number of subject: ";
        string fn, ln;
        int subs; // number of subjects
        cin >> fn >> ln >> subs;
        cout << endl
             << "Enter the marks in all the subjects separated by spaces:\n";
        for (int j = 0; j < subs; j++)
        {
            int x;
            cin >> x;
            m[{fn, ln}].push_back(x);
        }
    }

    // Printing the entries
    for (auto pr : m)
    {
        auto &full_name = pr.first;
        auto &list = pr.second;
        cout << full_name.first << " " << full_name.second;
        cout << list.size() << endl;
        for (auto &element : list)
        {
            cout << element << " ";
        }
        cout << endl;
    }

    /*
    Other nested examples of stl
    map<pair<int, int>, int> m;
    map<set<int>, int> m;
    map<vector<int>, int> m;
    */

    return 0;
}