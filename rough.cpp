#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int util(int ind, int target, vector<int> &elements, vector<vector<int>> &dp)
{
    // Base case
    if (ind >= elements.size() || target < 0)
        return -1e9;
    if (target == 0)
        return 1;

    // Pick the element
    int pick = 0, notPick = 0;
    pick = 1 + util(ind + 1, target - elements[ind], elements, dp);

    // Skip the element
    notPick = util(ind + 1, target, elements, dp);

    return max(pick, notPick);
}

int find_max_elements(vector<int> array)
{
    int size = array[0] - 1;
    int target = array[1];

    vector<int> elements;
    for (int i = 0; i < size; i++)
    {
        elements.push_back(array[2 + i]);
    }

    vector<vector<int>> dp(size + 1, vector<int>(target + 1, -1));
    return util(0, target, elements, dp);
}

// int balance_water(vector<int> elements){

//     vector<int> capacities, initial_volume, final_volume;
//     for(int i=1; i<=4; i++) capacities.push_back(elements[i]);
//     for(i)
// }

int main()
{
    // vector<int> apple_sizes = {1, 2, 3, 2, 4};
    // {4, 2, 6, 100, 101, 101, 110, 102};
    // int max_size_difference = 1;
    // cout << find_max_apples(max_size_difference, apple_sizes);

    vector<int> array = {4, 5, 3, 3, 3};
    cout << find_max_elements(array);

    return 0;
}