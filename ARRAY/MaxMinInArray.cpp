/*Finc the Minimum and Maximum element in an array*/

#include <iostream>
using namespace std;

// function to find the minimum and maximum in an array.
void MinMax(int arr[], int size)
{

    int min = 0;
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    cout << "The max element is: " << max << endl;
    cout << "The minimum element is: " << min << endl;
}

int main()
{
    int arr[] = {1, 3, 4, 10, 34, 4, 6, 78, 6, 4, 0};

    int size = sizeof(arr) / sizeof(int);
    MinMax(arr, size);

    return 0;
}