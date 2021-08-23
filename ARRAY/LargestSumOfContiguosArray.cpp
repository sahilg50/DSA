//Find the largest sum of contiguos subArray

#include <iostream>
#include <algorithm>
using namespace std;

void LargestSum(int arr[], int m)
{

    int maxH = 0, maxF = arr[0];
    int temp = 0;

    for (int i = 0; i < m; i++)
    {
        maxH += arr[i];
        maxF = max(maxH, maxF);

        if (maxH < 0)
            maxH = 0;
    }

    cout << "The largest sum of the contiguos subArray is: " << maxF << endl;
}

int main()
{

    int arr[] = {-47, 43, 94, -94, -93, -59, 31, -86};
    int size = sizeof(arr) / sizeof(int);
    LargestSum(arr, size);
    return 0;
}