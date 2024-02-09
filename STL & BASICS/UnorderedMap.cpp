#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <typeinfo>
#include <algorithm>
using namespace std;

int main()
{

    /*
    TOPIC: Difference between maps and unordered_map
    In unordered_map, the elements are inserted on the basis of the hash value of the key, calculated using hash function.
    In map, the elements are inserted on the basis of the comparison of the key.
    Therefore, key values that are not hashable, like "vector", "sets" can be a part of map but not unordered_map.
    */

    unordered_map<int, string> M;

    // TOPIC: Insertion
    M[1] = "A";
    M.insert({2, "B"}); // Kwy value pair will be inserted at the end
    /*
    TC-> Best Case: O(1), Avg Case: O(1), Worst Case: O(N)
    */

    // TOPIC: Insertion at specific position
    auto itr = M.begin();
    M.insert(itr, {3, "C"}); // key value pair will be inserted at the specified position
    /*
    TC-> Best Case: O(1), Avg Case: O(1), Worst Case: O(N)
    */

    // TOPIC: Inserting elements within a specific range
    vector<pair<int, string>> V = {{4, "D"}, {5, "E"}, {6, "F"}, {7, "G"}};
    M.insert(V.begin() + 1, V.begin() + 2); // Note: In M.insert(pos1, pos2), pos2 is not inclusive
    /*
    TC-> Best Case: O(N), Avg Case: O(N), Worst Case: O(N*N)
    */

    // TOPIC: Accessing
    cout << M.at(6) << endl; // Throws error is the key is not present
    cout << M[6] << endl;    // Create a key value with key = "2" and default value = "0"
    /*
    TC-> Best Case: O(1), Avg Case: O(1), Worst Case: O(N)
    */

    // TOPIC: Updation
    M[1] = "Z";
    /*
    TC-> Best Case: O(1), Avg Case: O(1), Worst Case: O(N)
    */

    // TOPIC: Erase
    M.erase(1); // Erase by key

    auto itr = M.begin();
    M.erase(itr); // Erase by iterator; itr = M.begin()
    /*
    TC-> Best Case: O(1), Avg Case: O(1), Worst Case: O(N)
    */

    m[5] = "cdc";

    m[3] = "bf";
    m[2] = "gf";
    for (auto &itr : m)
    {
        // cout << typeid(itr).name() << endl;
        cout << itr.first << " " << itr.second;
    }
    /*
    Note that the new keys are inserted in the beginning of the unordered_map but if we define the key values while declaring the map itself then the key value pairs are inserted in the order we write them
    */
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