#include <iostream>
#include <queue>
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

    return 0;
}