#include <iostream>

using namespace std;

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(int);
    cout << size << endl;

    int target = 13;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            cout << "Target Found!";
            return 0;
        }
    }

    cout << "target Not found!";
    return 0;
}