// Reverse an Array

#include <iostream>
using namespace std;

/*Function to reverse the array from start to the end*/

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

//Utility function to print an array
void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*Driver function to test the above function*/
int main()
{
    int arr[] = {1, 2, 4, 4, 5, 5, 5, 5, 9, 1, 3, 5, 6, 9};
    int n = sizeof(arr) / sizeof(int);

    //print the original array
    printArray(arr, n);

    //reverse the array
    reverseArray(arr, 0, n - 1);
    cout << "The reversed array is: " << endl;

    //print the reversed array
    printArray(arr, n);

    return 0;
}