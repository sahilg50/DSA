#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{

    /*
    Note: The differences between sets and unordered sets is that the sets are in sorted order and unordered_sets are not in sorted order. The sets are implemented using red black trees(self balancing trees) and unoredered sets are implemented using hash tables. The another major difference in sets and uorderdered_sets is of time omplexities, the time complexity of sets is of the O(log(n)), whereas in case of the unordered_sets the TC is O(1).
    The sets can contain containers, whereas the unordered cannot contain containers, they'll only work on simple datatypes.
    */

    // In case we want to include containers in unordered_sets, in that case we'll have to define the hash function ourselves.

    // I've show the working for the sets, the unordered sets are implmented almost similar fashion

    // We can have a set of simple data types as well as containers.
    set<string> S;
    S.insert("penguin");
    S.insert("Akul"); // TC-> O(log(n))
    S.insert("is");
    S.insert("and donut");
    S.insert("likes");

    // To find the element in the set
    auto it = S.find("likes"); // TC->O(log(n))
    if (it != S.end())
    {
        cout << "Element is found and now we'll delete the element!";
        S.erase(it);
    }
    else
    {
        cout << "Element not found!";
    }

    cout << endl
         << endl;
    // Printing the elements
    for (string value : S)
    {
        cout << value << " ";
    }
    cout << endl;
    for (auto it = S.begin(); it != S.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl
         << endl;

    // Now let's move to multisets.
    multiset<int> s;
    s.insert(1);
    s.insert(20);
    s.insert(3);
    s.insert(1);
    s.insert(2);
    for (int val : s)
    {
        cout << val << " ";
    }
    /* Note: TC-> O(log(n)) in case of multimap bencause it is implemented using red black trees.
    This can we used in case of priority queue questions.
    Another important point to note is that while deleting the elemnts in multimap, if we use s.erase(ele), then it will delete all the ele in te multimap, but if we use, auto it = s.find(ele), s.erase(it); then only the single element will be deleted.
    */

    return 0;
}
