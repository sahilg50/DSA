#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> &piles, int mid_val, int H)
{
    int time = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        if (piles[i] % mid_val != 0)
            time += (piles[i] / mid_val) + 1;

        else
            time += piles[i] / mid_val;
    }

    return time <= H;
}

int minEatingSpeed(vector<int> &piles, int H)
{
    int start = *min_element(piles.begin(), piles.end());
    int end = *max_element(piles.begin(), piles.end());
    while (start < end)
    {
        int mid = (start + end) / 2;

        if (isValid(piles, mid, H))
            end = mid;
        else
            start = mid + 1;
    }
    return end;
}

int main()
{

    vector<int> piles = {30, 11, 23, 4, 20};
    int H = 6; // Number of hours
    cout << minEatingSpeed(piles, H);
    return 0;
}

/*
TC-> O(Nlog W), W = max(arr) - min(arr), N is the size of the array(Piles)
SC-> O(I)
*/