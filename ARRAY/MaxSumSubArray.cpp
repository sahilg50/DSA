/*Find the subarray in an array which has the maximum sum*/

#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

//Cumulative sum approach
int maxSumSubarrayCummApproach(int arr[], int n)
{
    int *cumm_arr = new int[n];
    int max = arr[0];
    cumm_arr[0] = max;
    for (int i = 1; i < n; i++)
    {
        max += arr[i];
        if (arr[i] > max)
        {
            cumm_arr[i] = arr[i];
            max = arr[i];
        }
        else
        {
            cumm_arr[i] = max;
        }
    }

    int maxSum = INT16_MIN;
    for (int j = 0; j < n; j++)
    {
        if (cumm_arr[j] > maxSum)
        {
            maxSum = cumm_arr[j];
        }
    }
    return maxSum;
}

//this algorithm works only if there exists one positive element.
void kadaneAlgorithm(int arr[], int n)
{

    int currentSum = 0;
    int maxSum = INT16_MIN;

    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        if (currentSum < 0)
        {
            currentSum = 0;
        }
        maxSum = max(maxSum, currentSum);
    }
};

int main()
{

    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = maxSumSubarrayCummApproach(arr, n);
    cout << ans;

    return 0;
}