int lcsRecur(int i, int j, string S1, string S2, count)
    // {
    //     if (i == 0 || j == 0)
    //         return count;

    //     if (S1[i - 1] == S2[j - 1])
    //     {
    //         count = lcsRecur(i - 1, j - 1, S1, S2, count + 1);
    //     }
    //     count = max(count, max(lcsRecur(i, j - 1, S1, S2, 0), lcsRecur(i - 1, j, S1, S2, 0)));
    //     return count;
    // }