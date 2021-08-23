/*
Problem
Given an unsorted array A of size N of non-negative integers, find a continuous
subarray which adds to a given number S.
Constraints
1 <= N <= 105
0 <= Ai <= 1010
Example
Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements from 2nd position to 4th position is 12.
*/

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
int main()
{

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target variable: ";
    cin >> target;
    int low = 0;
    int high = 0;
    int sum = 0;

    while (high <= n)
    {

        if (sum == target)
        {
            break;
        }

        else if (sum > target && low != high)
        {
            sum -= arr[low];
            low++;
        }

        else
        {
            sum += arr[high];
            high++;
        }
    }

    if (sum == target)
    {
        cout << low << " " << high - 1 << endl;
    }
    else
    {
        cout << "There is no subarray whose sum i0s equal to the target variable.";
    }
    return 0;
}

//It will return the indeces both inclusive of the subarray.