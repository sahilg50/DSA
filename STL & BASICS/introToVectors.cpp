#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

using namespace std;

struct node
{
    int x, y;
};

void printVec(vector<int> v)
{
    /*
    In this function, a copy of the vector is received, so the changes made in this function won't reflect in the original vector.

    To reflect the changes, the vector should passed by reference ->
    void printVec(vector<int> &v)
    */
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

bool isEven(int i)
{
    return !(i % 2);
}

int myFunc(int x, int y)
{
    return x * y;
}

// NOTE: All the vectors are stored in contiguous memory locations.
int main()
{
    // 2D vector where n = rows and m = cols and -1 = default value
    int n = 10, m = 5;
    vector<vector<int>> vec(n, vector<int>(m, -1));

    // Initializing a vector with size 10 and default value -2
    vector<int> V(10, -2);

    // statically allocates the memory
    vector<int> v = {5, 4, 8, -1};

    // TOPIC: Accessing Elements of vectors
    cout << "Accessing elements of vectors:";
    cout << "\nElement at index 1: " << v.at(1);
    // Returns error if the range is index is out the range

    cout << "\nElement at index 1: " << v[100];
    // Returns the garbage value if the index is out of range

    // TOPIC: Methods of vector container
    cout << "\n\n\n\nMethods of vector container:";

    cout << "\nSize of vector: " << v.size();
    // Returns the size. TC-> O(1)

    cout << "\nFirst element: " << v.front();
    // Returns the first element. TC-> O(1)

    cout << "\nLast element: " << v.back();
    // Returns the last element. TC-> O(1)

    cout << "\nIs empty? " << boolalpha << v.empty();
    // Returns true if array is empty, false otherwise. TC-> O(1)

    v.push_back(10);
    // Appends an element at the end. TC-> O(1)

    v.pop_back();
    // Removes the last element and does not return anything. TC-> O(1)

    v.clear();
    /*
    Removes all elements from vector and reducing it to size 0.
    All elements are destroyed one by one. TC-> O(N), SC->O(1)
    */

    v.begin();
    // Returns a bidirectional iterator pointing to the first element of the vector container. Bidirectional iterator can be incremented as well as decremented. TC-> O(1)

    v.end();
    // Returns a bidirectional iterator pointing right next to the last element of the vector container. TC-> O(1)

    v.rbegin();
    /* Returns a reverse bidirectional iterator pointing to the last element of the vector container. TC-> O(1)

    auto it = V.rbegin();
    it++, will move it towards V.rend();
    */

    v.rend();
    /*
    Returns a reverse bidirectional iterator pointing right before the first element of the vector container. TC-> O(1)

    auto it = V.rend();
    it--, will move it towards V.rbegin();
    */

    v.insert(v.end(), 10);
    /*
    Can insert 10 at any position from v.begin() to v.end() (both inclusive). But not any other position, that we cause an error.
    TC-> O(N + M) where N is the number of elements inserted and M is the number of the elements moved .
    */

    n = 30;
    int val = -1;
    v.resize(n, val);
    /*
    This method alters the container’s content in actual by inserting or deleting the elements from it.
    If n < size of vector, then extra elements are demolished.
    Else If n > size of vector, then upcoming elements are appended at the end of the vector with value = val. Default value of val is 0.
    TC-> O(N), where N is the size of resized vector.
    */

    v.erase(v.begin());
    v.erase(v.begin(), v.begin() + 2);
    /*
    Deletes a single element or a range of elements. TC-> O(N + M) where N is the number of the elements erased and M is the number of successive elements moved to fill the gap.
    Note: If you want eliminate elements that fulfill a certain criterion from a container. Then don't call this method again and again, because that will result in O(N^2) TC. Instead use erase–remove idiom.
    */

    /*
    TOPIC: Useful functions for vectors
    All the functions below are inclusive of lower limit and exclusive of upper limit.
    */
    cout << "\n\n\n\nUseful functions for vectors:";

    v = {1, 8, 2, 3, 4, 4, 1, 100};
    cout << "\nThe minimum element is: " << *min_element(v.begin(), v.end());
    /*
    Return Value: It return a pointer to the smallest element in the range, and in case if there are more than one such element, then it points to the first one. It points to the last in case the range is empty.
    TC-> O(N)  SC-> O(1)
    */

    cout << "\nThe maximum element is: " << *max_element(v.begin(), v.end());
    /*
    Return Value: It return a pointer to the largest element in the range, and in case if there are more than one such element, then it points to the first one. It points to the last in case the range is empty.
    TC-> O(N)  SC-> O(1)
    */

    cout << "\nCount of 4 in vector v is: " << count(v.begin(), v.end(), 4);
    /*
    Returns the frequency of the number in the specified range.
    TC-> O(N)  SC-> O(1)
    */

    cout << "\nFind in vector v is: " << *find(v.begin(), v.end(), 2);
    /*
    Returns an iterator to the first element found. If not present then points to v.end(). To check if certain element is present or not, we can write: if(find(v.begin(), v.end(), 10) != v.end())
    TC-> O(N)  SC-> O(1)
    */

    cout << "\nFind_If in vector v returns: " << *find_if(v.begin(), v.end(), isEven);
    /*
    Returns an iterator to the first element found that meets the specified condition. If not present then points to v.end(). Here in this case it returns the iterator to 8 because that is the first even element in the vector.
    TC-> O(N)  SC-> O(1)
    */

    sort(v.begin(), v.end(), greater<int>());
    /*
    Sorts the specified range in descending format. Does not return anything.
    TC-> O(N * logN)  SC->Recursion Stack: O(logN)ASC
    NOTE: Sort() uses Intro Sort which is a combination of Quick Sort, Heap Sort, and Insertion Sort. It ensures that the recursion depth is bounded by O(log N) by limiting the depth of Quick Sort and switching to Heap Sort when necessary. The time complexity of heat sort is O(N * logN) in both the average and worst cases.
    */

    sort(v.begin(), v.end());
    /*
    Sorts the specified range in ascending format. Does not return anything.
    TC-> O(N * logN)  SC->Recursion Stack: O(logN)ASC
    */

    cout << "\nBinary search on vector: " << binary_search(v.begin(), v.end(), 100);
    /*
    Returns 1 if element is found and 0 if not found. But only works correctly on a sorted array.
    TC-> O(logN)  SC-> O(1)
    */

    v = {5, 10, 15};
    cout << "\nAccumulate() returns: " << accumulate(v.begin(), v.end(), 0);
    /*
    0 is the initial value of the sum.
    Step 1: 0+5 = 5
    Step 2: 5+10 = 15
    Step 3: 15+15 = 750.
    It returns the final sum.

    TC-> O(N)  SC-> O(1)
    */

    cout << "\nAccumulate() with myFunc returns: " << accumulate(v.begin(), v.end(), 1, myFunc);
    /*
    1 is the initial value of the sum.
    myFunc is performing the task of updating the sum with sum * current number. It will work as:
    Step 1: 1*5 = 5
    Step 2: 5*10 = 50
    Step 3: 50*15 = 750.
    Adding myFunc is optional. It returns the final sum.

    TC-> O(N)  SC-> O(1)
    */

    cout << "\nAccumulate() with minus<int>() returns: " << accumulate(v.begin(), v.end(), 2, minus<int>());
    /*
    2 is the initial value of the sum.
    Step 1: 2-5 = -3
    Step 2: -3-10 = -13
    Step 3: -13-15 = -28
    It returns the final sum.

    TC-> O(N)  SC-> O(1)
    */

    v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    reverse(v.begin(), v.end());
    /*
    Reverses the vector container. Does not return anything.
    TC-> O(N)  SC-> O(1)
    */

    auto it = remove(v.begin(), v.end(), 2);
    it = remove_if(v.begin(), v.end(), isEven);
    /*
    Shifts all the elements that match a specific criterion or a value to the end of the vector container and returns an iterator pointing right next the last element that is not removed.
    But note that the elements are still in the vector, they're not removed.
    TC-> O(N)
    */

    v.erase(it, v.end());
    /*
    Now we can use the iterator returned by remove_if() inside the .erase() method to delete the unwanted elements. This is called erase-remove idiom.
    TC-> O(N)
    */

    // TOPIC: Capacity and Size of the vectors
    vector<int> v2;
    cout << "\n\n\n\nCapacity and Size of the vectors:";
    for (int i = 0; i < 100; i++)
    {
        v2.push_back(i);
        cout << "\nValue: " << v2[i] << " Size: " << v2.size() << " Capacity: " << v2.capacity();
    }

    // TOPIC: Deep Copy and Shallow Copy
    // Making a copy, TC-> O(n)
    cout << "\n\n\n\nWhen making a deep copy: \n";
    vector<int> v3 = v;
    v3.push_back(34);
    printVec(v3), printVec(v);

    // Making a reference to the vector
    cout << "\nWhen making a reference(shallow copy): \n";
    vector<int> &v4 = v;
    v4.push_back(24);
    printVec(v4), printVec(v);

    // TOPIC: Creating a vector of pairs
    cout << "\n\n\n\nCreating a vector of pairs: ";
    vector<pair<int, int>> vp = {{1, 2}, {3, 4}};
    vp.push_back({5, 6});
    for (int i = 0; i < vp.size(); i++)
    {
        cout << endl
             << vp[i].first << " " << vp[i].second;
    }

    /*
    TOPIC: Array of vectors
    It's a 2D matrix, where we can increase the number of columns but not the rows.

    Static Allocation -> vector<int> AV[3];
    Dynamic Allocation -> vector<int> *AV = new vector<int>[n];
    */
    cout << "\n\n\n\n\nArray of Vectors: \n";
    n = 5;
    vector<int> *AV = new vector<int>[5];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            AV[i].push_back(rand() % 10);

    for (int i = 0; i < n; i++)
        printVec(AV[i]);

    /*
    TOPIC: Vector of vectors
    It is a 2D matrix where we can increase the number fo rows as well columns. The number of rows can be increased by pushing an entire vector into the vector of vectors and we can also decrease the number of rows by poping an entire vector from the vector of vectors.
    */
    cout << "\n\n\n\n\nVector of Vectors: \n";
    vector<vector<int>> VV;
    n = 2, m = 3;
    for (int row = 0; row < n; row++)
    {
        vector<int> temp;
        for (int i = 0; i < m; i++)
            temp.push_back(rand() % 10);
        VV.push_back(temp);
    }
    for (int row = 0; row < VV.size(); row++)
        printVec(VV[row]);

    // TOPIC: 3D Vector
    vector<vector<vector<int>>>
        dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    // TOPIC: Vector of structures
    cout << "\n\n\n\nVector of structures:\n";
    vector<struct node> VS;
    VS.push_back({1, 2});
    cout << VS[0].x << " " << VS[0].y << endl;

    // TOPIC: Dynamically allocate the memory to vector
    cout << "\n\n\n\nDynamically allocate the memory to vector:";
    vector<int> *dv = new vector<int>(3, -2);
    cout << "\nSize of vector: " << dv->size() << endl;
    dv->push_back(20), dv->push_back(10);
    for (int i = 0; i < dv->size(); i++)
        cout << dv->at(i) << " ";

    delete[] dv;

    return 0;
}