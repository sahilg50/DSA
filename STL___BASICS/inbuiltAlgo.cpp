#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> v = {1, 3, 532, -1, 9, 0};
    cout << endl
         << "The min element is: " << *min_element(v.begin(), v.end());

    cout << endl
         << "The max element is: " << *max_element(v.begin(), v.end());

    // To find the sum
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << endl
         << "The sum is: " << sum;

    // To find the frequency
    int num = 0;
    int ct = count(v.begin(), v.end(), num);
    cout << endl
         << "The count of " << num << " in the vector is: " << ct;

    // To find the element
    auto it = find(v.begin(), v.end(), 10);
    if (it != v.end())
        cout << endl
             << "Found: " << *it;
    else
        cout << endl
             << "The element not found!";

    // Reverse the vector
    reverse(v.begin(), v.end());
    cout << endl
         << "After reversing: ";
    for (int &val : v)
        cout << val << " ";

    /*
    Note that all these operations are O(n) in case of vectors and arrays, but in case of maps and sets, the find and count function are O(log(n))
    */
    return 0;
}
