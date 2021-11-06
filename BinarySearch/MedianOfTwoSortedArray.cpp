// Find the median of two sorted arrays of different sizes
// The brute force time complexity would be O(m+n)
// The optimal time complexity would be O(log(m+n))
// Apply the binary search on the smaller array because this way you'll pass many edge test cases.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if (nums2.size() < nums1.size())
        return findMedianSortedArrays(nums2, nums1);
    int n1 = nums1.size();
    int n2 = nums2.size();
    int low = 0, high = n1;

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = cut1 == 0 ? INT16_MIN : nums1[cut1 - 1];
        int left2 = cut2 == 0 ? INT16_MIN : nums2[cut2 - 1];

        int right1 = cut1 == n1 ? INT16_MAX : nums1[cut1];
        int right2 = cut2 == n2 ? INT16_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}

int main()
{
    //Both the array are to be sorted before passing them onto the function
    vector<int> vect1{10, 20, 30, 40};
    vector<int> vect2{5, 50, 90};

    cout << findMedianSortedArrays(vect1, vect2);

    return 0;
}