#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <limits.h>
#include <utility>

using namespace std;

int main()
{
    // Stack -> LIFO
    cout << endl
         << "Stack:" << endl;
    stack<int> S;
    int arr[] = {1, 2, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        S.push(rand());
    }

    // Popping the elements from the stack
    while (!S.empty())
    {
        cout << S.top() << endl;
        S.pop();
    }

    // QUEUE FIFO
    cout << endl
         << "Queue:" << endl;
    queue<int> Q;
    for (int i = 0; i < 5; i++)
    {
        Q.push(rand());
    }
    while (!Q.empty())
    {
        cout << Q.front() << endl;
        Q.pop();
    }

    return 0;
}