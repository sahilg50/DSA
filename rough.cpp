#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void sumOfElements(int *A, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += A[i];
    }
    cout << "\nThe sum of all elements of the array is: " << sum;
}

// Function to find the min and maximum elements from the array
void Min_MAX(int *A, int size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (min > A[i])
        {
            min = A[i];
        }
    }

    cout << "\nThe min element is: " << min;

    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }

    cout << "\nThe max element is: " << max;
}

// Function to reverse the elements of the array
void Reverse(int A[], int size)
{

    int low = 0, high = size - 1;
    while (low < high)
    {
        int temp = A[low];
        A[low] = A[high];
        A[high] = temp;
        low++, high--;
    }
}

void countFreq(int arr[], int n)
{
    // Mark all array elements as not visited
    vector<bool> visited(n, false);

    // Traverse through array elements and
    // count frequencies
    for (int i = 0; i < n; i++)
    {

        // Skip this element if already processed
        if (visited[i] == true)
            continue;

        // Count frequency
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " " << count << endl;
    }
}

int main()
{
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    int *A = new int[size];
    // Storing the elements in the array
    cout << "Enter the elements in the array: ";
    int val;
    for (int i = 0; i < size; i++)
    {
        cin >> val;
        A[i] = val;
    }

    // Print sum of all the elments
    sumOfElements(A, size);

    // Find the sum of all the elements
    Min_MAX(A, size);

    // Reverse the elements of the array
    Reverse(A, size);

    // Print the array
    cout << "\nELements after reversing the array:\n";
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }

    // Count the Frequency
    cout << "\nThe frequency of all the elements of the array is as follows:\n";
    countFreq(A, size);

    return 0;
}