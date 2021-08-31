//Check if a string is palindrome or not.

#include <iostream>

using namespace std;

int main()
{
    char arr[100];

    cout << "Enter the string: ";
    cin >> arr;

    int len = 0;
    while (arr[len])
    {
        len++;
    }

    cout << "The length of the string stored in array is: " << len << endl;

    int i = 0;
    int flag = true;
    while (i <= len / 2)
    {
        if (arr[i] != arr[len - 1 - i])
        {
            flag = false;
            break;
        }
        i++;
    }
    if (flag)
    {
        cout << "The string is  palindrome!" << endl;
    }
    else
    {
        cout << "The string is  not palindrome!" << endl;
    }
    return 0;
}