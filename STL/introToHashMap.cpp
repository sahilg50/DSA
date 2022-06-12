#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
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

    return 0;
}