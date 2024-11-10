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
    Therefore, key values that cannot be hashed, like "vector", "sets" can be a part of map but not unordered_map.
    */

    /*
    IMPORTANT!
    When declaring a map like this, the elements are inserted in the reverse order. So when printing the elements from starting to end. -> {24, "T"} {25, "Y"}, {26, "Z"}.
    */
    unordered_map<int, string> M = {{26, "Z"}, {25, "Y"}, {24, "T"}};

    /*
    TOPIC: Begin Iterator
    Get an iterator to the first element
    */
    auto itr = M.begin();
    cout << itr->first << " " << itr->second;
    // TC-> O(1)

    /*
    TOPIC: End Iterator
    Get an iterator to the end (position next to the last element)
    */
    itr = M.end();
    cout << itr->first << " " << itr->second; // This will not print anything because there's no element at the end.
    // TC-> O(1)

    /*
    TOPIC: Constant Begin Iterator
    Get a "constant" iterator to the beginning
    */
    auto itr1 = M.cbegin();
    cout << itr1->first << " " << itr1->second;
    /*
    itr += 1;
    This will give an error because you can't increment/decrement the constant pointer. But you can reassign the iterator.
    */
    // TC-> O(1)

    /*
    TOPIC: Constant End Iterator
    Get a "constant" iterator to the end (position next to the last element)
    */
    itr1 = M.cend();
    cout << itr1->first << " " << itr1->second; // This will not print anything because there's no element at the end.
    /*
    itr -= 1;
    This will give an error because you can't increment/decrement the constant pointer. But you can reassign the iterator.
    */
    // TC-> O(1)

    /*
    IMPORTANT!
    In all four operations, i.e., insertion, accessing, updation, deletion, find, and count the best case scenario takes place when the hash function of the unordered_map is good and there are a minimal number of collisions that take place at respective operations. In contrast, the worst scenario takes place when the hash table of the unordered_map is not good, and a very high number of collisions occur at each operation.
    */

    // TOPIC: Insertion
    M[1] = "A";

    pair<int, string> p = {23, "S"}; // Can also use "pair container" for insertion in map.
    M.insert(p);

    M.insert({2, "B"}); // Key value pair will be inserted at the end
    // TC-> Best Case: O(1), Avg Case: O(1), Worst Case: O(N)

    // TOPIC: Insertion at specific position
    itr = M.begin();
    M.insert(itr, {3, "C"}); // key value pair will be inserted at the specified position
    // TC-> Best Case: O(1), Avg Case: O(1), Worst Case: O(N)

    // TOPIC: Inserting elements within a specific range
    vector<pair<int, string>> V = {{4, "D"}, {5, "E"}, {6, "F"}, {7, "G"}};
    M.insert(V.begin() + 1, V.begin() + 2); // Note: In M.insert(pos1, pos2), pos2 is not inclusive
    // TC-> Best Case: O(N), Avg Case: O(N), Worst Case: O(N*N)

    // TOPIC: Accessing
    cout << M.at(10) << endl; // Throws error is the key is not present
    cout << M[10] << endl;    // Create a key value with key = "2" and default value = "0"
    // TC-> Best Case: O(1), Avg Case: O(1), Worst Case: O(N)

    // TOPIC: Updation
    M[1] = "Z";
    // TC-> Best Case: O(1), Avg Case: O(1), Worst Case: O(N)

    // TOPIC: Erase
    M.erase(1); // Erase by key

    itr = M.begin();
    M.erase(itr); // Erase by iterator; itr = M.begin()
    // TC-> Best Case: O(1), Avg Case: O(1), Worst Case: O(N)

    /*
    TOPIC: Size
    Get the number of key-value pairs
    */
    cout << M.size();
    // TC-> O(1)

    /*
    TOPIC: Max size
    Get the maximum storage capacity
    */
    cout << M.max_size();
    // TC-> O(1)

    /*
    TOPIC: Empty
    Checks if the map is empty or not.
    */
    cout << M.empty(); // Returns True or False
    // TC-> O(1)

    /*
    TOPIC: Find
    Find an element by key
    */
    itr = M.find(2); // If found, returns an iterator to that index else returns M.end()
    // TC-> Best Case: O(1), Avg Case: O(1), Worst Case: O(N)

    /*
    TOPIC: Count
    Counts the occurrences of a key
    Note: As unordered_map does not allow to store elements with duplicate keys, so the count() function basically checks if there exists an element in the unordered_map with a given key or not.
    */
    cout << M.count(2); // This function returns 1 if key exists in map, else returns 0.
    // TC-> Best Case: O(1), Avg Case: O(1), Worst Case: O(N)

    /*
    TOPIC: Clear
    Erase all elements in the map
    */
    M.clear();
    /*
    TC-> O(N). This is because the clear() method has to iterate over all of the elements in the map and delete them.
    */

    // TOPIC: Iterating
    for (auto itr = M.begin(); itr != M.end(); itr++)
        cout << itr->first << " " << itr->second << "\n";
    /*
    In the above loop, we use iterators to iterate over the container M. Iterators emulate pointers, and have to be dereferenced to give the value the iterator is "pointing" at. In fact, for that loop, itr->first is really the same as (*itr).first.
    */

    M = {{1, "A"}, {2, "B"}, {3, "C"}};
    for (auto itr : M)
        cout << itr.first << " " << itr.second << endl;
    /*
    In the above loop, we loop over the values in the container M. The loop itself uses iterators internally and dereferences them for us.
    */

    /*
    TOPIC: SORTING
    There is no inbuilt way of sorting the map, so you can initialize a vector<pair<>> and sort that.
    */
    unordered_map<char, int> M2;
    M2['c'] = 10;
    M2['a'] = 30;
    M2['z'] = 15;
    vector<pair<char, int>> v(M2.begin(), M2.end());
    // sorting based on the first value in the pair vector
    sort(v.begin(), v.end());
    for (auto &it : v)
        cout << it.first << " " << it.second << "\t";

    return 0;
}