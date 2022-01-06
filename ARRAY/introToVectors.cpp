#include <iostream>
#include <vector>
using namespace std;

// vector<vector<int>> vec( n , vector<int> (m, 0));mr
int main()
{
    // vector<int> *dv = new vector<int>(); // Dynamically allocates the memory

    // vector<int> v2(10, -2); // we're initializing a vector with size 10 and default value -2

    vector<int> v; // statically allocates the memory

    //insert
    v.push_back(10);
    v.push_back(90);
    v.push_back(80);

    //access
    cout << "Index 1: " << v.at(1) << endl; //returns error if the range is index is out the range
    cout << "Index 1: " << v[1] << endl;    //returns the garbage value if the index is out of range

    //size
    cout << "Size: " << v.size() << endl; //returns the size of the vector

    //deleting the last element
    cout << "Size: " << v.size() << endl;
    v.pop_back();
    cout << "Size: " << v.size() << endl;

    //access the out of range indices
    cout << "Index 5: " << v[5] << endl; //returns the garbage value because the index is out of range
    // cout << "Index 5: " << v.at(5) << endl; //returns error because the range is index is out the range

    //find the underlying capacity of the array
    cout << "Lets check the size of the vector and the underlying capacity of the vevctor ad we pushback elements in the vector." << endl;

    vector<int> v2;
    for (int i = 0; i < 100; i++)
    {
        v2.push_back(i);
        cout << "Value: " << v2[i] << " Size: " << v2.size() << " Capacity: " << v2.capacity() << endl;
    }

    return 0;
}