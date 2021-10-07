#include <iostream>
using namespace std;

void primeSieve(int n)
{
    int *arr = new int[n];

    //Initialize all the elements to zero.
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }

    //Mark all the non prime numbers
    for (int i = 2; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i * i; j < n; j += i)
            {
                arr[j] = 1;
            }
        }
    }

    //Printing all the numbers prime numbers
    for (int i = 2; i < n; i++)
    {
        if (arr[i] == 0)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    primeSieve(n);

    return 0;
}