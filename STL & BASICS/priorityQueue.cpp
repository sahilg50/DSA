#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    // It is implement as max heap by default
    priority_queue<int> pq;

    // integers are arranged in ascending order: min heap
    priority_queue<int, vector<int>, greater<int>> pq2;

    /*
    Methods Description
    push() inserts the element into the priority queue
    pop() removes the element with the highest priority
    top() returns the element with the highest priority
    size() returns the number of elements
    empty() returns true if the priority_queue is empty
    */

    /*
    We cannot iterate through a priority queue like we can with vectors and other containers.
    This is why we have used a while loop and various priority_queue methods to print its elements in the program above.
    */
    while (!pq.empty())
    {
        cout << pq.top() << ", ";
        pq.pop();
    }
    /*
    This is because priority_queue is an STL Container Adapter that provides restrictive access to make it behave like a standard priority queue data structure.
*/

    /*
    Method 1: Inserting the elements iteratively
    TC-> O(NlogN)
    SC-> O(N)
    */
    int arr[] = {15, 25, 6, 54, 45, 26, 12};
    int N = sizeof(arr) / sizeof(arr[0]);
    priority_queue<int> PQ;
    for (int i = 0; i < N; i++)
        PQ.push(arr[i]);

    /*
    Method 2: Inserting all the elements at once
    This method is efficient
    TC-> O(N)
    SC-> O(N)
    */
    priority_queue<int> PQ2(arr, arr + N);

    /*
    In Priority queue of vectors, the priority is decided by comparing the elements of the vectors.
    If the first element is same, then the priority is decided by the second element in the vector and so on.
    */

    priority_queue<vector<int>> pv;
    pv.push({1, 2});
    pv.push({1, 5});
    vector<int> ans = pv.top();
    cout << "\nThe top vector is: ";
    for (int &i : ans)
        cout << i << " ";

    return 0;
}