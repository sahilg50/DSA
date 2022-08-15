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
    vector<int> a = {10};
    int k = 1;
    cout << findMaximumSum(a, k);
    return 0;
}