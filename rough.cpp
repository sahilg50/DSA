#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int powerfulSubarray(int A[], int N)
{
    unordered_map<int, int> left, count;
    int mx = 0, mn, strindex;
    for (int i = 0; i < N; i++)
    {
        int x = A[i];

        if (count[x] == 0)
        {
            left[x] = i;
            count[x] = 1;
        }
        else
            count[x]++;
        if (count[x] > mx)
        {
            mx = count[x];
            mn = i - left[x] + 1;
            strindex = left[x];
        }
        else if (count[x] == mx && i - left[x] + 1 < mn)
        {
            mn = i - left[x] + 1;
            strindex = left[x];
        }
    }
    return mn - strindex;
};
int main()
{
    int a[] = {16, 3, 15, 10, 16, 17, 16, 16, 12, 2};
    cout << powerfulSubarray(a, 10);
    return 0;
}