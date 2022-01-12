class Solution
{
    //Define a strcture
    struct Column
    {
        int height;
        int Lmax;
        int Rmax;
    };

public:
    int trap(vector<int> &H)
    {
        // Now we'll be looking at a way to trade off the space complexity of the brute force solution with the time complexity.

        if (H.size() < 3)
        {
            return 0;
        }

        //Dynamic array of structures to maintain the Height of the element and leftMax and rightMax for each element of the array.
        struct Column *arr = new struct Column[H.size()];

        //Find the Height and Lmax for each element
        int Lmax = 0;
        for (int i = 0; i < H.size(); i++)
        {
            Lmax = max(Lmax, H[i]);
            arr[i].height = H[i];
            arr[i].Lmax = Lmax;
        }

        //Find the Rmax for each element
        int Rmax = 0;
        for (int i = H.size() - 1; i >= 0; i--)
        {
            Rmax = max(Rmax, H[i]);
            arr[i].Rmax = Rmax;
        }

        int totalWater = 0, currWater;
        for (int i = 0; i < H.size(); i++)
        {
            currWater = min(arr[i].Lmax, arr[i].Rmax) - arr[i].height;

            totalWater += currWater > 0 ? currWater : 0;
        }

        return totalWater;
    }
};

/*
TC: O(N)
SC: O(N)
N is the size of the array.
*/