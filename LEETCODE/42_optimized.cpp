class Solution
{
public:
    int trap(vector<int> &H)
    {

        /*Now we'll look at the optimized solution for this problem which is based on the ideology from the brute force solution*/

        if (H.size() < 3)
        {
            return 0; //First and last index and cannot hold water.
        }

        int lMax = 0, rMax = 0;
        int totalWater = 0, currentWater;
        int low = 0, high = H.size() - 1;

        while (low < high)
        {

            lMax = max(lMax, H[low]);
            rMax = max(rMax, H[high]);

            //Move left ptr if lMax < rMax
            if (lMax <= rMax)
            {
                currentWater = lMax - H[low++];
                totalWater += currentWater > 0 ? currentWater : 0;
            }
            //Move right ptr if lMax > rMax
            else
            {
                currentWater = rMax - H[high--];
                totalWater += currentWater > 0 ? currentWater : 0;
            }
        }
        return totalWater;
    }
};

/*
TC: O(N), where N is the size of the array 
SC: O(1)
*/