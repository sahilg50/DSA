#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> Arr = {1, 2, 3, 0, 7, 1, 9};
    int K = 10;

    int maxLen = 0;
    int SUM = 0;

    int l = 0;

    for (int r = 0; r < Arr.size(); r++)
    {

        SUM += Arr[r];

        if (SUM == K)
            maxLen = max(maxLen, r - l + 1);

        else if (SUM > K)
        {
            while (SUM > K)
            {
                SUM -= Arr[l];
                l += 1;
                if (SUM == K)
                    maxLen = max(maxLen, r - l + 1);
            }
        }
    }

    cout << "maxLen: " << maxLen;

    return 0;
}