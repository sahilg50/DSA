#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    // We can have a set of simple data types as well as containers.
    set<string> S;
    S.insert("penguin");
    S.insert("Akul"); // TC-> O(log(n))
    S.insert("is");
    S.insert("and donut");
    S.insert("likes");

    // To find the element in the set
    auto it = S.find("likes");
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

        return 0;
}
