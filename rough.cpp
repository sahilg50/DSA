#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int FindMaxSum(vector<int> &A, int k)
{
    unordered_set<int> S;
    int i, maxSum = 0, currSum = 0;
    for (i = 0; i < k; i++)
    {
        currSum += A[i];
        S.insert(A[i]);
    }
    if (S.size() == k)
        maxSum = max(maxSum, currSum);

    int L = 0, R = i, n = A.size();

    for (; R < n; R++)
    {
        S.erase(A[L++]);
        currSum -= A[L];
        S.insert(A[R]);
        currSum += A[R];
        if (S.size() == k)
            maxSum = max(maxSum, currSum);
    }

    return maxSum == 0 ? -1 : maxSum;
}

int main()
{
    vector<int> A = {20, 1, 2, 3, 40, 4, 1};
    int k = 4;
    cout << FindMaxSum(A, k);
    return 0;
}