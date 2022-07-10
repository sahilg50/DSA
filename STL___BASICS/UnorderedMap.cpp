#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <typeinfo>
#include <algorithm>
using namespace std;

int main()
{
    // Note: The difference between maps and unordered_map is the in maps, the elements are inserted on the basis of the comparison of the key whereas in unordered maps, the elements are inserted on the basis of the hash value of the key that is calculated using hashtables. Therefore your key values can be vectors, sets etc in case of maps whereas not in the case of the unordered maps.

    // Unordered Maps are implemented using hastables.
    unordered_map<int, string> m;
    m[1] = "abc"; // TC-> Time complexity to insert or access the elements in unordered_map is O(1), beacuse of the collisions, the time complexity will increase but we still go with O(1)
    m[5] = "cdc";
    m[3] = "bf";
    m[2] = "gf";
    for (auto &itr : m)
    {
        // cout << typeid(itr).name() << endl;
        cout << itr.first << " " << itr.second;
    }
    // Note that the new keys are inserted in the beginning of the unrdered_map

    unordered_map<string, int> map;
    // Insert
    pair<string, int> p("s", 225);
    map.insert(p);

    map["manan"] = 225;

    // find or access
    cout << map["s"] << endl;

    cout << map["akul"] << endl; // creates a new key value pair with the default value 0
    // cout << map.at("rishav") << endl; // throws error is the key is not present

    // size
    cout << "Size: " << map.size() << endl; // returns the size of the hashmap

    // Check the presence
    cout << map.count("sahil") << endl; // returns 0 or 1

    // erase
    cout << "Size: " << map.size() << endl;
    map.erase("sahil"); // deletes the key value pair.
    cout << "Size: " << map.size() << endl;

    /*
    SORTING
    There is no inbuilt way of sorting the map, so you can initialize a vector<pair<>> and sort that.
    */
    unordered_map<char, int> m2;
    m2['c'] = 10;
    m2['a'] = 30;
    m2['z'] = 15;
    vector<pair<char, int>> v(m2.begin(), m2.end());
    // sorting based on the first value in the pair vector
    sort(v.begin(), v.end());
    for (auto &it : v)
        cout << it.first << " " << it.second << "\t";

    return 0;
}