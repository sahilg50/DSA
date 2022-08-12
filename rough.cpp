#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char finLongestSingleSlot(vector<pair<int, int>> &leaveTime)
{
    int id = leaveTime[0].first;
    int maxShift = leaveTime[0].second;
    for (int i = 1; i < leaveTime.size(); i++)
    {
        int currShift = leaveTime[i].second - leaveTime[i - 1].second;
        if (currShift > maxShift)
        {
            maxShift = currShift;
            id = leaveTime[i].first;
        }
    }
    return 'a' + id;
}

int main()
{
    int n;
    cin >> n;
    int size;
    cin >> size;
    int id, lt;
    vector<pair<int, int>> input;
    while (n--)
    {
        cin >> id >> lt;
        input.push_back({id, lt});
    }
    cout << finLongestSingleSlot(input);
}