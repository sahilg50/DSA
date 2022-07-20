#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j == i)
                break;
            else
                cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}