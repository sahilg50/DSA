//Find the largest word in the sentence.

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    char arr[1000];
    cout << "Enter the string: ";
    cin.getline(arr, 1000);
    cin.ignore();

    int maxlen = INT16_MIN;
    int st = 0, maxst = 0;
    int currLen = 0;
    int i = 0;
    while (true)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {

            if (currLen > maxlen)
            {
                maxlen = currLen;
                maxst = st;
            }
            currLen = 0;
            st = i + 1;
        }
        else
        {
            currLen++;
        }
        if (arr[i] == '\0')
        {
            break;
        }
        i++;
    }

    cout << endl
         << maxlen << endl;

    for (int i = 0; i < maxlen; i++)
    {
        cout << arr[i + maxst];
    }

    return 0;
}