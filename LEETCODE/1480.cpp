class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {

        for (int i = 1; i < size(nums); i++)
            nums[i] = nums[i - 1] + nums[i];

        return nums;
    }
};

/*
TC: O(N), wehere N is the size of the array nums
SC: O(1)
*/