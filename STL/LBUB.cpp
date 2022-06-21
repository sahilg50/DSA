#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// Note the before applying the lower bound or the upper bound, the array/vector must be sorted in order to get the ans in the O(log n) TC.

int main()
{
    int n = 5;
    int *arr = new int[n];
    cout << endl
         << "Enter all " << n << " the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    /*
    LOWER BOUND
    It returns the pointer to element to be found or the element greater than that.
    If both of them are not present, then it returns the pointer to the nth index.
    In case multiple same elemets are present, then it return the pointer to the first element.
    */
    int *ptr = lower_bound(arr, arr + n, 3);
    if (ptr == (arr + n))
        cout << endl
             << "NOT FOUND" << endl;
    else
        cout << endl
             << "The element found is: " << *ptr;

    /*
    UPPER BOUND
    It returns the pointer to element greater than the element to be found.
    If that is not present, then it returns the pointer to the nth index.
    */
    ptr = upper_bound(arr, arr + n, 3);
    if (ptr == (arr + n))
        cout << endl
             << "NOT FOUND" << endl;
    else
        cout << endl
             << "The element found is: " << *ptr;

    /*
    GOOD JOB!
    Now in case of the sets and hashmaps:
    - The elements of the set must be sorted and the keys in the map must be in sorted order.
    - If LB or UB is implemented as we implement in the case of arrays or vectors then that works in the O(n) TC.
    - To make it work in the O(log(n)) TC, we write a slight;y different code.
    */

    set<int> S;
    for (int i = 0; i < 1e6; i++)
    {
        S.insert(rand());
    }

    for (int i = 0; i < 1e5; i++)
    {
        /*
        auto it = lower_bound(S.begin(), S.end(), rand());

        If you implement the lower bound in the above manner then this for loop will take a lot of time because it works in the O(n) TC.
        And you can test this, uncomment this and comment out the lower line and see it for yourself.
        */
        auto it = S.lower_bound(rand());
    }
    cout << endl
         << "The lower bound on sets is completed!";

    // LB and UP can be implemented in the strings and pairs too.
    return 0;
}