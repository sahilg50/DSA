/*Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
*/

#include <iostream>
using namespace std;

//function to swap two numbers in an array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort012(int arr[], int size)
{
    int low = 0;
    int mid = 0;
    int high = size - 1;
    while (mid <= high)
    {

        if (arr[mid] == 0)
        {
            swap(&arr[mid], &arr[low]);
            mid++;
            low++;
        }

        else if (arr[mid] == 1)
        {
            mid++;
        }

        else
        {
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 2, 1, 1, 1, 0, 2, 0, 1, 0};
    int size = sizeof(arr) / sizeof(int);

    sort012(arr, size);
    cout << "The sorted array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}