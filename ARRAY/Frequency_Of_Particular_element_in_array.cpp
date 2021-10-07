//Program to find the frequency of a particular element in the array
#include <iostream>

using namespace std;
int main()
{
    cout << endl
         << "Enter the size of the array: ";
    int n;
    cin >> n;

    int *arr = new int[n];
    cout << endl
         << "Enter the elements of the array: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl
         << "Enter the target whose frequency is to be found in the array: ";

    int target;
    cin >> target;

    int freq = 0;
    for (int i = 0; i < n; i++)
    {
        if (target == arr[i])
        {
            freq++;
        }
    }

    cout << "The frequency of " << target << " is " << freq << endl;

    return 0;
}