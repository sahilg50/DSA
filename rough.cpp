#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

void util(int i, vector<int> &val, long currSum, long &maxSum)
{
    // Base case
    if (i >= val.size())
        return;

    if (currSum % 2 == 0)
        maxSum = max(maxSum, currSum);

    // Perform all operations
    util(i + 1, val, currSum + val[i], maxSum);
    util(i + 1, val, currSum, maxSum);

    return;
}

long getMaximumEvenSum(vector<int> val)
{
    long maxSum = 0;
    util(0, val, 0, maxSum);
    return maxSum;
}

int main()
{
    return 0;
}