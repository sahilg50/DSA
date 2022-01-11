class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        /*We'll be using Moore's voting algorithm*/

        int counter = 0, majority;
        for (int num : nums)
        {
            if (counter == 0)
                majority = num;

            counter += num == majority ? 1 : -1;
        }

        return majority;
    }
};

/*
TC: O(N), where N is the size of the array
SC: O(1)
*/