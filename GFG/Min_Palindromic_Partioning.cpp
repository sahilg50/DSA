/*
Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for a palindrome partitioning of a given string. For example, minimum of 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”. If a string is a palindrome, then minimum 0 cuts are needed. If a string of length n containing all different characters, then minimum n-1 cuts are needed.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

bool isPalindrome(string &S, int L, int H)
{
    while (L < H)
    {
        if (S[L++] != S[H--])
            return false;
    }
    return true;
}

/*
Approach 1-> Recursion
The basic idea behind this approach is that we make cuts at each index and then recur for the 2 substrings formed by that.
*/
int minPaliPartitions(string S, int start, int end)
{
    if (start >= end || isPalindrome(S, start, end))
        return 0;

    int ans = INT_MAX;
    for (int cut = start; cut < end; cut++)
    {
        int count = minPaliPartitions(S, start, cut) + minPaliPartitions(S, cut + 1, end) + 1;
        ans = min(ans, count);
    }
    return ans;
}
/*
TC-> O(2^n * (n/2)), n is the size of the string. Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome.
SC-> O(n), The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
*/

int main()
{
    cout << endl
         << "Enter the string: ";
    string S;
    cin >> S;
    cout << minPaliPartitions(S, 0, S.size() - 1) << endl;
    return 0;
}
