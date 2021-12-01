#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets;
void generate(vector<int> &subset, int i, vector<int> &nums)
{

    //base condition
    if (i == nums.size())
    {
        subsets.push_back(subset);
        return;
    }
    // Ith element not in subset
    generate(subset, i + 1, nums);

    // Ith element in the subset
    subset.push_back(nums[i]);
    generate(subset, i + 1, nums);

    //This is called the backtracking step, i.e we have to undo the change that we made for the next function call.
    subset.pop_back();
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> subset; //empty subset
    generate(subset, 0, nums);

    for (auto i : subsets)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}