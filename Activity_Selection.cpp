#include <iostream>
#include <algorithm>

using namespace std;

struct Item
{
    int start, end, no;
    Item(int s, int e, int n)
    {
        start = s;
        end = e;
        no = n;
    }
};

bool cmp(Item a, Item b)
{
    return a.end < b.end;
}

void activitySelection(Item arr[], int n)
{
    sort(arr, arr + n, cmp);

    int ftime = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].start >= ftime)
        {
            cout << arr[i].no << " ";
            ftime = arr[i].end;
        }
    }
}

int main()
{
    Item obj[] = {{4, 8, 1}, {1, 2, 2}, {2, 3, 3}, {0, 5, 4}, {4, 6, 5}, {7, 8, 6}};
    int n = sizeof(obj) / sizeof(obj[0]);

    cout << "Activities chosen are as below: \n";
    activitySelection(obj, n);

    return 0;
}
