bool cmp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &segments)
    {

        /*
        We've followed a greedy approach, where in we'll be sorting the entire vector based upon the Xend. And then we'll check if any arrow passes through the segment for a particular balloon, if yes then increase then move on to the next segment else mark the arrow as the Xend.
        */
        sort(segments.begin(), segments.end(), cmp);
        int ans = 0, arrow = 0;
        for (int i = 0; i < segments.size(); i++)
        {
            if (ans == 0 || segments[i][0] > arrow)
            {
                ans++;
                arrow = segments[i][1];
            }
        }
        return ans;
    }
};

/*
TC: O(NlogN), N is the size of the vector.
SC: O(1)
*/