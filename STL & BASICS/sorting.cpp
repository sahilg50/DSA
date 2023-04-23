#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <random>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    /*
    Compares the first element of the pair, if it is same then it compares the second element of the pair.
    */
    return a < b;
}

int main()
{
    /*
    TOPIC: INTRO
    SORT is used by c++ STL
    In the sorting function, we define the starting index and the ending index + 1.
    */
    cout << "\nSorting the array using sort()" << endl;
    int arr[] = {3, 1, 7, 9, 4, 5, 10, 6};
    int n = sizeof(arr) / sizeof(int);
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    /*
    Now let's look at comparator function and we'll sort a vector of pairs using selection sort and custom comparator function(cmp)
    */
    vector<pair<int, int>> V = {{1, 2}, {3, 4}, {9, 0}, {-1, -1}, {-1, -10}};
    n = V.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (cmp(V[i], V[j]))
            {
                swap(V[i], V[j]);
            }
        }
    }

    cout << "\n\nPrinting the sorted vector<pair>: ";
    for (auto &pv : V)
    {
        cout << endl
             << pv.first << " " << pv.second;
    }

    // TOPIC: Custom comparator function.
    V = {{1, 2}, {3, 4}, {9, 0}, {-1, -1}, {-1, -10}};
    sort(V.begin(), V.end(), cmp);
    cout << "\n\nPrinting the sorted vector<pair> using custom cmp inside sort(): ";
    for (auto &pv : V)
    {
        cout << endl
             << pv.first << " " << pv.second;
    }

    // TOPIC: Inbuilt comparator function.
    sort(V.begin(), V.end(), greater<pair<int, int>>());
    cout << "\n\nPrinting using inbuilt cmp inside sort(): ";
    for (auto &pv : V)
    {
        cout << endl
             << pv.first << " " << pv.second;
    }

    /*
    TOPIC: is_sorted()
    https://www.educative.io/answers/how-to-use-the-issorted-function-in-cpp

    The is_sorted() function accepts the following parameters.
        -> first: This is the start position of your search space. It is an iterator that usually points to the start of an array.

        -> last: This is the end position of your search space. It is an iterator that usually points to the last position of an array.

        -> comparator: This is an optional parameter. It is a binary function that accepts two elements of the same type as you have in your list. It then returns a Boolean value that indicates which element to be considered first among the two elements passed to the function.
    */
    vector<string> words = {"What", "a", "sunny", "day"};
    bool sorted = is_sorted(words.begin(), words.end());
    cout << "\n\nIs the vector of strings sorted? " << boolalpha << sorted;
    /*
    Note: "boolalpha" specifies "cout" to print in true and false format.
    In case of numbers: TC-> O(N), SC-> O(1), N = length of array
    In case of strings: TC-> O(N*W), SC-> O(1), N = number of words, W = max length of string
    */

    return 0;
}