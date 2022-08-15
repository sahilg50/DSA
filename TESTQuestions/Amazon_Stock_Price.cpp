/*
The price of Amazon common stock is analyzed over a period of several months. A group of k consecutive months is said to be observable if no two months in the group have the same stock price. In other words, all the prices in the period are distinct. The sum of stock prices of an observable group of months is called the cumulative observable sum. Given the price of Amazon stock for n months, find the maximum possible cumulative observable sum among all the observable groups of months. If there is no observable group, return -1.

Test Cases:
1-> SP=[7,7,7,7] k=1
2-> SP=[7,7,7,7] k=2
3-> SP=[1,2,7,7,4,3,6] k=3
4-> SP=[20,1,2,3,40,4,1] k=4
5-> SP=[10] k = 1
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void removeDuplicates(vector<int> &SP, int &L, int &R, int &currSum, unordered_map<int, bool> &M)
{
    while (M[SP[R]])
    {
        M[SP[L]] = false;
        currSum -= SP[L];
        L++;
    }
    M[SP[R]] = true;
    currSum += SP[R];
};

long findMaximumSum(vector<int> &SP, int k)
{
    unordered_map<int, bool> M;
    for (auto num : SP)
    {
        M[num] = false;
    }

    int L = 0, n = SP.size(), currSum = 0, maxi = 0;
    M[SP[L]] = true;
    currSum += SP[L];
    if (k == 1)
        maxi = max(maxi, currSum);
    for (int R = 1; R < n; R++)
    {
        int size = R - L + 1;
        if (size < k)
        {
            removeDuplicates(SP, L, R, currSum, M);
        }
        else if (size == k)
        {
            removeDuplicates(SP, L, R, currSum, M);
            if (R - L + 1 == k)
                maxi = max(currSum, maxi);
        }
        else
        {
            M[SP[L]] = false;
            currSum -= SP[L];
            L++;
            removeDuplicates(SP, L, R, currSum, M);
            if (R - L + 1 == k)
                maxi = max(currSum, maxi);
        }
    }
    if (maxi == 0)
        return -1;
    return maxi;
}

int main()
{
    vector<int> a = {20, 1, 2, 3, 40, 4, 1};
    int k = 4;
    cout << findMaximumSum(a, k);
    return 0;
}

/*
TC-> Creating Map:O(N) + FindMaxSum:O(N)
SC-> Map:O(N)
*/