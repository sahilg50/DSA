#include <iostream>
#include <deque>
using namespace std;

/*
The functions for deque are same as vector, with an addition of push and pop operations for both front and back.
The time complexities for doing various operations on deques are:
    - Accessing Elements- O(1)
    - Insertion or removal of elements- O(N)
    - Insertion or removal of elements at start or end- O(1)
*/

int main()
{
    deque<int> D;
    D.push_front(10);
    D.push_back(20);
    D.push_back(3);
    D.push_front(1);

    for (int i = 0; i < D.size(); i++)
        cout << D[i] << " ";
    return 0;
}