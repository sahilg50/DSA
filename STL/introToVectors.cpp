#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> v)
{

    // In this function, a copy of the vector is recieved, so the changes made in this function won't reflect in the original vector.

    // To reflect the chages, the vector should passed by reference, i.e. void printVec(vector<int> &v)
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    // 2D vector intitailization where n, m is the rows, cols respectively
    int n = 10, m = 5;
    vector<vector<int>> vec(n, vector<int>(m, 0));

    // Dynamically allocates the memory
    vector<int> *dv = new vector<int>();

    // we're initializing a vector with size 10 and default value -2
    vector<int> v3(10, -2);

    // statically allocates the memory
    vector<int> v;

    // insert
    v.push_back(10); // TC-> O(1)
    v.push_back(90);
    v.push_back(80);

    // access
    cout << "Index 1: " << v.at(1) << endl; // returns error if the range is index is out the range
    cout << "Index 1: " << v[1] << endl;    // returns the garbage value if the index is out of range

    // size
    cout << "Size: " << v.size() << endl; // returns the size of the vector

    // deleting the last element
    cout << "Size: " << v.size() << endl;
    v.pop_back();
    cout << "Size: " << v.size() << endl;

    // access the out of range indices
    cout << "Index 5: " << v[5] << endl; // returns the garbage value because the index is out of range
    // cout << "Index 5: " << v.at(5) << endl; //returns error because the range is index is out the range
    v.pop_back(); // TC-> O(1)

    // find the underlying capacity and the size of the array
    vector<int> v2;
    for (int i = 0; i < 100; i++)
    {
        v2.push_back(i);
        cout << "Value: " << v2[i] << " Size: " << v2.size() << " Capacity: " << v2.capacity() << endl;
    }

    // Making a copy, TC-> O(n)
    cout << endl
         << endl
         << "When making copy: " << endl;
    vector<int> v4 = v;
    v4.push_back(34);
    printVec(v4);
    printVec(v);

    // Making a reference to the vector
    cout << endl
         << endl
         << "When making a reference: " << endl;
    vector<int> &v5 = v;
    v5.push_back(24);
    printVec(v5);
    printVec(v);

    return 0;
}