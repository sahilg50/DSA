#include <iostream>
#include <cstring>
using namespace std;

/*
 - Collection of datatypes is array
 - local array size limit = order of 10^5
 - global array size limit = order of 10^7
 - global and static arrays are stored in data segemnt of the memory.
 - local arrays or pointer to dynamic array(array stored in heap) are stored in stack.
 - With dynamic arrays, you have to handle the memory by yourself, so it is preferred to use vectors where the memory management is hidden from the user.
*/

const int N = 1e7;
int arr1[N];

int main()
{

    int a[10]; // array a of size

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

    // 2D Array
    int b[3][4]; // 3 rows and 4 columns

    return 0;
}