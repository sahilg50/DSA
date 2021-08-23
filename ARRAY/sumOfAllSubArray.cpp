//WAP to print the sum of all the subarray

#include <iostream>
#include <algorithm>

using namespace std;
int main()
{

    int arr[] = {1, 2, 0, 7, 2};

    int sum;
    for (int i = 0; i < 5; i++)
    {

        sum = 0;
        for (int j = i; j < 5; j++)
        {
            sum += arr[j];
            cout << sum << " ";
        }
    }

    return 0;
}