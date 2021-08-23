/* 
Lucky alive person in a circle 
Given N people standing in a circle where 1st is having a sword, find the luckiest person in the circle, if, from 1st soldier who is having a sword each has to kill the next soldier and handover the sword to next soldier, in turn, the soldier will kill the adjacent soldier and handover the sword to next soldier such that one soldier remains in this war who is not killed by anyone.
*/

/* The complexity of the algorithm is O(logN), where N is the total nuber of soldiers*/

#include <iostream>

using namespace std;

int AlivePosition(int N)
{

    int p = 1;
    while (p <= N)
    {
        p *= 2;
    }
    p /= 2;

    return 2 * (N - p) + 1;
}

int main()
{
    int N;
    cout << "Enter the total number of soldiers: ";
    cin >> N;
    cout << AlivePosition(N);
    return 0;
}