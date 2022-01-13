class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> have;
        unordered_map<char, int> need;

        for (auto i : t)
        {
            need[i]++;
        }

        int haveCount = 0, needCount = need.size();
        int i = -1, j = -1, resLength = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.length(); r++)
        {
            char c = s[r];
            have[c]++;

            if (need.count(c) && have[c] == need[c])
            {
                haveCount += 1;
            }

            while (haveCount == needCount)
            {
                if ((r - l + 1) < resLength)
                {
                    i = l;
                    j = r;
                    resLength = r - l + 1;
                }

                //Pop from the left of our window
                have[s[l]] -= 1;
                if (need.count(s[l]) && have[s[l]] < need[s[l]])
                {
                    haveCount -= 1;
                }
                l += 1;
            }
        }

        if (resLength != INT_MAX)
        {

            return s.substr(i, resLength);
        }
        return "";
    }
};