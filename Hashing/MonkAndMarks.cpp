/*
Monk and Class Marks:
Monk is a multi-talented person, and prepares results for his college in his free time. (Yes, he is still in love with his old college!) He gets a list of students with their marks. The maximum marks which can be obtained in the exam is 100.

The Monk is supposed to arrange the list in such a manner that the list is sorted in decreasing order of marks. And if two students have the same marks, they should be arranged in lexicographical manner.

Help Monk prepare the same!
*/

#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
int main()
{

    map<int, multiset<string>> marks_map;
    // Number of students
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int marks;
        string name;
        cin >> name >> marks;
        marks_map[marks].insert(name);
    }
    auto it = --marks_map.end();
    while (true)
    {
        auto &students = (*it).second;
        int marks = (*it).first;
        for (auto student : students)
        {
            cout << student << " " << marks << endl;
        }
        if (it == marks_map.begin())
            break;
        it--;
    }
    return 0;
}