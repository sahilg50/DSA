class Solution
{
public:
    int maxProfit(vector<int> &P)
    {

        /*
        L: buying price
        R: Selling price
        */
        int L = 0, R = 1, maxProfit = 0;

        while (R < P.size())
        {
            //Update the buying price
            if (P[R] < P[L])
            {
                L = R;
            }

            //Update the maxProfit
            maxProfit = max(maxProfit, (P[R] - P[L]));

            R++;
        }

        return maxProfit;
    }
};

/*
TC: O(N), N is the size of the array.
SC: O(1)
*/