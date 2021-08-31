//Print the maximum circular subarray sum.

#include <iostream>
#include <algorithm>

int kadaneAlgorithm(int arr[], int n)
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

    return maxSum;
};

int maxCircularSubArraySum(int arr[], int n){

};

using namespace std;
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

    int wrapSum;
    int nonwrapSum;

    nonwrapSum = kadaneAlgorithm(arr, n);

    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
        arr[i] = -arr[i];
    }

    wrapSum = total_sum + kadaneAlgorithm(arr, n);

    cout << max(wrapSum, nonwrapSum);
    return 0;
}