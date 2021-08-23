#include <iostream>
using namespace std;

int main()
{
    struct Dataset
    {
        int number;
        int count = 0;
        int flag = 0;
    };

    cout << "Enter the length of the array:\t";

    int length;
    cin >> length;

    Dataset DS[50];

    for (int i = 0; i < length; i++)
    {
        int temp;
        cout << "nter the number:\t";
        cin >> temp;
        DS[i].number = temp;
    }

    for (int j = 0; j < length; j++)
    {

        int number;

        if (DS[j].flag == 0)
        {
            DS[j].flag = 1;
            DS[j].count = 1;
            number = DS[j].number;

            for (int k = j + 1; k < length; k++)
            {
                if (DS[k].number == number)
                {
                    DS[k].flag = 1;
                    DS[j].count++;
                }
            }
        }
    }

    for (int i = 0; i < length; i++)
    {
        if (DS[i].count != 0)
        {
            cout << "The frequency of " << DS[i].number << " is " << DS[i].count << "\n";
        }
    }

    return 0;
}
