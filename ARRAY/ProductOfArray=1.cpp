/*
Minimum steps to make the product of the array equal to 1
*/

/*The time complexity of the algorithm is O(N), where N is the size of the array */

#include <iostream>
using namespace std;

int Steps(int arr[], int n)
{
    int negatives = 0,
        zeros = 0,
        positives = 0;

    int steps = 0;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] == 0)
            zeros++;

        else if (arr[i] < 0)
        {
            negatives++;
            steps += (-1 - arr[i]);
        }

        else
        {
            positives++;
            steps += arr[i] - 1;
        }
    }

    if (negatives % 2 == 0)
        steps += zeros;

    else
    {

        // If there are zeroes present
        // in the array
        if (zeros > 0)
        {

            // Change one zero to -1
            // and rest of them to 1
            // Total cost here will
            // be count of '0'
            steps = steps + zeros;
        }

        // If there are no zeros in the array
        else
        {

            // As no 0s are available so we
            // have to change one -1 to 1
            // which will cost 2 to
            // change -1 to 1
            steps = steps + 2;
        }
    }

    return steps;
}

int main()
{
    int arr[] = {-2, 4, 0};
    int size = sizeof(arr) / sizeof(int);

    cout << Steps(arr, size);
    return 0;
}