#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2};

    /*
    void partial_sort(RandomAccessIterator first, RandomAccessIterator middle,
                      RandomAccessIterator last);

    first: Random-Access iterator to the first element in the container.
    last: Random-Access iterator to the last element in the container.
    middle: Random-Access iterator pointing to the element in the
    range [first, last), that is used as the upper boundary for the elements
    to be sorted.
    Return Value: It has a void return type, so it does not return any value.

    The complexity of partial_sort() is O(N*log K) where N is the number of elements in array and K is the number of elements between middle and start. The partial_sort() is faster than sort() if K is significantly smaller than N as partial_sort() will sort first K elements whereas sort() will sort all the N elements.

    */
    partial_sort(v.begin(), v.begin() + 3, v.end());
    cout << "\nAfter sorting: ";
    for (auto i : v)
        cout << i << " ";

    /*
    we can use our own comparator function, but here we've used inbuilt comparator function to sort the vector in the descending order
    */
    partial_sort(v.begin(), v.begin() + 3, v.end(), greater<int>());
    cout << "\nAfter sorting: ";
    for (auto i : v)
        cout << i << " ";
    return 0;
}