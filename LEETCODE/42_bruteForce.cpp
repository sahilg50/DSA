class Solution
{
public:
    int trap(vector<int> &H)
    {
        /*
        Brute Force solution:
        We notice that for every index, the water stored is given by the formula: Min(max(rSide),max(lSide)) - height[i].
        Basically, it means that for every index, the water stored is the water stored by the largest height on each side minus the height of the current index.
        
        Also note that the left and right sides of the graph do not count as walls.
        */
        int ans = 0, currentWater;
        int lMax = H[0], rMax = 0;
        for (int i = 1; i < H.size() - 1; i++)
        {

            //Look for the max height on the left side.
            lMax = max(lMax, H[i - 1]);

            //look for the max height on the right side.
            rMax = 0;
            int itr = i + 1;
            while (itr < H.size())
            {
                rMax = max(rMax, H[itr]);
                itr++;
            }

            currentWater = min(lMax, rMax) - H[i];
            ans += currentWater > 0 ? currentWater : 0;
        }

        return ans;
    }
};

/*
TC: O(N^2)
SC: O(1)
*/