#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    // Maps are implmenete using red black trees and the
    // Elements are arranged in the sorted order in map
    map<int, string> m;
    m[1] = "abc"; // TC-> O(Olog(n)), wehere n is the current size of the map
    m[5] = "cbc";
    m[3] = "acd";
    m.insert({4, "doifj"});
    map<int, string>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
    cout << endl
         << endl;

    // Other way of iterating
    for (auto itr : m)
    {
        cout << itr.first << " " << itr.second << endl;
    }

    // For finding the element
    auto it1 = m.find(3); // TC->O(log(n))
    if (it1 == m.end())
    {
        cout << "No Value";
    }
    else
    {
        cout << (*it1).first << " " << (*it1).second;
    }

    // For deleting the element
    m.erase(3); // TC-> O(log(n))
    // The other way of deleting the element is using iterator
    auto it2 = m.find(1);
    if (it2 != m.end())
        m.erase(it2);

    // To clear the elements of the map
    m.clear();

    // To find the size of the hashmap
    cout << endl
         << "The size after clearing the map is: " << m.size();

    // Note: One more point to note on the time complexity of the insertion is:
    map<string, int> M;
    M["sahil"] = 1;
    M["Tejal"] = 2; // TC-> O(size(key)*log(n)), this is because when key is your string then the time to copare the strings is also counted while executing the program.

    // Reverse Iterator
    map<char, int> mpp = {
        {'a', 1},
        {'b', 2},
        {'c', 3},
        {'d', 4},
        {'e', 5},
    };

    cout << "\n\nMap contains following elements in reverse order" << endl;

    for (auto it = mpp.rbegin(); it != mpp.rend(); ++it)
        cout << it->first << " = " << it->second << endl;
    return 0;
}