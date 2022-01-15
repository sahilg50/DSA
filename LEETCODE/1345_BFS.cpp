class Solution
{
public:
    int minJumps(vector<int> &arr)
    {

        /*
        This question can be understood by breaking down it down into two parts:
        1. Forming a directed graph.
        2. Applying BFS and return the level at which the last index is reached
        
        Although we've written a slight different code to optimize the solution to O(n) time and space complexity. So basically we've applied BFS, without forming any graph.
        */
        int n = arr.size();

        unordered_map<int, vector<int>> indicesOfValues;
        for (int i = 0; i < arr.size(); i++)
        {
            indicesOfValues[arr[i]].push_back(i);
        }

        vector<bool> visited(n);
        visited[0] = true;
        queue<int> q;
        q.push(0);

        int step = 0;
        while (!q.empty())
        {
            for (int size = q.size(); size > 0; --size)
            {
                int i = q.front();
                q.pop();

                if (i == n - 1)
                    return step; //Reached to the last index
                vector<int> &next = indicesOfValues[arr[i]];
                next.push_back(i - 1);
                next.push_back(i + 1);
                for (int j : next)
                {
                    if (j >= 0 && j < n && !visited[j])
                    {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear();
            }
            step++;
        }
        return 0;
    }
};

/*
TC: O(n); n is the size of the array
SC: O(n)
*/