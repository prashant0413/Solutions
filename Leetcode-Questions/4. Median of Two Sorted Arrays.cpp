// APPROACH 1: USING BINARY SEARCH
// TC: O(LOG MIN(M, N))
// SC: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = m;
        while (low <= high) {
            int px = low + (high - low) / 2;
            int py = (m + n + 1) / 2 - px;

            // LEFT SIDE
            int x1 = (px == 0) ? INT_MIN : nums1[px - 1];
            int x2 = (py == 0) ? INT_MIN : nums2[py - 1];

            // RIGHT SIDE
            int x3 = (px == m) ? INT_MAX : nums1[px];
            int x4 = (py == n) ? INT_MAX : nums2[py];

            if (x1 <= x4 && x2 <= x3) {
                if ((m + n) & 1) return max(x1, x2);
                else return (max(x1, x2) + min(x3, x4)) / 2.0;
            }

            if (x1 > x4) high = px - 1;
            else if (x2 > x3) low = px + 1;
        }

        return -1;
    }
};
