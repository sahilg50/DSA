#include <iostream>
#include <vector>
using namespace std;

// Create the segment tree based on the maximum element in a given range.
void createSegmentTree(int ind, int low, int high, vector<int> &arr, vector<int> &seg)
{
    // Base case
    if (low == high)
    {
        seg[ind] = arr[low];
        return;
    }

    // Perform all operations
    int mid = (low + high) / 2;
    createSegmentTree(2 * mid + 1, low, mid, arr, seg);
    createSegmentTree(2 * mid + 2, mid + 1, high, arr, seg);

    // Return
    seg[ind] = max(seg[ind * 2 + 1], seg[ind * 2 + 2]);
}

int query(int ind, int low, int high, vector<int> &seg, int l, int r)
{
    if (low >= l && high <= r)
    {
        return seg[ind];
    }

    if (high < l || low > r)
    {
        return INT_MIN;
    }

    int mid = (low + high) / 2;
    int left = (mid * 2 + 1, low, mid, seg, l, r);
    int right = (mid * 2 + 2, mid + 1, high, seg, l, r);

    return max(left, right);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int N = arr.size();
    vector<int> seg(N * 4, 0); // Maximum size of segment tree = O(4*N)
    createSegmentTree(0, 0, N - 1, arr, seg);

    return 0;
}