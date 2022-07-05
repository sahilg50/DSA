#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout << "\nEnter the size of the array: ";
    int n;
    cin >> n;
    int *arr = new int[n]; // Dynamic array

    // set all the elments equal to zero
    memset(arr, 0, n * sizeof(int)); // (array address, default value, size occupied by array)

    // printing all the elements
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}