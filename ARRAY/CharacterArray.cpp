//Check if a name is palindrome or not.

#include <iostream>

using namespace std;

int main()
{

    char arr[100];
    cin >> arr;

    bool check = 1;

    int i = 0;
    while (arr[i] != '\0')
    {

        if (arr[i] != arr[n - 1 - i])
        {
            check = 0;
            break;
        }
    }

    return 0;
}