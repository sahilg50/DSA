#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

struct node
{
    int x, y;
};

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

// NOTE: All the vectors are stored in contiguous memory locations.
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

    // Now we'll declare the vector of pair
    cout << endl
         << "Vector of pairs: ";
    vector<pair<int, int>> vp = {{1, 2}, {3, 4}};
    vp.push_back({5, 6});
    for (int i = 0; i < vp.size(); i++)
    {
        cout << vp[i].first << " " << vp[i].second << endl;
    }

    // Array of vectors
    // Note: Its's like the a 2D matrix, where we can increase the number of olumns but we cannot increase the number of rows.
    cout << endl
         << "Array of Vectors explanation: ";
    vector<int> va[3];
    for (int i = 0; i < 3; i++)
    {
        //  taking user input to input the number of elements to input in the vector va[i]
        cout << endl
             << "The values in the vectors will be inserted using rand(), just enter the size of the vector at index " << i << ": ";
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            va[i].push_back(rand());
        }
    }

    // Vector of vectors
    // Note: THe vector of vectors is like a 2D matrix where we can increase the number fo rows as well the number of columns. The number of rows can be increased by pushing(push_back()) an entire vector into the vector of vectors and we can also decrease the number of rows by poping (pop_back()) an entire vector from the vector of vectors.

    cout << endl
         << "Vector of Vectors: ";
    int N;
    cin >> N;
    vector<vector<int>> vv;
    for (int i = 0; i < N; i++)
    {

        vector<int> temp;
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            temp.push_back(rand());
        }
        vv.push_back(temp);
    }

    // 3d nested Vector
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    /*
    Parameter:The function accepts three parameters specified as below:
    position – It specifies the iterator which points to the position where the insertion is to be done.
    size – It specifies the number of times a val is to be inserted at the specified position.
    val – It specifies the value to be inserted.

    v.insert(v.begin()+index, val);
    */

    // vector of structures
    cout << endl
         << "Vector of structures: ";
    vector<struct node> SV;
    SV.push_back({1, 2});
    struct node *test = &SV[0];
    cout << endl
         << test->x << " " << test->y;

    // pop_back()
    cout << endl
         << "POP FRONT() demo: ";
    vector<int> v20 = {1, 2, 3};
    v20.pop_back();
    cout << v20.front(); // cout << v20[0]
    return 0;
}