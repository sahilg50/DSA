#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -inf < nums[i] < +inf
void largest_secondLargest(vector<int> &nums)
{
    if (nums[0] > nums[1])
        swap(nums[0], nums[1]);

    int fl = nums[1];
    int sl = nums[0];

    for (int i = 2; i < nums.size(); i++)
    {
        if (nums[i] > fl)
        {
            sl = fl;
            fl = nums[i];
        }
        else if (nums[i] < fl)
            sl = max(sl, nums[i]);
    }

    cout << "\nLargest: " << fl << "\nSecond largest: " << sl;

    /*
    TC-> O(N), single pass of array
    SC-> O(1), constant
    */
}

int main()
{
    vector<int> nums = {-10, 0, -2, 8, 9};
    largest_secondLargest(nums);
    return 0;
}