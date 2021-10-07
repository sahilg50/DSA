//Fractional Knapsack

#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int w, value;
    Item(int w, int v)
    {
        this->w = w;
        value = v;
    }
};

bool cmp(Item a, Item b)
{
    return (float)a.value / (float)a.w > (float)b.value / (float)b.w;
}

void findprofit(int n, Item obj[], int W)
{
    sort(obj, obj + n, cmp);

    float w_sum = 0, v_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (w_sum == W)
            break;
        else if (w_sum + obj[i].w > W)
        {
            v_sum += ((float)(W - w_sum) / (float)obj[i].w) * (float)obj[i].value;
            w_sum = W;
        }
        else
        {
            v_sum += obj[i].value;
            w_sum += obj[i].w;
        }
    }

    cout << "Maximum profit: " << v_sum << endl;
}

int main()
{
    Item obj[] = {{1, 5}, {3, 10}, {5, 15}, {4, 7}, {1, 8}, {3, 9}, {2, 4}};
    int W = 15;
    int n = sizeof(obj) / sizeof(obj[0]);

    findprofit(n, obj, W);

    return 0;
}
